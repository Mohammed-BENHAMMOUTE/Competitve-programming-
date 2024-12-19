#include<bits/stdc++.h>
using namespace std;


class ConstructStringWithRepeatLimit
{
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int freq[26] = {0};
        // Count frequency 
        priority_queue<char> pq;

        for(const char& x  : s){
            freq[x-'a']++;
        }

        for(int i =0 ; i < 26 ; i++){
            if(freq[i]){
                pq.emplace('a' + i);
            };
        };

        string ans;
        ans.reserve(s.size());
        while(!pq.empty()){
            char c = pq.top();
            pq.pop();
            int f= freq[c -'a'];
            int use = min(f, repeatLimit);
            ans.append(use, c);
            freq[c-'a']-=use;
            if(freq[c-'a'] > 0) {
                if(pq.empty()){
                    break;
                }
                char nx = pq.top();
                ans.push_back(nx);
                freq[nx-'a']--;
                if(freq[nx-'a'] == 0){
                    pq.pop();
                }
                pq.emplace(c);
            };
        };
        return ans;
    }
};

