#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

/*LAB #2 - 2*/

// Jamshidjon Khakimjonov // UnixProg // U1710260 //

int main(int argc, char const *argv[])
{

	int fd,fdr,decimal=0,x;
	char *filename="filename.txt";
	char *result_filename="resulting_file_2nd.txt";

	char buf[1024];
	int cur,counter=0;
	char binary[32];
	int sizeoffile;

	fd=open(filename,O_RDWR,0777);
	fdr=open(result_filename,O_CREAT|O_TRUNC|O_RDWR,0777);


	sizeoffile=read(fd,buf,1024);
	lseek(fd,0,SEEK_SET);

	for (int i = 0; i < sizeoffile/2; ++i){
		read(fd,buf,1);
		write(fdr,buf,1);
	}

	for (int i = 1; i <=sizeoffile-sizeoffile/2; i++){
		lseek(fd,(off_t)i*(-1),SEEK_END);
		read(fd,buf,1);
		write(fdr,buf,1);
	}
	close(fd);
	close(fdr);
	return 0;
}
