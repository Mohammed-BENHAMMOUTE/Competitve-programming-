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
    int a,b,c,d;
    cin >> a >> b >> c >>d;
    int sum1 = a, sum2 = c;
    int ans =0;
    if(a<= c) {
        while(sum1 <= sum2) {
            if(sum1+b <= sum2){
                sum1+=b;
                ans = sum1;
            }else{
                ans = sum2;
                break;
            }
            if(sum2-d>=sum1){
                sum2-=d;
                ans = sum2;
            }else{
                ans = sum1;
                break;
            }
        }
        cout << ans <<endl;
    }else{
        cout << a<<endl;
    }
    return;
}

int main()
{
    fastio();
    solve();

    return 0;
}