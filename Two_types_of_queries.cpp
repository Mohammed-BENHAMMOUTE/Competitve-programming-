#include<bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, size;
    DSU() {
        parent.resize(26);
        size.resize(26, 1);
        for (int i = 0; i < 26; i++) {
            parent[i] = i;
        }
    }

    int find(int a) {
        if (parent[a] == a) return a;
        return parent[a] = find(parent[a]);
    }

    bool unite(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa == pb) return false;
        if (size[pa] < size[pb]) {
            swap(pa, pb);
        }
        parent[pb] = pa;
        size[pa] += size[pb];
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    string s; cin >> s;
    int q; cin >> q;
    DSU d;
    vector<pair<int, int>> pairs;
    for (int j = 0; j < n/2; j++) {
        if (s[j] != s[n-j-1]) {
            pairs.emplace_back(s[j]-'a', s[n-j-1]-'a');
        }
    }
    int currentCost = 0;
    for (auto &p : pairs) {
        if (d.find(p.first) != d.find(p.second)) {
            currentCost++;
        }
    }

    while (q--) {
        int query; cin >> query;
        if (query == 1) {
            char x, y; cin >> x >> y;
            int xx = x - 'a';
            int yy = y - 'a';
            
            // Only need to recheck pairs if we're actually uniting different sets
            if (d.find(xx) != d.find(yy)) {
                d.unite(xx, yy);
                
                currentCost = 0;
                for (auto &p : pairs) {
                    if (d.find(p.first) != d.find(p.second)) {
                        currentCost++;
                    }
                }
            }
        } else {
            cout << currentCost << endl;
        }
    }
    return 0;
}