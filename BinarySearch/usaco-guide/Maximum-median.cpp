#include <bits/stdc++.h>
#include <functional>
#include <ostream>
using namespace std;


typedef long long ll ;


int last_true(ll l ,ll  r, function<bool(int)> f)
{
  l--;
  while(l < r)
  {
    int mid = l + (r -l + 1)/2;
    if(f(mid))
    {
      l = mid;
    }else{
      r = mid -1;
    }
  }
  return l;
}

int main()
{
  ll n , k; cin >> n >>k;
  vector<ll> a(n);
  for(int i =0 ; i < n ; i++)
  {
    cin >> a[i];
  };
  sort(a.begin() , a.end());
  auto f = [&](ll x) -> bool
  {
    int mid = (n-1)/2;
    ll sum =0;
    for(int i = mid ; i < n; i++)
    {
        sum+= max((ll)0 , (ll)x - a[i]);
    };
    return sum <= k;
  };
  cout << last_true(0 , 2e9 , f) << endl;
  return 0;
};
