//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method */
    int findMaxDiff(vector<int> &arr) {
        // Your code here
        stack<int>st1;
        stack<int>st2;
        vector<int>l(arr.size(),0);
        vector<int>r(arr.size(),0);
        for(int i = 0; i < arr.size(); i++){
            while(!st1.empty() and st1.top()>=arr[i]){
                st1.pop();
            }
            if(!st1.empty()) l[i] = st1.top();
            st1.push(arr[i]);
        }
        for(int i = arr.size()-1; i >= 0;  i--){
            while (!st2.empty() && st2.top() >= arr[i]) {
               st2.pop();
            }
            if (!st2.empty()) {
                r[i] = st2.top();
            }
            st2.push(arr[i]);
        }
        int m = 0;
        for(int i = 0; i < l.size(); i++){
            m = max(m,abs(l[i]-r[i]));
        }
        return m;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.findMaxDiff(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends