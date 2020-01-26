#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <list>
#include <queue>
#include <string>
using namespace std;
// a graph for input it contains a cycle
// 6 7
// 0 1
// 0 4
// 1 2
// 2 4
// 2 3
// 3 4
// 5 3
template<typename T>
class Graph
{
	unordered_map<T,list<T> > adjList;
public:
	Graph(){

	}
	void addEdge(T u, T v,bool bidir = true)
	{
		adjList[u].push_back(v);
		if(bidir)
		{
			adjList[v].push_back(u);
		}
	}
	void print(){
		for(auto i:adjList){
			cout<<i.first<<"->";
			for(auto val:i.second){
				cout<<val<<",";
			}
			cout<<endl;
		}
	}
	void dfsHelper(T node,unordered_map<T ,bool>&isv){
		// Whenever we come to a node, mark it visited
		isv[node] = true;
		cout<<node<<" ";
		// to find out a node which is neighbour of current node and not yet visited
		for(T neighbour:adjList[node]){
			if(!isv[neighbour]){
				dfsHelper(neighbour,isv);
			}
		}
	}
	void dfs(T src){
		unordered_map<T,bool>isv;
		int component = 1;
		dfsHelper(src,isv);
		cout<<endl;
		for(auto i:adjList){
			T city = i.first;
			if(!isv[city]){
				dfsHelper(city,isv);cout<<endl;
				component++;
			}
		}
		cout<<"The current graph has "<<component<<" components"<<endl;
	}
	void Helper(T node,map<T ,bool> &visited,list<T>&ordering){
		visited[node] = true;
		// will call dfs oon the unviseted neighbours of the current node
		for(T neighbour:adjList[node]){
			if(!visited[neighbour]){
				Helper(neighbour,visited,ordering);
			}
			// at this point all the children of the current node have been visited
			// so we can add current node to the list
			ordering.push_front(node);
		}
	}
	void dfsTopologicalSort(){
		map<T , bool>visited;
		list<T> ordering;
		for(auto i:adjList){
			// i is a pair of node followed a list of node
			T node = i.first;
			if(!visited[node]){
				Helper(node,visited,ordering);
			}
		}
		for(T elm:ordering){
			cout<<elm<<"-->";
		}
	}
	// u have to call it from every node to cover all the cases of traversal
	bool isCyclic(T src){
		unordered_map<T,bool> isv;
		unordered_map<T,int> parent;
		queue<T> q;
		q.push(src);
		isv[src] = true;
		parent[src] = src;
		while(!q.empty()){
			T node = q.front();
			q.pop();
			// we are iterating over the children of the particular neighbour
			for(T neighbour:adjList[node]){
				// this condition means any node which not the parent of the current node but which has already been visited
				// that can only be possible when there is a cycle present in the graph
				// neighbours are all the children of node
				if(isv[neighbour] == true && parent[node] != neighbour){
					return true;
				}else if(!isv[neighbour]){
					isv[neighbour] = true;
					parent[neighbour] = node;
					q.push(neighbour);
 				}

			}
		}
		return false;
	}
	bool isCyclicDFSHelper(T node,unordered_map<T,bool>&isv,unordered_map<T,bool>&inStack){
		isv[node] = true;
		inStack[node] = true;
		for(T neighbour:adjList[node]){
			// two things are possible
			// the current node is not visited but further branch is leading to a cycle
			if(!isv[node] && (isCyclicDFSHelper(neighbour,isv,inStack) || inStack[neighbour] == true)){
				return true;
			}
		}
		inStack[node] = false;
		return false;
	}
	bool isCyclicDFS(){
		unordered_map<T,bool>isv;
		unordered_map<T,bool>inStack;
		// i have to check for a cycle in each dfs tree
		for(auto i:adjList){
			T node = i.first;
			if(!isv[node]){
				bool cyclePresent = isCyclicDFSHelper(node,isv,inStack);
				if(cyclePresent){
					return true;
				}else{
					return false;
				}
			}
		}
	}
};
int main()
{
	// Graph<string>g;
	/*g.addEdge("Amritsar","Jaipur");g.addEdge("Amritsar","Delhi");g.addEdge("Delhi","Jaipur");g.addEdge("Mumbai","Jaipur");g.addEdge("Mumbai","Bhopal");g.addEdge("Delhi","Bhopal");g.addEdge("Mumbai","Bangalore");g.addEdge("Agra","Delhi");g.addEdge("Amdaman","Nicobar");
	input for topological sort
	g.addEdge("English","Programming Logic",false);g.addEdge("Maths","Programming Logic",false);g.addEdge("Programming Logic","HTML",false);g.addEdge("Programming Logic","Python",false);g.addEdge("Programming Logic","Java",false);g.addEdge("Programming Logic","JS",false);g.addEdge("Python","Web Dev",false);g.addEdge("CSS","JS",false);g.addEdge("HTML","CSS",false);g.addEdge("JS","Web Dev",false);g.addEdge("Java","Web Dev",false);g.addEdge("Python","Web Dev",false);g.dfsTopologicalSort();g.dfs("Amritsar");*/
	Graph<int> g;
	g.addEdge(0,2,false);
	g.addEdge(0,1,false);
	g.addEdge(2,4,false);	
	g.addEdge(2,3,false);
	g.addEdge(3,0,false);
	g.addEdge(4,5,false);
	g.addEdge(1,5,false);
	cout<<g.isCyclicDFS()<<endl;
	return 0;
}