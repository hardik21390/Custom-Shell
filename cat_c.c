#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h> 
#include <unistd.h> 
#include <libgen.h> 
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <time.h>
#include <dirent.h>

void cat(int argc, char *c[]){
	FILE *file_pc;
	
	if(strcmp(c[1],"-E")==0 || strcmp(c[1],"-E\n")==0){
		file_pc =fopen(c[2],"r");
		if( file_pc != NULL){
			char * buffer=NULL;
			size_t l=0;
			ssize_t read;
			
			while ((read= getline(&buffer,&l,file_pc)) != -1){
				printf("&%s", buffer);
			}
		}
		else{
			perror("Error: ");
		}
		fclose(file_pc);
	}

	else if(strcmp(c[1],"-n")==0 || strcmp(c[1],"-n\n")==0){
		file_pc =fopen(c[2],"r");
		if( file_pc != NULL){
			char * buffer=NULL;
			size_t l=0;
			ssize_t read;
			int count=1;
			while ((read= getline(&buffer,&l,file_pc)) != -1){
				printf("%d %s",count++,buffer );
			}
		}
		else{
			perror("Error: ");
		}
		fclose(file_pc);
	}

	else{
		if(argc==2){
			file_pc =fopen(c[1],"r");
			if( file_pc != NULL){
				char * buffer=NULL;
				size_t l=0;
				ssize_t read;
				
				while ((read= getline(&buffer,&l,file_pc)) != -1){
					printf("%s",buffer );
				}
			}
			else{
				perror("Error: ");
			}
			fclose(file_pc);
		}
		else{printf("Error: Arguments not passed correctly");}
		
	}
	printf("\n");
	
}

int main(int argc, char *argv[])
{
	// for(int i=0;i<argc;i++){
	// 	printf("%s",argv[i]);
	// }
	if(argc==1){
		printf("ERROR: :Enter file name\n");
		return 0;
	}
	cat(argc, argv);
	return 0;
}