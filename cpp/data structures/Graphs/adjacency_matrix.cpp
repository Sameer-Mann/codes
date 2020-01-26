#include <iostream>
#include <unordered_map>
#include <queue>
#include <climits>
using namespace std;
// sv is the starting vertex
// this is also called dfs traversal
// here this printdfs function is valid only for a connected graph
void printDFS(int** edges,int n,int sv,unordered_map<int,bool> &isv){
	isv[sv] = true;
	cout<<sv<<",";
	for (int i = 0; i < n; ++i)
	{
		if(edges[sv][i] == 1){
			if(isv.find(i) != isv.end()){
				continue; 
			}
			else
			{
				isv[i] = true;
				printDFS(edges,n,i,isv);
			}
		}
	}
}
// to also cover disconnected graphs after calling the pringdfs function for the first time
// i will iterate over all the elements and see which elements are not present in my isvisited map
// whenever i find any unvisited no. i call the printdfs function from that no.
void dfs(int** edges, int n){
	unordered_map<int,bool>isv;
	printDFS(edges,n,0,isv);cout<<endl;
	for(int i = 0;i < n;i++){
		if(isv.find(i) == isv.end()){
			printDFS(edges,n,i,isv);cout<<endl;
		}
	}
}
void bfs1(int sv,int n,int **edges,unordered_map<int ,bool> &isv){
	queue<int>q;
	q.push(sv);
	isv[sv] = true;
	while(!q.empty()){
		int front = q.front();
		cout<<front<<",";
		q.pop();
		for (int i = 0; i < n; i++)
		{
			if(edges[front][i] == 1){
				if(isv.find(i) != isv.end()){
					continue;
				}
				if(isv.find(i) == isv.end()){
					q.push(i);
					isv[i] = true;
				}
			}
		}
	}
}
bool hasPath(int start,int end,unordered_map<int,bool> &isv,int** edges,int n){
	isv[start] = true;
	for (int i = 0; i < n; ++i)
	{
		if(edges[start][i] == 1){
			if(isv.find(i) == isv.end()){
				if(i == end){
					isv[i] = true;
					return true;
				}
				isv[i] = true;
				hasPath(i,end,isv,edges,n);
			}else{
				continue;
			}
		}
	}
	return false;
}
void bfs(int** edges,int n){
	unordered_map<int ,bool>isv;
	bfs1(0,n,edges,isv);cout<<endl;
	for(int i = 0;i < n;i++){
		if(isv.find(i) == isv.end()){
			bfs1(i,n,edges,isv);cout<<endl;
		}
	}
}
// this uses the bfs algorithm to calculate the shortest path to all other nodes from a given starting node
// it is true for unweighted graph only in this form
// we have maintained record of the parent element as we know that the distance of all children from their parent node is always 1 and it is the shortest
void shortest_path(int sv,int n,int **edges,unordered_map<int ,int> dist){
	queue<int>q;
	unordered_map<int,int> parent;
	for (int i = 0; i < n; ++i)
	{
		dist[i] = INT_MAX;
	}
	q.push(sv);
	dist[sv] = 0;
	parent[sv] = sv;
	while(!q.empty()){
		int front = q.front();
		cout<<front<<",";
		q.pop();
		for (int i = 0; i < n; i++)
		{
			if(edges[front][i] == 1){
				if(dist[i] == INT_MAX){
					q.push(i);
					dist[i] = dist[front]+1;
					parent[i] = front;
				}
			}
		}
	}
	for(auto i:dist){
		cout<<"Distance of "<<i.first<<" from "<<sv<<" is "<<i.second<<endl;
	}
}
// topological sort only works for DAG(Directed Acyclic Graph) it outputs linear ordering of vertices
// such that for every edge(u->v) vertex u comes before vertex v in the ordering
int main(){
	// no. of vertices and no. of edges
	unordered_map<int ,bool>isv;
	unordered_map<int ,int>dist;
	int n;int e;
	cin>>n>>e;
	int** edges = new int*[n]; 
	for (int i = 0; i < n; ++i)
	{
		edges[i] = new int [n];
		for (int j = 0; j < n; ++j)
		{
			edges[i][j] = 0;
		}
	}
	for (int i = 0; i < e; ++i)
	{
		int first,sec;
		cin>>first>>sec;
		// considering the graph is bidirectional
		edges[first][sec] = 1;
		edges[sec][first] = 1;
	}
	// dfs(edges,n);
	bfs1(1,n,edges,isv);
	// shortest_path(0,n,edges,dist);
	// if(hasPath(0,3,isv,edges,n)){
	// 	cout<<"YES"<<endl;
	// }else{
	// 	cout<<"NO"<<endl;
	// }
	delete[] edges;
	return 0;
}