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
		const char *prompt="Enseash>";
		int sizePrompt=strlen(prompt);
		
		write(STDOUT_FILENO, prompt,sizePrompt);
		
		//Put in a buffer the input of the user
		fgets(buffer, SIZE_OF_BUFFER,stdin);
		//Add a \0 at the end of the buffer to told him that it's the end
		buffer[strlen(buffer)-1]='\0';
		
		//Question 1 finished
		
		if(strcmp("fortune",buffer)==0){
			const char *answer="Today is what happened to yesterday. \n";
			int sizeAnswer=strlen(answer);
			write(STDOUT_FILENO, answer,sizeAnswer);
		}
		if(strcmp("date",buffer)==0){
			time_t t = time(NULL);
			time(*t);
			const char *answer=const char (t);
			int sizeAnswer=strlen(answer);
			write(STDOUT_FILENO, answer,sizeAnswer);
		}
	}
}
