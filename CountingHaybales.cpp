#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;



void solve() 
{
  int n , q; cin >> n >> q;
  vector<ll> a(n);
  for(ll& x : a)
  {
    cin >> x;
  };
  auto atMost = [&] (int x)
  {
    int l = 0, r = n-1;
    int result = -1;
    while(l <= r)
    {
      ll mid = l + (r - l)/2;
      if(a[mid] <= x){
        result = mid;
        l = mid + 1;
      }else{
        r = mid - 1;
      }
    }
    return (result == -1 ? 0 : result + 1);
  };
  sort(a.begin() , a.end());
  for(int i = 0; i < q; i++) 
  {
    int left, right; cin >> left >> right;
    cout << atMost(right) - atMost(left - 1) << endl;
  }
}


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  while(t--){
    solve();
  }
}
