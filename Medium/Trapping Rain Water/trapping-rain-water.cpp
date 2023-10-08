//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    public:
    long long trappingWater(int v[], int n){
        if(n<=2){
            return 0;
        }
        int i=n-1;
        vector<int>l(n,-1);
        l[0]=v[0];
        for(int i=1;i<n;i++){
            if(v[i]<l[i-1]){
                l[i]=l[i-1];
            }
            else{
                l[i]=v[i];
            }
        }
        vector<int>r(n,-1);
        r[n-1]=v[n-1];
        for(int i=n-2;i>=0;i--){
            if(v[i]<r[i+1]){
                r[i]=r[i+1];
            }
            else{
                r[i]=v[i];
            }
        }
        long long fw=0;
        for(int i=1;i<n-1;i++){
            fw+=min(l[i],r[i])-v[i];
        }
        return fw;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends