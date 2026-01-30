class Solution {
public:
    vector<int> topo(vector<int>&result,vector<int> &indegree,int n,vector<vector<int>>adj)
    {
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
                result.push_back(i);
                
            }
        }
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            for(auto x:adj[temp]){
                indegree[x]--;
                
                if(indegree[x]==0){
                    q.push(x);
                    result.push_back(x);
                }

            }
        }
        if(result.size()!=n) return {};
        return result;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        int n=numCourses;
        vector<int> indegree(n);
        vector<vector<int>>adj(n);
        for(auto x:pre){
            adj[x[1]].push_back(x[0]);
            indegree[x[0]]++;
        }
        vector<int>result;
        
        return topo(result,indegree,n,adj);
    }
};