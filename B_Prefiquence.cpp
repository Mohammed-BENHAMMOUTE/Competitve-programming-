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
static  pair<int,int> count01(string s) {
    int count0 = 0, count1 = 0;
    for(int i = 0; i<s.size(); i++){
        if(s[i] == '0') count0++;
        else count1++;
    };
    return {count0, count1};
}

void fastio()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void solve() {
    int n, m; cin >> n >> m;
    string a, b; cin >> a >> b;

    int max_k = 0;
    for(int i = 0, j = n - 1; j >= 0; --j) {
        string suba = a.substr(0, j - i + 1);
        if(suba.size() > m) continue;
        int inner_j = 0;
        for(int k = 0; k < m; ++k){
            
            if(b[k] == suba[inner_j]){
                ++inner_j;
            }
            
        };
        if(inner_j == suba.size()){
                cout << inner_j << endl;
                return;
        };
    }
    cout << max_k << endl;
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