#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Graph represented using adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adjList[MAX_VERTICES];
int visited[MAX_VERTICES];

// Function to create a new adjacency list node
Node* createNode(int vertex) {
    //write your code here...
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;//write your code here...
    
    
    
}

// Function to add an edge to the graph
void addEdge(int u, int v) {
    //write your code here...
    //write your code here...
    Node* newNode = createNode(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;
    
    
    
    
    
}

// Function to sort the adjacency list for each vertex
void sortAdjList(int V) {
    //write your code here...
    //write your code here...
    for (int i = 0; i < V; i++) {
        Node* sorted = NULL;
        Node* current = adjList[i];

        while (current != NULL) {
            Node* next = current->next;

            // Insert current in sorted list
            if (sorted == NULL || current->vertex < sorted->vertex) {
                current->next = sorted;
                sorted = current;
            } else {
                Node* temp = sorted;
                while (temp->next != NULL && temp->next->vertex < current->vertex) {
}
