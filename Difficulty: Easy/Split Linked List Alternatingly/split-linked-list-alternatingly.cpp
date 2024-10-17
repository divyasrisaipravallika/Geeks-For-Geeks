//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    // Function to split a linked list into two lists alternately
    vector<Node*> alternatingSplitList(struct Node* head) {
        // Your code here
        Node* h1 = NULL;
        Node* h2 = NULL;
        Node* t1 = NULL;
        Node* t2 = NULL;
        Node* s = head;
        if(head->next == NULL){
            return {head,NULL};
        }
        Node* f = head->next;
        while(s!=NULL and s->next!=NULL){
            Node* n = new Node(s->data);
            if(h1 == NULL and t1 == NULL){
                h1 = n;
                t1 = n;
            }
            else{
                t1->next = n;
                t1 = n;
            }
            s = s->next->next;
        }
        int c = 0;
        while(f!=NULL and f->next!=NULL){
            Node* n = new Node(f->data);
            if(h2 == NULL and t2 == NULL){
                h2 = n;
                t2 = n;
            }
            else{
                t2->next = n;
                t2 = n;
            }
            c++;
            f = f->next->next;
        }
        if(f!=NULL){
            Node* n = new Node(f->data);
            if(h2 == NULL and t2 == NULL){
                h2 = n;
                t2 = n;
            }
            else{
                t2->next = n;
                t2 = n;
            }
        }
        if(s!=NULL){
            Node* n = new Node(s->data);
            if(h1 == NULL and t1 == NULL){
                h1 = n;
                t1 = n;
            }
            else{
                t1->next = n;
                t1 = n;
            }
        }
        return {h1,h2};
    }
};


//{ Driver Code Starts.

void printList(struct Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        struct Node* head = new Node(arr[0]);
        struct Node* tail = head;

        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }

        Solution ob;
        vector<Node*> result = ob.alternatingSplitList(head);
        printList(result[0]);
        printList(result[1]);
    }

    return 0;
}

// } Driver Code Ends