#include<bits/stdc++.h>
using namespace std;
void bfs(vector<int> adj[], int node, vector<int> &vis) {
    queue<int> Q;
    Q.push(node);
    vis[node] = 1;
    while(!Q.empty()) {
        int top = Q.front();
        cout << top << " ";
        Q.pop();
        for(auto it : adj[top]){
            if(!vis[it]){
                Q.push(it);
                vis[it] = 1;
            }
        }
    }

}
int main() {
    int N, E;
    //N -> No of nodes
    //E -> No of edges
    cin >> N >> E;
    vector<int> adj[N + 1];
    for(int i = 0 ; i < E ; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(N + 1, 0);
    bfs(adj, 1, vis);
    // for(auto it : vis)
}