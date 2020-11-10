
// Problem : Distinct Numbers
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1621
// Memory Limit : 512 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;
int main() {
	int n;
	cin >> n;
	set<int> st;
	int num;
	for (int i = 0; i < n; ++i) {
		cin >> num; 
		st.insert(num);
	}
	cout << st.size();
		
	return 0;
}