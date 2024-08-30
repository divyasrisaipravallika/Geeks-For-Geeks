//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int> arr, int n, long long s) {
        // Your code here
        long long sum = 0;
        unordered_map<long long,int>map;
        for(int i = 0 ; i < arr.size(); i++){
            sum+=arr[i];
            if(i==0 and sum-s==0){
                return {i+1,i+1};
            }
            if(sum==s){
                return {1,i+1};
            }
            if(map.find(sum-s)!=map.end()){
                return {map[sum-s]+2,i+1};
            }
              map[sum] = i;
            
        }
        return {-1};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long s;
        cin >> n >> s;
        vector<int> arr(n);
        // int arr[n];
        const int mx = 1e9;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> res;
        res = ob.subarraySum(arr, n, s);

        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends