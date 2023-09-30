//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> v){
        int i=v.size()-1;
        while(i>0){
            if(v[i]>v[i-1]){
                break;
            }
            else{
                i--;
            }
        }      
        if(i<=0){
            sort(v.begin(),v.end());
            return v;
        }
        sort(v.begin()+i,v.end());
        int x=i;
        while(x<v.size()){
            if(v[x]>v[i-1]){
                break;
            }
            x++;
        }
        swap(v[x],v[i-1]);
        return v;
}
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends