/*
	Accepted.
	http://acmp.ru/?main=task&id_task=500
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

	vector<pair<int, int> > A(N);	// age, risk.
	for (int i = 0;i < N;i++)
	{
		cin >>A[i].first >>A[i].second;
	}
	sort(A.begin(), A.end());

	vector<int> D(N, INT_MAX);
	D[1] = A[1].second;	// для двух агентов, риск всегда равен риску старшего.

	for (int i = 2;i < N;i++)
	{
		D[i] = min(A[i].second + D[i-1], D[i]);		// соединяем текущего агента с предыдущим.
		if (i != N - 1)
			// текущего с предыдущим не соединяем, а соединяем со следующим.
			D[i+1] = min(D[i+1], D[i-1] + A[i+1].second);
	}

	cout <<D[N-1];

	return 0;
}
