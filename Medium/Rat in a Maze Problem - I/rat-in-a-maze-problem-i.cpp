//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    bool ispossible(vector<vector<int>>&v,int i,int j){
        if(i<v.size() && i>=0 && j>=0 && j<v.size()){
            if(v[i][j]==1){
                return true;
            }
        }
        return false;
    }
    
    void helper(vector<string>&ans,vector<vector<int>>&v,int i,int j,string& path){
        if(i==v.size()-1 && j==v[0].size()-1){
            ans.push_back(path);
            return;
        }
        
        //right
        if(ispossible(v,i,j+1)){
            v[i][j]=0;
            path+="R";
            helper(ans,v,i,j+1,path);
            path.pop_back();
            v[i][j]=1;
        }
        
        //down
        if(ispossible(v,i+1,j)){
            v[i][j]=0;
            path+="D";
            helper(ans,v,i+1,j,path);
            path.pop_back();
            v[i][j]=1;
        }
        
        //left
        if(ispossible(v,i,j-1)){
            v[i][j]=0;
            path+="L";
            helper(ans,v,i,j-1,path);
            path.pop_back();
            v[i][j]=1;
        }
        
        //up
        if(ispossible(v,i-1,j)){
            v[i][j]=0;
            path+="U";
            helper(ans,v,i-1,j,path);
            path.pop_back();
            v[i][j]=1;
        }
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string>ans;
        string s="";
        if(m[0][0]==0){
            return ans;
        }
        helper(ans,m,0,0,s);
        return ans;
        
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends