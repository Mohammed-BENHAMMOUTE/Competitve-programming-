#include<bits/stdc++.h>
using namespace std;

int Max (int N, int K, vector<int> arr) {
   
   
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int K;
    cin >> K;
    vector<int> arr(N);
    for(int i_arr = 0; i_arr < N; i_arr++)
    {
    	cin >> arr[i_arr];
    }

    int out_;
    out_ = Max(N, K, arr);
    cout << out_;
}