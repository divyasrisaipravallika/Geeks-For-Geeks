//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    string Reduced_String(int k,string s){
        // Your code goes here
        int j = 0, flag = 0, c = 0;
        if(k==1) return "";
        while(j<s.size()-1)
        {
            if(s[j]==s[j+1])
            {
                j++;
                c++;
            }
            else
            {
                if(c>=k-1)
                {
                    s.erase(j-k+1,k);
                    flag = 1;
                    j = j-k+1;
                    c = 0;
                }
                else
                {
                    c = 0;
                    j++;
                }
            }
        }
        if(c>=k-1)
        {
             s.erase(j-k+1,k);
            flag = 1;
            j = j-k+2;
            c = 0;
        }
        if(flag==0) return s;
        return Reduced_String(k,s);
    }


};

//{ Driver Code Starts.

int main() {
    
    
    int t;cin>>t;
    while(t--)
    {
        int k;
        cin>>k;
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.Reduced_String(k,s)<<"\n";
        
    }
    
	return 0;
}
// } Driver Code Ends