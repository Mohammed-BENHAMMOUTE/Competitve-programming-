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
    
    int n ; cin >> n;
    if( n ==1) {
        cout << 1 << " " << 1 << endl;
        cout << 1 << " " << 1 << " 1"<<  endl;
        return;
    };
    if(n == 2) {
        cout <<"7 3"<<endl;
        cout <<"1 1 1 2"<<endl;
        cout <<"1 2 1 2"<<endl;
        cout <<"2 1 1 2"<<endl;
        return;
    }
    string s;
    for(int i = 1 ; i <= n ; i++){
        s += to_string(i) + " ";
    };
    int help = n*(n+1)/2;
    int res = 0;
    int start =1;
    for(int i = 1; i < 2*n ; i+=2){
        res+= start *i;
        start++; 
    };
    int ops =2*n;
    cout << res << " " << ops << endl;
    for(int i =0 ; i < n ; i++) {
        cout << 1<< " " << n-i << " "<< s<<endl;
        cout << 2 << " " << n-i <<" " <<s<<endl;
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