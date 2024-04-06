#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i <n ;i++){
        cin >> a[i];
    }
    k = min(n, k);
    int last = n-1;
    for(int _ =0; _<k; _++){
        if(a[last] > n){
            cout << "No\n";
            return;
        }else{
            last += n-a[last];
            last = last%n;
        }
    }
    cout << "Yes\n";
    return;
};
int main() {
    int z;
    cin >> z;
    while(z-->0){
        solve();
    };
    return 0;
}