#include <bits/stdc++.h>

using namespace std;

const int MAX { 1001 };
bitset<MAX> visited;

int dfs(int u, vector<int> &adj) {
    if (visited[u]) {
        return u;
    }
    
    visited[u] = true;

    int v = adj[u];
    return dfs(v, adj);
}

int main() {
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> adj(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> adj[i];
    }

    for (int i = 1; i <= N; i++) {
        visited.reset();
        auto a = dfs(i, adj);
        cout << a << " ";
    }

    cout << "\n";

    return 0;
}