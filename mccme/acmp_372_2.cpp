// Solution for http://acmp.ru/?main=task&id_task=372
// Accepted.


#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <stack>

using namespace std;

int N;
string s;

bool isComplement(char a, char b)
{
	return (a == '(' && b == ')') || (a == '[' && b == ']') ;
}

char find_last_unclosed(int pos)
{
	stack<char> st;
	for (int i = 0;i < pos;i++)
	{
		char c = s[i];
		if (st.empty())
			st.push(c);
		else if (isComplement(st.top(), c))
			st.pop();
		else
			st.push(c);
	}

	char res =  st.top() == '(' ? ')' : ']';
	return res;
}

void rec(int toClose, int pos)
{
	if (N - pos == toClose)	// close everything
	{
		for (int i = pos;i < N;i++)
			s[i] = find_last_unclosed(i);
		cout <<s <<endl;
		return;
	}

	s[pos] = '(';
	rec(toClose + 1, pos + 1);

	s[pos] = '[';
	rec(toClose + 1, pos + 1);

	if (toClose > 0)	// needs closing. Close last one.
	{
		s[pos] = find_last_unclosed(pos);
		rec(toClose - 1, pos + 1);
	}
}


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >>N;
	s.reserve(N);
	s.resize(N, '-');

	rec(0, 0);

	return 0;
}
