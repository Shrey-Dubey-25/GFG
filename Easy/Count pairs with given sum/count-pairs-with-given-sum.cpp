//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int getPairsCount(int v[], int n, int k) {
    int m=INT_MIN;
    for(int i=0;i<n;i++){
        if(v[i]>m){
            m=v[i];
        }
    }
    vector<int>h(m+1,0);
    for(int i=0;i<n;i++){
        h[v[i]]++;
    }
    int p=0;
    for(int i=0;i<h.size();i++){
        if(h[i]>0){
            int ele=k-i;
            if(ele==i){
                p+=(h[i]*(h[i]-1))/2;
            }
            else if(ele>=0 && ele<h.size()){
                p+=h[i]*h[ele];
                h[i]=0;
                h[ele]=0;
            }
        }
    }
    return p;
}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}
// } Driver Code Ends