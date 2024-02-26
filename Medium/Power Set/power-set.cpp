//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	vector<string>A;
	void recursion(vector<char>v,string s,int size,int index){
	    if(index >=  size){
	        string k="";
	        for(int i = 0 ; i < v.size() ; i++) k+=v[i];
	        if(k!="")A.push_back(k);
	        return;
	    }
	    v.push_back(s[index]);
	    recursion(v,s,size,index+1);
	    v.pop_back();
	    recursion(v,s,size,index+1);
	}
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    recursion({},s,s.size(),0);
		    sort(A.begin(),A.end());
		    return A;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends