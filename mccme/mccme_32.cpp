// Problem http://informatics.mccme.ru/moodle/mod/statements/view.php?chapterid=32

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

vector<int> A;
vector<char> P;
	long long N;
	int M;

long long S = 0;
char C = 0;

char MINC = 120;
vector<char> res;

void rec(int p)
{
	if (S > N || C > MINC)
		return;	// no answer

	if (p >= M)
	{
		if (S == N && C < MINC)
		{
			MINC = C;
			res = P;
		}
		return;
	}

	rec(p + 1);

	S += A[p];
	C++;
	P[p] = 1;
	rec(p + 1);

	S += A[p];
	C++;
	P[p] = 2;
	rec(p + 1);

	S = S - A[p] - A[p];
	C -= 2;
	P[p] = 0;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);


	cin >>N >>M;
	A.resize(M);
	long long s = 0;
	for (int i = 0;i < M;i++)
	{
		cin >>A[i];
		s += 2*A[i];
	}

	if (s < N)
	{
		cout <<-1;
		return 0;
	}

	P.resize(M);
	rec(0);

	if (MINC == 120)
	{
		cout <<0;
		return 0;
	}

	int rr = 0;
	for (int i = 0;i < M;i++)
		rr += res[i];

	cout <<rr <<endl;
	for (int i = 0;i < M;i++)
		for (int j = 0;j < res[i];j++)
			cout <<A[i] <<" ";

	return 0;
}