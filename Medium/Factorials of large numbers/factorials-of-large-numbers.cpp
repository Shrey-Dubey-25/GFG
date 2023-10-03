//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    void multiply(vector<int> &result, int x){
        int carry = 0;
        for(int i=result.size()-1; i>=0; i--){
            int temp = (result[i]*x)+carry;
            result[i]= temp%10;
            carry = temp/10;
        }
        
        while(carry){
            result.insert(result.begin(),carry%10);
            carry /= 10;
        }
 }
    vector<int> factorial(int n){
        vector<int>v{1};
        for(int i=n;i>1;i--){
            multiply(v,i);
        }
        return v;
    }

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends