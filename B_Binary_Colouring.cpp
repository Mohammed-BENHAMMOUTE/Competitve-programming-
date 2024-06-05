#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll x; cin >> x;
    vector<int> a(32);
    int n = 0;

   for(int i = 0; x!=0; i++) {
        n++;
        if(x&1 == 1) 
        {
            a[i] = 1;
            x>>=1;
            if((x&1) == 1){
                a[i] = -1;
                x++;
            };
        }else{
            x>>=1;
        };
    };
    cout << n << endl;
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    };
    cout << endl;
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t; cin >> t;
    for (int test = 0; test < t; ++test) {
        solve();
    }
    return 0;
}