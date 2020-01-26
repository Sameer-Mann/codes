// Dikkstra's Algorithm is used to find the single source shortes path. it is used to find the shortest path from the source node to all other nodes
// it works for weighted graphs with no negative weight cycle.works for bidirectional as well as directed graphs
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
template<typename T>
class Graph
{
	unordered_map<T,vector<pair<T,int> > >m;
public:
	void addEdge(T u,T v,int dist,bool bidir=true)
	{
		m[u].push_back(make_pair(v,dist));
		if(bidir){
			m[v].push_back(make_pair(u,dist));
		}
	}
	void printAdj()
	{
		for(auto i:m)
		{
			cout<<i.first<<"-->";
			for(auto j:i.second)
			{
				cout<<"("<<j.first<<","<<j.second<<")";
			}
			cout<<endl;
		}

	}
// the working principle here is that at every step starting from the source node we will always pick the edge which has the 
// minimum weight to it so at every step we push the children of the current node into our set(provided if not already present)
// if they are already present, then we compare their distance with the current distance and update it if it is less
// we do so repeatedly until our set becomes empty
	void dijkstra(T src)
	{
		unordered_map<T,int>dist;
		for(auto i:m)
		{
			dist[i.first] = INT_MAX;
		}
		// make a set to find out the node with minimum distance
		// sorting in set is always according to the first parameter
		set<pair<int, T> >s;
		dist[src] = 0;
		s.insert(make_pair(0,src));
		while(!s.empty())
		{
			// Find the pair at the front
			auto p = *(s.begin());
			T node = p.second;

			int nodeDist = p.first;
			s.erase(s.begin());
			// iterate over the neighbours of the current node
			for(auto childPair:m[node])
			{
// if the distance of the children node is smaller than what was the previously stored distance for that node than we update it
				if(nodeDist + childPair.second < dist[childPair.first])
				{
					// updation of a particular node is not possible in set
					// so we delete the old pair and insert the new pair
					T dest = childPair.first;
					auto f = s.find(make_pair(dist[dest],dest));
					// means if element found then removing it
					if(f!=s.end())
					{
						s.erase(f);
					}
					// now inserting the new distance of the node as it is lesser
					dist[dest] = nodeDist + childPair.second;
					s.insert(make_pair(dist[dest],dest));
				}
			}
		}
		for(auto i:dist)
		{
			cout<<i.first<<"is at a distance of "<<i.second<<endl;
		}
	}
};
int main()
{
	Graph<int>g;
	g.addEdge(1,2,1);g.addEdge(1,3,4);g.addEdge(2,3,1);g.addEdge(3,4,2);g.addEdge(1,4,7);
	// g.printAdj();
	g.dijkstra(1);
	return 0;
}