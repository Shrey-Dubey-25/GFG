//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfs(vector<vector<int>>& adj,vector<int>&visited,int i,vector<int>&res){
        vector<int>v=adj[i];
        for(auto i:v){
            if(visited[i]==0){
                res.push_back(i);
                visited[i]=1;
                dfs(adj,visited,i,res);
            }
        }
        return res;
    }
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        vector<int>visited(adj.size(),0);
        vector<int>res;
        for(int i=0;i<adj.size();i++){
            if(visited[i]==0){
                visited[i]=1;
                res.push_back(0);
                dfs(adj,visited,i,res);
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;
        vector<int> ans = obj.dfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends