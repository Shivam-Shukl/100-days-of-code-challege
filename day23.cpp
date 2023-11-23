/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    private:
    void insertAtTail (Node * &head, Node * &tail,int d)
    {
        Node * newNode =new Node(d);
        if(head==NULL)
        {
            head=newNode;
            tail=newNode;
            return;
        }
        else
        {
            tail->next =newNode;
            tail=newNode;
        }
    }
public:
    Node* copyRandomList(Node* head) 
    {
        //step 1 
        Node * CloneHead =NULL;
        Node * CloneTail =NULL;

        Node * temp =head;
        while(temp != NULL)
        {
            insertAtTail(CloneHead,CloneTail,temp->val);
            temp=temp->next;
        }
        //step 2

        Node * originalNode =head;
        Node * CloneNode =CloneHead;

        while(originalNode != NULL && CloneNode !=NULL)
        {
            Node *next =originalNode->next;
            originalNode -> next =CloneNode;
            originalNode =next;
            next=CloneNode->next;
            CloneNode->next=originalNode;
            CloneNode =next;
        }
        
        //step 3

        temp=head;
        while(temp!=NULL)
        {
            if(temp->next!=NULL)
            {
                if(temp->random!=NULL)
                {
                    temp->next->random=temp->random->next;
                }
            }
            else
            {
                temp->next=temp->random;
            }
            temp=temp->next->next;
        }

        //step 4
        originalNode=head;
        CloneNode =CloneHead;
        
        while(originalNode !=NULL && CloneNode != NULL)
        {
            originalNode->next=CloneNode->next;
            originalNode=originalNode->next;
            if(originalNode!=NULL)
            {
                CloneNode->next=originalNode->next;
                CloneNode =CloneNode->next;
            }
        }

        return CloneHead;
        
    }
};