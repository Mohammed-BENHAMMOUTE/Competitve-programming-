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
    int n, f, k; cin >> n >> f >> k;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    };
    int fav = a[f];
    // sort(a.begin(), a.end(), greater<int>());
    // int pos = lower_bound(a.begin(), a.end(), fav, greater<int>()) - a.begin();
    // int cnt = count(a.begin(), a.begin() + pos, fav);
    // if(pos - cnt < k){
    //     cout << "YES" << endl;
    // }else if(pos < k){
    //     cout << "MAYBE" << endl;
    // }else{
    //     cout << "NO" << endl;
    // }
    int greater = 0;
    int equal = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] > fav){
            greater++;
        }else if(a[i] == fav ){
            equal++;
        }
    };
    if(greater >= k){
        cout << "NO" << endl;
        return;
    };
    if(greater+equal <= k){
        cout << "YES" << endl;
    }else if(greater + equal > k){
        cout << "MAYBE" << endl;
    }
    return;
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