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
    int n;
    cin >> n;
    vector<ll> arr(n);
    unordered_set<ll> s;
    ll pre = 0;
    int count = 0;
    for (int j = 0; j < n; ++j) {
        cin >> arr[j];
        if(pre == arr[j]){
            count++;
            pre+=arr[j];
        }else{
            pre += arr[j];
            if(s.find(pre) != s.end()){
                count++;
            }
        };
        s.insert(2*arr[j]);
    };
    cout << count << endl;
    

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