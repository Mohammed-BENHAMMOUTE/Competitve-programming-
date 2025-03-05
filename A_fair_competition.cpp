#include<bits/stdc++.h>
using namespace std;
class  DSU {
public:
    vector<int> parent, Size;
    DSU(int n) {
        parent.resize(n);
        Size.resize(n , 1);
        for (int i =0 ; i < n ;i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    bool unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px ==py) return false;
        if (Size[px] < Size[py]) {
            swap(px , py);
        }
        parent[py] = px;
        Size[px] += Size[py];
        return true;
    }
};

void solve() {
    int n , m; cin >> n >> m;
    DSU dsu(n);
    for (int i =0 ; i < m; i++) {
        int x, y; cin >> x >>y;
        x--;y--;
        dsu.unite(x , y);
    }
    unordered_set<int> s;
    vector<int> sizes;
    long long answer = 0;
    for (int i = 0; i < n; i++) {
       int temp = dsu.find(i);
        if (s.find(temp) == s.end()) {
            s.insert(temp);
            sizes.push_back(dsu.Size[temp]);
        }
    }
    for (int i =0 ; i < sizes.size() ; i++) {
        for (int j = i+1 ; j < sizes.size();j++) {
            answer+=sizes[i] * sizes[j] * 2;
        }
    }
    cout << answer << endl;
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t =1; cin >> t;
    while (t--) {
        solve();
    };
    return 0;
}
