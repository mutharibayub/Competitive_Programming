#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int upperDiv(int numer, int denom)
{
	if (numer % denom == 0)
	{
		return numer / denom;
	}
	else
	{
		return numer / denom + 1;
	}
}

class Graph
{
	vector<vector<int>> edges;
	vector<vector<int>> tripCount;
	int nodes;
public:
	Graph(int nodes):nodes(nodes)
	{
		edges.assign(nodes, vector<int>(nodes, 9999999));
		tripCount.assign(nodes, vector<int>(nodes, 0));
	}
	void makeEdge(int index1, int index2, int magnitude)
	{
		edges[index1][index2] = magnitude;
		edges[index2][index1] = magnitude;
		tripCount[index1][index2] = 1;
		tripCount[index2][index1] = 1;
	}
	void printEdges()
	{
		for (int i = 0; i < nodes; i++)
		{
			for (int j = 0; j < nodes; j++)
			{
				cout << edges[i][j] << "\t";
			}
			cout << endl;
		}
	}
	void printTripCount()
	{
		for (int i = 0; i < nodes; i++)
		{
			for (int j = 0; j < nodes; j++)
			{
				cout << tripCount[i][j] << "\t";
			}
			cout << endl;
		}
	}
	void solveForShortest()
	{
		for (int i = 0; i < nodes; i++)
		{
			for (int j = 0; j < nodes; j++)
			{
				if (i == j) { continue; }
				for (int k = 0; k < nodes; k++)
				{
					if (k == i) { continue; }
					if (edges[k][i] + edges[i][j] < edges[j][k])
					{
						edges[j][k] = edges[k][i] + edges[i][j];
						tripCount[j][k] = tripCount[k][i] + tripCount[i][k];
					}
				}
			}
		}
	}
	int shortestPath(int index1, int index2)
	{
		return tripCount[index2][index1];
	}
};

class Path
{
public:
	int src;
	int dest;
	int len;
};

//string testCase(const string& input){}

int main()
{
	int testCases;;
	cin >> testCases;
	for (int i = 0; i < testCases; i++)
	{
		int cityCount, roadSegment;
		cin >> cityCount >> roadSegment;
		vector<Path> roadSegments(roadSegment, Path());
		for (int j = 0; j < roadSegment; j++)
		{
			cin >> roadSegments[j].src >> roadSegments[j].dest >> roadSegments[j].len;
		}
		int nsrc;
		int ndest;
		int limit;
		cin >> nsrc >> ndest >> limit;
		Graph g(cityCount);
		for (int j = 0; j < roadSegments.size(); j++)
		{
			g.makeEdge(roadSegments[j].src - 1, roadSegments[j].dest - 1, upperDiv(limit, roadSegments[j].len));
		}
		g.solveForShortest();
		cout<<g.shortestPath(nsrc - 1, ndest - 1)<<" trips" << endl;
	}
}