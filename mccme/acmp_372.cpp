// Solution for http://acmp.ru/?main=task&id_task=372
// MLE

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <map>

using namespace std;

int N;
string s;
set<string> res;
map<int, list<string> > M;

void gen(int len)
{
	if (len == 2)
	{
		list<string> s;
		s.push_back("[]");
		s.push_back("()");
		M[len] = s;
		return;
	}

	map<int, list<string> >::iterator it = M.find(len);
	if (it != M.end())
		return;

	list<string> res;

	for (int i = 2;i < len;i+=2)
	{
		gen(i);
		gen(len - i);
		list<string> &left = M[i];
		list<string> &right = M[len - i];

		for (list<string>::iterator i1 = left.begin();i1 != left.end();i1++)
			for (list<string>::iterator i2 = right.begin();i2 != right.end();i2++)
			{
				res.push_back(*i1 + *i2);
			}
	}

	gen(len - 2);
	list<string> &smaller = M[len - 2];
	for (list<string>::iterator it = smaller.begin();it != smaller.end();it++)
	{
		res.push_back("(" + *it + ")");
		res.push_back("[" + *it + "]");
	}

	M[len] = res;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >>N;
	s.resize(N, '0');

	gen(N);
	list<string> r = M[N];
	int cnt = 0;
	for (list<string>::iterator it = r.begin();it != r.end();it++)
	{
		//cnt++;
		//cout <<*it <<endl;
		res.insert(*it);
	}
//	cout <<cnt;

	for (set<string>::iterator it = res.begin();it != res.end();it++)
		cout <<*it <<endl;
	//cout <<res.size();

	return 0;
}
