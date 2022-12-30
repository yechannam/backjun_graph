#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

void dfs(int arr[][2000], int i, int n, int (*result)[2000])
{
	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < n; j++)
	//	{
	//		cout << arr[i][j] << ' ';
	//	}
	//	cout << endl;
	//}
	int j = 0;
	while (j < n)
	{
		if (arr[i][j] == 1)
		{
			(*result)[j] = 1;
			if (i < j)
				dfs(arr, j, n, result);
		}
		j++;
	}
}

int main()
{
	int n, m = 0;
	int a, b;
	int flag = 1;

	cin >> n >> m;
	int arr[n][2000];
	int result[2000] = {};

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j]=0;
		}
	}
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	dfs(arr, 0, n, &result);
	for (int i = 0; i < n; i++)
	{
		cout << result[i] << ' ';
		if(result[i] == 0)
			flag = 0;
	}
	cout << endl;
	if (flag == 1)
		cout << '1';
	else
		cout << '0';
}