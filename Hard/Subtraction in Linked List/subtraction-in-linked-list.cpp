//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

// Linked List Class
class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(NULL), tail(NULL) {}

    // creates a new node with given value and appends it at the end of the linked list
    void insert(int val) {
        if (head == NULL) {
            head = new Node(val);
            tail = head;
        } else {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    Node* subLinkedList(Node* head1, Node* head2) {
        // Your implementation of subLinkedList goes here
        // Make sure to return the head of the resulting linked list
         Node* po = new Node(0);
        while(head1!=NULL and head1->data==0){
               head1 = head1->next;
        }
        while(head2!=NULL and head2->data==0){
            head2 = head2->next;     
        }
        if(head1==NULL and head2==NULL) 
        {
            return po;
        }
        else if(head1==NULL)
        {
            return head2;
        }
        else if(head2==NULL)
        {
            return head1;
        }
        Node* g = head1;
        Node* h = head2;
        while(g->next!=NULL and h->next!=NULL and g->data==h->data)
        {   //cout<<g->data<<" "<<h->data<<endl;
            g = g->next;
            h = h->next;
        }
        int i = g->data;
        int j = h->data;
       // cout<<i<<" "<<j<<endl;
        Node* temp1 = NULL;
        Node* cur1 = head1;
        int c1=0;
        while(cur1){
            Node* next = cur1->next;
            cur1->next = temp1;
            temp1 = cur1;
            cur1 = next;
            c1++;
        } 
        Node* temp2 = NULL;
        Node* cur2 = head2;
        int c2=0;
        while(cur2){
            Node* next = cur2->next;
            cur2->next = temp2;
            temp2 = cur2;
            cur2 = next;
            c2++;
        }
        Node* n;
        Node* m;
        if(c1>c2 and c1!=c2){
          // cout<<1<<endl;
             n = temp1;
             m = temp2;
        }
        else if(c1==c2){
          if(i>j){
             // cout<<2<<endl;
              n = temp1;
              m = temp2;
          }
          else{
             //cout<<3<<endl;
              n = temp2;
              m = temp1;
          }
        }
        else{
             // cout<<4<<endl;
              n = temp2;
              m = temp1;
        }
        int a = n->data;
        int b = m->data;
        int c = 0;
        n = n->next;
        m = m->next;
        if(a<b){
            a = a+10;
            c = 1;
        }
        else{
            c = 0;
        }
        Node* x = new Node(a-b);
        while(n!=NULL and m!=NULL){
            a = n->data;
            b = m->data;
            if(c==1)
            {
                a = a-1;
            }
            if(a<b){
                a = a+10;
                c = 1;
            }
            else{
                c = 0;
            }
            Node* y = new Node(a-b);
            y->next = x;
            x = y;
            n = n->next;
            m = m->next;
        }
        while(n!=NULL and n->next!=NULL)
        {  
            a = n->data;
            // cout<<a<<endl;
            if(c==1)
            {
                a = a-1;
                if(a<0)
                {   a+=10;
                    c = 1;
                }
                else
                {
                    c = 0;
                }
            }
            Node* y = new Node(a);
            y->next = x;
            x = y;
            n = n->next;
        }
        if(n!=NULL){
            a = n->data;
            //cout<<a<<endl;
            if(c==1){
                a = a-1;
                if(a<=0){
                    c = 1;
                }
                else{
                    c = 0;
                }
            }
            if(a!=0){
                //cout<<a<<endl;
                Node* y = new Node(a);
                y->next = x;
                x = y;
            }
        }
        while(x->next!=NULL and x->data==0)
        {
            x = x->next;
        }
        return x;
    }
};

//{ Driver Code Starts.

// prints the elements of linked list starting with head
void printList(Node* n) {
    while (n) {
        cout << n->data;
        n = n->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        LinkedList LL1;
        string l1,l2;
        cin>>l1;
        for (int j = 0; j < n; ++j) {
            int x=(l1[j]-'0');
            LL1.insert(x);
        }

        int m;
        cin >> m;
        LinkedList LL2;
        cin>>l2;
        for (int j = 0; j < m; ++j) {
            int x=(l2[j]-'0');
            LL2.insert(x);
        }

        Solution ob;
        Node* res = ob.subLinkedList(LL1.head, LL2.head);
        printList(res);
    }

    return 0;
}

// } Driver Code Ends