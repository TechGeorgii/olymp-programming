/*
Accepted.
http://acmp.ru/?main=task&id_task=554
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

	vector<long long> D(N + 1, 0);

	D[0] = 1;
	for (int i = 1;i <= N;i++)
	{
		D[i] = D[i-1];
		if (i >= 2)
			D[i] += D[i-2];
		if (i >= 3)
			D[i] += D[i-3];
	}

	cout <<D[N];
	return 0;
}
