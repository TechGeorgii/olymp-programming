// Problem http://acmp.ru/index.asp?main=task&id_task=154
// accepted.

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int cubes[1260];
int res[8] = {0};

bool rec(int n, int ind, int prev)
{
	if (n == 0)
		return true;
	if (ind > 7)
		return false;

	for (int c = 
		//1259
				prev	// - нужно начинать перебор с предыдущего числа. Значительно сокращая кол-во вариантов.
		;c > 0;c--)
	{
		if (n - c*c*c < 0)
			continue;
		res[ind] = c;

		if (rec(n - c*c*c, ind+1, c))
			return true;
		res[ind] = 0;
	}
	return false;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int N;
	cin >>N;

	rec(N, 0, 1259);
	if (res[0] == 0)
		cout <<"IMPOSSIBLE";
	else
		for (int i = 0;i < 8;i++)
			if (res[i] == 0)
				break;
			else cout <<res[i]<<" ";

	return 0;
}