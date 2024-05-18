#include<stdio.h>  
#include<string.h>  
#include<stdlib.h>  
  
// 函数：wcexe  
// 功能：读取文件并统计字符数和/或单词数  
// 参数：filename - 文件名  
void wcexe(char *filename, int x){  
    FILE *fp;  
    char buffer[1000]; // 用于存储从文件中读取的每一行的内容  
    char c;           // 用于存储当前字符  
    int bufferlen;    // 当前行的长度  
    int isLastBlank = 0; // 上一个字符是否是空格的标志  
    int charCount=0;     // 字符数  
    int wordCount=0;     // 单词数  
    int i;  
  
    // 尝试打开文件  
    if((fp=fopen(filename,"rb"))==NULL){  
        printf("文件不能打开\n");  
        exit(0);  
    }  
  
    // 逐行读取文件  
    while(fgets(buffer,1000,fp)!=NULL){  
        bufferlen=strlen(buffer);  
        for(i=0;i<bufferlen;i++){  
            c=buffer[i];  
  
            // 如果当前字符是空格或制表符  
            if(c==' ' || c=='\t'){  
                // 如果上一个字符不是空格，则增加单词数  
                if(isLastBlank==0){  
                    wordCount++;  
                }  
                isLastBlank=1; // 设置上一个字符为空格  
  
            // 如果当前字符不是换行符或回车符  
            }else if(c!='\n'&&c!='\r'){  
                charCount++; // 增加字符数  
                isLastBlank=0; // 设置上一个字符不是空格  
            }  
        }  
  
        // 如果行尾不是空格，则增加一个单词数（考虑到文件结束可能没有空格）  
        if(isLastBlank==0)  
            wordCount++;  
  
        isLastBlank=1;  
    }  
  
    fclose(fp); // 关闭文件  
  
    // 根据 x 的值输出字符数或单词数  
    if(x==1){  
        printf("字符数：%d\n",charCount);  
    }else if(x==2){ 
        printf("单词数：%d\n",wordCount);  
    }  
}  
  
int main(){  
    char a[3]; // 存储两个字符和一个终止符 '\0'  
    int x=0;  
    scanf("%s", a); // 使用 %2s 防止缓冲区溢出，并读取两个字符  
  
    // 根据输入设置 x 的值  
    if(a[1]=='c'){  
        x=1;  
    }else if(a[1]=='w'){  
        x=2; // 修正逻辑，设置 x 为 2  
    }  
  
    char filename[]="123.txt";  
    wcexe(filename,x);  
    return 0;  
}
