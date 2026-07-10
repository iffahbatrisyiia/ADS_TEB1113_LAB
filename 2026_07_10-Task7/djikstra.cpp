#include <iostream>
#include <string>
#define INF 1e9 //define infinity for unreachable nodes

using namespace std;

//1. Modified Node to represent an Edge in an Adjacency List
struct Vertex {
    string dest;      // Destination vertex name
    int weight;       // Edge weight/distance
    Vertex* next = NULL;
};

// Helper function to insert an edge at the front of the neighbor list
void insertEdge(Vertex*& head, string dest, int weight) {
    Vertex* newVertex = new Vertex();
    newVertex->dest = dest;
    newVertex->weight = weight;
    newVertex->next = head;
    head = newVertex;
}

// 2. Structures to keep track of Dijkstra state
struct VertexState {
    string name;
    int distance;
    bool visited;
};

int main() {
    // Let's define 4 vertices: "Ali", "Batrisyia", "Claire", "Dmitri"
    const int numVertices = 4;
    string vertices[numVertices] = {"Ali", "Batrisyia", "Claire", "Dmitri"};

    // An array of Vertex pointers representing our Adjacency List
    Vertex* adjList[numVertices] = {NULL};

    // --- Graph Construction ---
    // Ali --(weight 4)--> Batrisyia, Ali --(weight 2)--> Claire 
    insertEdge(adjList[0], "Batrisyia", 4);
    insertEdge(adjList[0], "Claire", 2);

    // Batrisyia --(weight 3)--> Dmitri 
    insertEdge(adjList[1], "Dmitri", 3);

    // Claire --(weight 1)--> Batrisyia, Claire --(weight 5)--> Dmitri 
    insertEdge(adjList[2], "Batrisyia", 1);
    insertEdge(adjList[2], "Dmitri", 5);

    // Dmitri has no outgoing edges

    // --- Dijkstra's Algorithm Initialization ---
    VertexState state[numVertices];
    for (int i = 0; i < numVertices; i++) {
        state[i].name = vertices[i];
        state[i].distance = INF;
        state[i].visited = false;
    }

    // Set starting vertex (e.g., "Ali" at index 0)
    state[0].distance = 0;

    cout << "Running Dijkstra starting from: " << state[0].name << "\n\n";

    // --- Main Dijkstra Loop ---
    for (int count = 0; count < numVertices - 1; count++) {
        // Step A: Find the unvisited vertex with the minimum distance
        int minDistance = INF;
        int u = -1;

        for (int i = 0; i < numVertices; i++) {
            if (!state[i].visited && state[i].distance < minDistance) {
                minDistance = state[i].distance;
                u = i;
            }
        }

        // If we can't find a reachable vertex, break
        if (u == -1) break;

        // Mark the chosen vertex as visited
        state[u].visited = true;

        // Step B: Traverse the custom linked list of neighbors for vertex `u`
        Vertex* currentEdge = adjList[u];
        while (currentEdge != NULL) {
            string destinationName = currentEdge->dest;
            int edgeWeight = currentEdge->weight;

            // Find the index of the destination vertex in our array
            int v = -1;
            for (int i = 0; i < numVertices; i++) {
                if (state[i].name == destinationName) {
                    v = i;
                    break;
                }
            }

            // Relaxation Step
            if (v != -1 && !state[v].visited) {
                if (state[u].distance + edgeWeight < state[v].distance) {
                    state[v].distance = state[u].distance + edgeWeight;
                }
            }

            // Move to the next neighbor in the linked list
            currentEdge = currentEdge->next;
        }
    }

    // --- Display Results ---
    cout << "Vertex\tShortest Distance from " << state[0].name << "\n";
    for (int i = 0; i < numVertices; i++) {
        cout << state[i].name << "\t";
        if (state[i].distance == INF) {
            cout << "INF" << endl;
        } else {
            cout << state[i].distance << endl;
        }
    }

    // Cleanup memory
    for (int i = 0; i < numVertices; i++) {
        Vertex* current = adjList[i];
        while (current != NULL) {
            Vertex* temp = current;
            current = current->next;
            delete temp;
        }
    }

    return 0;
}