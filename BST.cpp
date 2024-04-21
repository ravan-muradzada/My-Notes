#include <iostream>
#include <stack>
#include <queue>
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
    TreeNode* Root(){
        TreeNode* Temp = root;
        return Temp;
    }
    void insert(int val){
        if (root == nullptr){
            root = new TreeNode(val);
            return;
        }
        TreeNode* newNode = new TreeNode(val);
        TreeNode* curr = root, *prev = nullptr;
        while (curr){
            prev = curr;
            if (val > curr->data)
                curr = curr->right;
            else curr = curr->left;
        }
        if (val > prev->data)
            prev->right = newNode;
        else prev->left = newNode;
    }
};

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
        b1.insert(i);
    }
    preOrder(b1.root);
    return 0;
}