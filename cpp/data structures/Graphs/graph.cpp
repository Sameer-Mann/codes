#include <iostream>
#include <unordered_map>
#include <list>
#include <string>
using namespace std;
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
};
int main()
{
	Graph<string>g;
	g.addEdge("Putin","Trump",false);
	g.addEdge("Putin","Modi",false);
	g.addEdge("Putin","Pope",false);
	g.addEdge("Modi","Trump",false);
	g.addEdge("Modi","Yogi",false);
	g.addEdge("Modi","Trump",true);
	g.addEdge("Yogi","Prabhu",false);
	g.addEdge("Prabhu","Modi",false);
	g.print();
	return 0;
}