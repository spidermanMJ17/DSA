#include<bits/stdc++.h>
using namespace std;

class DSU {
    private:
        vector<int> parent, rank;
    public:
        DSU(int n){
            rank.resize(n+1,0);
            parent.resize(n+1);
            for(int i =0;i<=n;i++){
                parent[i]=i;
            }
        }

        findUpar(int node){
            if(node == parent[node]) return node;
            return parent[node]=findUpar(parent[node])
        }

        unionbyrank(int u, int v){
            ulp_u = findUpar(u);
            ulp_v = findUpar(v);
            if(ulp_u == ulp_v) return;
            if(rank[ulp_u] < rank[ulp_v]){
                parent[ulp_u] = ulp_v;
            } 
            else if(rank[ulp_v]<rank[ulp_u]){
                parent[ulp_v]=ulp_u;
            }
            else{
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }
}