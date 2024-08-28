//User function Template for C++

class Solution {
  public:
    int t=1;
    void dfs(int x,int par,vector<int>& vis,vector<int>&tin,vector<int>& low,vector<int>adj[],vector<int>& mark){
        vis[x]=1;
        tin[x]=low[x]=t;
        t++;
        int child=0;
        for(auto c:adj[x]){
            if(c==par)continue;
            if(vis[c]==0){
                dfs(c,x,vis,tin,low,adj,mark);
                low[x]=min(low[x],low[c]);
                if(low[c]>=tin[x]&&par!=-1){
                    mark[x]=1;
                }
                child++;
            }
            else{
                low[x]=min(low[x],tin[c]);
            }
        }
        if(child>1&&par==-1){
            mark[x]=1;
        }
    }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        vector<int> vis(V,0),tin(V),low(V);
        vector<int> mark(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,-1,vis,tin,low,adj,mark);
            }
        }
        vector<int> ans;
        for(int i=0;i<V;i++){
            if(mark[i]==1)ans.push_back(i);
        }
        if(ans.size()==0)return {-1};
        return ans;
    }
};
