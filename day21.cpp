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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *first=list1;
        ListNode *second =list2;
        ListNode *result =NULL ,*tail =NULL ;

        while (first != NULL && second !=NULL)
        {
            if(first->val == second->val)
            {
                ListNode * newNode = new ListNode(first-> val);
                if(result == NULL)
                {
                    result = newNode;
                    tail =result;
                }
                else
                {
                    tail->next =newNode;
                    tail=tail->next;
                }
                ListNode * NewNode =new ListNode(first->val);
                
                tail->next=NewNode;
                tail=tail->next;

                first =first->next;
                second =second->next;
            }
            else if (first->val >second ->val)
            {
                ListNode * newNode = new ListNode(second-> val);
                if(result == NULL)
                {
                    result = newNode;
                    tail =result;
                }
                else
                {
                    tail->next =newNode;
                    tail=tail->next;
                }
                
                second =second->next;

            }
            else {
                ListNode * newNode = new ListNode(first-> val);
                if(result == NULL)
                {
                    result = newNode;
                    tail =result;
                }
                else
                {
                    tail->next =newNode;
                    tail=tail->next;
                }

                first =first->next;
                
            }
         
        }
        while(first != NULL)
        {
            ListNode * newNode = new ListNode(first-> val);
            if(result == NULL)
            {
                result = newNode;
                tail =result;
            }
            else
            {
                tail->next =newNode;
                tail=tail->next;
            }

            first =first->next;
                
        }
        while(second !=NULL)
        {
            ListNode * newNode = new ListNode(second-> val);
            if(result == NULL)
            {
                result = newNode;
                tail =result;
            }
            else
            {
                tail->next =newNode;
                tail=tail->next;
            }

            second =second->next;
        }
        return result;
    }
};