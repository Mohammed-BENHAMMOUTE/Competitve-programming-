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
    int k, q;
    cin >> k >> q;
    vector<int> A(k);
    for(int i = 0 ; i < k ; i++){
        cin >> A[i];
    };
    vector<int> B(q);
    for(int i =0; i<q; i++){
        cin >> B[i];
    };
    for(int x : B) {
        vector<int> C;
        for(int i = 0; i < x ; i++){
            C.pb(i+1);
        };
        while(C.size() >= A[0]) {
            for(int y : A) {
                if(y<= C.size()) {
                    C.erase(C.begin() + y - 1);
                }else{
                    break;
                }
            }
        }
        cout << C.size() << " ";
    }   
    return; 
    cout << endl;
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