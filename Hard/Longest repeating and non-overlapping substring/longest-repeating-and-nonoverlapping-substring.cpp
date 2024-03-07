//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string longestSubstring(string s, int n) {
        // code here
        int max = 0;
        string ans = "-1",t;
        for(int i = 0, j = 0; i < n and j < n ; ++j){
            t = s.substr(i,j-i+1);
            if(s.find(t,j+1)!=string::npos){
                if(t.size()>max) 
                {
                max = t.size();
                ans = t;
                }
            }
            else ++i;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        string S;

        cin >> N;
        cin >> S;

        Solution ob;
        cout << ob.longestSubstring(S, N) << endl;
    }
    return 0;
}
// } Driver Code Ends