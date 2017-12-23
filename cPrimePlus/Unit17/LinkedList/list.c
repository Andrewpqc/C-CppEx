#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

NodePtr create_list(){
    NodePtr head=NULL;
    return head;
}

size_t  get_size(NodePtr head){
    size_t count=0;
    NodePtr temp=head;
    temp=temp->next;
    while(temp!=NULL){
        ++count;
        temp=temp->next;
    } 
    return count;
}

bool is_empty(NodePtr head){
    if(head==NULL||head->next==NULL)
        return true;
    else
        return false;
}

bool add_node_at_rear(NodePtr head,Item item){
    NodePtr temp=head;
    while(temp!=NULL)
        temp=temp->next;
    NodePtr temp2;
    if((temp2=(NodePtr)malloc(sizeof(Node)))==NULL){
        fprintf(stderr," malloc error!");
        return false;
    }
    temp2->next=NULL;
    temp2->item=item;
    temp->next=temp2;
    return true;
}

bool add_node_at_head(NodePtr head,Item item){
    NodePtr temp=head;
    NodePtr temp2;
    if((temp2=(NodePtr)malloc(sizeof(Node)))==NULL){
        fprintf(stderr," malloc error!");
        return false;
    }
    temp2->item=item;
    if(temp==NULL){
        temp->next=temp2;
        temp2->next=NULL;
        return true;
    }
    NodePtr temp3=temp->next;
    temp->next=temp2;
    temp2->next=temp3->next;
    free(temp3);
    return true;
}

bool del_node_at_rear(NodePtr head){
    if(head==NULL||head->next==NULL){
        fprintf(stderr,"list is empty now!");
        return false;
    }
    NodePtr temp1=head;
    NodePtr temp2=head->next;
    while(temp2->next!=NULL){
        temp1=temp1->next;
        temp2=temp2->next;
    }
    temp1->next=NULL;
    free(temp2);
    return true;
}

bool del_node_at_head(NodePtr head){
    if(head==NULL||head->next==NULL){
        fprintf(stderr,"list is empty now!");
        return false;
    }
    NodePtr temp=head->next;
    NodePtr temp2=temp->next;
    head->next=temp2;
    free(temp);
    return true;
}

Item get_item_at_rear(NodePtr head){
    if(head==NULL||head->next==NULL){
        fprintf(stderr,"list is empty now!");
        exit(EXIT_FAILURE);
    }
    NodePtr temp=head;
    while(temp->next==NULL)
        temp=temp->next;
    return temp->item;
}

Item get_item_at_head(NodePtr head){
    if(head==NULL||head->next==NULL){
        fprintf(stderr,"list is empty now!");
        exit(EXIT_FAILURE);
    }
    NodePtr temp=head->next;
    return temp->item;
}

void show(NodePtr head){
    NodePtr temp=head;
    temp=temp->next;
    while(temp->next!=NULL){
        fprintf(stdout,"%s %d\n",temp->item.name,temp->item.age);
        temp=temp->next;
    }
}