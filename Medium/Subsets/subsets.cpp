//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    void Subset(vector<int> v, int index,vector<int>&ans, int size,vector<vector<int>>&re)
    {
        if(index>=size)
        {    
            re.push_back(ans);
            return;
        }
        ans.push_back(v[index]);
        Subset(v,index+1,ans,v.size(),re);
        ans.pop_back();
        Subset(v,index+1,ans,v.size(),re);
    }
    vector<vector<int> > subsets(vector<int>& A)
    {
        //code here
        vector<vector<int>>re;
        vector<int>c;
        Subset(A,0,c,A.size(),re);
        sort(re.begin(),re.end());
        return re;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, x;
		cin >> n;

		vector<int> array;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			array.push_back(x);
		}
        
        
        Solution ob;
		vector<vector<int> > res = ob.subsets(array);

		// Print result
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << endl;
		}

		
	}

	return 0;
}
// } Driver Code Ends