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
    string x, y;
    cin >> x >> y;
    bool flag  = false;
    int i = 0;
    string ans = "";
    while(i < x.size()) {
        if(!flag) {
            if(x[i] - '0' > y[i]-'0') {
                flag = true;
            }
            if(x[i] - '0' < y[i]-'0') {
                char temp = x[i];
                x[i] = y[i];
                y[i] = temp;
                flag = true;
            }
            
        }else{
            if(x[i] - '0' > y[i]-'0') {
                char temp = x[i];
                x[i] = y[i];
                y[i] = temp;
            }
        }
        i++;
    }
    cout << x << endl << y << endl;
    
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