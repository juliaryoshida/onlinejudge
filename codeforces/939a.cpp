#include <bits/stdc++.h>

using namespace std;

bool isThereALoveTriangle(int n, const vector<int> &list) {
    for (int i = 1; i <= n; i++) {
        auto A = list[i];
        auto B = list[A];

        if (list[B] == i) {
            return true;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> list(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> list[i];
    }

    auto answer = isThereALoveTriangle(n, list);

    cout << (answer ? "YES" : "NO") << "\n";

    return 0;
}