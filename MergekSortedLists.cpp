#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
        
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for (auto list : lists) {
            if (list) {
                pq.push(list);
            }
        }
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            tail->next = node;
            tail = tail->next;
            if (node->next) {
                pq.push(node->next);
            }
        }
        return dummy->next;
    }
};