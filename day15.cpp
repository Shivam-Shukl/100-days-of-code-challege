/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int lenA = getLength(headA);
        int lenB = getLength(headB);

       
        if (lenA > lenB) {
            int diff = lenA - lenB;
            while (diff--) headA = headA->next;
        } else {
            int diff = lenB - lenA;
            while (diff--) headB = headB->next;
        }

        
        while (headA && headB && headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }

        return headA; 
    }

private:
    int getLength(ListNode *head) {
        int length = 0;
        while (head) {
            length++;
            head = head->next;
        }
        return length;
    }
};
