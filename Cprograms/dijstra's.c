// Satyam Bhardwaj
// 5, CSE, 2nd year
// Design and Analysis of Algorithm Lab
#include <limits.h> 
#include <stdio.h> 
#include <stdbool.h>
#define V 5 
void dijkstra(int graph[V][V], int src); 
int minD(int dist[], bool sptSet[]);
  
int main() 
{ 
    int graph[V][V] = { { 0, 0, 0, 7, 1},
                        { 3, 0, 8, -4, 0},
                        { 4, 0, 0, 0, -5},
                        { 0, 0, 0, 0, 6},
                        { 0, 2, 0, 0, 0},
                        }; 
    dijkstra(graph, 0); 
  
    return 0; 
}
  
int minD(int dist[], bool sptSet[]) 
{ 
    int min = INT_MAX, min_index; 
  
    for (int v = 0; v < V; v++) 
        if (sptSet[v] == false && dist[v] <= min) 
            min = dist[v], min_index = v; 
  
    return min_index; 
} 
  
  
void dijkstra(int graph[V][V], int src) 
{ 
    int dist[V]; 
    // distance from src to i 
  
    bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest 
    // path tree or shortest distance from src to i is finalized 
  
    // Initialize all distances as INFINITE and stpSet[] as false 
    for (int i = 0; i < V; i++) 
        dist[i] = INT_MAX, sptSet[i] = false; 
  
    // Distance of source vertex from itself is always 0 
    dist[src] = 0; 
  
    // Find shortest path for all vertices 
    for (int count = 0; count < V - 1; count++) { 
        int u = minD(dist, sptSet); 
  
        sptSet[u] = true; 
  
        for (int v = 0; v < V; v++) 
  
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v]) 
                dist[v] = dist[u] + graph[u][v]; 
    } 
  
    // print the constructed distance array 
    printf("Source vertex is vertex 1.\n"); 
    for (int i = 0; i < V; i++) 
        printf("Distance of %d vertex from source is %d\n", i+1, dist[i]); 
 
} 
  
