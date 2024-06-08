//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findExtra(int n, int arr1[], int arr2[]) {
        // add code here.
        int l = 0;
        int h = n-1;
        int k = 0;
        while(l<h){
            int m = (l+h)/2;
            if(arr1[m]!=arr2[m]){
                k = m;
                break;
            } 
            else{
                l = m+1;
            }
        }
       // cout<<k;
        for(int i = 0; i <= k; i++){ 
            if(arr1[i]!=arr2[i]) return i;
        }
        if(k==0) return n-1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr1[n], arr2[n - 1];
        for (int i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (int i = 0; i < n - 1; i++) {
            cin >> arr2[i];
        }
        Solution obj;
        cout << obj.findExtra(n, arr1, arr2) << endl;
    }
}
// } Driver Code Ends