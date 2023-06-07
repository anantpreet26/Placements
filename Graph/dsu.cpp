#include <bits/stdc++.h>
using namespace std;

// class of disjoint set 
class Disjoints{
    public:
    vector<int >parent,rank;
    //parent = {-1,-1,-1,-1,-1,-1,-1};
    //rank = {0,0,0,0,0,0,0};
    Disjoints(int value){
        parent.resize(value+1,-1);
        rank.resize(value+1,0);
    }
    // to find the ultimate parent 
    int find(int x){
        if(parent[x]==-1)return x;
        return parent[x]=find(parent[x]);
    }
    // to union two elements 
    void Union(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y) return;
        if(rank[x]>rank[y])parent[y]=x;
        else if(rank[x]<rank[y])parent[x]=y;
        else if(rank[x]==rank[y]) {
            parent[y]=x;
            rank[x]++;
        }
    }
};
int main(){
    //making a disjoint set
    Disjoints ds(7);
    // adding edges to the disjoint set
    ds.Union(0,1);
    ds.Union(1,2);
    ds.Union(2,3);
    ds.Union(3,4);
    ds.Union(6,5);
    ds.Union(6,7);

    // finding connected components
    int cnt = 0;
    for(auto i = 0 ;i<ds.parent.size();i++){
        if(ds.parent[i] == -1){
            cnt++;
            // cout<<i<<"->"<<ds.parent[i]<<endl;
        }
    }
    // printing connected components
    cout<<cnt<<endl;
    return 0;

}