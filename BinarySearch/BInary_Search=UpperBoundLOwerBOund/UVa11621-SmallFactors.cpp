#include<bits/stdc++.h>
using namespace std;
int Next23(int m, vector<int> v){
    auto k = upper_bound(v.begin(),v.end(),m-1);
    cout << *k << endl;
    return 0;
};
int main() {
    int n;
    vector<int> v;
    long long i = 0;
    long long j = 0;
    for(int i = 0;  i <= 31 ; i++){
        for(int j = 0; j <= 31 && i+j<=31; j++){
            v.push_back(pow(2,i)*pow(3,j));
        }
    }
    sort(v.begin(),v.end());
    while(cin >> n){
        if( n== 0){
            break;
        };
        Next23(n , v);
    };
    return 0;
}
