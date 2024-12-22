#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;


bool checkValidArithmeticProgression( vector<int> v, int step) {
    int sz = v.size();
    for(int i = 1; i < sz ; i++){
        if(v[i] != v[i-1] + step){
            return false;
        }
    };
    return true;
}
int main()
{
    fastio;
    int n; cin >> n;
    vector<int> arr(n);
    map<int,vector<int>> m;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        m[arr[i]].push_back(i);
    };
    vector<pair<int,int>> ans;
    for(const auto& [x, y] : m){
        if(y.size() <=1) {
            ans.push_back({x, 0});
        }else{

            int min = *min_element(y.begin(), y.end());
            int max = *max_element(y.begin(), y.end());
            int step = (max -min)/(y.size()-1);
            if(checkValidArithmeticProgression(y, step)){
                ans.push_back(make_pair(x , step));
            }
        }
    };
    cout << ans.size() <<endl;
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    return 0;
};


