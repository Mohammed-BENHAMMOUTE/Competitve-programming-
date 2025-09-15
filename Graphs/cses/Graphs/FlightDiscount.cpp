#include<bits/stdc++.h>
using namespace std;

void solve() {
  int n,m; cin >> n >> m;
  vector<vector<pair<int,int>>> graph(n+1);
  for (int i =0 ; i <m ; i++) {
    int a, b, c; cin >> a >> b >> c;
    graph[a].push_back({b, c});
  } 

 // coupon not used = 0, coupon used 1 
  vector<vector<long long>> dist(n+1, vector<long long> (2, LLONG_MAX));
  priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<>> pq; 

  dist[1][0] = 0;
  pq.push({0, 1, 0});

  while(!pq.empty()) {
    auto [current_dist, city, used_coupon] = pq.top();
    pq.pop();

    if (current_dist > dist[city][used_coupon]) continue;

    for (auto [next_city, flight_cost] : graph[city]) {
      long long new_dist = current_dist + flight_cost;
      // take the flight without using coupong
      if(new_dist < dist[next_city][used_coupon]) {
        dist[next_city][used_coupon] = new_dist;
        pq.push({new_dist, next_city, used_coupon});
      }

      // use the coupon if you can:
      if (used_coupon == 0) {
        long long discounted_cost = flight_cost / 2;
        long long new_dist_with_coupon = current_dist + discounted_cost;

        if (new_dist_with_coupon < dist[next_city][1]) {
          dist[next_city][1] = new_dist_with_coupon;
          pq.push({new_dist_with_coupon, next_city, 1});
        }
      }
    }
  }
  long long result = min(dist[n][0], dist[n][1]);
  cout << result << endl;
  return;
}



int main() {
  solve();
  return 0;
}
