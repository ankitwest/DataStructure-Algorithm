		//Union by rank(height)
		void Union(int x, int y, int *parent, int *rank)
		{
			int s1 = find(x, parent);
			int s2 = find(y, parent);
			if (s1 != s2)
			{
				if (rank[s1] > rank[s2])
				{
					parent[s2] = s1;
				}
				else if (rank[s1] < rank[s2])
				{
					parent[s1] = s2;
				}
				else
				{
					parent[s1] = s2;
					rank[s2]++;
				}
			}
		}


https://www.codechef.com/users/ashwanisri
void make_set(vll &parent,vll &rank,int v){
    parent[v]=v;
    rank[v]=0;
}
int find_set(vll &parent,int v){
    if(v==parent[v]){
        return v;
    }
    return parent[v]=find_set(parent,parent[v]);
}
void union_sets(vll &parent,vll &rank,int a,int b){
    a=find_set(parent,a);
    b=find_set(parent,b);
    if(a!=b){
        if(rank[a]<rank[b]){
            swap(a,b);
        }
        parent[b]=a;
        if(rank[a]==rank[b]){
            rank[a]++;
        }
    }
}
