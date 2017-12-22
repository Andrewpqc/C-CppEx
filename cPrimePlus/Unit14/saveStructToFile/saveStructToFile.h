/**
 * 函数库
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book{
    char* bookname;
    char* authorname;
    float price;
};

char ui(){
    char choice;
    puts("what kind of operators do you want?");
    puts("___________________________________________");
    puts("______a.search data    b.remove data_______");
    puts("______                             ________");
    puts("______c.modify data    d.add data   _______");
    puts("______                              _______");
    puts("______e.view data       f.exit      _______");
    puts("--------------------------------------------");
    printf("choice:_\b");
    choice=getchar();
    //处理多余的输入
    while(getchar()!='\n')
        continue;
    while(strchr("abcdef",choice)==NULL){
        printf("that is not a good choice,please give the right choice:_\b");
        choice=getchar();
        while(getchar()!='\n')
            continue;
    }
    return choice;
}

size_t view_data(struct Book* books,size_t size,FILE* fp){
    size_t count=0;
    while(fread(&books[count],size,1,fp)==1){
        printf("%20s %20s %.2f\n",books[count].bookname,books[count].authorname,books[count].price);
        ++count;
    }
    return count;
}


void add_data(){

}


/**
 * 文件复制函数
 * @param  fSource       要复制的原文件
 * @param  offsetSource  原文件的位置偏移（相对文件开头），也就是从哪里开始复制
 * @param  len           要复制的内容长度，小于0表示复制offsetSource后边的所有内容
 * @param  fTarget       目标文件，也就是将文件复制到哪里
 * @param  offsetTarget  目标文件的位置偏移，也就是复制到目标文件的什么位置
 * @return  成功复制的字节数
**/
long fcopy(FILE *fSource, long offsetSource, long len, FILE *fTarget, long offsetTarget){
    int bufferLen = 1024*4;  // 缓冲区长度
    char *buffer = (char*)malloc(bufferLen);  // 开辟缓存
    int readCount;  // 每次调用fread()读取的字节数
    long nBytes = 0;  //总共复制了多少个字节
    int n = 0;  //需要调用多少次fread()函数
    int i;  //循环控制变量
    fseek(fSource, offsetSource, SEEK_SET);
    fseek(fTarget, offsetTarget, SEEK_SET);
    if(len<0){  //复制所有内容
        while( (readCount=fread(buffer, 1, bufferLen, fSource)) > 0 ){
            nBytes += readCount;
            fwrite(buffer, readCount, 1, fTarget);
        }
    }else{  //复制len个字节的内容
        n = (int)ceil((double)((double)len/bufferLen));
        for(i=1; i<=n; i++){
            if(len-nBytes < bufferLen){ bufferLen = len-nBytes; }
            readCount = fread(buffer, 1, bufferLen, fSource);
            fwrite(buffer, readCount, 1, fTarget);
            nBytes += readCount;
        }
    }
    fflush(fTarget);
    free(buffer);
    return nBytes;
}


/**
 * 向文件中插入内容
 * @param  fp      要插入内容的文件
 * @param  buffer  缓冲区，也就是要插入的内容
 * @param  offset  偏移量（相对文件开头），也就是从哪里开始插入
 * @param  len     要插入的内容长度
 * @return  成功插入的字节数
**/
int finsert(FILE *fp, long offset, void *buffer, int len){
    long fileSize = fsize(fp);
    FILE *fpTemp;  //临时文件
    if(offset>fileSize || offset<0 || len<0){  //插入错误
        return -1;
    }
    if(offset == fileSize){  //在文件末尾插入
        fseek(fp, offset, SEEK_SET);
        if(!fwrite(buffer, len, 1, fp)){
            return -1;
        }
    }
    if(offset < fileSize){  //从开头或者中间位置插入
        fpTemp = tmpfile();
        fcopy(fp, 0, offset, fpTemp, 0);
        fwrite(buffer, len, 1, fpTemp);
        fcopy(fp, offset, -1, fpTemp, offset+len);
        freopen(FILENAME, "wb+", fp );
        fcopy(fpTemp, 0, -1, fp, 0);
        fclose(fpTemp);
    }
   
    return 0;
}

int fdelete(FILE *fp, long offset, int len){
    long fileSize = getFileSize(fp);
    FILE *fpTemp;
    if(offset>fileSize || offset<0 || len<0){  //错误
        return -1;
    }
    fpTemp = tmpfile();
    fcopy(fp, 0, offset, fpTemp, 0);  //将前offset字节的数据复制到临时文件
    fcopy(fp, offset+len, -1, fpTemp, offset);  //将offset+len之后的所有内容都复制到临时文件
    freopen(FILENAME, "wb+", fp );  //重新打开文件
    fcopy(fpTemp, 0, -1, fp, 0);
    fclose(fpTemp);
    return 0;
}


char*  my_gets(char* a,int size){
    char* ret_val;
    char*temp;
    ret_val=fgets(a,size,stdin);
    if(ret_val){
        temp=strchr(a,'\n');
        if(temp){
            *temp='\0';
        }else{
            while(getchar()!='\n')
                continue;
        }
    }
    return ret_val;
}

