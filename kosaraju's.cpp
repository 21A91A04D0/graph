// it is a linear time algorithm to find the strongly connected components of a directed graph

/* 
    ->how can we say that the component is strongly connected?

    A strongly connected component is the component of a directed graph that has a path from every vertex to every other vertex in that component. It can only be used in a directed graph.

    A subgraph of a directed graph is considered to be an Strongly Connected Components (SCC) if and only if for every pair of vertices A and B, there exists a path from A to B and a path from B to A. 


    Applications of Kosaraju's :- 
        used to obtain a bipartite graph edges classification method


    steps to follow :
        1) sort all the edges according to the finishing time.
        2) Reverse the Graph.
        3) Do a dfs.
 */

#include<bits/stdc++.h>
using namespace std;
void dfs(int node, vector<int> &vis, vector<int> adj[], stack<int> &st) {
    vis[node] = 1;
    for(auto it : adj[node]) {
        if(!vis[it]) {
            dfs(it, vis, adj, st);
        }
    }
    st.push(node);
}
void dfs2(int node, vector<int> adj[], vector<int> &vis) {
    vis[node] = 1;
    for(auto it : adj[node]) {
        if(!vis[it]) {
            dfs2(it, adj, vis);
        }
    }
}
int main() {
    int N, E;
    cin >> N >> E;
    // space O(2 * N)
    // time O(N + E)
    vector<int> adj[N];
    for(int i = 0 ; i < E ; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    // sorting the edges according to the finishing time...
    vector<int> vis(N, 0);
    stack<int> st;
    for(int i = 0 ; i < N ; i++) {
        if(!vis[i]) {
            dfs(i, vis, adj, st);
        }
    }

    // reverse the graph...
    vector<int> adjT[N];
    for(int i = 0 ; i < N ; i++) {
        vis[i] = 0; // to reuse the same visited vector...
        for(auto it : adj[i]) {
            adjT[it].push_back(i);
        }
    }

    // again traverse the dfs...
    int cnt = 0;
    while(!st.empty()) {
        int node = st.top();
        st.pop();
        if(!vis[node]) {
            cnt++;
            dfs2(node, adjT, vis);
        }
    }
    cout << cnt;
    return 0;
}



