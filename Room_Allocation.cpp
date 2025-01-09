#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n ;cin >> n;
    vector<pair<pair<int,int>,int>> events;
    for(int i = 0; i < n ; i++){
        int x, y; cin >> x >> y;
        events.push_back({{y,2}, i});
        events.push_back({{x, 1}, i});
    }
    sort(events.begin() , events.end());
    vector<int> ans(n);
    set<int> availableRooms;
    int currentRooms = 0;
    for(int i = 0 ; i < 2*n ; i++) {
        auto frt = events[i].first;
        if(frt.second == 1) {
            if(availableRooms.size() == 0){
                currentRooms++;
                ans[events[i].second] = currentRooms;
            }else{
                ans[events[i].second] = *availableRooms.begin();
                availableRooms.erase(availableRooms.begin());
            }
        }else{
            availableRooms.insert(ans[events[i].second]);
        };
    }
    cout << currentRooms << endl;
    for(int i = 0 ; i < n ; i++) {
        cout << ans[i] << " ";
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}