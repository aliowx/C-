#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define V 4

void floydWarshall(int graph[V][V]) {
    int dist[V][V];


    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i == j) {
                dist[i][j] = 0;  
            } else if (graph[i][j] != 0) {
                dist[i][j] = graph[i][j];  
            } else {
                dist[i][j] = INT_MAX;  
            }
        }
    }


    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }


    cout << "Shortest distances between every pair of vertices:" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INT_MAX) {
                cout << "INF ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main() {

    int graph[V][V] = {
        {0, 3, 0, 5},
        {3, 0, 4, 0},
        {0, 4, 0, 2},
        {5, 0, 2, 0}
    };


    floydWarshall(graph);
    return 0;
}
