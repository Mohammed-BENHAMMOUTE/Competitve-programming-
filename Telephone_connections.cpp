#include<bits/stdc++.h>
using namespace std;

long long numberofConnections(long long n) {
    return (n*(n-1))/2;
}

vector<long long> MinMax (int A, int B) {
    long long mx = 0; 
    long long mn = 0;
    if(A % B == 0) {
        mx = numberofConnections(A - B + 1);
        mn = B * numberofConnections(A / B);
    } else {
        mx = numberofConnections(A - B + 1);
        mn = (A % B) * numberofConnections(A / B + 1);
        mn += (B - A % B) * numberofConnections(A / B);
    }
    return {mn, mx};
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int A;
    cin >> A;
    int B;
    cin >> B;

    vector<long long> out_;
    out_ = MinMax(A, B);
    cout << out_[0];
    for(int i_out_ = 1; i_out_ < out_.size(); i_out_++)
    {
        cout << " " << out_[i_out_];
    }
}