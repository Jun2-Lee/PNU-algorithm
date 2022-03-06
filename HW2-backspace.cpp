#include <iostream>
#include <vector>

using namespace std;
int back_start;
bool check_string(string s, string t, int s_start, int t_start) {
    if (t_start == t.size()) {
        if ((s.size() - s_start) % 2 == 0) return true;
        else return false;
    }
    if (t_start == 0) {
        for (int i = s_start; i < s.size(); i++) {
            if (s[i] == t[t_start]) {
                return check_string(s, t, i + 1, t_start + 1);
            }
        }
        return false;
    }
    else {
        for (int i = s_start; i < s.size(); i += 2) {
            if (s[i] == t[t_start]) {
                return check_string(s, t, i + 1, t_start + 1);
            }
        }
        return false;
    }
}


void input_string(int n) {
    string s, t;
    for (int i = 0; i < n; i++) {
        bool ans = false;
        cin >> s >> t;
        for (int i = 0; i < s.size(); i++) {
            bool flag1 = check_string(s, t, i, 0);
            if (flag1) {
                ans = flag1;
                break;
            }
        }
        if (ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}


int main() {

    int n;

    cin >> n;
    input_string(n);

    return 0;
}
