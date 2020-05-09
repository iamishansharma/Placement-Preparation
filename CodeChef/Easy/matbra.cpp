#include<bits/stdc++.h>
using namespace std;

#define ll long long
int main() {
	int N; cin >> N;
	int Depth = 0, MaxDepth = 0, DelthLoc = 0;
	int Cnt = 0, max_Cnt = 0, CntLoc = 0;
	int BracketStartIndex = 0;

	for (int x = 1; x <= N; x++) { // count starts from 1
		if (!Depth) { // Depth = 0
			Cnt = 0;
			BracketStartIndex = x;
		}
		int i; cin >> i; // input of the sequence
		Cnt++;
		if ( i == 1) Depth++;
		else Depth--;

		if (Depth > MaxDepth) {
			DelthLoc = x;
			MaxDepth = Depth;
		}
		if (Cnt > max_Cnt) {
			CntLoc = BracketStartIndex;
			max_Cnt = Cnt;
		}
	}
	cout << MaxDepth << " " << DelthLoc << " " << max_Cnt << " " << CntLoc << "\n";
	return 0;
}