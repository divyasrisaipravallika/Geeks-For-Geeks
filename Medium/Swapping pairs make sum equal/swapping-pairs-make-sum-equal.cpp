//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        // Your code goes here
        int s = accumulate(a,a+n,0);
        int t = accumulate(b,b+m,0);
        int ans = (s-t)/2;
        if((s-t)%2!=0) return -1;
        int i = 0, j = 0;
        sort(a,a+n);
        sort(b,b+m);
        while(i < n and j < m){
            int d = (a[i]-b[j]);
            if(d == ans){
                 return 1;
            }
            else if(d < ans) i++;
            else j++;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends