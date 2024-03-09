//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    char nthCharacter(string s, int r, int n) {
        //code here
        char ans;
        if(n==0 and r==0) return s[0];
        for(int i = 0; i < r; i++){
            string a;
            s = s.substr(0,n+1);
            for(int j = 0; j < s.length(); j++){
                if(s[j]=='0') a+="01";
                else a+="10";
            }
            ans = a[n];
            s = a;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends