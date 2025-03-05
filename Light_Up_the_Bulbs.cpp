#include<bits/stdc++.h>
using namespace std;
class DSU {
private:
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n,0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    };
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        };
        return parent[x];
    }
    bool  unionSet(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py) return false;

        if (rank[px] < rank[py]) {
            swap(px, py);
        }
        parent[py] = px;
        if (rank[px] == rank[py]) {
            rank[px]++;
        }
        return true;
    }
};


void solve() {
    int n ;cin >> n;
    vector<pair<int,int>> points(n);
    for (auto& x : points) {
        cin >> x.first >> x.second;
    }
    vector<tuple<int, int , int>> adj;
    for (int i =0 ; i < n ; i++) {
        for (int  j = i +1 ; j < n ; j++) {
            int dist = pow(points[i].first - points[j].first,2) + pow(points[i].second - points[j].second , 2);
            adj.push_back({dist , i , j});
        }
    }
    sort(adj.begin() , adj.end());
    int totalWeight = 0;
    DSU dsu(n);
    for (auto& [dist , u, v] : adj) {
        if (dsu.unionSet(u, v)) {
            totalWeight+=dist;
        }
    }
    printf("%d" , totalWeight);
    printf("\n");
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t =1;
    while (t--) {
        solve();
    };
    return 0;
}
