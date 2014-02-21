// Problem http://acmp.ru/index.asp?main=task&id_task=555
// accepted.

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<long long> S(3000);
vector<long long> E(3000);
vector<long long> A(3000);
vector<long long> C(3000);

set<long long> B;
vector<long long> P;

	int N;

long long res = 1;
long long MOD = 1LL << 32LL;

long long rec(int pos)
{
	if (pos >= N)
		return 1;

	int iters = 0;
	for (int i = 0;i < P.size();i++)
	{
		bool inc = false;
		int counter = P[i];
		if (S[pos] >= 0 && counter >= S[pos] && counter <= E[pos])
		{
			C[pos] = counter;
			iters++;
			inc = true;
		}
		else if (S[pos] < 0)
		{
			int ind = -S[pos] - 1;
			if (counter >= C[ind] && counter <= E[pos])
			{
				C[pos] = counter;
				iters++;
				inc = true;
			}
		}

		if (iters > 0 && inc)
		{
			rec(pos + 1);
		}
	}
	
	return iters;
}

int main()
{
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >>N;

	for (int i = 0;i < N;i++)
	{
		cin >>S[i] >>E[i];
		if (S[i] >= 0)
			B.insert(S[i]);
		B.insert(E[i]);
	}

	for (set<long long>::iterator it = B.begin();it != B.end();it++)
		P.push_back(*it);

	sort(P.begin(), P.end());


	//for (int i = 0;i < N;i++)
	//{
	//	if (S[i] >= 0 && E[i] >= 0)
	//	{
	//		if (S[i] > E[i])
	//		{
	//			res = 0;
	//			break;
	//		}
	//		res = (res * (E[i] - S[i] + 1)) % MOD;
	//		A[i] = (E[i] + S[i]);
	//	}
	//	else if (S[i] < 0)
	//	{
 //			int ind = -S[i] - 1;
	//		if (E[i] < S[ind])
	//		{
	//			res = 0;
	//			break;
	//		}

	//		A[i] = (E[i]+1)*2 - A[ind];

	//		if (E[i] < E[ind])
	//		{
	//			//res = 
	//		}
	//		else
	//			res = ((res * a) / 2LL) % MOD;
	//	}
	//}

	if (!rec(0))
		res = 0;
	cout <<res;

	return 0;
}
