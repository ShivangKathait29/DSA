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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next) return head;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        for(int i=0;i<left-1;i++){ 
            prev = curr;
            curr = curr->next;
        }
        
        ListNode *firstPrev = prev,* firstCurr = curr;
        for(int i=left;i<=right;i++){
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        if(left==1) head = prev;
        else firstPrev->next = prev; 
        firstCurr->next = curr; 
        
        return head;

    }
};