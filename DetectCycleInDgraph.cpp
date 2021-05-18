//DIfficulty Level - Medium 
//Problem Statement - 
/*
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.


Example 1:

Input:



4 4
0 1
1 2
2 3
3 3
o/p : - 1


*/
//Code :- 
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
	//Function to detect cycle in a directed graph.
	bool cyclic(vector<int>adj[],int i , bool visited[],bool recST[])
	{
	    visited[i] = true;
	    recST[i] = true;
	    for(int x : adj[i]){
	        if(visited[x]==false && cyclic(adj,x,visited,recST)==true)
	            return true;
	        else if(recST[x] == true)
	            return true;
	    }
	    recST[i] = false;
	    return false;
	}
	bool isCyclic(int v, vector<int> adj[]) 
	{
	   	bool visited[v] , recST[v];
	   	for(int i = 0 ; i < v ; i++){
	   	    visited[i] = false;
	   	    recST[i] = false;
	   	}
	   	for(int i = 0 ; i < v ; i++){
	   	    if(visited[i]==false){
	   	        if(cyclic(adj,i,visited,recST)==true)
	   	            return true;
	   	    }
	   	}
	   	return false;
	}
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
