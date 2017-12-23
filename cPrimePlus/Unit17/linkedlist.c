/**
 * 一个傻逼链表
 **/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BOOKNAME_SIZE 30

struct Book{
    char bookname[BOOKNAME_SIZE];
    float price;
    struct Book *next;
};

char *my_gets(char *a, int size);
void show(struct Book *p);
int main(void){
    struct Book *head, *prev, *current;
    head = (struct Book *)malloc(sizeof(struct Book));
    head->next = NULL;
    prev = head;
    char input[BOOKNAME_SIZE];

    printf("Enter the book name:");
    while (my_gets(input, BOOKNAME_SIZE) != NULL && input[0] != '\0'){
        current = (struct Book *)malloc(sizeof(struct Book));
        strncpy(current->bookname, input, BOOKNAME_SIZE);
        printf("Enter the price:");
        scanf("%f", &current->price);
        while (getchar() != '\n')
            continue;
        current->next = NULL;
        prev->next = current;
        prev = prev->next;
        printf("Enter the next book name(empty line to quit!):");
    }

    for (struct Book *p = head->next; p != NULL; p = p->next)
        show(p);

    return 0;
}

void show(struct Book *pt){
    printf("%s %f\n", pt->bookname, pt->price);
}

char *my_gets(char *a, int size){
    char *ret_val;
    char *temp;
    ret_val = fgets(a, size, stdin);
    if (ret_val){
        temp = strchr(a, '\n');
        if (temp){
            *temp = '\0';
        }
        else{
            while (getchar() != '\n')
                continue;
        }
    }
    return ret_val;
}
