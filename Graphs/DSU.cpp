#include<bits/stdc++.h>
using namespace std;

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
                size(i)=1;
            }
        }

        int findUpar(int node){
            if(node == parent[node]) return node;
            return parent[node]=findUpar(parent[node])
        }

        void unionbyrank(int u, int v){
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

        void unionbysize(int u, int v){
            ulp_u = findUpar(u);
            ulp_v = findUpar(v);
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
}

int main(){
    DSU ds(5);

    return 0;
}