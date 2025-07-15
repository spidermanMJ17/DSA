//to find MST using DSU

// first sort all the edges according to weight
// User function Template for C++
class DSU {
    private:
        vector<int> parent, rank, size;
    public:
        DSU(int n){
            rank.resize(n+1,0);
            parent.resize(n+1);
            size.resize(n+1,0);
            for(int i =0;i<=n;i++){
                parent[i]=i;
                size[i]=1;
            }
        }

        int findUpar(int node){
            if(node == parent[node]) return node;
            return parent[node]=findUpar(parent[node]);
        }

        void unionbysize(int u, int v){
            int ulp_u = findUpar(u);
            int ulp_v = findUpar(v);
            if(ulp_u == ulp_v) return;
            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            } 
            else{
                parent[ulp_v]=ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
};
class Solution {
  public:
    int kruskalsMST(int V, vector<vector<int>> &newedges) {
        // code here
        DSU ds(V);
        
        vector<vector<int>> edges;
        for (auto &it : newedges) {
            edges.push_back({it[2], it[0], it[1]});
        }
        
        sort(edges.begin(), edges.end());
        int sum=0;
        
        for(auto it: edges){
            int wt = it[0];
            int u = it[1];
            int v = it[2];
            
            if(ds.findUpar(u) != ds.findUpar(v)){
                sum += wt;
                ds.unionbysize(u,v);
            }
        }
        return sum;
        
    }
};