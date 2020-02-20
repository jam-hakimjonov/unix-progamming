#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

/*LAB #2 - 1*/

// Jamshidjon Khakimjonov // UnixProg // U1710260 //

int main(int argc, char const *argv[])
{
	int fd,fdr,decimal=0,x;
	char *filename="filename.txt";
	char *result_filename="resulting_file_1st.txt";

	char buf[1024];
	int cur,counter=0;
	char binary[32];
	int sizeoffile;

	fd=open(filename,O_RDWR,0777);
	fdr=open(result_filename,O_CREAT|O_TRUNC|O_RDWR,0777);
	
	lseek(fd,0,SEEK_SET);
			while(read(fd,buf,1)>0)
			{	
				cur=lseek(fd,0,SEEK_CUR);
				if(buf[0]>=48&&buf[0]<=57)
				{
					if((cur-1)%2==0&&counter!=-1)
					{
						if(counter<0)
						counter=0;
						binary[counter]=buf[0];	
						binary[counter+1]='\0';					
						counter++;
					}
					else
					{
						if(counter>0)
						{
							binary[counter]=buf[0];
							binary[counter+1]='\0';
							counter++;
						}
						else
						{
							counter=-1;
							write(fdr,buf,1);
						}
					}

				}
				else
				{
					decimal=strtol(binary,NULL,10);	
					if(counter>0){
					for (int i = 31; i >=0; i--)
						{
						 x=decimal>>i;
							 if(x&1)
							 {
							 	write(fdr,"1",1);
							 }
							else
							{
								write(fdr,"0",1);
							}
						}
					}
					counter=0;
					binary[counter]='\0';
					write(fdr,buf,1);
				}
			}
	close(fd);
	close(fdr);

	return 0;
}
