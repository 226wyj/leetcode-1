
// Problem : Permutations
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1070
// Memory Limit : 512 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
int n;

int num[N];

void swap(int i , int j) {
	int tmp = num[i];
	num[i] = num[j];
	num[j] = tmp;
}


bool dfs(int idx) {
	if (idx == n) {
		for (int i = 0; i < n; ++i)
			cout << num[i] << " ";
		return true;
	}
	
	for (int i = idx; i < n; ++i) {
		if (idx > 0 && abs(num[idx - 1] - num[i]) == 1) continue;
		swap(idx, i);
		if (dfs(idx + 1)) return true;
		swap(idx, i);
	}
	return false;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) num[i] = i + 1;
	if (!dfs(0)) cout << "NO SOLUTION";
	return 0;
}