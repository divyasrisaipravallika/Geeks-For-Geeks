//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
 vector<string>v;
  void recursion(string s, int on, int ze, int i, int n){
      if(i == n){
          v.push_back(s);
          return;
      }
      recursion(s+'1',on+1,ze,i+1,n);
      if(on >= ze+1) recursion(s+'0',on,ze+1,i+1,n);
  }
	vector<string> NBitBinary(int n)
	{
	    // Your code goes here
	    string s = "1";
	     recursion(s,1,0,1,n);
	     sort(v.rbegin(),v.rend());
	     return v;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends