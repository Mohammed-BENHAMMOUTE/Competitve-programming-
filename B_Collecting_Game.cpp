#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define tc     \
    ll tc;     \
    cin >> tc; \
    while (tc--)
#define pb push_back
#define mp make_pair
const ll MOD = 1e9 + 7;

void fastio()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
};
void solve()
{
    ll n;cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    };
    vector<int> b =a;
    sort(b.begin(), b.end());
    vector<int> x ;
    x.push_back(b[0]);
    for(int i = 1; i<n; i++) {
        x.push_back(x[i-1] + b[i]);
    };
    unique(b.begin(), b.end());
    map<int, int> m;
    for(int i =b.size(); i>=0; i--) {
        if(b[i] == b[n-1]){
            m[b[i]] = n-1;
        }else{
            if(m.find(b[i]) != m.end()) {
                continue;
            }
            m[b[i]] = i;
            int j = i+1;
            while(j < n) {
                if(x[j] >= b[i]) {
                    m[b[i]] += 1;
                    j++;
                } else {
                    break;
                }
            }
        }
    };
    for(int i = 0; i< n ; i++) {
        cout << m[a[i]] << " ";
    }
    cout << endl;
}

int main()
{
    fastio();
    ll t;
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        solve();
    }

    return 0;
}