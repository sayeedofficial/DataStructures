#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;


void bfs(int **graph, int n) {

	bool *visited = new bool[n];
	for (int i = 0; i < n; i++) {
		visited[i] = false;
	}
	int sv = 0;

	queue<int> pendingVertices;
	pendingVertices.push(sv);
	visited[sv] = true;

	while (!pendingVertices.empty()) {

		int currentVertex = pendingVertices.front();
		pendingVertices.pop();
		cout << currentVertex << " ";
		for (int i = 0; i < n; i++) {
			if (graph[currentVertex][i] == 1 && !visited[i]) {
				pendingVertices.push(i);
				visited[currentVertex] = true;


			}
		}
	}
}

void dfs(int **graph, int n, int sv, int *visited) {

	visited[sv] = 1;
	for (int i = 0; i < n; i++) {
		if (graph[sv][i] == 1 && visited[i] == 0)
			dfs(graph, n, i, visited);
	}
}


int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;

	int **arr = new int*[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}





	return 0;
}
