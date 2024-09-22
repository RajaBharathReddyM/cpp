#include <iostream>
#include <vector>
#include <queue>
#include <climits> 
using namespace std;

// Function to find the shortest path using Dijkstra's algorithm
void findShortestPath(int start, int end, vector<vector<pair<int, int> > >& graph, int totalNodes) {
    vector<int> distance(totalNodes, INT_MAX);  // Stores shortest distance from start to each node
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > exploreNext;

    // Start from the source node
    distance[start] = 0;  // Distance to itself is 0
    exploreNext.push(make_pair(0, start));  // Add start node to queue (distance, node)

    while (!exploreNext.empty()) {
        int currentDist = exploreNext.top().first;  // The distance to the current node
        int currentNode = exploreNext.top().second; // The node we're looking at
        exploreNext.pop();  // Remove it from the queue

        // Loop through all neighbors of the current node
        for (vector<pair<int, int> >::iterator it = graph[currentNode].begin(); it != graph[currentNode].end(); ++it) {
            int nextNode = it->first;    // Neighbor node
            int pathCost = it->second;   // Cost to reach neighbor

            // If we find a shorter path to the neighbor, update it
            if (distance[currentNode] + pathCost < distance[nextNode]) {
                distance[nextNode] = distance[currentNode] + pathCost;
                exploreNext.push(make_pair(distance[nextNode], nextNode));  // Add neighbor to the queue
            }
        }
    }

    // Print the result
    if (distance[end] == INT_MAX) {
        cout << "No path from node " << start << " to node " << end << endl;
    } else {
        cout << "Shortest path from node " << start << " to node " << end << " is " << distance[end] << endl;
    }
}

int main() {
    int nodes, edges;
    cout << "Enter the number of nodes and edges: ";
    cin >> nodes >> edges;

    // Create a graph using a list of neighbors for each node
    vector<vector<pair<int, int> > > graph(nodes);

    cout << "Enter the edges (format: node1 node2 cost):" << endl;
    for (int i = 0; i < edges; ++i) {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].push_back(make_pair(to, cost));
        graph[to].push_back(make_pair(from, cost));
    }

    int startNode, endNode;
    cout << "Enter the starting node: ";
    cin >> startNode;
    cout << "Enter the ending node: ";
    cin >> endNode;
    findShortestPath(startNode, endNode, graph, nodes);

    return 0;
}