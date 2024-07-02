//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    vector<int> sieveOfEratosthenes(int n)
    {
        // Write Your Code here
        vector<int>primes(n+1,true);
        primes[0] = false;
        primes[1] = false;
        for(int i = 0; i <= sqrt(n); i++){
            if(primes[i]){
                for(int j = i*i ; j <= n ; j+=i){
                    if(primes[j]) primes[j] = false;
                }
            }
        }
        vector<int>ans;
        for(int i = 2 ; i <= n; i++){
            if(primes[i]) ans.push_back(i);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        vector<int> primes  = ob.sieveOfEratosthenes(N);
        for(auto prime : primes) {
            cout<< prime <<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends