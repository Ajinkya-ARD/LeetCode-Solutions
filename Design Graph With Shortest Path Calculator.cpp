class Graph {
public:
    // Construct a graph with n nodes and initialized edges
    Graph(int n, const vector<vector<int>>& edges) {
        this->numNodes = n;
        // Initialize graph with 'numNodes' and set distances to infinity (INT_MAX represents infinity)
        adjMatrix = vector<vector<int>>(numNodes, vector<int>(numNodes, INT_MAX));
        // Set edge distances based on the input edges
        for (const auto& edge : edges) {
            int from = edge[0], to = edge[1], cost = edge[2];
            adjMatrix[from][to] = cost;
        }
    }

    // Adds a new edge to the graph
    void addEdge(const vector<int>& edge) {
        int from = edge[0], to = edge[1], cost = edge[2];
        adjMatrix[from][to] = cost;
    }

    // Computes the shortest path between node1 and node2 using Dijkstra's algorithm
    int shortestPath(int startNode, int endNode) {
        vector<bool> visited(numNodes, false);
        vector<int> distances(numNodes, INT_MAX);
        distances[startNode] = 0;

        // Iterate 'numNodes' times to find the shortest paths
        for (int i = 0; i < numNodes; ++i) {
            int closest = -1;
            // Find the nearest unvisited node
            for (int j = 0; j < numNodes; ++j) {
                if (!visited[j] && (closest == -1 || distances[closest] > distances[j])) {
                    closest = j;
                }
            }
            visited[closest] = true; // Mark the node as visited
          
            // Update the distances of the adjacent nodes
            for (int j = 0; j < numNodes; ++j) {
                // Safe addition to avoid integer overflow
                if(distances[closest] != INT_MAX && adjMatrix[closest][j] != INT_MAX) {
                    distances[j] = min(distances[j], distances[closest] + adjMatrix[closest][j]);
                }
            }
        }
        // Return the shortest path to 'endNode', or -1 if it's not reachable
        return distances[endNode] == INT_MAX ? -1 : distances[endNode];
    }

private:
    vector<vector<int>> adjMatrix; // Adjacency matrix to represent the graph
    int numNodes; // Number of nodes in the graph
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */