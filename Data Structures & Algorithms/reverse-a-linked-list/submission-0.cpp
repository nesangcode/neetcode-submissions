/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* res = head;
        ListNode* prev = nullptr;
        if(res == nullptr){
            return res;
        }

        while(true){
            ListNode* nxt = res->next;
            res->next = prev;
            
            if(nxt == nullptr) break;
            prev = res;
            res = nxt;
        }

        return res;
    }
};
