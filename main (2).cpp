#include<iostream>
#include <cstdlib>
#include<ctime>
using namespace std;


void CreateArray(int *&a, int n)
{
	int min = 0;
	int max = 1000000;
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		a[i] = min + rand() % (max - min);
	}
}
void ShowArray(int* a, int n)
{
	for(int i = 0; i < n; i++)
	{
		cout << a[i] << endl;
	}
}
void swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}
void QuickSort(int a[],int l,int r)
{
	if (l <= r)
	{
		int key = a[(l + r) / 2];
		int i = l;
		int j = r;
		while (i <= j)
		{
			while (a[i] < key)
				i++;
			
			while (a[j] > key)
				j--;
			if (i <= j)
			{
				swap(a[i], a[j]);
				i++;
				j--;
			}
		}
		if (l < j)
		{
			QuickSort(a, l, j);
		}
		if (r > i)
		{
			QuickSort(a, i, r);
		}
	}
}
struct node
{
	int value;
	node* left;
	node* right;
	int height;
};
struct avl_tree
{
	node* root;
	void Init()
	{
		root = NULL;
	}
};
int main(int argc, char* argv[])
{
	int n = atoi(argv[1]);
	int* arr = new int[n];
	CreateArray(arr, n);
	QuickSort(arr, 0, n - 1);
	ShowArray(arr, n);
	cout << endl << n;
	return 0;
}
