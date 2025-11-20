#include <bits/stdc++.h>
    
using namespace std;
    
int solve(int n) {
    for (int m = 1; m < 1000; m++) {
        int a = (n * m) + 1;
        if (a <= 3) {
            continue;
        }
        for (int i = 2; i < a; i++) {
            if (a % i == 0) {
                return m;
            }
        }
    }
    return -1;
}
    
int main () {
    ios::sync_with_stdio(false);
    
    int n;
    cin >>n;
    
    auto a = solve(n);
    
    cout << a << "\n";
    
    return 0;
}