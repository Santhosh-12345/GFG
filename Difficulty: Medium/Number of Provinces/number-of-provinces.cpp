//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs_traverse(vector<vector<int>>&adjList,vector<int>&vis,int node
    ,vector<int>&dfs)
    {
        vis[node]=1;
        dfs.push_back(node);
        for(auto it:adjList[node])
        {
            if(!vis[it])
            dfs_traverse(adjList,vis,it,dfs);
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<vector<int>>adjList(V);
        vector<int>vis(V,0);
        int count=0;
        vector<int>dfs;
        for(int i=0;i<adj.size();i++)
        {
            for(int j=0;j<adj[0].size();j++)
            {
                if(adj[i][j]==1 && i!=j)
                {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                count++;
                dfs_traverse(adjList,vis,i,dfs);
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends