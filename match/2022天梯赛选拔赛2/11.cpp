#include <bits/stdc++.h>
using namespace std;
struct People
{
	string id;
	int a;
};
bool cmp(const People &a, const People &b) { return a.id < b.id; }
int main()
{
	int n, m;
	double sum = 0;
	cin >> n;
	string s1[n];
	for (int i = 0; i < n; i++)
		cin >> s1[i];
	cin >> m;
	People s2[m];
	for (int i = 0; i < m; i++)
	{
		cin >> s2[i].id;
		cin >> s2[i].a;
		sum += s2[i].a;
	}
	sum /= m;
	sort(s2, s2 + m, cmp);
	bool flag0 = false;
	for (int i = 0; i < m; i++)
		if (s2[i].a > sum)
		{
			bool flag = true;
			for (int j = 0; j < n; j++)
				if (s1[j] == s2[i].id)
				{
					flag = false;
					break;
				}
			if (flag)
			{
				cout << s2[i].id << endl;
				flag0 = true;
			}
		}
	if (!flag0)
		cout << "Bing Mei You";
	return 0;
}
