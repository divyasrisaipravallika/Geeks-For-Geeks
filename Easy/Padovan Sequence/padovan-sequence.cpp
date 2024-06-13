//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int padovanSequence(int n) {
        // code here.
        if(n==0 or n==1 or n==2) return 1;
        if(n==3 or n==4) return 2;
        int x = 1;
        int y = 2;
        int z = 2;
        int i = 4;
        int mod = 10e9+7;
        while(i!=n){
            int temp = x+y;
            x = y;
            y = z;
            z = temp;
            z %= 1000000007;
            x %= 1000000007;
            y %= 1000000007;
            i++;
        }
        return z;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.padovanSequence(n) << endl;
    }
    return 0;
}
// } Driver Code Ends