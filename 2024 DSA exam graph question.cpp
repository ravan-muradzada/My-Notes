#include iostream
#include vector
using namespace std;
int Count = 0;
void printAdjacencyMatrix(int n, vectorvectorint& adj){
    for (int i = 0; i  n; ++i){
        cout  From node   i   there are ways to ;
        for (int j adj[i]){
            cout  j   ;
        }
        cout  endl;
    }
}

void dfs(int node, vectorvectorint& adj, vectorbool& visited){
    visited[node] = true;
    Count++;
    for (int i adj[node]){
        if (!visited[i])
            dfs(i, adj, visited);
    }
}

int countOfComponents(int n, vectorvectorint& adj, vectorbool& visited){
    int components = 0;
    
    for (int i = 0; i  n; ++i){
        if (!visited[i]){
            dfs(i, adj, visited);
            components++;
        }
    }
    return components;
}

void countOfEachComponent(int n, vectorvectorint& adj, vectorbool& visited){
    for (int i = 0; i  n; ++i){
        Count = 0;
        if (!visited[i]){
            dfs(i, adj, visited);
            cout  Count   ;
        }
    }
}


int main(){
    int n, m, from, to;
    cin  n  m;
    vectorvectorint adj(n);
    vectorbool visited(n, false);
    
    for (int i = 0; i  m; ++i){  Subtask 1
        cin  from  to;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    printAdjacencyMatrix(adj);
    cout  Count of components   countOfComponents(n, adj, visited)  endl;  Subtask 2
    visited.assign(n, false);
    cout  Count of each component ;
    countOfEachComponent(n, adj, visited);  Subtask 3
    
    
    
    return 0;
}