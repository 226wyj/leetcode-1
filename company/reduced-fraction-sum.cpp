#include <bits/stdc++.h>

using namespace std;
pair<int, int> inline get(string str) {
	int div = 0;
	while (div < (int) str.size() && str[div++] != '/') ;
	return {stoi(str.substr(0, div)), stoi(str.substr(div, str.size()))};
}

vector<string> reducedFractionSums(vector<string> express) {
	vector<string> res;
	for (string& e : express) {
		int plus = 0;
		while (plus < (int) e.size() && e[plus++] != '+') ;
		// cout << e.substr(0, plus - 1) << " " << e.substr(plus) << endl;
		auto l = get(e.substr(0, plus - 1)), r = get(e.substr(plus));
		int a = l.first, b = l.second, c = r.first, d = r.second;
		printf("a:%d, b:%d, c:%d, d:%d\n", a, b, c, d);
		int x = a * d + b * c, y = b * d;
		res.push_back(to_string(x / gcd(x, y)) + "/" + to_string(y / gcd(x, y)));
	}
	return res;
}


int main() {
	vector<string> input = {"722/148+360/176", "978/1212+183/183", "358/472+301/417",
												  "780/309+684/988", "258/840+854/686"};
	vector<string> res = reducedFractionSums(input);
	for (string s : res) cout << s << endl;
	return 0;
}