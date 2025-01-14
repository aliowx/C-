#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;


typedef pair<int, int> Edge; 

void dijkstra(int source, vector<vector<Edge>>& graph, int vertices) {

    vector<int> distance(vertices, INT_MAX);
    distance[source] = 0;


    priority_queue<Edge, vector<Edge>, greater<Edge>> pq; 
    pq.push({0, source});

    while (!pq.empty()) {
        int currentDistance = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();


        for (const Edge& edge : graph[currentNode]) {
            int weight = edge.first;
            int neighbor = edge.second;


            if (currentDistance + weight < distance[neighbor]) {
                distance[neighbor] = currentDistance + weight;
                pq.push({distance[neighbor], neighbor});
            }
        }
    }


    cout << "Shortest distances from node " << source << ":\n";
    for (int i = 0; i < vertices; i++) {
        cout << "Node " << i << ": " << distance[i] << endl;
    }
}

int main() {
    int vertices = 5; 
    vector<vector<Edge>> graph(vertices);


    graph[0].push_back({10, 1});
    graph[0].push_back({3, 2});
    graph[1].push_back({1, 2});
    graph[1].push_back({2, 3});
    graph[2].push_back({8, 3});
    graph[3].push_back({7, 4});
    graph[2].push_back({4, 4});

    int source = 0; 
    dijkstra(source, graph, vertices);

    return 0;
}
