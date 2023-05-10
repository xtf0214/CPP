#include<bits/stdc++.h>
using namespace std;

bool isPrime[20]{0,0,1,1,0,1,0,1,0,0,0,1,0,1,0};

void solve(int n) {
	int cnt = 0; 
	vector<int> a(n);
	iota(a.begin(), a.end(), 1);
	do {
		bool ok = true;
		for(int i=0;i<n;i++)
			if (!isPrime[abs(a[i] - a[(i+1)%n])])
				ok = false;
		if(ok) {
			for(int i=0;i<n;i++)
				cout << a[i] << " \n"[i+1==n]; 
			cnt++;
		}
		if(cnt>=10)
			break;
	}while(next_permutation(a.begin(),a.end())); 
}
int main() {
//	int i=5;i<=1;i++)
		solve(17); 
//		solve(8);
//		solve(7);
//		solve(6);
//		solve(5);
	
}
