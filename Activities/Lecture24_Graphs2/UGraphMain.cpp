#include <iostream>
#include <string>
#include <vector>
#include "UGraph.h"  

int main() {
    // SERVERS EXAMPLE
    // Create a graph with 7 nodes representing servers
    UGraph<int> serverNetwork(7);

    // Adding servers (nodes labeled as numbers)
    serverNetwork.addVertex(1);
    serverNetwork.addVertex(2);
    serverNetwork.addVertex(3);
    serverNetwork.addVertex(4);
    serverNetwork.addVertex(5);
    serverNetwork.addVertex(6);
    serverNetwork.addVertex(7);

    // Adding edges to represent connections between servers
    serverNetwork.addEdge(1, 2); // Server 1 is connected to Server 2
    serverNetwork.addEdge(2, 3); // Server 2 is connected to Server 3
    serverNetwork.addEdge(3, 4); // Server 3 is connected to Server 4
    serverNetwork.addEdge(4, 1); // Server 4 is connected back to Server 1 (forming a cycle)
    serverNetwork.addEdge(5, 6); // Server 5 is connected to Server 6
    serverNetwork.addEdge(6, 7); // Server 6 is connected to Server 7

    // Print DFS traversal starting from server 1
    std::cout << "DFS traversal starting from Server 1:" << std::endl;
    std::vector<int> dfs_order = serverNetwork.dfs(1);
    
    // Display the DFS order
    std::cout << "DFS order: ";
    for (int node : dfs_order) {
        std::cout << node << " ";
    }
    std::cout << std::endl;

    // Print BFS traversal starting from server 1
    std::cout << "\nBFS traversal starting from Server 1:" << std::endl;
    std::vector<int> bfs_order = serverNetwork.bfs(1);
    
    // Display the BFS order
    std::cout << "BFS order: ";
    for (int node : bfs_order) {
        std::cout << node << " ";
    }
    std::cout << std::endl;

    // Check if certain servers are adjacent
    std::cout << "\nAre Server 1 and Server 4 connected? "
              << (serverNetwork.areAdjacent(1, 4) ? "Yes" : "No") << std::endl;

    std::cout << "Are Server 5 and Server 7 connected? "
              << (serverNetwork.areAdjacent(5, 7) ? "Yes" : "No") << std::endl;

    // Find the number of isolated networks (islands) in the server network
    // int islands = serverNetwork.findIslands();
    // std::cout << "\nNumber of isolated networks (islands): " << islands << std::endl;



    // CITIES EXAMPLE FROM WARMUP 
    // Create a graph with a sufficient size to hold all cities (24 cities in this example)
    UGraph<std::string> citiesGraph(24);

    // List of all cities as vertices
    std::vector<std::string> cities = {
        "New York", "Boston", "Chicago", "Philadelphia", "Atlanta", "Miami", "New Orleans", "Washington D.C.",
        "Sydney", "Melbourne", "Brisbane", "Perth", "Adelaide", "Gold Coast", "Cairns", "Hobart",
        "Madrid", "Barcelona", "Valencia", "Seville", "Bilbao", "Zaragoza", "Granada", "Malaga"
    };

    // Add each city as a vertex in the citiesGraph using a regular for loop
    for (int i = 0; i < cities.size(); i++) {
      citiesGraph.addVertex(cities[i]);
    }

    // Add edges for USA Island
  citiesGraph.addEdge("New York", "Boston");
  citiesGraph.addEdge("Boston", "Chicago");
  citiesGraph.addEdge("Chicago", "New York");
  citiesGraph.addEdge("New York", "Philadelphia");
  citiesGraph.addEdge("Philadelphia", "Chicago");
  citiesGraph.addEdge("Chicago", "Atlanta");
  citiesGraph.addEdge("Atlanta", "Miami");
  citiesGraph.addEdge("Miami", "New Orleans");
  citiesGraph.addEdge("New Orleans", "Chicago");
  citiesGraph.addEdge("Philadelphia", "Washington D.C.");
  citiesGraph.addEdge("Washington D.C.", "New York");

    // Add edges for Australia Island
  citiesGraph.addEdge("Sydney", "Melbourne");
  citiesGraph.addEdge("Melbourne", "Brisbane");
  citiesGraph.addEdge("Brisbane", "Sydney");
  citiesGraph.addEdge("Sydney", "Perth");
  citiesGraph.addEdge("Perth", "Adelaide");
  citiesGraph.addEdge("Adelaide", "Melbourne");
  citiesGraph.addEdge("Brisbane", "Gold Coast");
  citiesGraph.addEdge("Gold Coast", "Cairns");
  citiesGraph.addEdge("Cairns", "Brisbane");
  citiesGraph.addEdge("Melbourne", "Hobart");

    // Add edges for Spain Island
  citiesGraph.addEdge("Madrid", "Barcelona");
  citiesGraph.addEdge("Barcelona", "Valencia");
  citiesGraph.addEdge("Valencia", "Madrid");
  citiesGraph.addEdge("Madrid", "Seville");
  citiesGraph.addEdge("Seville", "Barcelona");
  citiesGraph.addEdge("Barcelona", "Bilbao");
  citiesGraph.addEdge("Bilbao", "Zaragoza");
  citiesGraph.addEdge("Zaragoza", "Madrid");
  citiesGraph.addEdge("Seville", "Granada");
  citiesGraph.addEdge("Granada", "Malaga");
  citiesGraph.addEdge("Malaga", "Seville");

    // Test DFS from "New York"
    std::vector<std::string> dfs_order_cities = citiesGraph.dfs("New York");
    std::cout << "DFS Order starting from New York: ";
    for (int i = 0; i < dfs_order_cities.size(); i++) {
        std::cout << dfs_order_cities[i] << "    ";
    }
    std::cout << std::endl;

    // Test BFS from "Sydney"
    std::vector<std::string> bfs_order_cities = citiesGraph.bfs("Sydney");
    std::cout << "BFS Order starting from Sydney: ";
    for (int i = 0; i < bfs_order_cities.size(); i++) {
        std::cout << bfs_order_cities[i] << "    ";
    }
    std::cout << std::endl;

    // Test adjacency
    std::cout << "Are New York and Boston adjacent? " 
              << (citiesGraph.areAdjacent("New York", "Boston") ? "Yes" : "No") << std::endl;
    std::cout << "Are Sydney and Melbourne adjacent? " 
              << (citiesGraph.areAdjacent("Sydney", "Melbourne") ? "Yes" : "No") << std::endl;
    std::cout << "Are Madrid and Chicago adjacent? " 
              << (citiesGraph.areAdjacent("Madrid", "Chicago") ? "Yes" : "No") << std::endl;


    // Test findIslands (disconnected components)
    // int num_islands = citiesGraph.findIslands();
    // std::cout << "Number of disconnected components (islands): " << num_islands << std::endl;

    return 0;
}