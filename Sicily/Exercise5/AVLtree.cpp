#include <iostream>
#include <cstdio>
using namespace std;

struct tree {
    int elem;
    int balance;
    tree * left;
    tree * right;
    tree(int e) {
        elem = e;
        balance = 0;
        left = right = NULL;
    }
};

void left_rotate(tree* &sub_root) {
    tree* right_tree = sub_root->right;
    sub_root->right = right_tree->left;
    right_tree->left = sub_root;
    sub_root = right_tree;
}

void right_rotate(tree* &sub_root) {
    tree* left_tree = sub_root->left;
    sub_root->left = left_tree->right;
    left_tree->right = sub_root;
    sub_root = left_tree;
}

void right_balance(tree* &sub_root) {
    tree*& right_tree = sub_root->right;
    switch(right_tree->balance) {
        case 1:
            sub_root->balance = 0;
            right_tree->balance = 0;
            left_rotate(sub_root);
            break;
        case -1:
        {
            tree* sub_tree = right_tree->left;
            switch(sub_tree->balance) {
                case 0:
                    sub_root->balance = 0;
                    right_tree->balance = 0;
                    break;
                case -1:
                    sub_root->balance = 0;
                    right_tree->balance = 1;
                    break;
                case 1:
                    sub_root->balance = -1;
                    right_tree->balance = 0;
                    break;                  
            }
            sub_tree->balance = 0;
            right_rotate(right_tree);
            left_rotate(sub_root);
            break;          
        }                   
    }
}


void left_balance(tree* &sub_root) {
    tree*& left_tree = sub_root->left;
    switch(left_tree->balance) {
        case -1:
            sub_root->balance = 0;
            left_tree->balance = 0;
            right_rotate(sub_root);
            break;
        case 1:
        {
            tree* sub_tree = left_tree->right;
            switch(sub_tree->balance) {
                case 0:
                    sub_root->balance = 0;
                    left_tree->balance = 0;
                    break;
                case 1:
                    sub_root->balance = 0;
                    left_tree->balance = -1;
                    break;
                case -1:
                    sub_root->balance = 1;
                    left_tree->balance = 0;
                    break;
            }
            sub_tree->balance = 0;
            left_rotate(left_tree);
            right_rotate(sub_root);
            break;          
        }                   
    }
}

void insert(tree*& sub_root, int& new_data, bool& taller) {
    if(sub_root == NULL) {
        sub_root = new tree(new_data);
        taller = true;
    }
    else if (new_data <= sub_root->elem) {
        insert(sub_root->left, new_data, taller);
        if(taller == true) {
            switch(sub_root->balance) {
                case -1: 
                    left_balance(sub_root);
                    taller = false;
                    break;
                case 0: 
                    sub_root->balance = -1;
                    break;
                case 1:
                    sub_root->balance = 0;
                    taller = false;
                    break;  
            }   
        }
    }
    else {
        insert(sub_root->right, new_data, taller);
        if (taller == true) {
            switch(sub_root->balance) {
                    case -1:
                        sub_root->balance = 0;
                        taller = false;
                        break;
                    case 0: 
                        sub_root->balance = 1;
                        break;
                    case 1: 
                        right_balance(sub_root);
                        taller = false;
                        break;
            }
        }
    }
}

void pre(tree * & root) {
    if(root == NULL) return;
    printf("%d ", root->elem);
    pre(root->left);
    pre(root->right);
}

void deleteTree(tree*& root) {
    if(root == NULL) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    int t, n, i, e;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        bool taller = true;
        tree* root = NULL;
        for(i = 0; i < n; i++) {
            scanf("%d", &e);
            insert(root, e, taller);
        }
        pre(root);
        printf("\n");
        deleteTree(root);
    }
    return 0;
}                                 