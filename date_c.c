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


void date(int argc, char *c[]){
	time_t Time;
	time(&Time);
	char buffer[100];
	if(argc==1){
		time_t Time;
		time(&Time);
		strftime(buffer,100,"%a %b %d %X %Z %Y ", localtime(&Time));
		printf("%s\n", buffer);
	}
	else{
		if(strcmp(c[1],"-R\n")==0 || strcmp(c[1],"-R")==0){
		strftime(buffer,100,"%a, %d %b %Y %X %Z ", localtime(&Time));
		printf("%s +0530\n", buffer);
		}
		else if(strcmp(c[1],"-I")==0 || strcmp(c[1],"-I\n")==0){
			strftime(buffer,100,"%Y-%m-%d ", localtime(&Time));
			printf("%s\n", buffer);
		}
		else{
			printf("Wrong form!!\n");
		}
	}
	

}

int main(int argc, char *argv[])
{
	if(argc>2){
		printf("Wrong number of argumnts passed!!\n");
	}
	else{date(argc, argv);}
	
	return 0;
}