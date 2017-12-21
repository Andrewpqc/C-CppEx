#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 20
struct Book{
    char* bookname;
    char* authorname;
    float price;
};
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

int main (void){
    struct Book book1;
    char temp[SIZE];
    my_gets(temp,SIZE);
    
    //下面这样操作的话，bookname就刚好占用它所需要的空间，不会造成空间浪费
    book1.bookname=(char*)malloc((strlen(temp)+1)*sizeof(char));
    strcpy(book1.bookname,temp);

    my_gets(temp,SIZE);
    book1.authorname=(char*)malloc((strlen(temp)+1)*sizeof(char));
    strcpy(book1.authorname,temp);
    book1.price=1.0;
    puts(book1.bookname);
    puts(book1.authorname);

    return 0;
}