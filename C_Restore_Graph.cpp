#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define pb push_back
#define F first
#define S second
#define rep(i,a,b) for(int i=a; i<b; i++)

const int MAXN = 1e5 + 5;

int n, k;
int d[MAXN], deg[MAXN];
vi v[MAXN];
vector<pii> ans;

void solve() {
    cin >> n >> k;
    rep(i,1,n+1) {
        cin >> d[i];
        v[d[i]].pb(i);
    }

    if (v[0].size() != 1) {
        cout << "-1\n";
        return;
    }

    rep(i,1,n+1) {
        if (v[i].empty()) continue;
        if (v[i-1].empty()) {
            cout << "-1\n";
            return;
        }
        int idx = 0;
        for (int u : v[i]) {
            int w = v[i-1][idx];
            ans.pb({u, w});
            deg[u]++; deg[w]++;
            idx = (idx + 1) % v[i-1].size();
        }
    }

    rep(i,1,n+1) {
        if (deg[i] > k) {
            cout << "-1\n";
            return;
        }
    }

    cout << ans.size() << "\n";
    for (auto e : ans) {
        cout << e.F << " " << e.S << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    
    return 0;
}