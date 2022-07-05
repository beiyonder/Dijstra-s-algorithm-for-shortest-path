//Siddharth
#include <bits/stdc++.h>
using namespace std;

// function to find the vertex with minimum distance value, from the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool isShortestPath[])
{
	
	int min = INT_MAX, min_index;
	for (int i = 0; i < 9; i++)
		if (isShortestPath[i] == false && dist[i] <= min)
			min = dist[i], min_index = i;
	return min_index;
}

// Function to print shortest path from source to j using parent array
void printPath(int parent[], int j)
{
	// Base Case : If j is source
	if (parent[j] == -1)
		return;
	printPath(parent, parent[j]);
	cout << j << " ";
}

// A utility function to print the constructed distance
// array
void printSolution(int dist[], int n, int parent[])
{
	int source = 1;
	cout << "Vertex\t Distance\tPath";
	for (int i = 1; i < 9; i++) {
		printf("\n%d -> %d \t\t %d\t\t%d ", source, i, dist[i],
			source);
		printPath(parent, i);
	}
}

// Dijkstra's single source function implementation
void dijkstra(int graph[9][9], int source)
{
	// The output array. dist[i] will hold the shortest distance from source to i
	int dist[9];
	bool isShortestPath[9] = { false };
	int parent[9] = { -1 };
	for (int i = 0; i < 9; i++)
		dist[i] = INT_MAX;

	
	dist[source] = 0;

	for (int count = 0; count < 9 - 1; count++) {
		int u = minDistance(dist, isShortestPath);
		isShortestPath[u] = true;
		for (int v = 0; v < 9; v++)
			if (!isShortestPath[v] && graph[u][v]
				&& dist[u] + graph[u][v] < dist[v]) {
				parent[v] = u;
				dist[v] = dist[u] + graph[u][v];
			}
	}
	printSolution(dist, 9, parent);
}

int main()
{
	//example input
	int graph[9][9] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
						{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
						{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
						{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
						{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
						{ 0, 0, 4, 0, 10, 0, 2, 0, 0 },
						{ 0, 0, 0, 14, 0, 2, 0, 1, 6 },
						{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
						{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
	dijkstra(graph, 0);
	return 0;
}


