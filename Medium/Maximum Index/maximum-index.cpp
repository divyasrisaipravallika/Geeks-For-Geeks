//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int a[], int n) 
    { 
        // Your code here
        vector<int>mini(n,a[0]);
        vector<int>maxi(n,a[n-1]);
        for(int i = 1; i < n; i++){
            mini[i] = min(mini[i-1],a[i]);
        }
        for(int i = n-2; i >= 0; i--){
            maxi[i] = max(maxi[i+1],a[i]);
        }
        int l = 0;
        int r = 0;
        int mx = 0;
        while(l<n and r<n){
            if(mini[l]<=maxi[r]){
                mx = max(mx,r-l);
                r++;
            }
            else l++;
        }
        return mx;
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends