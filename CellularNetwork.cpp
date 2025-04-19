#include <algorithm>
#include <bits/stdc++.h>
#include <unistd.h>
#include <vector>
using namespace std;
typedef long long ll;

// we need to find the first true 






void solve()
{
  int n, m; 
  cin >> n >> m;
  vector<ll> cities(n);
  vector<ll> towers(m);
  for(int i =0 ; i < n ; i++)
  {
    cin >> cities[i];
  };
  for(int j  = 0; j < m ; j++) 
  {
    cin >> towers[j];
  }
  // TODO: we need to find r such that the coverage is maximum.
  ll minCity = *min_element(cities.begin(), cities.end());
  ll maxCity = *max_element(cities.begin(), cities.end());
  auto can = [&](int r) {
    // Check if with current radius r, we can cover all cities
    for(ll x : cities) {
        auto it = lower_bound(towers.begin(), towers.end(), x);
        bool found = false;
        
        // Check tower ahead of or at city
        if(it != towers.end() && abs(*it - x) <= r) {
            found = true;
        }
        
        // Check tower before city
        if(it != towers.begin()) {
            auto previous = it - 1;
            if(abs(*previous - x) <= r) {
                found = true;
            }
        }
        
        if(!found) {
            return false;
        }
    }
    return true;
  };
  ll l = 0 , r = 2e9;
  ll response = 0;
  while(l <= r){
    ll mid = l + ( r - l) /2;
    if(can(mid))
    {
      response = mid;
      r = mid - 1;
    }else{
      l = mid +1;
    }
  }
  cout << response << endl;
}


int main() 
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t = 1;
  // cin >> t;
  while(t-->0) {
    solve();
  }
}




