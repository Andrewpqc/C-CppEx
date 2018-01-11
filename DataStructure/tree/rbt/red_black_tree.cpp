/**
 * 红黑树实现
 **/
#include <iostream>
using namespace std;
typedef struct rbt_node
{
    int key;
    bool color; //true为红，false为黑
    struct rbt_node *left;
    struct rbt_node *right;
    struct rbt_node *parent;
} rbt_node, *rbt_node_ptr;

//左旋
static void rbt_LL_right_rotate(rbt_node_ptr &root, rbt_node_ptr node){
    rbt_node_ptr temp = node->left; //获取node的左节点

    //将temp的右子树挂到node的左支上，注意处理父子节点
    node->left = temp->right;
    if (temp->right != NULL)
        temp->right->parent = node;

    //处理temp的父指针的指向
    temp->parent = node->parent;

    //如果node的父节点为空，直接将temp挂到root上
    if (node->parent == NULL)
        root = temp;
    else{
        if (node->parent->left == node) //node原来挂在其父节点的左枝上
            node->parent->left = temp;
        else //node原来挂在其父节点的右支上
            node->parent->right = temp;
    }
    temp->right = node;
    node->parent = temp;
}

//右旋
static void rbt_RR_left_rotate(rbt_node_ptr &root, rbt_node_ptr node){
    rbt_node_ptr temp = node->right;
    node->right = temp->left;
    if (temp->left != NULL)
        temp->left->parent = node;

    temp->parent = node->parent;
    if (node->parent == NULL)
        root = temp;
    else{
        if (node->parent->left == node)
            node->parent->left = temp;
        else
            node->parent->right = temp;
    }
    temp->left = node;
    node->parent = temp;
}

//insert_node插入到树root中后的调整函数
static void rbt_insert_fixup(rbt_node_ptr &root, rbt_node_ptr insert_node){
    rbt_node_ptr parent, gparent;

    //父节点存在，并且父节点为红色
    while ((parent = insert_node->parent) && parent->color == true){                             //insert_node的父节点不空且颜色为红色
        gparent = parent->parent; //insert_node的祖父节点

        //父节点是祖父节点的左孩子
        if (parent == gparent->left){

            rbt_node_ptr uncle = gparent->right;
            if (uncle && uncle->color == true){ //叔节点存在，并且颜色为红色 case1
                uncle->color = false;
                parent->color = false;
                gparent->color = true;
                insert_node = gparent;
                continue;
            }

            if (parent->right == insert_node){ //uncle节点为黑色，并且当前节点位于其父节点的右支上 case2
                rbt_node_ptr tmp;
                rbt_RR_left_rotate(root, parent);
                tmp = parent;
                parent = insert_node;
                insert_node = tmp;
            }

            //uncle节点为黑色，并且当前节点位于其父节点的左支上case3
            parent->color = false;
            gparent->color = true;
            rbt_LL_right_rotate(root, gparent);
        }
        else{
            //父节点是祖父节点的右孩子
            rbt_node_ptr uncle = gparent->left;
            if (uncle && uncle->color == true){ //叔节点存在，并且颜色为红色 case1
                uncle->color = false;
                parent->color = false;
                gparent->color = true;
                insert_node = gparent;
                continue;
            }

            if (parent->right == insert_node){ //uncle节点为黑色，并且当前节点位于其父节点的右支上 case2
                rbt_node_ptr tmp;
                rbt_LL_right_rotate(root, parent);
                tmp = parent;
                parent = insert_node;
                insert_node = tmp;
            }

            //uncle节点为黑色，并且当前节点位于其父节点的左支上case3
            parent->color = false;
            gparent->color = true;
            rbt_RR_left_rotate(root, gparent);
        }
    }
    root->color = false;
}

//delete_node从树root中删除后的调整函数
static void rbt_delete_fixup(rbt_node_ptr &root, rbt_node_ptr delete_node)
{
}

bool rbt_insert(rbt_node_ptr &root, int k){
    //向红黑树中插入一个节点
    rbt_node_ptr current_node = NULL, insert_node = NULL, temp = NULL;
    current_node = root;
    while (current_node != NULL){
        temp = current_node;
        if (k < current_node->key)
            current_node = current_node->left;
        else if (k > current_node->key)
            current_node = current_node->right;
        else{ //插入已经存在的键
            cout << "键已经存在" << endl;
            return false;
        }
    }
    //while循环退出之后，说明找到了k所对应节点要插入的地方，此时current_node为空，
    //temp则指向current_node的父节点,此时k应该插入为temp节点的子节点
    insert_node = new rbt_node;
    if (!insert_node){
        cout << "分配内存失败!" << endl;
        return false;
    }
    insert_node->key = k;
    insert_node->color = true; //新插入的节点设置为红色
    insert_node->left = NULL;
    insert_node->right = NULL;
    insert_node->parent = NULL;

    if (temp == NULL){
        //temp仍然为初始化时的NULL,则说明此时树为空树，根本就没有进入上面的while循环
        root = insert_node;
    }
    else{                      //非空树
        if (k < temp->key) //插入为temp节点的左孩子
            temp->left = insert_node;
        else //插入为temp节点的右孩子
            temp->right = insert_node;
    }
    insert_node->parent = temp;

    //调整红黑树，保持性质
    rbt_insert_fixup(root, insert_node);
    return true;
}

//删除关键字为k的节点
bool rbt_delete(rbt_node_ptr &root, int k)
{
}

void preorder(rbt_node_ptr root){
    if (root){
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

int main(void){
    rbt_node_ptr root = NULL;
    int a[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
        rbt_insert(root, a[i]);

    // preorder(root);

    return 0;
}