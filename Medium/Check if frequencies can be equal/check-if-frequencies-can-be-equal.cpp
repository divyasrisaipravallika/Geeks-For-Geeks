//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool sameFreq(string s)
	{
	    // code here 
	    map<char,int>m;
	    for(int i=0;i<s.length();i++){
	        m[s[i]]++;
	    }
	    int mn = s.length();
	    int mx = 0;
	    int count = 0,c = 0;
	    for(auto it:m){
	        mx = max(mx,it.second);
	        mn = min(mn,it.second);
	        count+=it.second;
	        c++;
	    }
	    if(mx == 1){
	        return true;
	    }
	    if(count == mn+count-1 and (count-1)/(c-1) == mx){
	        return true;
	    }
	    int f = 0; 
	    for(auto it:m){
	        if(it.second > mn){
	            f++;
	            if(it.second-1 > mn){
	               return false;
	            }
	        }
	    }
	    if(f>1){
	            return false;
	        }
	    return true;
	}
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends