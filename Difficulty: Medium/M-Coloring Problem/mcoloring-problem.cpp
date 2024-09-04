//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    bool isSafe(int node,int k,int color[],int n,bool graph[101][101])
    {
        for(int i=0;i<n;i++)
        {
            if(i!=node && graph[i][node]==1 && color[i]==k)
            return false;
        }
        return true;
    }
    bool func(int node,int m,int color[],bool graph[101][101],int n)
    {
        if(node==n)
        return true;
        for(int k=1;k<=m;k++)
        {
            if(isSafe(node,k,color,n,graph))
            {
                color[node]=k;
                if(func(node+1,m,color,graph,n))
                return true;
                color[node]=0;
            }
        }
        return false;
    }
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        int color[n]={0};
        if(func(0,m,color,graph,n))
        return true;
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends