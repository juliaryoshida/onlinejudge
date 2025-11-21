#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAX { 100005 };

bitset<MAX> visited;
vector<ll> cost(MAX);
vector<int> friends[MAX];

ll dfs(int u, ll payment) {
    if (visited[u]) {
        return payment;
    }

    visited[u] = true;

    if (friends[u].empty()) {
        return cost[u];
    }

    for (auto v : friends[u]) {
        if (not visited[v]) {
            payment = min(payment, cost[v]);
            payment = dfs(v, payment);
        }
    }
    return payment;
}

ll connected_components(int n) {
    visited.reset();
    
    ll ans = 0;

    for (int u = 1; u <= n; u++) {
        if (not visited[u]) {
            ans += dfs(u, cost[u]);
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);

    int n, m;

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> cost[i];
    }

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        friends[a].push_back(b);
        friends[b].push_back(a);
    }

    auto total = connected_components(n);

    cout << total << "\n";

    return 0;
}