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

    void ins(ListNode* &head, ListNode* &tail, ListNode* &li){
        if(head==nullptr){
            head = li;
            tail = li;
            return;
        }

        tail->next=li;
        tail = tail->next;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        
        while(list1!=nullptr&&list2!=nullptr){
            if(list1->val <= list2->val){
                ins(head, tail, list1);
                list1 = list1->next;
            } else {
                ins(head, tail, list2);
                list2 = list2->next;
            }
        }

        while(list1!=nullptr){
            ins(head, tail, list1);
            list1 = list1->next;
        }

        while(list2!=nullptr){
            ins(head, tail, list2);
            list2 = list2->next;
        }

        return head;
    }

};
