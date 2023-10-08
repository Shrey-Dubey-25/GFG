//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int v[], int n, int x) {
    int i = 0, s = 0, j = 0, m = INT_MAX;
    while (i < n) {
        s += v[i];
        while (s > x) {
            m = min(m, i - j + 1);
            s -= v[j];
            j++;
        }
        i++;
    }
    if(m!=INT_MAX) {
        return m;
    }
    return 0;  
}
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}
// } Driver Code Ends