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
    int n,m;cin >> n >> m;
    vector<string> a;
    vector<int> ak;
    for(int i= 0; i < n; i++){
        string x;cin >> x;
        a.pb(x);
        int temp = 0;
        for(char u : x){
            temp= (temp + (u-'0'))%3;
        }
        ak.pb(temp);
    };
    vector<string> b;  
    vector<int> bk; 
    for(int i = 0; i < n ; i++)
    {
        string x;cin >> x;
        b.pb(x);
        int temp = 0;
        for(char u : x)
        {
            temp = (temp + (u -'0'))%3;
        };
        
    };
    for(int i = )
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