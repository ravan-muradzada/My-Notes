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

int sumOfLeaves(TreeNode*& tree){
    if (tree == nullptr) return 0;
    if (!tree->left && !tree->right){
        return tree->data;
    }else{
        return sumOfLeaves(tree->left) + sumOfLeaves(tree->right);
    }
}

int sumOfLeftLeaves(TreeNode*& tree){
    if (!tree) return 0;
    if (tree->left && !tree->left->left && !tree->left->right){
        return tree->left->data + sumOfLeftLeaves(tree->right);
    }else{
        return sumOfLeftLeaves(tree->left) + sumOfLeftLeaves(tree->right);
    }
}

bool isSymmetric(TreeNode*& leftSide, TreeNode*& rightSide){
    if (!leftSide && !rightSide) return true;
    if (!leftSide || !rightSide) return false;
    else{
        return (leftSide->data == rightSide->data) && 
        (isSymmetric(leftSide->left, rightSide->right)) && 
        (isSymmetric(leftSide->right, rightSide->left));
     }
}

bool isSame(TreeNode*& tree_1, TreeNode*& tree_2){
    if (!tree_1 && !tree_2) return true;
    if (!tree_1 || !tree_2) return false;
    
    return (tree_1->data == tree_2->data) && 
           (isSame(tree_1->left, tree_2->left))&
           (isSame(tree_1->right, tree_2->right));
}

int main(){
    BST b1, b2;
    int arr[] = {7, 5, 3, 6, 1, 4, 12, 9, 15, 8, 10, 13, 17};
    for (int i: arr){
        insert(b1.root, i);
        insert(b2.root, i);
    }
    insert(b2.roogt, 25);
    cout << boolalpha << isSame(b1.root, b2.root);

    return 0;
}
