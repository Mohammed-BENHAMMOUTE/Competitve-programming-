#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"
using namespace std;

class Solution {
public:
    int longestSuccessiveElements(vector<int>&a) {
        int n = a.size();
        sort(a.begin() , a.end());
        auto last = unique(a.begin() , a.end());
        a.erase(last , a.end());
        int currentCount = 1;
        int maxCount = 1;
        for(int i =0 ; i < n;i++){
            int temp = i + 1;
            while(temp < n && (a[temp] - a[temp-1]) ==1){
                currentCount++;
                temp++;
            }
            maxCount = max(maxCount , currentCount);
            currentCount = 1;
            i = temp -1;
        }
        return maxCount;
    }
    // second upraoch using HashSet
    int longestSuccessiveElementsII(vector<int>&a) {
        int n = a.size();
        unordered_set<int> us(a.begin() , a.end());
        int currentCount;
        int maxCount = 1;
        for(int num  : a) {
            // check if its the start of a sequence
            if(us.find(num -1) == us.end())
            {
                currentCount =1;
                int temp = num;
                while(us.find(temp+1) != us.end()){
                    currentCount++;
                    temp++;
                }
                maxCount = max(maxCount , currentCount);
            }
        }
        return maxCount;
    }
};