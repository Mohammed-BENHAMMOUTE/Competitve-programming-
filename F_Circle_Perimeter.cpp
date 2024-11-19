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
    int r;cin >> r;
    int height = r;
    int ans = 0;
    for(int i = 0; i <= r; i++){
        while( height*height + i*i >= (r+1)*(r+1)){
            height--;
        }
        int curr= height;
        while((curr*curr + i*i) >= r*r && curr > 0){
            ans++;
            curr--;
        }
    }
    cout<<ans*4<<endl;
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