/**
 * 为了保证查找的速度，这里使用平衡二叉树
 **/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct avl_node{
    long key;
    long height;
    struct avl_node *left;
    struct avl_node *right;
} avl_node, *avl_node_ptr;

int get_height(avl_node_ptr node){
    return ((node == NULL) ? 0 : node->height);
}

int max(int a, int b){
    return ((a < b) ? b : a);
}

int get_bf(avl_node_ptr node){
    if (node == NULL)
        return 0;
    return get_height(node->left) - get_height(node->right);
}

avl_node_ptr LL_right_rotate(avl_node_ptr node){
    avl_node_ptr t = node->left;
    node->left = t->right;
    t->right = node;
    node->height = max(get_height(node->left), get_height(node->right)) + 1;
    t->height = max(get_height(t->left), get_height(t->right)) + 1;
    return t;
}

avl_node_ptr RR_left_rotate(avl_node_ptr node){
    avl_node_ptr t = node->right;
    node->right = t->left;
    t->left = node;
    node->height = max(get_height(node->left), get_height(node->right)) + 1;
    t->height = max(get_height(t->left), get_height(t->right)) + 1;
    return t;
}

avl_node_ptr LR_left_right_rotate(avl_node_ptr node){
    node->left = RR_left_rotate(node->left);
    return LL_right_rotate(node);
}

avl_node_ptr RL_right_left_rotate(avl_node_ptr node){
    node->right = RR_left_rotate(node->right);
    return LL_right_rotate(node);
}

avl_node_ptr re_balance(avl_node_ptr node){
    if (node == NULL)
        return node;
    int bf = get_bf(node);
    int bf_r = get_bf(node->right);
    int bf_l = get_bf(node->left);

    if (bf > 1 && bf_l > 0) //LL
        return LL_right_rotate(node);
    if (bf > 1 && bf_l < 0) //LR
        return LR_left_right_rotate(node);
    if (bf < -1 && bf_r > 0) //RL
        return RL_right_left_rotate(node);
    if (bf < -1 && bf_r < 0) //RR
        return RR_left_rotate(node);
    //返回未失衡的指针
    return node;
}

avl_node_ptr is_in_or_not(avl_node_ptr node, long k){
    if (!node || node->key == k)
        return node;
    avl_node_ptr temp = node;
    while (temp != NULL) {
        if (k < temp->key){
            temp = temp->left;
        }
        else if (k > temp->key){
            temp = temp->right;
        }
        else{
            return temp;
        }
    }

    return temp;
}

avl_node_ptr avl_insert(avl_node_ptr node, long k){
    if (!node){
        node = new avl_node;
        node->key = k;
        node->height = 1;
        node->left = NULL;
        node->right = NULL;
        return node;
    }
    if (k < node->key)
        node->left = avl_insert(node->left, k);
    else if (k > node->key)
        node->right = avl_insert(node->right, k);
    else{
        cout << "can't insert a key that already esixt!" << endl;
        return node;
    }
    node->height = max(get_height(node->left), get_height(node->right)) + 1;
    node = re_balance(node);
    return node;
}

int main(void){
    avl_node_ptr root = NULL;
    size_t count1, count2;
    vector<long> a;
    cin >> count1;
    long temp;
    for (int i = 0; i < count1 * 2; i++){
        cin >> temp;
        root = avl_insert(root, temp);
    }
    cin >> count2;
    for (int i = 0; i < count2; i++){
        cin >> temp;
        if (is_in_or_not(root, temp) == NULL){
            a.push_back(temp);
        }
    }

    sort(a.begin(), a.end());
    cout << a.size() << endl;
    for (int i = 0; i < a.size() - 1; i++){
        cout << a[i] << " ";
    }
    cout << a[a.size() - 1];
    return 0;
}
