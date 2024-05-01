#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    while(t--){
        long long n,k;
        cin>>n>>k;
        deque<long long> a(n);
        int sum;
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum += a[i]; 
        };
        if(k >= sum){
            cout << n << endl;
            continue;
        };
        while(k>0) {
            int min = std::min(a.front(),a.back());
            if(k <min) {
                cout << a.size() << endl;
                break;
            }else{
                a.front() -= min;
                a.back() -= min;
                if(a.front() == 0){
                    a.pop_front();
                };
                if(a.back() == 0){
                    a.pop_back();
                };
            };
            k -= min;
        };
        cout << n - a.size() << endl;

    }
    return 0;
}