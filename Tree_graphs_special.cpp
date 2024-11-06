#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Graph {
public:
    unordered_map<int, vector<int>> adjList;
    bool isDirected;

    // Constructor for Graph; pass 'true' for directed, 'false' for undirected
    Graph(bool directed) : isDirected(directed) {}

    // Add edge to the graph
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        if (!isDirected) {
            adjList[v].push_back(u); // For undirected graphs, add reverse edge
        }
    }

    // DFS traversal
    void dfs(int start) {
        unordered_set<int> visited;
        dfsUtil(start, visited);
        cout << endl;
    }

    // BFS traversal
    void bfs(int start) {
        unordered_set<int> visited;
        queue<int> q;
        q.push(start);
        visited.insert(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int neighbor : adjList[node]) {
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }

    // Cycle detection for undirected graph using DFS
    bool hasCycleUndirected() {
        unordered_set<int> visited;
        for (const auto& node : adjList) {
            if (visited.find(node.first) == visited.end()) {
                if (dfsCycleUndirected(node.first, visited, -1)) {
                    return true;
                }
            }
        }
        return false;
    }

    // Cycle detection for directed graph using DFS
    bool hasCycleDirected() {
        unordered_map<int, bool> visited;
        unordered_map<int, bool> recursionStack;

        for (const auto& node : adjList) {
            if (visited.find(node.first) == visited.end()) {
                if (dfsCycleDirected(node.first, visited, recursionStack)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    // Utility function for DFS traversal
    void dfsUtil(int node, unordered_set<int>& visited) {
        visited.insert(node);
        cout << node << " ";

        for (int neighbor : adjList[node]) {
            if (visited.find(neighbor) == visited.end()) {
                dfsUtil(neighbor, visited);
            }
        }
    }

    // Helper function for undirected cycle detection
    bool dfsCycleUndirected(int node, unordered_set<int>& visited, int parent) {
        visited.insert(node);
        for (int neighbor : adjList[node]) {
            if (visited.find(neighbor) == visited.end()) {
                if (dfsCycleUndirected(neighbor, visited, node)) {
                    return true;
                }
            } else if (neighbor != parent) {
                return true;
            }
        }
        return false;
    }

    // Helper function for directed cycle detection
    bool dfsCycleDirected(int node, unordered_map<int, bool>& visited, unordered_map<int, bool>& recursionStack) {
        visited[node] = true;
        recursionStack[node] = true;

        for (int neighbor : adjList[node]) {
            if (!visited[neighbor] && dfsCycleDirected(neighbor, visited, recursionStack)) {
                return true;
            } else if (recursionStack[neighbor]) {
                return true;
            }
        }

        recursionStack[node] = false;
        return false;
    }
};

int main() {
    // Example for directed graph
    Graph directedGraph(true);
    directedGraph.addEdge(0, 1);
    directedGraph.addEdge(1, 2);
    directedGraph.addEdge(2, 3);
    directedGraph.addEdge(3, 1); // Cycle exists

    cout << "Directed Graph - DFS Traversal from Node 0: ";
    directedGraph.dfs(0);

    cout << "Directed Graph - BFS Traversal from Node 0: ";
    directedGraph.bfs(0);

    cout << "Directed Graph - Has Cycle: " << (directedGraph.hasCycleDirected() ? "Yes" : "No") << endl;

    // Example for undirected graph
    Graph undirectedGraph(false);
    undirectedGraph.addEdge(0, 1);
    undirectedGraph.addEdge(1, 2);
    undirectedGraph.addEdge(2, 3);
    undirectedGraph.addEdge(3, 0); // Cycle exists

    cout << "Undirected Graph - DFS Traversal from Node 0: ";
    undirectedGraph.dfs(0);

    cout << "Undirected Graph - BFS Traversal from Node 0: ";
    undirectedGraph.bfs(0);

    cout << "Undirected Graph - Has Cycle: " << (undirectedGraph.hasCycleUndirected() ? "Yes" : "No") << endl;

    return 0;
}
