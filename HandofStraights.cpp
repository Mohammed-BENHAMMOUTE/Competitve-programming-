#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) return false;
        if(groupSize == 1) return true;
        map<int, int> freq;
        for(int x : hand){
            freq[x]++;
        }
        while(!freq.empty()){
            int first  = freq.begin()->first;
            for(int i = 0; i < groupSize ;i++) {
                int current = first + i;
                if(freq.find(current)  == freq.end()){
                    return false;
                }
                freq[current]--;
                if(freq[current] == 0) {
                    freq.erase(current);
                }
            }
            
        }
        return true;
    }
};