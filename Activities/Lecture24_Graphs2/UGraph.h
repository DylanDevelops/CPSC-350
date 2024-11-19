#include <iostream>
#include <vector> // C++'s version of Java's ArrayList, just a wrapper class for arrays
#include <stack> // C++'s stack
#include <queue> // C++'s queue
#include <set> // set is an unordered collection with unique elements
#include <unordered_map> // C++'s hashmap 

// CLASS TO REPRESENT EACH VERTEX
template <typename T>
class Vertex {
public:
    T name; // Each vertex has a 'name' of type T
    Vertex(T n); // Constructor
    ~Vertex(); // Destructor
};

template <typename T>
Vertex<T>::Vertex(T n) { name = n; } // Assign 'name' during construction

template <typename T>
Vertex<T>::~Vertex() {} // No specific cleanup needed for Vertex




// CLASS TO REPRESENT AN UNWEIGHTED GRAPH
template <typename T>
class UGraph {
public:
    UGraph(int sz); // Constructor to initialize graph of a given size
    ~UGraph(); // Destructor to clean up dynamic allocations
    
    // Public methods for interacting with the graph
    void addVertex(T name);             
    void addEdge(T name1, T name2);     
    void removeEdge(T name1, T name2);  
    bool areAdjacent(T name1, T name2); 
    std::vector<T> dfs(T startVertex);  
    std::vector<T> bfs(T startVertex);  
    int findIslands();

private:
    int m_size; // Maximum number of vertices in the graph
    bool** m_adj; // 2D array representing adjacency matrix for edges
    std::vector<Vertex<T>> m_vertices; // List of vertices
    std::unordered_map<T, int> m_nameToIndex; // Map to track each vertex's index by name
};

// CONSTRUCTOR
template <typename T>
UGraph<T>::UGraph(int sz) : m_size(sz) {
    // Initialize adjacency matrix with 'false' values indicating no edges
    m_adj = new bool*[m_size];
    for (int i = 0; i < m_size; ++i) {
        m_adj[i] = new bool[m_size]{false}; // Set all connections to false
    }
}

// DESTRUCTOR
template <typename T>
UGraph<T>::~UGraph() {
    // Delete each row in the adjacency matrix
    for (int i = 0; i < m_size; ++i) {
        delete[] m_adj[i];
    }
    // Delete the adjacency matrix itself
    delete[] m_adj;
}

// Add a new vertex to the graph
template <typename T>
void UGraph<T>::addVertex(T name) {
    if (m_vertices.size() < m_size) { // Ensure graph size limit isn't exceeded
        m_vertices.push_back(Vertex<T>(name)); // Add the vertex to list
        m_nameToIndex[name] = m_vertices.size() - 1; // Map vertex name to index
    } else {
        std::cerr << "Graph capacity reached. Cannot add more vertices." << std::endl;
    }
}

// Add an edge between two vertices by their names
template <typename T>
void UGraph<T>::addEdge(T name1, T name2) {
    // Check if both vertices exist in the graph
    if (m_nameToIndex.count(name1) > 0 && m_nameToIndex.count(name2) > 0) {
        int i = m_nameToIndex[name1]; // Get the index for that name
        int j = m_nameToIndex[name2]; // Get the index for that name
        m_adj[i][j] = true; // Mark as connected
        m_adj[j][i] = true; // Symmetric connection in undirected graph
    } else {
        std::cerr << "One or both vertices not found in the graph." << std::endl;
    }
}

// Remove an edge between two vertices by their names
template <typename T>
void UGraph<T>::removeEdge(T name1, T name2) {
    if (m_nameToIndex.count(name1) > 0 && m_nameToIndex.count(name2) > 0) {
        int i = m_nameToIndex[name1]; // Get the index for that name
        int j = m_nameToIndex[name2]; // Get the index for that name
        m_adj[i][j] = false; // Remove connection
        m_adj[j][i] = false; // Symmetric removal
    } else {
        std::cerr << "One or both vertices not found in the graph." << std::endl;
    }
}

// Check if two vertices are adjacent
template <typename T>
bool UGraph<T>::areAdjacent(T name1, T name2) {
    if (m_nameToIndex.count(name1) > 0 && m_nameToIndex.count(name2) > 0) {
        int i = m_nameToIndex[name1]; // Get the index for that name
        int j = m_nameToIndex[name2]; // Get the index for that name
        return m_adj[i][j]; // Returns true if they are connected, false otherwise
    }
    std::cerr << "One or both vertices not found in the graph." << std::endl;
    return false;
}

// DFS traversal starting from a given vertex name
template <typename T>
std::vector<T> UGraph<T>::dfs(T startVertex) {
    std::vector<T> visited_order; // Track order of visited vertices
    if (m_nameToIndex.count(startVertex) == 0) {
        std::cerr << "Vertex not found in the graph." << std::endl;
        return visited_order;
    }

    std::stack<int> stk; // stack to conduct the DFS
    int startIndex = m_nameToIndex[startVertex]; // index of the start vertex
    std::set<int> visited; // keep track of all nodes we've visited, either still in the stack or already popped
    stk.push(startIndex); // add the index of the starting point to the stack

    while(!stk.empty() && visited.size() < m_size) {
        int current = stk.top(); // peek the top element
        stk.pop(); // remove the thing at the top

        // if this current vertex has already been visited
        if(visited.count(current) != 0) {
            continue;
        }

        // visit the vertex/node
        visited.insert(current); // Mark as visited
        visited_order.push_back(m_vertices[current].name); // Record visit order

        // Iterate through neighbors in the adjacency matrix
        for (int k = 0; k < m_size; ++k) {
            if (m_adj[current][k] && visited.count(k) == 0) {
                stk.push(k); // Add unvisited neighbors to the stack
            }
        }
    }

    return visited_order; // Return traversal order
}

// BFS traversal starting from a given vertex name
template <typename T>
std::vector<T> UGraph<T>::bfs(T startVertex) {
    std::vector<T> visited_order; // Store BFS traversal order
    if (m_nameToIndex.count(startVertex) == 0) {
        std::cerr << "Vertex not found in the graph." << std::endl;
        return visited_order;
    }
    
    std::queue<int> q; // stack to conduct the DFS
    int startIndex = m_nameToIndex[startVertex]; // index of the start vertex
    std::set<int> visited; // keep track of all nodes we've visited, either still in the stack or already popped
    q.push(startIndex); // add the index of the starting point to the stack

    while(!q.empty() && visited.size() < m_size) {
        int current = q.front(); // peek the front element
        q.pop(); // remove the thing at the front

        // if this current vertex has already been visited
        if(visited.count(current) != 0) {
            continue;
        }

        // visit the vertex/node
        visited.insert(current); // Mark as visited
        visited_order.push_back(m_vertices[current].name); // Record visit order

        // Iterate through neighbors in the adjacency matrix
        for (int k = 0; k < m_size; ++k) {
            if (m_adj[current][k] && visited.count(k) == 0) {
                q.push(k); // Add unvisited neighbors to the stack
            }
        }
    }

    return visited_order;
}

// Count number of disconnected components (islands) in the graph
template <typename T>
int UGraph<T>::findIslands() {
    // TO DO
    return 0;
}