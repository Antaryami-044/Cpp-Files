#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <algorithm>
#include <utility>

using namespace std;

map<pair<int, int>, int> point_to_id;
vector<vector<int>> adj;
vector<bool> visited;
int vertex_count = 0;

int get_id(int x, int y) {
    if (point_to_id.find({x, y}) == point_to_id.end()) {
        point_to_id[{x, y}] = vertex_count++;
        adj.push_back({});
    }
    return point_to_id[{x, y}];
}

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int num_edges = 0;
    for (int i = 0; i < N; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int u = get_id(x1, y1);
        int v = get_id(x2, y2);
        adj[u].push_back(v);
        adj[v].push_back(u);
        num_edges++;
    }
    
    int num_vertices = vertex_count;
    visited.resize(num_vertices, false);

    int num_components = 0;
    for (int i = 0; i < num_vertices; ++i) {
        if (!visited[i]) {
            dfs(i);
            num_components++;
        }
    }

    int result = num_edges - num_vertices + num_components;
    cout << result << endl;

    return 0;
}