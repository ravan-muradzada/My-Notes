#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// BFS and DFS in C++, for undirected graph
void bfs(int n, vector<int> adjacencyList[], vector<bool>& visited){
    queue<int> q;
    q.push(1); visited[1] = true;
    while (!q.empty()){
        cout << q.front() << " ";
        for (int i: adjacencyList[q.front()]){
            if (visited[i] != true){
                q.push(i);
                visited[i] = true;
            }
        }
        q.pop();
    }
    cout << endl << endl;
}
void dfs(int node, vector<int> arr[], vector<bool>& visited){
    cout << node << " ";
    visited[node] = true;
    for (int i: arr[node]){
        if (!visited[i]) dfs(i, arr, visited);
    }
}

int main(){
    int n, m, from, to; // nodes, roads
    cin >> n >> m;
    vector<int> adjacencyList[n + 1];
    
    for (int i = 0; i < m; ++i){
        cin >> from >> to;
        adjacencyList[from].push_back(to);
        adjacencyList[to].push_back(from);
    }
    vector<bool>visited(n + 1, false);
    bfs(n, adjacencyList, visited);
    visited.assign(n + 1, false);
    dfs(1, adjacencyList, visited);
    
    return 0;
}
