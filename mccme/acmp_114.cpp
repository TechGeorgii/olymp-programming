/*
	Accepted.
		http://acmp.ru/index.asp?main=task&id_task=114

		����� ������� �������.
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

	int N, K;

	cin >>N>>K;

	vector<vector<int> > D;	// ����� ����� ����� N, ��������������� �� ����� K
	D.resize(N, vector<int>(K, 0));
	for (int i = 0;i < K;i++)
		D[0][i] = 1;		//	���� ����� ����� 1, �������������� �� ����� K.

	D[0][0] = 0;			// �������� �����, ������������ � ����.

	/*
		������ ����� - P.
		����������� ����� ����� S:
			-- ������� �� N �� N+1

		D[i+1][S] = SUM(D[i][P]) ��� ���� P, S, ���� S � P �� ����� 0
	*/

	for (int i = 0;i < N-1;i++)
		for (int P = 0;P < K;P++)
			for (int S = 0;S < K;S++)
			{
				if (S + P != 0)
					D[i+1][S] += D[i][P];
			}

	int ans = 0;
	for (int E = 0;E < K;E++)
		ans += D[N-1][E];

	cout <<ans;

	return 0;
}
