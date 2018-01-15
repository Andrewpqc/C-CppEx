#include <iostream>
#define RED true
#define BLACK false
using namespace std;

typedef struct rbt_node{
    int key;
    bool color;//red is true,black is false
    struct rbt_node* left;
    struct rbt_node* right;
    struct rbt_node* parent;
    rbt_node(k):key(k),color(BLACK),left(NULL),right(NULL),parent(NULL){};
    rbt_node():color(BLACK),left(NULL),right(NULL),parent(NULL){};
}rbt_node,*rbt_node_ptr;

class RBTree{
    private:
        rbt_node_ptr root;
        rbt_node_ptr nil;
    protected:
        void rbt_LL_right_rotate(rbt_node_ptr node);
        void rbt_RR_right_rotate(rbt_node_ptr node);
        void rbt_insert_fixup(rbt_node_ptr node);
        void rbt_delete_fixup(rbt_node_ptr node);
        void rbt_destory(rbt_node_ptr node);
    public:
        RBTree();
        ~RBTree();
        rbt_node_ptr rbt_search(int k);
        bool rbt_insert(int k);
        bool rbt_delete(int k);
}

void RBTree::rbt_destory(rbt_node_ptr node){
    if(node!=nil){
        this->rbt_destory(node->left);
        this->rbt_destory(node->right);
        delete node;
    }
}

RBTree::RBTree(){
    //nil节点的k无关紧要
    nil=new rbt_node();
    nil->left=nil;
    nil->right=nil;
    nil->parent=nil;
    root=nil;
}

//递归式的完全释放树
RBTree::~RBTree(){
    this->rbt_destory(this->root);
    delete nil;
}

void RBTree::rbt_LL_right_rotate(rbt_node_ptr node){
    rbt_node_ptr temp=node->left;
    if((node->left=temp->right)
        temp->parent=   
}