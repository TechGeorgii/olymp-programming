/*
	Accepted
	http://acmp.ru/?main=task&id_task=329
*/

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <stack>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int N;
	cin >>N;

	vector<int> A(N + 1);
	for (int i = 0;i < N;i++)
		cin >>A[i + 1];

	vector<int> D(N + 1, 0);

	D[1] = A[1];	// чтобы наступить на первую ступеньку, нужно это взять это число по-любому.
	vector<int> P(N + 1, -1);

	for (int i = 2;i <= N;i++)
	{
		D[i] = A[i] + max(D[i-1], D[i-2]);
		if (D[i-1] > D[i-2])
			P[i] = i - 1;
		else
			P[i] = i - 2;
	}

	cout <<D[N] <<endl;

	vector<int> path;
	int p = N;
	while (1)
	{
		path.push_back(p);
		p = P[p];
		if (p == -1 || p == 0)
			break;
	}

	for (int i = path.size()-1;i >= 0;i--)
		cout <<path[i] <<" ";

	return 0;
}
