#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>
#include<syslog.h>
int main(int argc, char* argv[]){
	
	if (argc<=2)
	{	
		openlog(NULL, 0,LOG_USER);
		syslog(LOG_ERR, "Invalid number of arguments: %d", argc);
		return 1;
	}
	
	char * buf= argv[2];
	ssize_t nr;


	printf("Number of arguments = %d \n", argc);
	for(int i=0; i<argc; i++){
		printf("%s\n", argv[i]);
	}

//opening/creating file
	int fd;
	fd = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, S_IRWXU);
	if(fd==-1)
	{
		openlog(NULL, 0,LOG_USER);
		syslog(LOG_ERR, "File could not open");
		return 1;
	}
	else
		printf("File opened\n");
	
//writing to file
	nr=write(fd,buf,strlen(buf));

	if(nr==-1)
	{
		openlog(NULL, 0,LOG_USER);
		syslog(LOG_ERR, "Writing to file failed");

		return 1;
	}
	else 
		printf("Written successfully");
	


//closing the file

	if(close(fd)==-1)
	{
		openlog(NULL, 0,LOG_USER);
		syslog(LOG_ERR, "Closing the  file failed");
		return 1;
	}
	else
		printf("File closed\n");
	
	openlog(NULL, 0, LOG_USER);
	syslog(LOG_DEBUG,"Writing %s to %s \n", argv[2], argv[1]);
	return 0;
}














