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

void my_mkdir(int argc, char *c[]){

    if(strcmp(c[1],"-m")==0){
        DIR* dir =opendir(c[2]);
		printf("Do you create this directory\n");
		char ans[10];
		mygets(ans,10);
		char *temp;
		temp=strtok(ans," ");
		if (strcmp(temp,"no")==0 ||strcmp(temp,"No")==0 || strcmp(temp,"NO")==0){}
		else{
			if(!dir){
        	    mkdir((const char *)c[2], S_IRWXU);
				printf("Directory has been created \n" );
			}
			else{
				printf("Directory already exists\n");
				closedir(dir);
			}
		}
		
	}
	else if(strcmp(c[1],"-v")==0){
		DIR* dir =opendir(c[2]);
		if(!dir){
            mkdir((const char *)c[2], S_IRWXU);
			printf("Directory has been created \n" );
		}
		else{
			printf("Directory already exists\n");
			closedir(dir);
		}
	}
	else{
		DIR* dir =opendir(c[1]);
		if(!dir){
            mkdir((const char *)c[1], S_IRWXU);
			
		}
		else{
			printf("Directory already exists\n");
			closedir(dir);
		}
	}
}

int main(int argc, char *argv[])
{
    if(argc==1){
		printf("No name entered!!\n");
        return 0;
	}
	else{
		my_mkdir(argc, argv);
	}
	
	return 0;
}