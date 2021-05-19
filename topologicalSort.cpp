// Difficulty :- Medium
// Problem statement : -
/*
Given a Directed Graph with V vertices and E edges, Find any Topological Sorting of that Graph.


Example 1:

Input:
3 4
3 0
1 0
2 0

Output:
1
Explanation:
The output 1 denotes that the order is
valid. So, if you have, implemented
your function correctly, then output
would be 1 for all test cases.
One possible Topological order for the
graph is 3, 2, 1, 0.
*/
//Code :- 
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	void dfsRec(vector<int>adj[],bool visited[],stack<int>&st,int i)
	{
	    visited[i] = true;
	    for(int x : adj[i]){
	        if(visited[x]==false)
	            dfsRec(adj,visited,st,x);
	    }
	    st.push(i);
	}
	vector<int> topoSort(int v, vector<int> adj[]) 
	{
	    bool visited[v];
	    for(int i = 0 ; i < v ; i++)
	        visited[i] = false;
	        
	    stack<int>st;
	    for(int i = 0 ; i < v ; i++)
	        if(visited[i]==false)
	            dfsRec(adj,visited,st,i);
	
	    vector<int> res;
	    while(st.empty()==false){
	        int j = st.top();
	        st.pop();
	        res.push_back(j);
	    }
	    return res;
	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
