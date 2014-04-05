/*
	Accepted
	http://acmp.ru/?main=task&id_task=183
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

	long long K, P;
	cin >>K >>P;

	if (K == 1)
	{
		cout<<0;
		return 0;
	}

	vector <long long> D(K + 1, 0);	// кол-во энтов, знающие k слов, которые могу обучать.
	D[2] = 1 % P;
	/*
		2
		4										3
		8				5						6				4
		16	9			10	6					12	7			8	5

		обратно
		C(8) = C(7) + C(4) = 3 + 2.

		C(4) = C(2) + C(3) = 1 + 1 = 2
		C(2) = 1
		C(3) = C(2) = 1
		C(7) = C(6) = 3

		C(6) = C(3) + C(5) = 1 + 2 = 3
		C(5) = C(4) = 2
	*/

	for (int i = 3;i <= K;i++)
	{
		if (i % 2 == 0)
			D[i] = (D[i/2] + D[i-1]) % P;
		else
			D[i] = D[i-1];
	}

	cout <<D[K];

	return 0;
}
