#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

const int MAX { 1000005 };
vector<int> aux[MAX];

vector<int> occurrenceLocation(int n, const vector<int> &list, const vector<ii> &occurrence) {
    for (int i = 0; i < MAX; i++) {
        aux[i].clear();
    }

    for (int i = 1; i <= n; i++) {
        aux[list[i]].push_back(i);
    }

    vector<int> ans;

    for (auto [k, v] : occurrence) {
        ans.push_back(k <= aux[v].size() ? aux[v][k - 1] : 0);
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);

    int n, m;

    while (cin >> n >> m) {
        vector<int> list(n + 1);
            vector<ii> occurrence(m);

            for (int i = 1; i <= n; i++) {
                cin >> list[i];
            }

            for (int i = 0; i < m; i++) {
                cin >> occurrence[i].first >> occurrence[i].second;
            }

            auto answer = occurrenceLocation(n, list, occurrence);

            for (auto a : answer) {
                cout << a << "\n";
            }
    }

    return 0;
}

