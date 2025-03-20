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
   int n , t; cin >> n >>t;
   vector<ll> a(n);
   for(int i  =0 ; i < n ; i++) {
    cin >> a[i];
   }
//    vector<int> pref(n);
//    pref[0] = a[0];
//    for(int i = 1 ; i < n ; i++) {
//     pref[i] += pref[i-1];
//    }

// we need interval with max sum less that t ?
// we need to use two pointers techniques 
   int  left = 0;
   int right = 0;
   int ans = 0;
   int curr = 0;
   while(left < n  && right < n) {
    while(right < n){
        curr += a[right++];
        if(curr > t) {
            curr -= a[--right];
            break;
        }
    }
    ans = max (ans , right - left);
    curr -= a[left++];
   }
   cout << ans << endl;
}

int main()
{
    fastio();
    solve();
    return 0;
};
