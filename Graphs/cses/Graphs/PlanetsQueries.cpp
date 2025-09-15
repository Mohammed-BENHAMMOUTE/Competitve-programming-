#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q;
    cin >> n >> q;
    
    const int MAXLOG = 30;
    
    vector<vector<int>> lift(n + 1, vector<int>(MAXLOG));
    
    for (int i = 1; i <= n; i++) {
        cin >> lift[i][0];
    }
    
    for (int j = 1; j < MAXLOG; j++) {
        for (int i = 1; i <= n; i++) {
            lift[i][j] = lift[lift[i][j-1]][j-1];
        }
    }
    
    for (int query = 0; query < q; query++) {
        int x, k;
        cin >> x >> k;
        
        int current = x;
        
        for (int j = 0; j < MAXLOG; j++) {
            if (k & (1 << j)) {
                current = lift[current][j];
            }
        }
        
        cout << current << "\n";
    }
    
    return 0;
}
