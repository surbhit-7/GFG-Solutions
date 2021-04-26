//Difficulty - Medium
/* PROBLEM STATEMENT :-
Given an array arr[] of N positive integers and a number K. The task is to find the kth largest element in the array.

Example 1:

Input:
N = 5, K = 3
arr[] = {3, 5, 4, 2, 9}
Output: 
4
Explanation: 
Third largest element
in the array is 4.

Example 2:

Input:
N = 5, K = 5
arr[] = {4, 3, 7, 6, 5} 
Output: 
3
Explanation: 
Fifth largest element
in the array is 3.
*/



//Solution
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    int KthLargest(int arr[], int n, int k) {
        priority_queue<int> pq(arr,arr+n);
        int x;
        while(k--){
            x = pq.top();
            pq.pop();
        }
        return x;
        
    }
};


int main() {

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;

        cout << ob.KthLargest(arr, n, k) << endl;
    }

    return 0;
} 
