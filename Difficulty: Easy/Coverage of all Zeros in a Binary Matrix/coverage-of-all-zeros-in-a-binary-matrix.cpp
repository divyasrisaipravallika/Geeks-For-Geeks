//{ Driver Code Starts


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int findCoverage(vector<vector<int>>& matrix) {
        // Code here
        int c = 0;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0;  j < matrix[i].size(); j++){
                if(matrix[i][j]==0){
                    if(i+1<matrix.size() and matrix[i+1][j]==1)  c++;
                    if(j+1<matrix[i].size() and matrix[i][j+1]) c++;
                    if(i-1>=0 and matrix[i-1][j]==1) c++;
                    if(j-1>=0 and matrix[i][j-1]==1) c++;
                }
            }
        }
        return c;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        int ans = obj.findCoverage(matrix);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends