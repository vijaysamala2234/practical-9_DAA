#include <iostream>
using namespace std;

int main() {

    int n, e;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    int edges[20][3];

    cout << "Enter edges (vertex1 vertex2 weight):\n";

    for (int i = 0; i < e; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    int visited[20] = {0};

    // Start from vertex 0
    visited[0] = 1;

    int total = 0;

    cout << "\nEdges in MST:\n";

    // MST contains n-1 edges
    for (int count = 0; count < n - 1; count++) {

        int min = 999;
        int u = -1, v = -1;

        // Find smallest edge
        for (int i = 0; i < e; i++) {

            int a = edges[i][0];
            int b = edges[i][1];
            int weight = edges[i][2];

            // One vertex visited and other not visited
            if (visited[a] != visited[b]) {

                if (weight < min) {
                    min = weight;
                    u = a;
                    v = b;
                }
            }
        }

        // Add edge to MST
        cout << u << " - " << v << " = " << min << endl;

        total = total + min;

        // Mark both vertices
        visited[u] = 1;
        visited[v] = 1;
    }

    cout << "\nTotal cost = " << total << endl;

    return 0;
}
