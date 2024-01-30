//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        Node* l1 = first;
        Node* l2 = second;
         Node* temp1 = NULL;
        Node* temp2 = NULL;
        if(l1==NULL && l2!=NULL) return l2;
        if(l1!=NULL && l2==NULL) return l1;
        if(l1==NULL && l2==NULL) return l1;
        while(l1)
        {
            Node* next = l1->next;
            l1->next = temp1;
            temp1 = l1;
            l1 = next;
        }
        while(l2)
        {
            Node* next = l2->next;
            l2->next = temp2;
            temp2 = l2;
            l2 = next;
        }
        int v = temp1->data+temp2->data;
        int c = 0;
        if(v<=9) c = 0;
        else
        {
            c = 1;
            v = v%10;
        }
        temp1 = temp1->next;
        temp2 = temp2 -> next;
        Node* x = new Node(v);
        while(temp1 && temp2)
        {
            v = temp1->data+temp2->data+c;
            if(v<=9) c = 0;
            else
            {
                c = 1;
                v = v%10;
            }
            Node* y = new Node(v);
            y->next=x;
            x = y;
            temp1= temp1->next;
            temp2 = temp2->next;
        }
        while(temp1!=NULL)
        {
           v = temp1->data+c;
            if(v<=9) c = 0;
            else
            {
                c = 1;
                v = v%10;
            }
            Node* y = new Node(v);
            y->next=x;
            x = y;
            temp1= temp1->next;
        }
        while(temp2!=NULL)
        {
            v = temp2->data+c;
            if(v<=9) c = 0;
            else
            {
                c = 1;
                v = v%10;
            }
            Node* y = new Node(v);
            y->next=x;
            x = y;
            temp2 = temp2->next;
        }
        if(c==1)
        {
            Node* y = new Node(c);
            y->next=x;
            x = y;
        }
         return x;
       
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends