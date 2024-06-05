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
static ll binPow(ll b, ll p , int m){
    b%=m;
    ll res = 1;
    while(p >0) {
        if(p&1)
        {
            res= res*b%m; 
        };
        b = b * b %m;
        p>>=1;
    }
    return res;
};
void fastio()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int main()
{
    fastio();
    ll b, p;
    int m;
    while(cin >> b) 
    {
        cin >> p >> m;
        cout << binPow(b,p,m) << endl;
        if(cin.peek() == '\n'){
            cin.ignore();
        };
    };
    return 0;
}