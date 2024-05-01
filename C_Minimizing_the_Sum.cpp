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
    int n, k;
    cin >> n >> k;
    int min = 1e9 + 7;
    int minIndex = 0;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if(v[i] < min){
            min = v[i];
            minIndex = i;
        }
    }
    int left = minIndex - 1;
    int right = minIndex + 1;
    while(k >0 && left>=0 && right < n){
        if(v[left] > v[right]){
            v[left] = min;
            left--;
        } else {
            v[right] = min;
            right++;
        }
        k--;
    };
    while(k > 0 && left >= 0){
        v[left] = min;
        left--;
        k--;
    };
    while(k > 0 && right < n){
        v[right] = min;
        right++;
        k--;
    };
    int sum =0;
    for(int i = 0 ; i < n; i++){
        cout << v[i] << " ";
        sum+=v[i];
    }
    // print the array to verify
    
    cout << sum << endl;
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