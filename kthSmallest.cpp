//Difficulty - Medium

/* problem statement :- 
Given an array arr[] of N positive integers and a number K. The task is to find the kth smallest element in the array.

 

Example 1:

Input: 
N = 5, K = 3
arr[] = {3,5,4,2,9}

Output: 
4

Explanation: 
Third smallest element in the array is 4.

Example 2:

Input:
N = 5, k = 5
arr[] = {4,3,7,6,5}

Output: 
7

Explanation: 
Fifth smallest element in the array is 7.

*/ 
//Solution :-
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


int kthSmallest(int arr[], int n, int k){
    sort(arr,arr+n);
    return arr[k-1];
}

// { Driver Code Starts.
int main(){
	
	int t;
	cin >> t;
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    int arr[n];
	    
	    for(int i = 0; i<n; ++i)
	        cin>>arr[i];
	        
	    cout << kthSmallest(arr, n, k) << endl;
	    
	}
	return 0;
}  // } Driver Code Ends
