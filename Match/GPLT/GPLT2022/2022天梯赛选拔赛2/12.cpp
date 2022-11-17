// 7-12 功夫传人
#include <bits/stdc++.h>
using namespace std;
struct People
{
	int plus;
	double s = 0;
	vector<int> q;
};
int main()
{
	int n;
	double z, r, sum = 0;
	queue<People> que;
	cin >> n >> z >> r;
	People a[n];
	a[0].s = z;
	for (int i = 0, k; i < n; i++)
	{
		cin >> k;
		if (k == 0)
			cin >> a[i].plus;
		else
			for (int j = 0, m; j < k; j++)
			{
				cin >> m;
				a[i].q.push_back(m);
			}
	}
	que.push(a[0]);
	while (!que.empty())
	{
		People T = que.front();
		que.pop();
		if (T.q.empty())
			sum += T.s * T.plus;
		for (int i : T.q)
		{
			a[i].s = T.s * (1 - r / 100);
			que.push(a[i]);
		}
	}
	cout << int(sum);
	return 0;
}
