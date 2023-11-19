class Solution {
private:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;

        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) {
            return true; // Empty list or single node is a palindrome
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev_slow = nullptr;

        while (fast && fast->next) {
            prev_slow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // If the list has odd number of elements, move slow to the next element
        if (fast != nullptr) {
            prev_slow = slow;
            slow = slow->next;
        }

        prev_slow->next = nullptr; // Break the first half from the rest of the list

        ListNode* reversedSecondHalf = reverse(slow);
        ListNode* temp = head;

        while (reversedSecondHalf) {
            if (temp->val != reversedSecondHalf->val) {
                return false;
            }
            temp = temp->next;
            reversedSecondHalf = reversedSecondHalf->next;
        }

        return true;
    }
};
