#include <iostream>
#include <vector>

using namespace std;

int main() {

    string i_string, j_string;

    cin >> i_string >> j_string;
    string ans = "";
    vector <vector<string>> dp(i_string.size(), vector<string>(j_string.size()));

    for (int i = 0; i < i_string.size(); i++) {
        for (int j = 0; j < j_string.size(); j++) {
            if (i_string[i] == j_string[j]) {
                if (i == 0 || j == 0) {
                    for (int temp_i = 0; temp_i < 2; temp_i++) {
                        for (int temp_j = 0; temp_j < 2; temp_j++) {
                            if (i + temp_i < i_string.size() && j + temp_j < j_string.size()) {
                                dp[i + temp_i][j + temp_j] = i_string[i];
                            }
                        }
                    }
                }
                else {
                    for (int temp_i = 0; temp_i < 2; temp_i++) {
                        for (int temp_j = 0; temp_j < 2; temp_j++) {
                            if (i + temp_i < i_string.size() && j + temp_j < j_string.size()) {
                                if (dp[i + temp_i][j + temp_j].size() <= dp[i - 1][j - 1].size() + 1) {
                                    dp[i + temp_i][j + temp_j] = dp[i - 1][j - 1] + i_string[i];
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < dp.size(); i++) {
        for (int j = 0; j < dp[i].size(); j++) {
            if (dp[i][j].size() > ans.size()) ans = dp[i][j];
            if (dp[i][j].size() == ans.size()) {
                if (dp[i][j] < ans) ans = dp[i][j];
            }
        }
    }

    cout << ans;
    return 0;
}