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
    int countSize(ListNode* head){
        int sz = 0;

        while(head!=nullptr){
            ++sz;
            head = head->next;
        }
        return sz;
    }

    void reorderList(ListNode* head) {
        int sz = countSize(head);

        int idx = 1;
        ListNode* ptr = head;
        ListNode* prev = nullptr;
        
        while(ptr!=nullptr){
            ListNode* nxt=ptr->next;
            if(idx > sz/2){
                ptr->next = prev;
            }
            prev = ptr;
            ptr = nxt;
            idx++;
        }

        ListNode* h = head;
        ListNode* tail = prev;

        while(true){
            ListNode* nh = h->next;
            if(h==nullptr||tail==nullptr) break;
            if(h==tail){
                h->next = nullptr;
                break;
            } else {
                h->next = tail;
            }

            h = nh;

            ListNode* nt = tail->next;
            if(h==nullptr||tail==nullptr) break;
            if(h==tail){
                tail->next = nullptr;
                break;
            } else {
                tail->next = h;
            }

            tail = nt;
        }
    }
};
