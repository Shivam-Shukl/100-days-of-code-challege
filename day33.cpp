class Solution
{
private:
    ListNode *sol(ListNode *l1, ListNode *l2, int count)
    {
        if (l1 == nullptr && l2 == nullptr && count == 0)
        {
            return nullptr;
        }

        int x = (l1 != nullptr) ? l1->val : 0;
        int y = (l2 != nullptr) ? l2->val : 0;
        int sum = x + y + count;

        ListNode *result = new ListNode(sum % 10);
        result->next = sol((l1 != nullptr) ? l1->next : nullptr,
                           (l2 != nullptr) ? l2->next : nullptr,
                           sum / 10);

        return result;
    }

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        return sol(l1, l2, 0);
    }
};
