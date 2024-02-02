//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        //Your code here
        int flag = 0;
        int k = 0;
        if(s[0]=='-')
        {
            flag = 1;
            k = 1;
        }
        int val = 0;
        for(int i = k ; i< s.size(); i++)
        {   
            if(s[i] >='0' and s[i]<='9')
            {
                val = val*10 + int(s[i] - '0');
            }
            else
            {
                return -1;
            }
            // cout<<val<<" ";
        }
        if(flag == 0) return val;
        return val*-1;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends