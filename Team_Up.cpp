#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"
using namespace std;

struct DSU {
    vector<int> par, size, sum;

    void init(int n) {
        par.resize(2*n + 1);
        size.resize(2*n + 1);
        sum.resize(2*n + 1);

        for(int i = 1; i <= n; i++) {
            par[i] = i + n;
            par[i + n] = i + n;
            size[i + n] = 1;
            sum[i + n] = i;
        }
    }

    int root(int a) {
        if(par[a] == a) return a;
        return par[a] = root(par[a]); // Path compression for better performance
    }

    void unite(int a, int b) {
        int root_a = root(a);
        int root_b = root(b);
        
        if(root_a == root_b) {
            return;
        }
        
        if(size[root_a] < size[root_b]) {
            par[root_a] = root_b;
            size[root_b] += size[root_a];
            sum[root_b] += sum[root_a];
        } else {
            par[root_b] = root_a;
            size[root_a] += size[root_b];
            sum[root_a] += sum[root_b];
        }
    }
    
    void move(int a, int b) {
        int root_a = root(a);
        int root_b = root(b);
        
        if(root_a == root_b) {
            return;
        }
        size[root_a]--;
        sum[root_a] -= a;
        par[a] = root_b;
        size[root_b]++;
        sum[root_b] += a;
    }
    
    int getSum(int x) {
        x = root(x);
        return sum[x];
    }
    
    int getSize(int x) {
        x = root(x);
        return size[x];
    }
};

void solve(int n, int q) {
    DSU dsu;
    dsu.init(n);
    
    for(int i = 0; i < q; i++) {
        int type;
        cin >> type;
        
        if(type == 1) {
            int x, y;
            cin >> x >> y;
            dsu.unite(x, y);
        } else if(type == 2) {
            int x;
            cin >> x;
            cout << dsu.getSize(x) << " " << dsu.getSum(x) << endl;
        } else if(type == 3) {
            int a, b;
            cin >> a >> b;
            dsu.move(a, b);
        }
    }
}

int main() {
    fastio;
    int t;
    cin >> t;
    while(t--) {
        int n, q;
        cin >> n >> q;
        solve(n, q);
    }
    return 0;
}