//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
    public:
    void quickSort(int arr[], int low, int high){
        if(low>=high){
            return ;
        }
        int i=low-1,j=low,p=high;
        while(j<p){
            if(arr[j]<=arr[p]){
                i++;
                swap(arr[i],arr[j]);
            }
            j++;
        }
        i++;
        swap(arr[i],arr[p]);
        quickSort(arr,low,i-1);
        quickSort(arr,i+1,high);
    }
    public:
    int partition (int arr[], int low, int high){
        
    }
};


//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends