//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void push(struct Node **head_ref, int new_data) {

    struct Node *new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void lvl(TreeNode *r) {
    if (r == NULL)
        return;
    queue<TreeNode *> q;
    q.push(r);
    while (!q.empty()) {
        TreeNode *j = q.front();
        cout << j->data << " ";
        q.pop();
        if (j->left)
            q.push(j->left);
        if (j->right)
            q.push(j->right);
    }
}

void reverses(Node **head) {
    Node *prev = NULL;
    Node *cur = *head;
    Node *nxt;
    while (cur != NULL) {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    *head = prev;
}


// } Driver Code Ends
class Solution {
    public:
  void recursion(vector<int>& v, int i, int size, TreeNode* root) {
        if (2 * i + 1 >= size) return; // No more children
        TreeNode* leftNode = new TreeNode(v[2 * i + 1]);
        root->left = leftNode;
        recursion(v, 2 * i + 1, size, leftNode);
        
        if (2 * i + 2 < size) {
            TreeNode* rightNode = new TreeNode(v[2 * i + 2]);
            root->right = rightNode;
            recursion(v, 2 * i + 2, size, rightNode);
        }
    }

    void convert(Node *head, TreeNode *&root) {
        vector<int> v;
        while (head != NULL) {
            v.push_back(head->data);
            head = head->next;
        }
        
        if (v.empty()) return; // Handle edge case when the linked list is empty
        
        root = new TreeNode(v[0]);
        recursion(v, 0, v.size(), root);
    }
};


//{ Driver Code Starts.

int main() {
    int T, i, n, l, k;

    cin >> T;

    while (T--) {
        struct Node *head = NULL;

        cin >> n;
        for (i = 1; i <= n; i++) {
            cin >> l;
            push(&head, l);
        }
        reverses(&head);
        Node *prevhead = head;
        TreeNode *root = NULL;
        Solution obj;

        obj.convert(head, root);
        if (root == NULL) {
            cout << "-1\n";
        } else if (root == NULL && prevhead != NULL) {
            cout << "-1\n";
        } else {
            lvl(root);
            cout << endl;
        }
        // inorder(root);
        getchar();
    }
    return 0;
}

// } Driver Code Ends