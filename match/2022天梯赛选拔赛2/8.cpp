#include <bits/stdc++.h>
using namespace std;
int main()
{
	bool ch[128];
	memset(ch, 0, sizeof(ch));
	string a, b, c;
	getline(cin, a);
	getline(cin, b);
	for (char i : b)
		ch[i] = true;
	for (char i : a)
		if (ch[i] == 0)
			c += i;
	cout << c;
}
