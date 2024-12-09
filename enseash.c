#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h> 

#define SIZE_OF_BUFFER 4096
#define SPACE "\n"
#define GOODBYE "See you next time ;)\n"


void PrintPrompt(const char *prompt,int size){
	write(STDOUT_FILENO,prompt,size);
	}
	
int ExecuteCommand(char *buffer) {
    int argc = 0;
    char *argv[SIZE_OF_BUFFER] = {};
    char *token = strtok(buffer, " ");

    // Configuration of argv
    while (token != NULL && argc < ((SIZE_OF_BUFFER) - 1)) {
        argv[argc++] = token;
        token = strtok(NULL, " ");
    }
    argv[argc] = NULL;

    if(argc==0){ //Handle the case when pressing entry
		return -1;
	}

    pid_t process = fork();

    if (process < 0) {
        perror("Fork failed");
        return -1;
    }
    if (process == 0) { // Child process
        int status = execvp(argv[0], argv);

        if (status == -1) {
            const char *errorMsg = "Error: Command not found \n";
            PrintPrompt(errorMsg, strlen(errorMsg));
            exit(EXIT_FAILURE);
        }
        return status;
    } else { // Parent process
        int status;
        waitpid(process, &status, 0);
        return status;
    }
    
}

int IsExit(ssize_t inputOfBuffer, char *buffer){
		if (inputOfBuffer==0){ //compare the buffer to see if it is equal to ctrl+d
			return 0;
		}
		if ((strcmp("exit",buffer)==0)){ //compare the buffer to see if it is equal to exit
			return 1;
		}
		return -1;
}

void NewPrompt(int status, int lastStatus, long duration){
	char prompt[SIZE_OF_BUFFER];
	
	if (WIFEXITED(status)) {
		lastStatus = WEXITSTATUS(status);
        snprintf(prompt, SIZE_OF_BUFFER, "Enseash [exit:%d|%ldms]>", lastStatus,duration);
    } else if (WIFSIGNALED(status)) {
		int signal = WTERMSIG(status);
        snprintf(prompt, SIZE_OF_BUFFER, "Enseash [sign:%d|%ldms]>", signal,duration);
    } else {
         snprintf(prompt, SIZE_OF_BUFFER, "Enseash>");
     }
     PrintPrompt(prompt,strlen(prompt)); 

}

long Duration(long second, long nanosecond){
	return second*1000+nanosecond/1000000;
	
	}

int main() {
	const char *introduction= "Hello !\nWelcome to the Ensea micro shell. If you wish to quit type 'exit'\n";
	int sizeIntro=strlen(introduction);
	char buffer[SIZE_OF_BUFFER];
	
	//print of the Introduction sentence of the micro shell
	PrintPrompt(introduction,sizeIntro);
	
	//Beginning of Question 1
	const char *firstBeginningPrompt="Enseash>";
	int sizeBeginning=strlen(firstBeginningPrompt);
		
	PrintPrompt(firstBeginningPrompt,sizeBeginning);
	
	
	while(1){
		struct timespec start;
		struct timespec end;
		
		int lastStatus=0; //Initialization for Question 4		
		//Put in a buffer the input of the user
		ssize_t inputOfBuffer=read(STDOUT_FILENO,buffer,SIZE_OF_BUFFER);
		//Add a \0 at the end of the buffer to told him that it's the end
		buffer[strlen(buffer)-1]='\0';
		
		//Question 1 finished
		
		//Beginning of Question 3

		int isExit=IsExit(inputOfBuffer,buffer);
		if(isExit==0){
			const char *answer=SPACE GOODBYE;
			int sizeAnswer=strlen(answer);
		
			PrintPrompt(answer,sizeAnswer);
			exit(EXIT_SUCCESS);
		}else if (isExit==1){
			const char *answer=GOODBYE;
			int sizeAnswer=strlen(answer);
		
			PrintPrompt(answer,sizeAnswer);
			exit(EXIT_SUCCESS);
		}
		//Question 3 finished
		
		clock_gettime(CLOCK_MONOTONIC, &start); //Beginning of the clock just before the beginning of the execution
		
		//Beginning of Question 2 with the modification of 6
		
		int status=ExecuteCommand(buffer);
		
		//Question 2 & 6 finished
		
		clock_gettime(CLOCK_MONOTONIC, &end); //End of the clock just after the end of the execution
		
        //Beginning of Question 5
		time_t duration =Duration((end.tv_sec - start.tv_sec),(end.tv_nsec - start.tv_nsec));
		//Question 5 finished
	
		//Beginning of Question 4 
		NewPrompt(status,lastStatus,duration);
        //Question 4 finished
        
        //Reset of the buffer for the next user input
        memset(buffer, 0, SIZE_OF_BUFFER);
        
		
	}
}
