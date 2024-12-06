#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <climits>
#include <string>
#include <utility>

using namespace std;
using Graph = unordered_map<string, unordered_map<string, int>>;

// Function to perform Dijkstra's algorithm
unordered_map<string, int> dijkstra(const Graph& graph, const string& source) {
    unordered_map<string, int> distances;

    // Initialize distances to all nodes as max int value
    for (const auto& pair : graph) {
        distances[pair.first] = INT_MAX;
    }
    
    // Distance to the source is 0
    distances[source] = 0;

    // Min heap priority queue to store (distance, node) pairs
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
    pq.push(make_pair(0, source));

    while (!pq.empty()) {
        pair<int, string> current = pq.top();
        pq.pop();

        int current_distance = current.first;
        string current_node = current.second;

        // If the current distance is greater than the recorded distance, skip
        if (current_distance > distances[current_node]) {
            continue;
        }

        // Explore neighbors of the current node
        for (const auto& neighbor_pair : graph.at(current_node)) {
            string neighbor = neighbor_pair.first;
            int weight = neighbor_pair.second;
            int distance = current_distance + weight;
            
            // If a shorter path to the neighbor is found
            if (distance < distances[neighbor]) {
                distances[neighbor] = distance;
                pq.push(make_pair(distance, neighbor));
            }
        }
    }

    return distances;
}

int main() {
    // Define the graph as an adjacency list
    Graph graph = {
        {"A", {{"B", 1}, {"C", 4}}},
        {"B", {{"A", 1}, {"C", 2}, {"D", 5}}},
        {"C", {{"A", 4}, {"B", 2}, {"D", 1}}},
        {"D", {{"B", 5}, {"C", 1}}}
    };

    // Compute shortest paths from node "A"
    auto shortest_paths = dijkstra(graph, "A");

    cout << "Shortest paths from A:\n";

    for (const auto& node_pair : shortest_paths) {
        string node = node_pair.first;
        int distance = node_pair.second;

        cout << node << ": " << (distance == INT_MAX ? -1 : distance) << endl;
    }

    // Simulate an attack by removing node "B" and its edges
    graph["A"].erase("B");
    graph.erase("B");

    // Compute shortest paths from node "A" after the attack
    auto shortest_paths_after_attack = dijkstra(graph, "A");
    cout << "\nShortest paths after attack on 'B':\n";

    for (const auto& node_pair : shortest_paths_after_attack) {
        string node = node_pair.first;
        int distance = node_pair.second;

        cout << node << ": " << (distance == INT_MAX ? -1 : distance) << endl;
    }

    return 0;
}