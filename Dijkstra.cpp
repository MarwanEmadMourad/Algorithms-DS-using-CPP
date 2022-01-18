#include <bits/stdc++.h>

using namespace std ;

void dijkstra(int start , vector<vector<int>> graph, vector <int> &shortest_distance , vector <bool> &visited) {
	priority_queue< pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> q ;
	q.push(make_pair(0,start));
	shortest_distance[start] = 0;
	while (q.size()) {
		pair<int, int> p = q.top();
		visited[p.second] = 1;
		q.pop();
		for (int i = 0; i < graph[p.second].size() ; i++) {
			if (graph[p.second][i] && !visited[i]) {
				shortest_distance[i] = min (shortest_distance[i] , graph[p.second][i] + shortest_distance[p.second]);
				q.push(make_pair(shortest_distance[i], i));
			}
		}
	}
}

int main()
{
	int graph_size = 20;
	// creating our graph and populating our graph
	vector<vector<int>> graph{
							  {0, 0, 0, 0, 0, 0, 9, 0, 5, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0},
							  {0, 0, 3, 0, 0, 0, 0, 0, 5, 0, 0, 11, 0, 0, 7, 11, 0, 0, 0, 0},
							  {0, 3, 0, 2, 0, 0, 0, 0, 9, 7, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0},
							  {0, 0, 2, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 3, 0, 0, 0, 0, 5, 0},
							  {0, 0, 0, 0, 0, 1, 0, 0, 9, 0, 0, 0, 7, 16, 0, 0, 0, 0, 0, 0},
							  {0, 0, 0, 0, 1, 0, 5, 3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
							  {9, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
							  {0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0},
							  {5, 5, 9, 3, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
							  {0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 11, 0},
							  {0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 7, 3, 0, 0},
							  {3, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0},
							  {0, 0, 0, 0, 7, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
							  {0, 0, 0, 3, 16, 0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7},
							  {0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 1, 0, 0},
							  {0, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 9, 0, 0},
							  {0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0},
							  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 1, 9, 0, 0, 0, 0},
							  {0, 0, 0, 5, 0, 0, 0, 0, 0, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9},
							  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 9, 0} };


	// array that will hold the shortest-distances from node 0 to the rest of the graph nodes 
	vector <int> shortest_distance(graph_size,1e9+8) ;
	// visited array to keep track of the already visited nodes in the graph
	vector <bool> visited (graph_size , 0);
	// the source node that we will caculate the shortest paths from
	int start_node = 0;
	
	// performing dijkstra
	dijkstra(start_node,graph, shortest_distance, visited); 

	// printing our result
	for (int i = 0; i < graph.size(); i++) {
		cout << "Shortest distance from node " << start_node+1 << " to node " << i+1 << " is: " << shortest_distance[i] << endl;
	}
}



