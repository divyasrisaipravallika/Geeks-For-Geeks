//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    void solve(string s, int start, int end,vector<string>&a){
        if(start >= end){
            a.push_back(s);
            return;
        }
        for(int i = start; i <= end ; i++){
            swap(s[start],s[i]);
            solve(s,start+1,end,a);
            swap(s[start],s[i]);
        }
    }
    vector<string> permutation(string S)
    {
        //Your code here
        vector<string>a;
        solve(S,0,S.size()-1,a);
        sort(a.begin(),a.end());
        return a;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends