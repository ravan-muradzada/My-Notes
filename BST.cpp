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
    
    void inOrder(){ // left, root, right
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
    
    void preOrder(){ // root, left, right
        stack<TreeNode*> st;
        TreeNode* node = nullptr;
        st.push(root);
        while (!st.empty()){
            node = st.top();
            st.pop();
            cout << node->data << " ";
            if (node->right) st.push(node->right);
            if (node->left) st.push(node->left);
        }
    }

    void levelOrder(){ // level by level
        if (root == nullptr) return;
        queue<TreeNode*> q;
        TreeNode* node = nullptr;
        q.push(root);
        int size;
        while (!q.empty()){
            size = q.size();
            for (int i = 0; i < size; ++i){
                node = q.front();
                q.pop();
                cout << node->data << " ";
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            cout << "| ";
        }
        cout << endl;
    }
    
    
};

int main(){
    BST b1;
    int arr[] = {7, 5, 3, 6, 1, 4, 12, 9, 15, 8, 10, 13, 17};
    for (int i: arr){
        b1.insert(i);
    }
    b1.preOrder();
    return 0;
}
