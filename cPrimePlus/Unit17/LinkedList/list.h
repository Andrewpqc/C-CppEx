#ifndef LIST_H
#define LIST_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NAMESIZE 20
//数据项
typedef struct Item{
    char name[NAMESIZE];
    int age;
}Item;

typedef struct Node{
    Item item;
    struct Node*  next;
}Node,* NodePtr;

//创建一个链表
NodePtr create_list();

//判断链表是否为空
bool is_empty(NodePtr);

//获取链表当前大小
size_t  get_size(NodePtr);

//在尾部增加元素
bool add_node_at_rear(NodePtr,Item);

//在头部增加元素
bool add_node_at_head(NodePtr,Item);

//删除尾部的元素
bool del_node_at_rear(NodePtr);

//删除头部元素
bool del_node_at_head(NodePtr); 

//获取尾部的元素中的Item对象
Item get_item_at_rear(NodePtr);

//获取头部的元素中的Item对象
Item get_item_at_head(NodePtr);

//展示链表信息
void show(NodePtr);


#endif