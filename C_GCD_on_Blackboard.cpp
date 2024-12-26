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


// long long prefixe[MAXN];
// long long suffixe[MAXN];

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
    vector<ll> a(n);
    for(int i = 0; i < n ; i++) {
        cin >> a[i];
    };
    vector<ll> prefixe(n+1, 0);
    vector<ll> suffixe(n+1, 0);
    for(int i =1 ; i <= n; i++) {
        prefixe[i] = gcd(a[i-1], prefixe[i-1]);
    };
    for(int i =n-1 ; i >=0 ; i--) {
        suffixe[i] = gcd(suffixe[i+1], a[i]);
    };

    ll ans = 0;
    int ind = -1;
    for(int i =1; i <= n; i++) {
        if(ans < gcd(prefixe[i-1], suffixe[i+1])){
            ans = gcd(prefixe[i-1], suffixe[i+1]);
            ind  = i -1;
        }
    };
    cout << ans <<endl;
    for(int i = 0; i < n ; i++){
        if(i!= ind){
            cout << a[i] << " ";
        }else{
            cout << ans << " ";
        }
    }
};


int main()
{
    fastio();
    solve();
    return 0;
}