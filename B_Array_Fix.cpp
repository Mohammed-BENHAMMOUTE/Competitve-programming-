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
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    };
    vector<int> b; 
    for(int i = 0; i<n ; i++){
        if(a[i]/10 != 0){
            if(a[i]%10 >= a[i]/10) {
                if(i <n-1 && a[i+1]/10 >= a[i]%10){
                    b.pb(a[i]/10);
                    b.push_back(a[i]%10);
                }
            }else{
                b.push_back(a[i]);
            };
        }
    };
    for(int i=0;i<b.size();i++)
    {
        cout << b[i] << " ";
    };
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