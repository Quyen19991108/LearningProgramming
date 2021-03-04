#include<iostream>

using namespace std;
#define NUM_NODE 5

int graph[NUM_NODE][NUM_NODE] = { 
{0, 1, 1, 0, 0},
{1, 0, 1, 1, 0},
{1, 1, 0, 1, 1},
{0, 1, 1, 0, 1},
{0, 0, 1, 1, 0} };
void Show_Matrix(int** a,int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
bool CheckSymmetryGraph(int** graph, int n)
{
	for(int i = 0; i < n;i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(graph[i][j]!=graph[j][i])
			{
				return false;
			}
		}
		return true;
	}
}
bool LienThong(int** _graph, int n)
{
	bool* visited = new bool[NUM_NODE];
	for (int i = 0; i < NUM_NODE; i++)
	{
		visited[i] = false;
	}
	visited[0] = true;
	int count = 1;
	bool success;
	do
	{
		success = true;
		for (int i = 0; i < NUM_NODE; i++)
		{
			if (visited[i])
			{
				for (int j = 0; j < NUM_NODE; j++)
				{
					if (visited[i] == false && _graph[i][j] > 0)
					{
						visited[i] = true;
						success = false;
						count++;
						if (count == NUM_NODE) return true;
					}

				}
			}
		}
	} while (success == false);
}
int main()
{
	int** _graph = new int* [NUM_NODE];
	for (int i = 0; i < NUM_NODE; i++)
	{
		_graph[i] = new int[NUM_NODE];
	}
	for (int i = 0; i < NUM_NODE; i++)
	{
		for (int j = 0; j < NUM_NODE; j++)
		{
			_graph[i][j] = graph[i][j];
		}
	}
	Show_Matrix(_graph, NUM_NODE);
	cout << CheckSymmetryGraph(_graph,NUM_NODE);
	cout << endl<< LienThong(_graph, NUM_NODE);
}

// Tham khảo : http://www.hoclaptrinh.xyz/2014/07/code-cc-xet-tinh-lien-thong-cua-o-thi.html