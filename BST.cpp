#include <iostream>
using namespace std;

class TreeNode{
public:
    int data;
    TreeNode* left, *right;
    TreeNode(int data): data(data) {}
    TreeNode(){
        data = 0;
    }
};

class BST{
public:
    TreeNode* root;
    BST(){
        root = nullptr;
    }
};

void insert(TreeNode*& root, int val) {
    if (root == nullptr) {
        root = new TreeNode(val);
        return;
    }
    if (val < root->data) {
        insert(root->left, val);
    } else {
        insert(root->right, val);
    }
}


void inOrder(TreeNode* tree){
    if (tree == nullptr) return;
    inOrder(tree->left);
    cout << tree->data << " ";
    inOrder(tree->right);
}

int main(){
    BST b1;
    int arr[] = {8, 4, 12, 6, 5, 16, 14, 3, 9};
    for (int i: arr){
        insert(b1.root, i);
    }
    inOrder(b1.root);
    
    return 0;
}