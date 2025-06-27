import java.util.*;
class Graph {
    // Graph Creation using constructor by taking adjacent List;
    private int V; // number of vertices
    private List<List<Integer>> adjList;

    public Graph(int V) {
        this.V = V;
        adjList = new ArrayList<>();
        for(int i = 0 ; i < V ; i++) {
            adjList.add(new ArrayList<>());
        }
    }

    //Add Edge(undirected Graph)
    public void addEdge(int u, int v) {
        adjList.get(u).add(v);
        adjList.get(v).add(u);
    }

    //dfs
    public void dfsUtil(int node, boolean[] visited) {
        visited[node] = true;
        System.out.print(node + " ");
        for(int neighbor : adjList.get(node)) {
            if(visited[neighbor] == false) {
                dfsUtil(neighbor,visited);
            }
        }
    }

    public void dfsTraversal(int startNode) {
        boolean[] visited = new boolean[V];
        dfsUtil(startNode,visited);
        System.out.println();
    }

    public static void main(String[] args) {
        Graph g = new Graph(5); // nodes should be 0 to 4;
        g.addEdge(0,1);
        g.addEdge(0, 2);
        g.addEdge(1, 2);
        g.addEdge(1, 4);
        g.addEdge(2,4);
        g.addEdge(3,1);
        g.addEdge(3, 4);

        g.dfsTraversal(0);
        g.bfsTraversal(0);
    }

    // bfs traversal;
    public void bfsTraversal(int startNode) {
        Queue<Integer> queue = new LinkedList<>();
        boolean[] vis = new boolean[V];
        vis[startNode] = true;
        queue.add(startNode);
        while(!queue.isEmpty()) {
            int current = queue.poll();
            System.out.print(current + " ");
            for(int neighbor : adjList.get(current)) {
                if(!vis[neighbor]) {
                    vis[neighbor] = true;
                    queue.add(neighbor);
                }
            }
        }
    }
}