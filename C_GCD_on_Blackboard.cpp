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
#define MAXN 100005
const ll MOD = 1e9 + 7;


long long prefixe[MAXN];
long long suffixe[MAXN];

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
     
}

void fastio()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
};


void solve() {
    int n; cin >> n;
    vector<long long> a(n);
    for(int i =0; i < n ; i++) {
        cin >> a[i];
    };


    prefixe[0] = a[0];
    suffixe[n-1] = a[n-1];
    for(int i = 1 ; i < n ; i++) 
    {
        prefixe[i] = gcd(prefixe[i-1], a[i]);
    };
    for(int i = n-2; i >=0; i--){
        suffixe[i] = gcd(suffixe[i+1],a[i]);
    };
    ll ans = max(prefixe[n-2], suffixe[1]);
    for(int i = 0; i < n-1; i++)
    {
        ans = max(ans, gcd(prefixe[i-1], suffixe[i+1]));
    };
    cout << ans << endl;
    return;
};


int main()
{
    fastio();
    solve();
    return 0;
}