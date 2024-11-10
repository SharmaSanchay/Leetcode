// Leetcode ->21 (https://leetcode.com/problems/merge-two-sorted-lists/description/)
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        // Base case: If both lists are null, return null
        if (list1 == nullptr && list2 == nullptr)
        {
            return list1;
        }
        // If list1 is null, return list2
        if (list1 == nullptr)
        {
            return list2;
        }
        // If list2 is null, return list1
        if (list2 == nullptr)
        {
            return list1;
        }

        // Create a dummy node to serve as the start of the merged list
        ListNode *dummy = new ListNode(-1);
        // Result points to the dummy node, and will be used to build the merged list
        ListNode *result = dummy;
        // Pointers to iterate over the input lists
        ListNode *head1 = list1;
        ListNode *head2 = list2;

        // While both lists have nodes, compare their values and attach the smaller node to the result
        while (head1 != nullptr && head2 != nullptr)
        {
            if (head1->val < head2->val)
            {
                result->next = head1;
                head1 = head1->next;
            }
            else
            {
                result->next = head2;
                head2 = head2->next;
            }
            result = result->next; // Move the result pointer forward
        }

        // If there are remaining nodes in list1, attach them to the result
        if (head1 != nullptr)
        {
            result->next = head1;
        }

        // If there are remaining nodes in list2, attach them to the result
        if (head2 != nullptr)
        {
            result->next = head2;
        }

        // Return the head of the merged linked list (skipping the dummy node)
        return dummy->next;
    }
};

/*
If Length of the Linked list1 -> N
Length of the Linked list2 -> M
Time complexity -> O(N+M)
Space Complexity->O(1) 
*/