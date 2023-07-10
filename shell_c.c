#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h> 
#include <unistd.h> 
#include <libgen.h> 
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <dirent.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <pthread.h>

struct temp{
	char *temp[100];
};

void *func(void *tt)
{
	
	struct temp* x = (struct temp*)tt;
	// printf("\n\nHI\n\n");
	if(strcmp(x->temp[0],"ls")==0){
		char a[] = "./ls ";
		if(!x->temp[1]){
		}
		else{
			// printf()
			for(int i=1;i<1000;i++){
				if(!x->temp[i]){break;}
				else{
					strcat(a,x->temp[i]);
					strcat(a," ");
				}
			}
		}
		system(a);
	}else if(strcmp(x->temp[0],"date")==0){
		char a[] = "./date ";
		if(!x->temp[1]){
		}
		else{
			// printf()
			for(int i=1;i<1000;i++){
				if(!x->temp[i]){break;}
				else{
					strcat(a,x->temp[i]);
					strcat(a," ");
				}
			}
		}
		system(a);
	}else if(strcmp(x->temp[0],"rm")==0){
		char a[] = "./rm ";
		if(!x->temp[1]){
		}
		else{
			// printf()
			for(int i=1;i<1000;i++){
				if(!x->temp[i]){break;}
				else{
					strcat(a,x->temp[i]);
					strcat(a," ");
				}
			}
		}
		system(a);
	}else if(strcmp(x->temp[0],"mkdir")==0){
		char a[] = "./mkdir ";
		if(!x->temp[1]){
		}
		else{
			// printf()
			for(int i=1;i<1000;i++){
				if(!x->temp[i]){break;}
				else{
					strcat(a,x->temp[i]);
					strcat(a," ");
				}
			}
		}
		system(a);
	}else if(strcmp(x->temp[0],"cat")==0){
		// printf("HI");
		char a[] = "./cat ";
		if(!x->temp[1]){
		}
		else{
			// printf()
			for(int i=1;i<1000;i++){
				if(!x->temp[i]){break;}
				else{
					strcat(a,x->temp[i]);
					strcat(a," ");
				}
			}
		}
		system(a);
	}
    // exit the current thread
    pthread_exit(NULL);
}



