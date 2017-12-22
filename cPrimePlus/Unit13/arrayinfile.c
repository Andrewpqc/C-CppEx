/**
 * 将数据存储到文件中，然后从中读取指定的数据
 */ 

#include <stdio.h>
#include <stdlib.h>
#define ARSIZE 1000
int main (void){
    double array[ARSIZE];
    int i;
    long pos;
    double value;
    const char * filename="myarray.dat";
    
    for(int j=1;j<=ARSIZE;j++)
        array[j]=(double)j;
    
    FILE* fp;
    if((fp=fopen(filename,"wb"))==NULL){
        fprintf(stderr,"Open file %s error!",filename);
        exit(EXIT_FAILURE);
    }

    fwrite(array,sizeof(double),ARSIZE,fp);//将数组写入文件
    fclose(fp);

    fprintf(stdout,"which number do you want?(0-%d)(out of range to quit!):",ARSIZE-1);
    while(scanf("%d",&i)==1 && i>=0 && i<ARSIZE){
        if((fp=fopen(filename,"rb"))==NULL){
            fprintf(stderr,"Open file %s error!",filename);
            exit(EXIT_FAILURE);
        }

        pos=(long)i*sizeof(double);
        fseek(fp,pos,SEEK_SET);
        fread(&value,sizeof(double),1,fp);
        fprintf(stdout,"the vaule there is %f \n",value);
        fprintf(stdout,"which number do you want?(0-%d)(out of range to quit!):",ARSIZE-1);
    }

    return 0;
}