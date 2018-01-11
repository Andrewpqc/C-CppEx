/**
 * 统计同成绩学生人数 平衡二叉树解决
 **/
#include <iostream>
using namespace std;

typedef struct date_node{
    int score;
    int count;
} Data;

typedef struct avl_node{
    Data data;
    int height;

    struct avl_node *left;
    struct avl_node *right;
} avl_node, *avl_node_ptr;

int get_hight(avl_node_ptr node){
    if (!node)
        return 0;
    return node->height;
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
    new_root->height = max(get_hight(new_root->left), get_hight(new_root->right)) + 1;
    root->height = max(get_hight(root->left), get_hight(root->right)) + 1;
    return new_root;
}

avl_node_ptr RR_left_rotate(avl_node_ptr root){
    avl_node_ptr new_root = root->right;
    root->right = new_root->left;
    new_root->left = root;
    new_root->height = max(get_hight(new_root->left), get_hight(new_root->right)) + 1;
    root->height = max(get_hight(root->left), get_hight(root->right)) + 1;
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
    int bf_left = get_bf(node->left);
    int bf_right = get_bf(node->right);
    if (bf > 1 && bf_left > 0) //LL
        node = LL_right_rotate(node);
    if (bf > 1 && bf_left < 0) //LR
        node = LR_left_right_rotate(node);
    if (bf < -1 && bf_right > 0) //RL
        node = RL_right_left_rotate(node);
    if (bf < -1 && bf_right < 0) //RR
        node = RR_left_rotate(node);
    return node;
}

avl_node_ptr avl_insert(avl_node_ptr root, int score){
    if (!root){
        Data d;
        d.score = score;
        d.count = 1;
        root = new avl_node;
        root->height = 1;
        root->data = d;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    if (score < root->data.score)
        root->left = avl_insert(root->left, score);
    else if (score > root->data.score)
        root->right = avl_insert(root->right, score);
    else
        root->data.count++;
    root->height = max(get_hight(root->left), get_hight(root->right)) + 1;
    root = re_balance(root);
    return root;
}

avl_node_ptr avl_search(avl_node_ptr root, int score){
    if (root == NULL || score == root->data.score)
        return root;
    while (root && score != root->data.score){
        if (score < root->data.score){
            root = root->left;
        }
        else if (score > root->data.score){
            root = root->right;
        }
    }
    return root;
}

int main(void){
    avl_node_ptr root = NULL;
    int score_count;
    int search_count;
    int temp_score;
    int temp_search;
    cin >> score_count;
    for (int i = 0; i < score_count; i++){
        cin >> temp_score;
        root = avl_insert(root, temp_score);
    }
    cin >> search_count;
    for (int i = 0; i < search_count - 1; i++){
        cin >> temp_search;
        avl_node_ptr target = avl_search(root, temp_search);
        if (!target)
            cout << 0 << " ";
        else
            cout << target->data.count << " ";
    }
    //最后不能留空格，单独处理
    cin >> temp_search;
    avl_node_ptr target = avl_search(root, temp_search);
    if (!target)
        cout << 0;
    else
        cout << target->data.count;
    return 0;
}