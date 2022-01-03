int maxn = 1e6+5;

int parent[maxn];
int rank[maxn];

void make_set(){
    for(int i=1;i<=n;i++){
        parent[i]=i;
        rank[i]=0;
    }
}

// 7 -> 6 -> 4 -> 3
int find_parent(int node){
    if(node==parent[node])
        return node;

    return parent[node]=find_parent(parent[node]);
}

void union(int a,int b){
    a=find_parent(a);
    b=find_parent(b);

    if(a!=b){
        if(rank[a]<rank[b])  swap(a,b);
        if(rank[a]>rank[b])  parent[b]=a;   
        if(rank[a]==rank[b]) parent[b]=a , rank[a]++;
    }
}

int main(){
    make_set();
    int m;cin>>m;
    while(m--){
        int a,b;cin>>a>>b;
        union(a,b);
    }

    // if 2 and 3 belong to the same component or not

    if(find_parent(2)!=find_parent(3)){
        cout<<"Different Component";
    }else {
        cout<<"Same";
    }
}
