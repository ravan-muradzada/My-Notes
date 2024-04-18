#include <iostream>
#include <stack>
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
private:
    TreeNode* root;
public:
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
    void inOrder(){
        if (root == nullptr) return;
        stack<TreeNode*> st;
        TreeNode* node = root;

        while (true){
            if (node){
                st.push(node);
                node = node->left;
            }else{
                if (st.empty()) break;
                node = st.top();
                st.pop();

                cout << node->data << " ";
                node = node->right;
            }
        }
        cout << endl << endl;
    }
};
void inOrderRecursion(TreeNode* tree){
    if (tree == nullptr)  return;
    inOrderRecursion(tree->left);
    cout << tree->data << " ";
    inOrderRecursion(tree->right);
}
int main(){
    BST b1;

    b1.insert(7);
    b1.insert(5);
    b1.insert(3);
    b1.insert(6);
    b1.insert(1);
    b1.insert(4);
    b1.insert(12);
    b1.insert(9);
    b1.insert(15);
    b1.insert(8);
    b1.insert(10);
    b1.insert(13);
    b1.insert(17);
    b1.inOrder();
    inOrderRecursion(b1.Root());
    // 1, 3, 4, 5, 6, 7, 8, 9, 10, 12, 13, 15, 17

    return 0;
}
