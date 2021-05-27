//Difficulty :- Easy
// Problem Statement :-
/*
Given an unsorted array having both negative and positive integers. The task is place all negative element at the end of array without changing the order of positive element and negative element.

 

Example 1:

Input : 
A[] = {1, -1, 3, 2, -7, -5, 11, 6 }
Output : 
1  3  2  11  6  -1  -7  -5


Example 2:

Input : 
A[] = {-5, 7, -3, -4, 9, 10, -1, 11}
Output :
7  9  10  11  -5  -3  -4  -1

 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function segregateElements() which takes the array A[] and its size N as inputs and store the answer in the array A[] itself.

 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
  */
Code :- #include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    void segregateElements(int arr[],int n)
    {   
        vector<int> arr1(n,0);
        int i = 0 , j = 0 , p = 0;
        while(j<n)
        {
            if(arr[j]>0)
            {
                swap(arr[i],arr[j]);
                i++;
                j++;
            }else
            {
               arr1[p++] = arr[j];
               j++; 
               
            }
        }
        int k = 0 ;
        for(int i = 0 ; i < n ; i++)
        {
            if(arr[i]<0)
                arr[i] = arr1[k++];
        }
    }
};

// { Driver Code Starts.
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		ob.segregateElements(a,n);
		
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
		cout<<endl;
	}
}
