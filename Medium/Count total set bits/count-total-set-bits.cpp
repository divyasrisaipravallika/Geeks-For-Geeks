//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        // Your logic here
        int i;
        int d = n;
        while(d!=0){
            i++;
            d = d>>1;
        }
        int ans = 0;
        n = n+1;
        for(int j = 1; j <= i; j++){
            int p = pow(2,j);
            int rem = n%p;
            rem = rem - (p/2);
            if(rem<0) rem = 0;
            int tp = (n/p)*(p/2);
            ans+=tp+rem;
        }
        return ans;
    }
};


//{ Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}

// } Driver Code Ends