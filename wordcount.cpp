#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void wcexe(char *filename,int x){
	FILE *fp;
	char buffer[1000];
	char c;
	int bufferlen;
	int isLastBlank = 0; // �ϸ��ַ��Ƿ��ǿո�(1��ʾ��  0��ʾ����)
	int charCount=0;
	int wordCount=0;
	int lineCount=0;
	int i;
 
	if((fp=fopen(filename,"rb"))==NULL){
		printf("�ļ����ܴ�\n");
		exit(0);
	}
	while(fgets(buffer,1000,fp)!=NULL){
		bufferlen=strlen(buffer);
		for(i=0;i<bufferlen;i++){
			c=buffer[i];
			if(c==' ' || c=='\t'){
				if(isLastBlank==0){
					wordCount++;
				}
				isLastBlank=1;
			}else if(c!='\n'&&c!='\r'){
				charCount++;
				isLastBlank=0;
			}
 
		}
		if(isLastBlank==0)
			wordCount++;
		isLastBlank=1;
		lineCount++;
	}
	fclose(fp);
	if(x==1){
		printf("�ַ�����%d\n",charCount);
	}else{
		printf("��������%d\n",wordCount);
	}
}
int main(){
	char a[2];
	int x=0;
	scanf("%s",&a);
	if(a[1]=='c'){
		x=1;
	}else if(a[1]=='w'){
		x=2;
	}
	char filename[]="123.txt";
	wcexe(filename,x);
	return 0;
}
