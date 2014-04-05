/*
	Accepted.
		http://acmp.ru/index.asp?main=task&id_task=214

*/

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <stack>
#include <map>

using namespace std;

int N, M;

short D[202][202][101];

// 0 - первый выигрывает, 1 - не выигрывает.
int rec(int c1, int c2, int c3)
{
	short &r = D[c1][c2][c3];
	if (r != -1)
		return r;

	if (c1 + c2 + c3 == 0)
	{
		return 1; // противник выигрывает
	}
	else
	{
		if (c1 > 0)
		{
			if (rec(c1 - 1, c2, c3) == 1)
				r = 0;
		}
		if (c2 > 0 && r == -1)
		{
			// срубаем одну голову из двух
			if (rec(c1 + 1, c2 - 1, c3) == 1)
				r = 0;
			// срубаем 2 головы
			else if (rec(c1, c2 - 1, c3) == 1)
				r = 0;
		}
		if (c3 > 0 && r == -1)
		{
			// рубим одну из трех
			if (rec(c1, c2 + 1, c3 - 1) == 1)
				r = 0;

			// рубим две из трех
			else if (rec(c1 + 1, c2, c3 - 1) == 1)
				r = 0;

			// рубим три из трех
			else if (rec(c1, c2, c3 - 1) == 1)
				r = 0;
		}
		if (r == -1)
			r = 1;	// противник выигрывает
	}


	return r;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	memset(D, -1, sizeof(D));
	
	cin >>N >> M;

	cout <<((rec(0, N, M) == 0) ? 1 : 2);

	return 0;
}
