#include <iostream>
#include <vector>
#define n 6
#define m 9
using namespace std;
void fullfill(vector<vector<int>>& adj){ // 1.
    adj[0] = {1, 5};
    adj[1] = {2, 4};
    adj[2] = {3};
    adj[3] = {0, 1};
    adj[4] = {3};
    adj[5] = {4};
}
int calculateOutDegreeOf_Node3(vector<vector<int>>& adj){ // 2.
    int count = 0;
    for (int i = 0; i < n; ++i){
        for (int j: adj[i]){
            if (j == 3) count++;
        }
    }
    return count;
}

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, bool& doesExist){ // 3.
    visited[node] = true;
    for (int i: adj[node]){
        if (i == 0){
            doesExist = true;
            return;
        }
        if (!visited[i]){
            dfs(i, adj, visited, doesExist);
        }
    }
}
int main(){
    vector<vector<int>> adj(n);
    fullfill(adj);
    cout << calculateOutDegreeOf_Node3(adj) << endl;
    vector <bool> visited(n, false);
    bool doesExist = false;
    dfs(1, adj, visited, doesExist);
    cout << boolalpha << doesExist;
    
    
    return 0;
}