//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        map<char,int>map;
        for(int i = 0; i<s.size(); i++){
            map[s[i]]++;
        }
        vector<int>v;
        for(auto it:map) v.push_back(it.second);
        while(k!=0){
            sort(v.begin(),v.end());
            int d = v.back();
            v.pop_back();
            v.push_back(d-1);
            k--;
        }
        int ans = 0;
        for(int i = 0; i<v.size(); i++) ans+=v[i]*v[i];
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends