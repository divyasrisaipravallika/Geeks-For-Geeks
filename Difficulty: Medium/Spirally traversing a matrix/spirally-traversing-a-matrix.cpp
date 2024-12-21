//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &mt) {
        // code here
        int n = mt[0].size();
        int m = mt.size();
        int i = 0, j = 0;
        int f = 0;
        int c = 0, d = 0;
        int a = m, b = n;
        int k = 0;
        vector<int>ans;
        while(1){
            k++;
            if(k>a*b) return ans;
            if(f==0 and j < n){
                ans.push_back(mt[i][j]);
                j++;
                if(j==n){
                    f = 1;
                    n--;
                    i++;
                    j--;
                }
            }
            else if(f==1 and i < m){
               ans.push_back(mt[i][j]);
                i++;
                if(i==m){
                    f = 2;
                    m--;
                    i--;
                    j--;
                }
            }
            else if(f==2 and j>=d){
               ans.push_back(mt[i][j]);
                if(j==d) {
                    f = 3;
                    i--;
                    c++;
                }
                else j--;
            }
            else if(f==3 and i>=c){
              ans.push_back(mt[i][j]);
                if(i==c){
                    f = 0;
                    d++;
                    j++;
                }
                else i--;
            }

        }
        return ans;
    }

};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++) {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends