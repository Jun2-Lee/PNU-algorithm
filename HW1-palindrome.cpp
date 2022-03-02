#include <iostream>
#include <vector>

using namespace std;

bool palindrome(string str) {
	int str_size = str.size();
	bool flag = true;
	for (int i = 0; i < str_size / 2; i++) {
		if (str[i] != str[str.size() - 1 - i]) {
			flag = false;
			break;
		}
	}
	return flag;
} 

bool quasi_palindrome(string str) {
	bool flag = true;
	int left = 0, right = str.size() - 1;
	while (left < right) {
		if (str[left] == str[right]) {
			left++; right--;
		}
		else {
			int l_temp = left; int r_temp = right;
			l_temp++;
			while (l_temp < r_temp) {
				if (str[l_temp] == str[r_temp]) { l_temp++;r_temp--; }
				else { flag = false; break;	}
			}
			if (flag) return true;
			l_temp = left; r_temp = right;
			r_temp--;
			while (l_temp < r_temp) {
				if (str[l_temp] == str[r_temp])	{ l_temp++; r_temp--; }
				else return false;
			}
			return true;
		}
	}
	return true;

}

void input_str(int n) {
	string str; bool pal, q_pal;
	for (int i = 0; i < n; i++) {
		cin >> str;
		pal = palindrome(str);
		if (pal == 1) cout << 1;
		else {
			q_pal = quasi_palindrome(str);
			if (q_pal == 1) cout << 2;
			else cout << 3;
		}
	}
}

int main() {
	int n;
	cin >> n;
	input_str(n);
	return 0;
}
