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

void insert(TreeNode*& tree, int val){
    if (!tree) tree = new TreeNode(val);
    else if (val > tree->data)
        insert(tree->right, val);
    else insert(tree->left, val);
}

void inOrder(TreeNode*& tree){
    if (!tree) return;
    inOrder(tree->left);    
    cout << tree->data << " ";
    inOrder(tree->right);
}

void preOrder(TreeNode*& tree){
    if (!tree) return;
    cout << tree->data << " ";
    preOrder(tree->left);
    preOrder(tree->right);
}

void postOrder(TreeNode*& tree){
    if (!tree) return;
    postOrder(tree->left);
    postOrder(tree->right);
    cout << tree->data << " ";
}

int main(){
    BST b1;
    int arr[] = {7, 5, 3, 6, 1, 4, 12, 9, 15, 8, 10, 13, 17};
    for (int i: arr){
        insert(b1.root, i);
    }
    preOrder(b1.root);
    return 0;
}
