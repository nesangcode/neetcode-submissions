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
    void ins(ListNode* &hx, ListNode* &tx, ListNode* &to){
        if(hx==nullptr){
            hx = to;
            tx = to;
        } else {
            tx->next = to;
            tx=to;
        }
        if(to!=nullptr) to=to->next;
    }

    pair<ListNode*, ListNode*> sort(int l, int r, vector<ListNode*>& lists){
        if(l==r){
            return make_pair(lists[l], lists[l]);
        }
        int mid = (l+r)/2;
        auto [hl, tl] = sort(l, mid, lists);
        auto [hr, tr] = sort(mid+1, r, lists);

        ListNode* hx=nullptr;
        ListNode* tx=nullptr;

        while(hl!=nullptr&&hr!=nullptr){
            if(hl->val <= hr->val){
                ins(hx, tx, hl);
            } else {
                ins(hx, tx, hr);
            }
        }
        while(hl!=nullptr){
            ins(hx, tx, hl);
        }
        while(hr!=nullptr){
            ins(hx, tx, hr);
        }

        return {hx, tx};
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;

       return sort(0, lists.size()-1, lists).first; 
    }
};
