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

static int dist(int a , int b, int c , int d){
    return abs(a-d)+ abs(b-d) + abs(c-d);
}

void solve() {
    int a , b , c; 
    cin >> a >> b >> c;
    int ans = INT16_MAX;
    for(int i =1; i <=  10; i++) 
    {
        ans = min(ans, dist(a,b,c,i));
    };
    cout << ans << endl;

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