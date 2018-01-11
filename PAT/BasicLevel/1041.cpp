/**
 * 平衡二叉树　考试座位号
 **/

#include <iostream>
#include <string>
using namespace std;

typedef struct node{
    string examinee_id;
    int exam_num;
    int try_num;
} Data;

typedef struct avlnode{
    int hight;
    Data d;
    struct avlnode *left;
    struct avlnode *right;
} avl_node, *avl_node_ptr;

int get_hight(avl_node_ptr node){
    if (!node)
        return 0;
    return node->hight;
}

int max(int a, int b){
    return a < b ? b : a;
}

int get_bf(avl_node_ptr node){
    if (!node)
        return 0;
    return get_hight(node->left) - get_hight(node->right);
}

avl_node_ptr LL_right_rotate(avl_node_ptr root){
    avl_node_ptr new_root = root->left;
    root->left = new_root->right;
    new_root->right = root;
    new_root->hight = max(get_hight(new_root->left), get_hight(new_root->right)) + 1;
    root->hight = max(get_hight(root->left), get_hight(root->right)) + 1;
    return new_root;
}

avl_node_ptr RR_left_rotate(avl_node_ptr root){
    avl_node_ptr new_root = root->right;
    root->right = new_root->left;
    new_root->left = root;
    new_root->hight = max(get_hight(new_root->left), get_hight(new_root->right)) + 1;
    root->hight = max(get_hight(root->left), get_hight(root->right)) + 1;
    return new_root;
}

avl_node_ptr RL_right_left_rotate(avl_node_ptr root){
    root->right = LL_right_rotate(root->right);
    return RR_left_rotate(root);
}

avl_node_ptr LR_left_right_rotate(avl_node_ptr root){
    root->left = RR_left_rotate(root->left);
    return LL_right_rotate(root);
}

avl_node_ptr re_balance(avl_node_ptr node){
    if (!node)
        return node;
    int bf = get_bf(node);
    int bf_l = get_bf(node->left);
    int bf_r = get_bf(node->right);
    if (bf > 1 && bf_l > 0)
        node = LL_right_rotate(node);
    if (bf > 1 && bf_l < 0)
        node = LR_left_right_rotate(node);
    if (bf < -1 && bf_r < 0)
        node = RR_left_rotate(node);
    if (bf < -1 && bf_r > 0)
        node = RL_right_left_rotate(node);
    return node;
}

avl_node_ptr avl_insert(avl_node_ptr root, int try_num, int exam_num, string examinee_id){
    if (!root){
        Data d;
        d.try_num = try_num;
        d.exam_num = exam_num;
        d.examinee_id = examinee_id;
        root = new avl_node;
        root->d = d;
        root->hight = 1;
        root->left = NULL;
        root->right = NULL;
    }

    if (try_num < root->d.try_num)
        root->left = avl_insert(root->left, try_num, exam_num, examinee_id);
    else if (try_num > root->d.try_num)
        root->right = avl_insert(root->right, try_num, exam_num, examinee_id);
    else
        return root;

    root->hight = max(get_hight(root->left), get_hight(root->right)) + 1;
    root = re_balance(root);
    return root;
}

avl_node_ptr avl_search(avl_node_ptr root, int try_num){
    if (!root || try_num == root->d.try_num)
        return root;
    while (root && root->d.try_num != try_num){
        if (try_num < root->d.try_num)
            root = root->left;
        else
            root = root->right;
    }
    return root;
}

int main(void)
{
    avl_node_ptr root = NULL;
    int count;
    cin >> count;
    string s;
    int a, b;
    for (int i = 0; i < count; i++){
        cin >> s >> a >> b;
        root = avl_insert(root, a, b, s);
    }
    int count2;
    int temp;
    cin >> count2;
    for (int i = 0; i < count2; i++){
        cin >> temp;
        avl_node_ptr t = avl_search(root, temp);
        cout << t->d.examinee_id << " " << t->d.exam_num << endl;
    }
    return 0;
}