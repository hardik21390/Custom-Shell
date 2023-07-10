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

char *mygets(char *buf, size_t size) {
    if (buf != NULL && size > 0) {
        if (fgets(buf, size, stdin)) {
            buf[strcspn(buf, "\n")] = '\0';
            return buf;
        }
        *buf = '\0';  /* clear buffer at end of file */
    }
    return NULL;
}

void rem(int argc, char *c[]){
	
	if(strcmp(c[1],"-i")==0){
		printf("Do you want to delete this file\n");
		char ans[10];
		mygets(ans,10);
		char *temp;
		temp=strtok(ans," ");
		if (strcmp(temp,"no")==0 ||strcmp(temp,"No")==0 || strcmp(temp,"NO")==0){}
		else{
			DIR *dir =opendir(c[2]);
			if(!dir){
				if(remove(c[2]) == 0){
					printf("File deleted successfully \n" );
				}
				else{
					printf("Error: unable to delete the file\n");
				}
				
			}
			else{
				printf("It is a Directory\n");
				closedir(dir);
			}
		}
	}	

	else if(strcmp(c[1],"-v")==0){
		DIR *dir =opendir(c[2]);
		if(!dir){
            if(remove(c[2]) == 0){
				printf("File deleted successfully \n" );
			}
			else{
				printf("Error: unable to delete the file\n");
			}
			
		}
		else{
			printf("It is a Directory\n");
			closedir(dir);
		}
	}

	else{
		DIR *dir =opendir(c[1]);
		if(!dir){
            if(remove(c[1]) == 0){
			}
			else{
				printf("Error: unable to delete the file\n");
			}
			
		}
		else{
			printf("It is a Directory\n");
			closedir(dir);
		}
	}

	
}

int main(int argc, char *argv[])
{
	if(argc==1){
		printf("ERROR: :Enter file name\n");
	}
	else{
		rem(argc, argv);
	}
	
	
	return 0;
}