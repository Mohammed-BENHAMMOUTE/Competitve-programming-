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

// void solve()
// {

// };
static ll C(int n, int k){
    double res = 1;
    for(int i = 1; i <= k; ++i) {
        res*=(double) (n-k+i)/i;
    };
    return (ll)(res+0.01);
};

int gcd(int a, int b) {
    if(b == 0) {
        return a;
    }else{
        return gcd(b, a%b);
    };
};

int main()
{
    fastio();
    int n;
    while(cin >> n && n!= 0) {
        vector<int> v(n);
        for(int i = 0; i < n ; i++) {
            cin >> v[i];
        };
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int  j = i+1; j < n ; j++){
                if(gcd(v[i],v[j]) == 1){
                    count++;
                };
            };
        };
        if(count == 0) {
            cout <<"No estimate for this data set." <<endl;
        }else{
            ll tot = C(n,2);
            long double res = sqrt(6.0 * tot / count);
            cout << fixed << setprecision(6) << res <<endl;
        }
    }
    return 0;
}