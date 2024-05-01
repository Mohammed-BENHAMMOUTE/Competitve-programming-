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
};

void solve()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
         cin>>a[i];
    };
    int front = 1;
    int back = 1;
    while(front < n && a[front] == a[front-1]){
        front++;
    };
    if(front == n){
        cout << -1 << endl;
        return;
    };

    while(back < n && a[n-back-1] == a[n-back]){
        back++;
    };
    int max =100000000;
    for(int i=front+1;i<n-back;i++){

        if(a[i] == a[0]) {
            int j = i;
            while(i<n-back && a[i] == a[0]){
                i++;
            };
            max = std::min(max, i-j);
        }
    };  
    int res =min(max, min(front,back));
    cout << res << endl;
    return;
};

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