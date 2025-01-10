#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> a(n);
	for (int &i : a) { cin >> i; }

	// stores currently selected numbers
	multiset<int> taken;

	// cannot take both the first and second number
	taken.insert(max(a[0], a[1]));
    long long ans = max(a[0] ,a[1]);

    for(int i =2; i < n-1 ; i+=2) {
        int least_Taken = *taken.begin();
        if(least_Taken < min(a[i+1], a[i])) {
            ans -= least_Taken;
            ans+=(a[i+1]+a[i]);
            taken.erase(taken.begin());
            taken.insert(a[i]);
            taken.insert(a[i+1]);
        }else{
            ans+=max(a[i+1], a[i]);
            taken.insert(max(a[i+1], a[i]));
        }
    }
    cout <<ans<<endl;
    
}