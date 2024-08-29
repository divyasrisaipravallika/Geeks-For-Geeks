//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(vector<int>& arr) {
        // Your code here
          map<int,int>mp;
        vector<pair<int,int>>v;
        vector<int>ans;
        int m = 0;
        for(int i=0;i<arr.size();i++) {
            mp[arr[i]]++;
        }
        for(auto it:mp) {
            pair<int,int>p;
            p = make_pair(it.second,it.first);;
            v.push_back(p);
            m = max(m,it.second);
        }
        sort(v.rbegin(),v.rend());
        sort(v.begin(),v.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) {
        if (p1.first == p2.first) {
            return p1.second < p2.second;
        }
        return p1.first > p2.first;
    });
        for(auto it:v){
            int x = it.first;
            for(int i = 0; i < x; i++){
                ans.push_back(it.second);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends