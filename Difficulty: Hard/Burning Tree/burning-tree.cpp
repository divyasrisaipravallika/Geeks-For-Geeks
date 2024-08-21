//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  int n;
  unordered_map<int,vector<int>>adj;
  void adjacency(Node* root){
      if (root == NULL) return;
        if (root->right != NULL && root->left != NULL && adj.find(root->data) == adj.end()) {
            adj[root->data] = {root->left->data, root->right->data};
            adj[root->left->data] = {root->data};
            adj[root->right->data] = {root->data};
        } else if (root->right != NULL && adj.find(root->data) == adj.end()) {
            adj[root->data] = {root->right->data};
            adj[root->right->data] = {root->data};
        } else if (root->left != NULL && adj.find(root->data) == adj.end()) {
            adj[root->data] = {root->left->data};
            adj[root->left->data] = {root->data};
        }

        if (root->right != NULL && root->left != NULL && adj.find(root->data) != adj.end() && root->data != n) {
            vector<int> v = adj[root->data];
            v.push_back(root->left->data);
            v.push_back(root->right->data);
            adj[root->data] = v;
            adj[root->left->data] = {root->data};
            adj[root->right->data] = {root->data};
        } else if (root->right != NULL && adj.find(root->data) != adj.end() && root->data != n) {
            vector<int> v = adj[root->data];
            v.push_back(root->right->data);
            adj[root->data] = v;
            adj[root->right->data] = {root->data};
        } else if (root->left != NULL && adj.find(root->data) != adj.end() && root->data != n) {
            vector<int> v = adj[root->data];
            v.push_back(root->left->data);
            adj[root->data] = v;
            adj[root->left->data] = {root->data};
        }

      adjacency(root->left);
      adjacency(root->right);
  }
    int minTime(Node* root, int target) 
    {   
       n = root->data;
        adjacency(root);
        unordered_map<int, bool> visited;
        queue<int> q;
        q.push(target);
        int time = 0;
        visited[target] = true;
        while (!q.empty()) {
            int s = q.size();
            bool burn = false;
        
            for (int i = 0; i < s; i++) {
                int k = q.front();
                q.pop();
                for (int it : adj[k]) {
                    if (!visited[it]) {
                        q.push(it);
                        visited[it] = true;
                        burn = true;
                    }
                }
            }
            if (burn) time++;
        }
        
        return time;

    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends