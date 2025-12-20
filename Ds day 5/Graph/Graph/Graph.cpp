#include <iostream>
#include <queue>
#include <stack>
#include <climits>
using namespace std;

string redColor = "\033[31m", greenColor = "\033[32m", defaultANSI = "\033[0m";

template<class vertexType>
class Graph {
	int numOfVertices; // number of current vertices
	vertexType vertices[50]; // list of	vertices names (max 50) => vertices[0] = "Cairo"
	int edges[50][50]; //Adjacency matrix (store weights) => edges[0][1] = 100 
	bool marks[50]; //check if I visited this node or not yet

public:
	Graph() {
		numOfVertices = 0;
		for (int i = 0; i < 50; i++) {
			marks[i] = false;
			for (int j = 0; j < 50; j++) {
				edges[i][j] = 0;
			}
		}
	}
	bool isFull() { return numOfVertices == 50; }
	bool isEmpty() { return numOfVertices == 0; }
	void makeEmpty() {
		for (int i = 0; i < 50; i++) {
			marks[i] = false;
			for (int j = 0; j < 50; j++) {
				edges[i][j] = 0;
			}
		}
		numOfVertices = 0;
	}
	int getIndex(const vertexType& vertex) {
		for (int i = 0; i < numOfVertices; i++) {
			if (vertices[i] == vertex) {
				return i;
			}
		}
		return -1;
	}
	void addVertex(const vertexType& vertex) {
		if (numOfVertices == 50) {
			cout << redColor << "Graph is full..." << defaultANSI << endl;
		}
		else {
			vertices[numOfVertices] = vertex;
			numOfVertices++;
		}
	}
	void addEdge(vertexType startVertex, vertexType endVertex, int weight) {
		int startIndex = getIndex(startVertex);
		int endIndex = getIndex(endVertex);
		if (startIndex == -1 || endIndex == -1) {
			cout << redColor << "Error: One of the vertices does not in the matrix..." << defaultANSI << endl;
		}
		else {
			edges[startIndex][endIndex] = weight;
		}
	}
	void clearMarks() {
		for (int i = 0; i < 50; i++)marks[i] = false;
	}
	void markVertex(const vertexType& vertix) {
		int index = getIndex(vertix);
		if (index == -1) {
			cout << redColor << "Error: vertix not in the matrix..." << defaultANSI << endl;
		}
		else {
			marks[index] = true;
		}
	}
	bool isMarked(const vertexType& vertix) {
		int index = getIndex(vertix);
		if (index == -1) return false;
		else return marks[index];

	}
	void getAdjacentVertices(const vertexType vertex, queue<vertexType>& vertexNeighbors) {
		int row = getIndex(vertex);
		if (row == -1)
			cout << redColor << "Error: vertix not in the matrix..." <<defaultANSI<< endl;
		else
			for (int column = 0; column < numOfVertices; column++) {
				if (edges[row][column] != 0) vertexNeighbors.push(vertices[column]);
			}

	}
	int getPathWeight(vertexType startVertex, vertexType endVertix) {
		int startIndex = getIndex(startVertex);
		int endIndex = getIndex(endVertix);
		if (startIndex == -1 || endIndex == -1) {
			cout << redColor << "Error: one of verixes not in the matrix..." <<defaultANSI<< endl;
			return 0;
		}
		else {
			return edges[startIndex][endIndex];
		}
	}
	void DepthFirstSearch(const vertexType startVertex, const vertexType endVertex) {
		stack<vertexType> paths;
		clearMarks(); //reset the graph
		paths.push(startVertex); // put the current location on stack
		markVertex(startVertex); //mark the start node as visited

		while (!paths.empty()) {
			vertexType currentVertex = paths.top();
			paths.pop();
			if (currentVertex == endVertex) {
				cout << greenColor << currentVertex << defaultANSI << endl;
				return;
			}
			else {
				cout << currentVertex << "->";
				queue<vertexType> neighbors;
				getAdjacentVertices(currentVertex, neighbors);
				while (!neighbors.empty()) {
					vertexType neighbor = neighbors.front();
					neighbors.pop();

					if (isMarked(neighbor) == false)
					{
						markVertex(neighbor);
						paths.push(neighbor);
					}
				}
			}
		}
		cout << redColor << "Target not found." << defaultANSI << endl;
	}
	void BreadthFirstSearch(const vertexType startVertex, const vertexType endVertex) {
		clearMarks();
		queue<vertexType> paths;
		paths.push(startVertex);
		markVertex(startVertex);
		while (!paths.empty()) {
			vertexType currentVertex = paths.front();
			paths.pop();
			if (currentVertex == endVertex) {
				cout << greenColor << currentVertex << defaultANSI << endl;
				return;
			}
			else {
				cout << currentVertex << "->";
				queue<vertexType> neighbors;
				getAdjacentVertices(currentVertex, neighbors);
				while (!neighbors.empty()) {
					vertexType neighbor = neighbors.front();
					neighbors.pop();
					if (isMarked(neighbor) == false) {
						markVertex(neighbor);
						paths.push(neighbor);
					}
				}
			}
		}
		cout << redColor << "Target not found." << defaultANSI << endl;
	}
	void Dijkstra(const vertexType& startVertex) {
		//create Distance array to store distances of each node from the start node
		int distance[50];
		fill(distance, distance + 50, INT_MAX);

		int startIndex = getIndex(startVertex);
		if (startIndex == -1) {
			cout << redColor << "this Vertex not found in the matrix..." << defaultANSI << endl;
			return;
		}
		distance[startIndex] = 0;

		//create priority queue to store each node with the samllest distance found
		priority_queue<pair<int, vertexType>, vector<pair<int, vertexType>>, greater<pair<int, vertexType>>> pq;
		pq.push({ 0,startVertex });

		//
		while (!pq.empty()) {
			vertexType currentVertex = pq.top().second;
			int currentDistance = pq.top().first;
			pq.pop();
			//Is distance of pulled Pqueue [BiggerThan] distance of what in the distance array    
			if (currentDistance > distance[getIndex(currentVertex)])
				continue;

			queue<vertexType> neighbors;
			getAdjacentVertices(currentVertex, neighbors);
			while (!neighbors.empty()) {
				vertexType neighbor = neighbors.front();
				neighbors.pop();
				int newDistance = distance[getIndex(currentVertex)] + edges[getIndex(currentVertex)][getIndex(neighbor)];
				if (newDistance < distance[getIndex(neighbor)]) {
					distance[getIndex(neighbor)] = newDistance;
					pq.push({ newDistance,neighbor });
				}
			}
		}

		cout << "Shortest paths from " << startVertex << ": " << endl;
		for (int i = 0; i < numOfVertices; i++) {
			if (distance[i] != 0) {
				cout << "To " << vertices[i] << ": ";
				if (distance[i] == INT_MAX)cout << "Unreachable" << endl;
				else cout << distance[i] << " KM" << endl;
			}
		}
	}
};

int main(){
	Graph<string> myMap;
	myMap.addVertex("Cairo");
	myMap.addVertex("Alex");
	myMap.addVertex("Tanta");
	myMap.addVertex("Matruh");

	myMap.addEdge("Cairo", "Tanta", 90);
	myMap.addEdge("Tanta", "Alex", 100);
	myMap.addEdge("Cairo", "Alex", 220);
	myMap.addEdge("Alex", "Matruh", 290);

	cout << greenColor << "DFS From Cairo To Matruh: " << defaultANSI << endl;
	myMap.DepthFirstSearch("Cairo", "Matruh");
	cout << "-----------------------------------------------------" << endl;

	cout << greenColor << "BFS From Cairo To Matruh: " << defaultANSI << endl;
	myMap.BreadthFirstSearch("Cairo", "Matruh");
	cout << "-----------------------------------------------------" << endl;

	cout << greenColor << "Dijkstra algorithm: " << defaultANSI << endl;
	myMap.Dijkstra("Cairo");


	return 0;
}
