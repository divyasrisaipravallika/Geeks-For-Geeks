//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long sequence(int n){
        // code here
        long long i = 1;
        long long sum = 0;
        long long j = 1e9+7;
        long long c = 1;
        int a = 1;
        while(i < n+1){
               c = 1;
               //cout<<i<<endl;
               for(int k = 1 ; k<=i ; k++)
               {   
                    c = (c * a) % j;
                    a++;
               }
               sum = (sum + c) %  j;
               i++;
        }
        return sum % j;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends