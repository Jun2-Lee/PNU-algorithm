#include <iostream>
#include <vector>

using namespace std;
int back_start;
bool check_string(string s, string t,int s_start, int t_start) {
	if (t_start == t.size()) {
		if ((s.size() - s_start) % 2 == 0) return true;
		else return false;
	}
	if (t_start == 0) {
		for (int i = s_start; i < s.size(); i++) {
			if (s[i] == t[t_start]) {
				return check_string(s, t, i+1, t_start + 1);
			}
		}
		return false;
	}
	else {
		for (int i = s_start; i < s.size(); i += 2) {
			if (s[i] == t[t_start]) {
				return check_string(s, t, i+1, t_start + 1);
			}
		}
		return false;
	}
}

bool check_string_back(string s, string t, int s_start, int t_start) {
	
	if (t_start == -1) {
		if ((s.size() - back_start) % 2 == 0) return true;
		else return false;
	}
	if (t_start == t.size() - 1) {
		for (int i = s_start; i > -1; i--) {
			if (s[i] == t[t_start]) {
				back_start = i+1;
				return check_string_back(s, t, i - 1, t_start - 1);
			}
		}
		return false;
	}
	else {
		for (int i = s_start; i > -1; i -= 2) {
			if (s[i] == t[t_start]) {
				return check_string_back(s, t, i - 1, t_start - 1);
			}
		}
		return false;
	}
}

void input_string(int n) {
	string s, t;
	for (int i = 0; i < n; i++) {
		cin >> s >> t;
		bool flag1 = check_string(s, t, 0, 0);
		bool flag2 = check_string(s, t, 1, 0);
		bool flag3 = check_string_back(s, t, s.size() - 1, t.size() - 1);
		if (flag1 || flag2 || flag3) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}


int main() {
	
	int n;
	
	cin >> n;
	input_string(n);

	return 0;
}