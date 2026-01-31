class Solution {
public:
void dfs(int node,int parent,vector<vector<int>>&adj,vector<int>&disc,vector<int>&low,vector<bool>&visited,vector<vector<int>>&bridges,int count)
{
    disc[node]=low[node]=count; //initially same rehta h
    visited[node]=true;
    for(int j=0;j<adj[node].size();j++)
    {
        int neigh=adj[node][j];
        if(neigh==parent)
        continue;
        else if(visited[neigh]){
            low[node]= min(low[node],low[neigh]);
        }
        else{
            count++;
            dfs(neigh,node,adj,disc,low,visited,bridges,count);
            //if bridge exist or not
            if(low[neigh]>disc[node]){
                vector<int>temp;
                temp.push_back(node);
                temp.push_back(neigh); 
                bridges.push_back(temp);
            }
            low[node]= min(low[node],low[neigh]);
        }


    }
     
}
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);

        for(auto x:connections){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<vector<int>>bridges;
        vector<int>disc(n);
        vector<int>low(n);
        vector<bool>visited(n,false);
        int count=0;
        dfs(0,-1,adj,disc,low,visited,bridges,count);

        return bridges;
    }
};