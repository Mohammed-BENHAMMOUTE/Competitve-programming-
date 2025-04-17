#include <bits/stdc++.h>
#include <climits>
#include <cstddef>
#include <ios>
#include <ostream>
#include <vector>
using namespace std;


typedef long long ll;



const int maxN = 1e5+5;
bool initialized = false;

vector<vector<int>> devisors(maxN);
void initialize() 
{
  if(!initialized){
     for(int i = 1 ; i < maxN; i++) 
    {
      for(int d = i ; d < maxN ; d+=i)
      {
        devisors[d].push_back(i);
      }
    }
  }
  initialized = true;
}

void solve() 
{
  int n , m; cin >> n >> m;
  vector<ll> a(n);
  for(ll& x : a){
    cin >> x;
  };
  sort(a.begin() , a.end());

  int count = 0 , left = 0;
  ll ans = LLONG_MAX, curr = 0;
  vector<int> b(m+1 , 0);
  for(int right =0 ; right < n ; right++) 
  {
    curr = a[right];
    for(int x : devisors[curr])
    {
      if(x <= m) {
        b[x]++;
        if(b[x] == 1) count++;
      }
    }
   
    while(count == m  && left <= right)
    {
      ans = min(ans , a[right] - a[left]);
      int currentleft = a[left++];
      for(int x : devisors[currentleft])
      {
        if( x <=  m)
        {
          b[x]--;
          if(b[x] == 0)
          {
            count--;
          }        
        }
      }
    };
  }
  if(ans == LLONG_MAX){
    cout<< "-1\n" ;
  }else{
    cout << ans <<endl;
  }
};

int main() 
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  initialize();

  int t =2;
  cin >> t;
  while(t--) 
  {
    solve();
  }
}
