#include <stdlib.h>
#include <stdio.h>
typedef int ElemType;
struct BinaryTree{
    ElemType e;
    struct BinaryTree *left;
    struct BinaryTree *right;
};


//创建二叉树
struct BinaryTree* createTree(BinaryTree*btree){
    int input;
    printf("输入数字\n");
    scanf("%d",&input);
    if(input==0){
        btree=NULL;
        return btree;
    }
    btree=(BinaryTree*)malloc(sizeof(BinaryTree));
    btree->e=input;
    btree->left=createTree(btree->left);
    btree->right=createTree(btree->right);
    return btree;
}


//先序遍历
void VisitTree1(BinaryTree *btree){
    if(btree!=NULL){
        printf("%d ",btree->e);
        VisitTree1(btree->left);
        VisitTree1(btree->right);
    };
}

//中序遍历
void VisitTree2(BinaryTree *btree){
    if(btree!=NULL){
        VisitTree2(btree->left);
        printf("%d ",btree->e);
        VisitTree2(btree->right);
    }
}

//后序遍历
void VisitTree3(BinaryTree *btree){
    if(btree!=NULL){
        VisitTree3(btree->left);
        VisitTree3(btree->right);
        printf("%d ",btree->e);
    }
}


//主函数
int main(void){
    BinaryTree *btree;
    btree=createTree(btree);
    VisitTree1(btree);
    printf("\n");
    VisitTree2(btree);
    printf("\n");
    VisitTree3(btree);
    printf("\n");
    return 0;
}
