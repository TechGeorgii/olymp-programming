/*
	Accepted.
	http://acmp.ru/?main=task&id_task=121
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

	vector<int> A(N);
	for (int i = 0;i < N;i++)
		cin >>A[i];

	sort(A.begin(), A.end());
	vector<int> D(N, INT_MAX);
	D[0] = 0;
	D[1] = A[1] - A[0];

	for (int i = 2;i < N;i++)
	{
		D[i] = min(D[i], D[i-1] + A[i] - A[i-1]);	// привязываем к предыдущему
		if (i != N - 1)
			D[i+1] = min(D[i+1], D[i-1] + A[i+1] - A[i]);	// привязываем к следующему
	}

	cout <<D[N-1];

	return 0;
}
