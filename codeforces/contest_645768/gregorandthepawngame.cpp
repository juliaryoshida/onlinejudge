#include <bits/stdc++.h>
    
using namespace std;
    
int solve(int n, vector<string> &board) {
    int cont = 0; 
    
    for (int i = 0; i < n; i++) {
        if (board[1][i] == '1') {
            if (board[0][i] == '0') {
                cont++;
                continue;
            }
            if ((i - 1) < 0) {
                if (board[0][i + 1] == '1') {
                    cont++;
                    board[0][i + 1] = '0';
                    continue;
                }
            }
            if (board[0][i - 1] == '1') {
                cont++;
                board[0][i - 1] = '0';
                continue;
            }  
            if (board[0][i + 1] == '1') {
                    cont++;
                    board[0][i + 1] = '0';
                    continue;
            }
            if ((i + 1) > n) {
                continue;
            } 
        }
    }
    return cont;
}
    
int main() {
    ios::sync_with_stdio(false);
    int t;
    
    cin >> t;
    
    vector<int> answer(t);
    
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<string> board(n);
    
        for (int a = 0; a < 2; a++) {
            cin >> board[a];
        }
    
        answer[i] = solve(n, board);
    }
    
    for (int i = 0; i < t; i++) {
        cout << answer[i] << "\n";
    }
}