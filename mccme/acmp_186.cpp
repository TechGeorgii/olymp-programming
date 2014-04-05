/*
	Accepted.
		http://acmp.ru/index.asp?main=task&id_task=186
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

	vector<int> D(N, INT_MAX);	// ����������� ��������������� ����� ��� ��������� �� 0 �� i ������������.
	
	D[1] = A[1] - A[0];			// ��� ���� - ����������.

	for (int i = 2;i < N;i++)
	{
		// ���������� ���������������
		int best = A[i] - A[0];	// ��� ������ i = 2, ����� ��������� ���������.

		// ������� ������� ����� �� ��� ���������: �� 0 �� j-1, �� j-1 �� i.
		// �� ������ ���� ������� ���������� �������� ���������������� ���� ���� ����������.
		for (int j = i-1;j >= 1;j--)	// ����� ������� ������.
		{
			int cur = max(A[i] - A[j], D[j-1]);
			if (cur < best)
				best = cur;
		}
		D[i] = best;
	}

	cout << D[N-1];

	return 0;
}
