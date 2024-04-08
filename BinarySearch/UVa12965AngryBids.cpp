#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--){
        int p,c;
        cin>>p>>c;
        vector<int> P(p);
        vector<int> C(c);
        int min = p+c;
        int Price = 0;
        for(int i = 0; i < p; i++){
            cin>>P[i];
        };
        for(int j = 0; j < c; j++){
            cin>>C[j];
        };
        sort(P.begin(),P.end());
        sort(C.begin(),C.end());
        for(int i = p-1; i >= 0 ; i--){
            int dist = distance(C.begin(),lower_bound(C.begin(),C.end(),P[i]));
            if(min > (p-i + dist)) continue;
            min = min < (p-i + dist) ? min : (p-i + dist);
            Price = P[i];
        };
        cout<<Price<<" "<<min<<endl;
    };
    cout << 0 << " " << 0 << endl;
    return 0;
};