int main(){

    int max_size = 100;
	
	char line[max_size];
	int ctr=0;

	char root_folder[1000];
	getcwd(root_folder,sizeof(root_folder));

    while(1){
        printf("myShell>>>");
		fgets(line,max_size,stdin);

		if(line==NULL){
			break;
		}

		char *history[100];
		history[ctr]=strdup(line);
		ctr++;

		char root[100];
		strcpy(root,root_folder);
		char *final=line;

		int command_check=0;

		char *present_dir;
		char curr_path[100];
		char buff[1000];

		

		char *tkn=NULL;
		tkn=strtok(line," ");
		
		char *exec[100];
		int i=0;
		
		while(tkn !=NULL){
			exec[i] = (char *) malloc(strlen(tkn)+1);
			strcpy(exec[i],tkn);
			tkn=strtok(NULL," ");
			i++;
		}
		int j=i;
		exec[i]=NULL;

        if(strcmp(exec[0],"exit\n")==0){
            break;
            //continue;
        }
        else if(strcmp(exec[0],"cd")==0 || strcmp(exec[0],"cd\n")==0){
			if(strcmp(exec[0],"cd\n")==0){
				printf("ERROR: Directory name not passed!!\n");
				continue;
			}
			int len = strlen(exec[1]);
    		exec[1][len-1] = '\0';
			// printf("%s",exec[1]);
			DIR *dir =opendir(exec[1]);
			if(dir){
				chdir(exec[1]);
			}
            else{
				printf("ERROR: Directory not found!!\n");
			}
            //cd
			continue;
        }
        else if(strcmp(exec[0],"pwd\n")==0 || strcmp(exec[0],"pwd")==0){
			if(strcmp(exec[0],"pwd\n")==0){
				char wd[1000];
            	printf("%s\n",getcwd(wd, sizeof(wd)));
			}
            else{
				if(strcmp(exec[1],"-L\n")==0 || strcmp(exec[1],"-L")==0){
					char wd[1000];
            		printf("%s\n",getcwd(wd, sizeof(wd)));
				}
				else if(strcmp(exec[1],"-P\n")==0){
					printf("%s\n",getenv("PWD"));
				}
				else{
					printf("WRONG COMMAND!!\n");
				}
			}
            //pwd
            continue;
        }
        else if(strcmp(exec[0],"echo")==0 || strcmp(exec[0],"echo\n")==0){
			// printf("%d",sizeof(exec));
			if(strcmp(exec[1],"*\n")==0){
				system("./ls");
			}
			
			else if(strcmp(exec[1],"-n")==0 || strcmp(exec[1],"-n\n")==0){
				char f;
				f=exec[2][0];
				if(f=='"' || f=='\''){
					exec[2] = exec[2]+1;
					exec[2][strlen(exec[2])-1] = '\0';
					strcat(exec[2], "\n");
				}
				exec[2][strlen(exec[2])-2] = '\0';
				if(exec[2]==NULL){
					printf("Argument not passed\n");
				}
				else{ 
					for(int i=2;i<sizeof(exec)-1;i++){
						if(exec[i]==NULL){
							break;
						}
						printf("%s ",exec[i]);
            	 	}
				}

			}
			else{
				char f;
				f=exec[1][0];
				if(f=='"' || f=='\''){
					exec[1] = exec[1]+1;
					exec[1][strlen(exec[1])-2] = '\0';
					strcat(exec[1], "\n");
				}

				if(exec[1]==NULL){
					printf("Argument not passed\n");
				}
				else{ 
					for(int i=1;i<sizeof(exec)-1;i++){
						if(exec[i]==NULL){
							break;
						}
						printf("%s ",exec[i]);
            	 	}
				}
			}
			
			continue;
        }

		if(strcmp(exec[j-1],"&t\n")==0){
			pthread_t ptid;

			// char *tkn=NULL;
			// tkn=strtok(line," ");
			
			// printf("HELLO AE");
			struct temp* tt = (struct temp*)malloc(sizeof(struct temp));
			for(int z=0;z<j-1;z++){
				tt->temp[z] = exec[z];
			}
  
    		// Creating a new thread
    		pthread_create(&ptid, NULL, &func, (void *)tt);
			pthread_join(ptid,NULL);
			//pthread
		}
		else{
			if(fork()==0){
				
				if(strcmp(exec[0],"ls\n")==0 || strcmp(exec[0],"ls")==0){
					int len = strlen(exec[j-1]);
    				exec[j-1][len-1] = '\0';
					strcat(root_folder,"/ls");
					execv(root_folder,exec);
				}else if(strcmp(exec[0],"date\n")==0 || strcmp(exec[0],"date")==0){
					int len = strlen(exec[j-1]);
    				exec[j-1][len-1] = '\0';
					strcat(root_folder,"/date");
					execv(root_folder,exec);
				}else if(strcmp(exec[0],"rm\n")==0 || strcmp(exec[0],"rm")==0){
					int len = strlen(exec[j-1]);
    				exec[j-1][len-1] = '\0';
					strcat(root_folder,"/rm");
					execv(root_folder,exec);
				}else if(strcmp(exec[0],"mkdir\n")==0 || strcmp(exec[0],"mkdir")==0){
					int len = strlen(exec[j-1]);
    				exec[j-1][len-1] = '\0';
					strcat(root_folder,"/mkdir");
					execv(root_folder,exec);
				}else if(strcmp(exec[0],"cat\n")==0 || strcmp(exec[0],"cat")==0){
					int len = strlen(exec[j-1]);
    				exec[j-1][len-1] = '\0';
					strcat(root_folder,"/cat");
					execv(root_folder,exec);
				}
				exit(0);
			}
			else{
				wait(NULL);
			}
		}
    }
    

}