#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, edges;
    cin >> n >> edges;

    vector<vector<int>> adj(n);

    while (edges--) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);  // for undirected graph
    }

    cout << "Adjacency List:\n";
    for (int i = 0; i < n; i++) {
        cout << i << " -> ";
        for (int x : adj[i]) cout << x << " ";
        cout << endl;
    }
    return 0;
}
