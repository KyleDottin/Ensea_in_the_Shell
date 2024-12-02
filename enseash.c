#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h> 

#define SIZE_OF_BUFFER 4096

int main() {
	const char *introduction= "Hello !\nWelcome to the Ensea micro shell. If you wish to quit type 'exit'\n";
	int sizeIntro=strlen(introduction);
	char buffer[SIZE_OF_BUFFER];
	
	//print of the Introduction sentence of the micro shell
	write(STDOUT_FILENO, introduction,sizeIntro);
	
	while(1){
			
		//Beginning of Question 1
		
		const char *prompt="Enseash>";
		int sizePrompt=strlen(prompt);
		
		write(STDOUT_FILENO, prompt,sizePrompt);
		
		//Put in a buffer the input of the user
		fgets(buffer, SIZE_OF_BUFFER,stdin);
		//Add a \0 at the end of the buffer to told him that it's the end
		buffer[strlen(buffer)-1]='\0';
		
		//Question 1 finished
		
		//Beginning of Question 3
		
		if ((strcmp("exit",buffer)==0) || (strcmp("EOF",buffer)==69)){ //compare the buffer to see if it is equal to exit or ctrl+d
			const char *answer="See you next time ;)\n";
			int sizeAnswer=strlen(answer);
		
			write(STDOUT_FILENO, answer,sizeAnswer);
			exit(EXIT_FAILURE);
		}
		
		//Question 3 finished
		
		//Beginning of Question 2
		
		int argc=0;
		char* argv[SIZE_OF_BUFFER/2]={};
		char *token = strtok(buffer, " ");
		
		//Configuration of argv
		while (token != NULL && argc < ((SIZE_OF_BUFFER/2) - 1)) {
			argv[argc++] = token;
			token = strtok(NULL, " ");
		}
		argv[argc]=NULL;
		
		pid_t process=fork();
		
		if (process < 0) {
            perror("Fork failed");
            continue;
        }
		
		//Execution of the command given by the user
		
		if(process==0){ //child process
			int status= execvp(buffer,argv);
			if(status==-1){
				const char *answer="Error: Command not found \n";
				printf("%s",buffer);
				int sizeAnswer=strlen(answer);
		
				write(STDOUT_FILENO, answer,sizeAnswer);
			}

		}else{ //parent process
			wait(&process);
		}
		
		//Question 2 finished
		
	}
}
