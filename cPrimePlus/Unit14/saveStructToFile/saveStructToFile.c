#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "saveStructToFile.h"
#define MAXBOOKNUM 1000

int main (void){
    const size_t size=sizeof(struct Book);
    FILE* fp;
    char choice;
    size_t count=0;
    struct Book books[MAXBOOKNUM];
    if((fp=fopen("a.dat","a+b"))==NULL){
        fprintf(stderr,"Open a.dat error!");
        exit(EXIT_FAILURE);
    }
    
    //打印当前存储的数据
    // while(fread(&books[count],size,1,fp)==1){
    //     printf("%20s %20s %.2f\n",books[count].bookname,books[count].authorname,books[count].price);
    //     ++count;
    // }
    printf("current data in the file:\n");
    count=view_data(books,size,fp);
    printf("there are %zd entities in the db,you can add %zd books!\n",count,1000-count);
    choice=ui();        
    switch(choice){
        case 'a':search_data();
            break;
        case 'b':remove_data();
            break;
        case 'c':modify_data();
            break;
        case 'd':add_data();
            break;
        case 'e':view_data(books,size,fp);
            break;
        case 'f':exit(EXIT_SUCCESS);
            break;
        default:printf("error happened!");
            break;
    }

    fclose(fp);
    return 0;
}





