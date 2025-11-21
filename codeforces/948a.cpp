#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

bool solve(int R, int C, vector<string> &M) {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (M[i][j] == 'S') {
                vector<ii> positions { {i - 1, j}, {i + 1, j}, {i, j - 1}, {i, j + 1} };
                for (auto [x, y] : positions) {
                    if (x < 0 || x >= R || y < 0 || y >= C) {
                        continue;
                    } 
                    if (M[x][y] == 'W') {
                        return false;
                    }
                    if (M[x][y] == '.') {                        
                        M[x][y] = 'D';
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);

    int R, C;

    cin >> R >> C;
    vector<string> M(R);

    for (int i = 0; i < R; i++) {
        cin >> M[i];
    }

    if (solve(R, C, M)) {
        cout << "Yes\n";
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cout << M[i][j];
            }
            cout << "\n";
        }
    } else {
        cout << "No\n";
    }

    return 0;
}