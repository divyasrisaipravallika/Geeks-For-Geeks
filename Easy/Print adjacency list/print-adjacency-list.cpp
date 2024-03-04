//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int,int>>v) {
        // Code here
        map<int,vector<int>>map;
        for(int i = 0 ; i < v.size(); i++){
            int k = v[i].first;
            int a = v[i].second;
            if(map.find(k)!=map.end()){
                vector<int>e;
                e = map[k];
                e.push_back(a);
                map[k] = e;
                if(map.find(a)!=map.end()){
                    vector<int>l = map[a];
                     l.push_back(k);
                     map[a] = l;
                    // cout<<a<<" [poi"<<endl;
                }
                else{
                    map[a]= {k};
                }
            }
            else{
                map[k] = {a};
               if(map.find(a)!=map.end()){
                    vector<int>l = map[a];
                     l.push_back(k);
                     map[a] = l;
                }
                else{
                    map[a]= {k};
                }
            }
        }
        vector<vector<int>>ans;
        for(int i = 0 ;i <= V; i++)
        {
            vector<int>e;
            for(auto it : map[i]){
                 e.push_back(it);   
           }
           ans.push_back(e);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<pair<int,int>>edges;
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u,v});
        }
        Solution obj;
        vector<vector<int>> adj = obj.printGraph(V, edges);
        for(int i=0;i<V;i++)
        {
            sort(adj[i].begin(),adj[i].end());
            for(auto it:adj[i])
                cout<<it<<" ";
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends