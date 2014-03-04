// Accepted.
// ACMP 366.

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

long long N, S;
vector<long long> A;
vector<char> ans;

long long cur;

bool rec(int p)
{
	if (p >= N)
	{
		return (cur == S);
	}

	ans[p] = '-';
	long long save = cur;
	cur -= A[p];
	if (rec(p + 1))
		return true;

	cur = save;
	save = cur;

	cur += A[p];
	ans[p] = '+';
	if (rec(p + 1))
		return true;

	cur = save;
	return false;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >>N >>S;
	
	A.resize(N);
	ans.resize(N);
	for (int i = 0;i < N;i++)
		cin >>A[i];

	cur = A[0];

	if (!rec(1))
		cout <<"No solution";
	else
	{
		for (int i = 1;i < N;i++)
			cout <<A[i-1] <<ans[i];
		cout <<A[N-1] <<"="<<S;
	}

	return 0;
}
