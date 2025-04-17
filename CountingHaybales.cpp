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
  sort(a.begin() , a.end());

  auto atMost = [&](ll x) {
    int l = 0 , r = n-1;
    int mid = 0;
    while(l < r){
      mid = l + (r - l)/2; // mid = (l + r)/2;
      if(a[mid] >= x){
        r = mid;
      }else{
        l = mid +1;
      }
    }
    return r;
  };


  for(int i =0 ; i < q; i++){
    ll left, right; cin >> left >> right;
    cout << atMost(right) - atMost(left -1) << "\n";
  }
}


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while(t--){
    solve();
  }
}
