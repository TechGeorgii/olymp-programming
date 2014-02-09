// Problem http://acmp.ru/index.asp?main=task&id_task=555
// accepted.

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int N;
	cin >>N;

	vector<int> S(N);
	vector<int> E(N);

	for (int i = 0;i < N;i++)
	{
		cin >>S[i] >>E[i];
	}

	return 0;
}