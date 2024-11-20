//Leetcode -> 19 (https://leetcode.com/problems/remove-nth-node-from-end-of-list/)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == nullptr){
            head = nullptr;
            return head;
        }
        ListNode *temp = head;
        for(int i=1;i<=n;i++){
            temp = temp->next;
        }
        if(temp == nullptr){return head->next;}
        ListNode *prev = head;
        while(temp!=nullptr && temp->next!=nullptr){
            prev = prev->next;
            temp = temp->next;
        }
        prev->next = prev->next->next;
        return head;
    }
};
/*
 Time Compelxity -> O(N)
 Space Complexity->0(1)
 */
