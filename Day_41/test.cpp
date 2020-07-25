// C++ program to find all the reachable nodes 
// for every node present in arr[0..n-1]. 
#include <bits/stdc++.h> 
using namespace std; 

// This class represents a directed graph using 
// adjacency list representation 
class Graph 
{ 
public: 
	int V; // No. of vertices 

	// Pointer to an array containing adjacency lists 
	list<int> *adj; 

	Graph(int ); // Constructor 

	void addEdge(int, int); 

	vector<int> BFS(int, int, int []); 
}; 

Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list<int>[V+1]; 
} 

void Graph::addEdge(int u, int v) 
{ 
	adj[u].push_back(v); // Add w to v’s list. 
	adj[v].push_back(u); // Add v to w’s list. 
} 

vector<int> Graph::BFS(int componentNum, int src, 
									int visited[]) 
{ 
	// Mark all the vertices as not visited 
	// Create a queue for BFS 
	queue<int> queue; 

	queue.push(src); 

	// Assign Component Number 
	visited[src] = componentNum; 

	// Vector to store all the reachable nodes from 'src' 
	vector<int> reachableNodes; 

	while(!queue.empty()) 
	{ 
		// Dequeue a vertex from queue 
		int u = queue.front(); 
		queue.pop(); 

		reachableNodes.push_back(u); 

		// Get all adjacent vertices of the dequeued 
		// vertex u. If a adjacent has not been visited, 
		// then mark it visited nd enqueue it 
		for (auto itr = adj[u].begin(); 
				itr != adj[u].end(); itr++) 
		{ 
			if (!visited[*itr]) 
			{ 
				// Assign Component Number to all the 
				// reachable nodes 
				visited[*itr] = componentNum; 
				queue.push(*itr); 
			} 
		} 
	} 
	return reachableNodes; 
} 

// Display all the Reachable Nodes from a node 'n' 
void displayReachableNodes(int n, 
			unordered_map <int, vector<int> > m) 
{ 
	vector<int> temp = m[n]; 
	for (int i=0; i<temp.size(); i++) 
		cout << temp[i] << " "; 

	cout << endl; 
} 

// Find all the reachable nodes for every element 
// in the arr 
void findReachableNodes(Graph g, int arr[], int n) 
{ 
	// Get the number of nodes in the graph 
	int V = g.V; 

	// Take a integer visited array and initialize 
	// all the elements with 0 
	int visited[V+1]; 
	memset(visited, 0, sizeof(visited)); 

	// Map to store list of reachable Nodes for a 
	// given node. 
	unordered_map <int, vector<int> > m; 

	// Initialize component Number with 0 
	int componentNum = 0; 

	// For each node in arr[] find reachable 
	// Nodes 
	for (int i = 0 ; i < n ; i++) 
	{ 
		int u = arr[i]; 

		// Visit all the nodes of the component 
		if (!visited[u]) 
		{ 
			componentNum++; 

			// Store the reachable Nodes corresponding to 
			// the node 'i' 
			m[visited[u]] = g.BFS(componentNum, u, visited); 
		} 

		// At this point, we have all reachable nodes 
		// from u, print them by doing a look up in map m. 
		cout << "Reachable Nodes from " << u <<" are\n"; 
		displayReachableNodes(visited[u], m); 
	} 
} 

// Driver program to test above functions 
int main() 
{ 
	// Create a graph given in the above diagram 
	int V = 5; 
	Graph g(V); 
	g.addEdge(5, 4); 
	//g.addEdge(2, 5); 
	g.addEdge(3, 2); 
	g.addEdge(1, 2); 
	//g.addEdge(5, 6); 
	//g.addEdge(5, 7); 

	// For every ith element in the arr 
	// find all reachable nodes from query[i] 
	int arr[] = {1,2,3, 4, 5}; 

	// Find number of elements in Set 
	int n = sizeof(arr)/sizeof(int); 

	findReachableNodes(g, arr, n); 

	return 0; 
} 
