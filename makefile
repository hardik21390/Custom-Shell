all:
	gcc date_c.c -o date
	gcc rm_c.c -o rm
	gcc mkdir_c.c -o mkdir
	gcc ls_c.c -o ls
	gcc cat_c.c -o cat
	gcc shell_c.c -o shell -lpthread
	./shell