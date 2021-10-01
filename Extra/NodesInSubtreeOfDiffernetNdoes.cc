// CPP code to find number of nodes
#include <bits/stdc++.h>
using namespace std;

const int N = 8;

int count1[N];
vector<int> adj[N];

void numberOfNodes(int s, int e){
	vector<int>::iterator u;
	count1[s] = 1;
	for (auto x:adj[s]){
		if (x == e) continue;
		numberOfNodes(x, s);
		count1[s] += count1[x];
	}
}

void addEdge(int a, int b){
	adj[a].push_back(b);
	adj[b].push_back(a);
}

void printNumberOfNodes(){
	for (int i = 1; i < N; i++) {
		cout << "\nNodes in subtree of " << i;
		cout << ": " << count1[i];
	}
}
vector<int> v;
int vis[100];
void generate(int n){
	v.push_back(n);
	vis[n]=1;
	for(auto x:adj[n]){
		if(!vis[x])
			generate(x);
	}
	v.push_back(n);
}
vector<int> fun(int n,vector<int> a) {

  vector<vector<int>> ve(n/2+1);
  for(int i=0;i<n;++i) ve[a[i]].push_back(i);

vector<int> ans;
  for(int i=1;i<ve.size();++i) 
  	ans.push_back(abs(ve[i][0]-ve[i][1])/2+1);
  return ans;
}

int main()
{
	addEdge(1, 2);
	addEdge(1, 4);
	addEdge(1, 5);
	addEdge(2, 6);
	addEdge(4, 3);
	addEdge(4, 7);
	
	numberOfNodes(1, 0);
	//
	generate(1);
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;

	//
	int n=4;
	vector<int> a={1,2,2,1};
	vector<int> ans=fun(n,a);
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}

	//
	printNumberOfNodes();
	return 0;
}




