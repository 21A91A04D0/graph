/* 
    Topological sorting for Directed Acyclic Graph (DAG) is a 
    linear ordering of vertices such that 
    for every directed edge u-v, vertex u comes before v in the ordering.

    Note: Topological Sorting for a graph is not possible if the graph is not a DAG.
*/

#include<bits/stdc++.h>
using namespace std;
vector<int> st;
void dfs(vector<int> adj[], vector<int> &vis, int node) {
    vis[node] = 1;
    for(auto it : adj[node]) {
        if(!vis[it]) {
            (adj, vis, it);
        }
    }
    st.push_back(node);
}
int main() {
    int N, E;
    cin >> N >> E;
    vector<int> adj[N];
    for(int i = 0 ; i < E ; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int> vis(N, 0);
    for(int i = 0 ; i < N ; i++) {
        if(!vis[i]) {
            dfs(adj, vis, i);
        }
    }
    reverse(st.begin(), st.end());
    for(auto it : st){
        cout << it << " ";
    }
}