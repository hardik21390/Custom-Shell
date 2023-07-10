#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <dirent.h>
void read(int i){

    DIR *folders;
	struct dirent *file_names;

	folders = opendir(".");
    if(i==1){
        if(folders== NULL){
        }
        else{
            while((file_names= readdir(folders)) != NULL){
                    if(strcmp(file_names->d_name,".")==0 || strcmp(file_names->d_name,"..")==0){
                    }
                    else{
                        printf("%s\t",file_names->d_name );
                    }
                }
        }
        closedir(folders);
    }
    else if(i==2){
        if(folders== NULL){
        }
        else{
            while((file_names= readdir(folders)) != NULL){
                    if(strcmp(file_names->d_name,".")==0 || strcmp(file_names->d_name,"..")==0){
                    }
                    else{
                        printf("%s\n",file_names->d_name );
                    }
                }
        }
        closedir(folders);
    }
    
}
void ls(int argc, char *c[]){

	
	DIR *folders;
	struct dirent *file_names;

	folders = opendir(".");
	

	

    if(argc!=1){
        if(strcmp(c[1],"-1\n")==0 || strcmp(c[1],"-1")==0){
            read(2);
            
        }
        else if(strcmp(c[1],"-m")==0 || strcmp(c[1],"-m\n")==0){
            // printf("\n");
            if(folders== NULL){
                
            }
            else{
                while((file_names= readdir(folders)) != NULL){
                    if(strcmp(file_names->d_name,".")==0 || strcmp(file_names->d_name,"..")==0){
                    }
                    else{
                        printf("%s, ",file_names->d_name );
                    }
                }
                printf("\n");
            }
            closedir(folders);
        }
        else{
            printf("ERORR: Improper command!!\n");
        }
    }
	
    else{
		read(1);
        printf("\n");
	}
	
	
}

int main(int argc, char  *argv[])
{
    
    if(argc>2){
		printf("Wrong number of argumnts passed!!");
	}
	else{ls(argc, argv);}
	return 0;
}