#include<stdio.h>  
#include<string.h>  
#include<stdlib.h>  
  
// ������wcexe  
// ���ܣ���ȡ�ļ���ͳ���ַ�����/�򵥴���  
// ������filename - �ļ���  
void wcexe(char *filename, int x){  
    FILE *fp;  
    char buffer[1000]; // ���ڴ洢���ļ��ж�ȡ��ÿһ�е�����  
    char c;           // ���ڴ洢��ǰ�ַ�  
    int bufferlen;    // ��ǰ�еĳ���  
    int isLastBlank = 0; // ��һ���ַ��Ƿ��ǿո�ı�־  
    int charCount=0;     // �ַ���  
    int wordCount=0;     // ������  
    int i;  
  
    // ���Դ��ļ�  
    if((fp=fopen(filename,"rb"))==NULL){  
        printf("�ļ����ܴ�\n");  
        exit(0);  
    }  
  
    // ���ж�ȡ�ļ�  
    while(fgets(buffer,1000,fp)!=NULL){  
        bufferlen=strlen(buffer);  
        for(i=0;i<bufferlen;i++){  
            c=buffer[i];  
  
            // �����ǰ�ַ��ǿո���Ʊ��  
            if(c==' ' || c=='\t'){  
                // �����һ���ַ����ǿո������ӵ�����  
                if(isLastBlank==0){  
                    wordCount++;  
                }  
                isLastBlank=1; // ������һ���ַ�Ϊ�ո�  
  
            // �����ǰ�ַ����ǻ��з���س���  
            }else if(c!='\n'&&c!='\r'){  
                charCount++; // �����ַ���  
                isLastBlank=0; // ������һ���ַ����ǿո�  
            }  
        }  
  
        // �����β���ǿո�������һ�������������ǵ��ļ���������û�пո�  
        if(isLastBlank==0)  
            wordCount++;  
  
        isLastBlank=1;  
    }  
  
    fclose(fp); // �ر��ļ�  
  
    // ���� x ��ֵ����ַ����򵥴���  
    if(x==1){  
        printf("�ַ�����%d\n",charCount);  
    }else if(x==2){ 
        printf("��������%d\n",wordCount);  
    }  
}  
  
int main(){  
    char a[3]; // �洢�����ַ���һ����ֹ�� '\0'  
    int x=0;  
    scanf("%s", a); // ʹ�� %2s ��ֹ���������������ȡ�����ַ�  
  
    // ������������ x ��ֵ  
    if(a[1]=='c'){  
        x=1;  
    }else if(a[1]=='w'){  
        x=2; // �����߼������� x Ϊ 2  
    }  
  
    char filename[]="123.txt";  
    wcexe(filename,x);  
    return 0;  
}
