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
}

void solve()
{
    int n; cin >> n;
    vector<ll> sm(n);
    for(int i = 0; i < n ; i++) {
        cin >> sm[i];
    };
    
    vector<int> pre(n, 1);
    vector<int> suff(n, 1);
    for(int i = 1; i < n; i++) {
        if(sm[i-1] < sm[i]){
            pre[i] = 1+ pre[i-1];
        }
    };
    cout <<endl;
    auto max_iter = std::max_element(pre.begin(), pre.end());
    int ans = *max_iter;
    for(int i = n-2; i >=0; i--) 
    {
        if(sm[i] < sm[i+1]){
            suff[i] = suff[i+1] + 1;
        }
    };
    cout << endl ;
    for(int i =1 ; i <= n-2; i++) {
        if(sm[i-1] < sm[i+1])
        {
            ans = max(ans, pre[i-1] + suff[i+1]);
        }
    };
    cout <<ans << endl;
}

int main()
{
    fastio();
    solve();

    return 0;
}