#include<bits/stdc++.h>
using namespace std;

#define f(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) f(i,0,n)

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n, a = 0, b = 0, i, rema, remb;
		string s;
		cin >> n;
		cin >> s;
		rema = n;
		remb = n;
		rep(i, s.length()) {
			if (s[i] == '1') {
				if (i % 2 == 0) {
					a++;
				}
				else {
					b++;
				}
			}
			if (i % 2 == 0) {
				rema--;
			}
			else {
				remb--;
			}

			if (a > remb + b) {
				cout << i + 1 << endl;
				break;
			}
			if (b > rema + a) {
				cout << i + 1 << endl;
				break;
			}
			if (a == b && remb == 0)
			{
				cout << i + 1 << endl;
				break;
			}
		}
	}
	return 0;
}