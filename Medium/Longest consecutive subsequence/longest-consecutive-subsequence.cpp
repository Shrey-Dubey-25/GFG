//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:

int findLongestConseqSubseq(int arr[], int n){
    int m=INT_MIN;
    if(n==1){
        return 1; 
    }
    for(int i=0;i<n;i++){
        if(arr[i]>m){
            m=arr[i];
        }
    }
    vector<int>h(m+1,0);
    for(int i=0;i<n;i++){
        h[arr[i]]++;
    }

    int c=1,ma=0;
    for(int i=1;i<h.size();i++){
        if(h[i-1]>0 && h[i]>0){
            c++;
        }
        else{
            c=1;
        }
        if(c>ma){
            ma=c;
        }
    }
    return ma;
}

};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends