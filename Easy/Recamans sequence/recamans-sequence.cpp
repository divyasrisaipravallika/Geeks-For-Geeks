//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> recamanSequence(int n){
       // code here
        if(n==0) return {0};
        vector<int>v(n,0);
        v[0]=0;
        map<int,int>m;
        m[0] = 1;
        for(int i = 1 ; i < n ; i++){
            if(v[i-1]-i > 0 and m[v[i-1]-i]!=1)
            {
                v[i] = v[i-1]-i;
                m[v[i-1]-i] = 1;
            }
            else{
                v[i] = v[i-1]+i;
                m[v[i-1]+i] = 1;
            }
        }
        if(v.size()>0) return v;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<int> ans = ob.recamanSequence(n);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends