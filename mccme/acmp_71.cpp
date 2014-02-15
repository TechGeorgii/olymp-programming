// Problem http://acmp.ru/index.asp?main=task&id_task=71
// accepted. Knapsack dynamic programming solution.

#include <iostream>
#include <vector>

using namespace std;

void main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, sa = 0;
	cin >>n;

	vector<int> A(n);
	for (int i = 0;i < n;i++)
	{
		cin >>A[i];
		sa += A[i];
	}

	vector<int> D(sa + 1, INT_MAX);
	D[sa] = sa;

	for (int i = 0;i < n;i++)
	{
		for (int s = 0;s <= sa;s++)
		{
			if (s - A[i] >= 0 && D[s] != INT_MAX)
				D[s - A[i]] = min(D[s - A[i]], 
				abs((s - A[i]) - (sa - (s - A[i]))));
		}
	}

	int res = INT_MAX;
	for (int i = 0;i < D.size();i++)
		res = min(res, D[i]);

	cout <<res;
}
