//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj,queue<int>& q,vector<int>&vis,vector<int>&res,int u){
        vis[u]=1;
        
        while(true){
            vector<int>v=adj[u];
            for(auto i:v){
                if(vis[i]==0){
                    vis[i]=1;
                    q.push(i);
                }
            }
            if(q.empty()){
                return res;
            }
            else{
                u=q.front();
                q.pop();
                res.push_back(u);
            }
        }
    }
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        vector<int>res;
        vector<int>vis(adj.size(),0);
        queue<int> q;
        q.push(0);
        bfs(adj,q,vis,res,0);
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

        // Now using vector of vectors instead of array of vectors
        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;
        vector<int> ans = obj.bfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends