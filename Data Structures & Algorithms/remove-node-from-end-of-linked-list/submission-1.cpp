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

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == nullptr){
            return nullptr;
        }

        int sz = 0;
        ListNode*itr = head;
        while(itr != nullptr){
            itr = itr->next;
            ++sz;
        }

        ListNode* prev = nullptr;
        ListNode* now = head;
        int idx = sz;
        while(true){
            ListNode* nxt = now->next;

            if(idx == n){
                if(prev == nullptr){
                    head = nxt;   
                } else {
                    prev->next = nxt;
                }
                break;
            }

            idx--;
            prev = now;
            now = nxt;
        }

        return head;
    }
};
