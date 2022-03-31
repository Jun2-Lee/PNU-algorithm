#include <iostream>
#include <vector>
using namespace std;

int main() {
	string code;
	cin >> code;
	int code_size = code.length();

	vector<vector<string>> DP(code_size, (vector<string>(code_size)));

	for (int i = 0; i < code_size; i++) {
		DP[i][i] = code[i];
	}

	for (int k = 1; k < code_size; k++) {
		for (int i = 0, j = i + k; j < code_size; i++, j++) {
			if (code[i] == code[j]) DP[i][j] = code[i] + DP[i + 1][j - 1] + code[j];
			else {
				if (DP[i + 1][j].size() > DP[i][j - 1].size()) DP[i][j] = DP[i + 1][j];
				else if(DP[i +1][j].size() < DP[i][j - 1].size()) DP[i][j] = DP[i][j - 1];
				else {
					if (DP[i + 1][j] >= DP[i][j - 1]) DP[i][j] = DP[i][j - 1];
					else DP[i][j] = DP[i + 1][j];
				}
			}
		}
	}

	cout << DP[0][code_size - 1] << endl;
}