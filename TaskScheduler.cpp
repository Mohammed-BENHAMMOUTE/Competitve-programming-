#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;
struct task {
    char sym;
    int val;
    task(char sym, int val) : sym(sym), val(val) {}; 
};
struct compare1 {
    bool operator()(task* task1, task* task2) {
        return task1->val < task2->val;
    }
};
struct compare2 {
    bool operator()(task* task1, task* task2) {
        return task1->val < task2->val;
    }
};

// solution: 1. find the element with the maximal frequency, why?  A = ["A" , "A" , "A" , "B" , "B" , "B"]
// MAX COUNT  = 3, countMax  = 2 , n = 2

// A B - A B - A B

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
       vector<int> freq(26, 0);
       for(char x : tasks){
        freq[x-'A']++;
       }
       int maxCount = *max_element(freq.begin() , freq.end());
       int countMax = count(freq.begin() , freq.end(), maxCount);
       int ans = (maxCount - 1)*(n+1) + countMax;
       return max(ans,(int)tasks.size());
    };
};
int main() {
    Solution s;
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    cout << s.leastInterval(tasks, 2) << endl;
}