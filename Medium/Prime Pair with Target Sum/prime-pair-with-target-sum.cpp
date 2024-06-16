//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    vector<int> getPrimes(int n) {
        // code here
        vector<bool>primes(n+1,true);
        primes[0] = false;
        primes[1] = false;
        for(int i = 2; i <= int(sqrt(n)); i++)
        {   
            if(primes[i])
            {
                for(int j=i*i; j<=n ; j+=i)
                {   
                    if(primes[j])
                    {
                        primes[j] = false; 
                        
                    }
                }
            }
       }
       vector<int>ans;
       for(int i = 2; i < n ; i++){
           if(primes[i]){
               int k = n-i;
               if(primes[k]){
                   ans.push_back(i);
                   ans.push_back(k);
                   return ans;
               }
           }
       }
       if(ans.size()==0) return {-1,-1};
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        vector<int> res = obj.getPrimes(n);

        Array::print(res);
    }
}

// } Driver Code Ends