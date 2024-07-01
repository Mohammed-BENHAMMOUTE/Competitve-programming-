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
ll divisable(ll x, ll y){
    while(x%y==0){
        x/=y;
    };
    return x;
};
ll smallestPowOfY(ll x , ll y){
    ll ans =y;
    while(ans< x){
        ans*=y;
    };
    return ans;
};

void solve()
{
    ll x, y, k; cin >> x >>y >> k;
    ll ans = smallestPowOfY(x, y);
    ll temp = x +k;
    if(temp >= ans)
    {
       k -= ans - x;
    }else{
        cout << temp << endl;
        return;
    };
    ll  ans2 = divisable ans, y);
    ll res = ans2+(k%y);
    cout << res << endl;
    
    
    
    

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