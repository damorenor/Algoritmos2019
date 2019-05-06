#include <stdio.h>
#include <stdlib.h>

int getFileSize(){
	int size;
	FILE *f;
	f = fopen("selfOutput.c","r");
	if (f== NULL)
	{
		perror("error");
		exit(-1);
	}

	int s = fseek(f,0,SEEK_END);
	if(s==-1){
		perror("error en el seek");
		exit(-1);
	}

	size = (int) ftell(f);
	fclose(f);
	return size;
}


int main(int argc, char const *argv[])
{
	int fileSize = getFileSize();
	char newProgram [fileSize];
	int r;
	FILE *f;
	FILE *p;

	f = fopen("selfOutput.c","r");
	if (f== NULL)
	{	
		perror("error");
		exit(-1);
	}

	p = fopen("newSelfOutput.c","w+");
	if (p== NULL)
	{	
		perror("error");
		exit(-1);
	}

	for (int i = 0; i < fileSize; ++i)
	{
		r = fread(&newProgram[i],sizeof(char),1,f);
		if(r==0){
			perror("error en el seek");
			exit(-1);
		}

		r = fwrite(&newProgram[i],sizeof(char),1,p);
		if(r==0){
			perror("error en el seek");
			exit(-1);
		}
		printf("%c", newProgram[i]);
	}
	fclose(f);
	fclose(p);
	return 0;
}