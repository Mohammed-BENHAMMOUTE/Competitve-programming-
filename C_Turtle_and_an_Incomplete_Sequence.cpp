#include <bits/stdc++.h>

using namespace std;
map<long long, vector<long long> > m;
long long n, k, ans, cnt;
void solve() {
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        long long x;
        cin >> x;
        m[x%k].push_back(x/k);
    }
    for (auto p:m) {
        int si=p.second.size();
        sort(p.second.begin(), p.second.end());
        if (si%2) {
            cnt++;
            if (si==1) continue;
            vector<long long> a, b;
            for (int i=1; i<si; i++) {
                long long val=p.second[i]-p.second[i-1];
                if (i%2) a.push_back(val);
                else b.push_back(val);
            }
            int sa=a.size();
            for (int i=1; i<sa; i++) {
                a[i]+=a[i-1];
            }
            for (int i=sa-2; i>=0; i--) {
                b[i]+=b[i+1];
            }
            long long mini=min(a[sa-1], b[0]);
            for (int i=0; i<sa-1; i++) {
                mini=min(mini, a[i]+b[i+1]);
            }
            ans+=mini;
        }
        else {
            for (int i=1; i<si; i+=2) {
                ans+=p.second[i]-p.second[i-1];
            }
        }
    }
    if (cnt>1) {
        cout << -1 << "\n";
    } else {
        cout << ans << "\n";
    }
    ans=0, cnt=0;
    m.clear();
}
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}
