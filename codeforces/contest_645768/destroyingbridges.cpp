#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

void solve(vector<ii> &c) {
    for (auto [x, y] : c) {
        if (y >= x - 1) {
            cout << 1 << "\n";
            continue;
        } 
        cout << x << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    vector<ii> c(t); 

    for (int i = 0; i < t; i++) {
        cin >> c[i].first >> c[i].second;
    }

    solve(c);

    return 0;
}