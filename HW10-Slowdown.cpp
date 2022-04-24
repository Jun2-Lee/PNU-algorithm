#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
struct work{
	int pay = 0;
	int day = 0;
};
bool compare(const work& p1, const work& p2) {
		return p1.pay > p2.pay;
}
void swap(work& a, work& b) {
	work temp;
	temp = a;
	a = b;
	b = temp;
	return;
}
int sum_pay(vector <vector<work>> machine_table, int T) {
	int pay = 0;
	for (int i = 0; i < T; i++) {
		for (int j = 0; j < machine_table[i].size(); j++) {
			pay += machine_table[i][j].pay;
		}
	}
	return pay;
}
vector <work> table;
vector <vector<work>> machine_table(10);
vector <work> not_use;
int main() {

	int N, T, k, max_pay=0, second_p = INT_MAX;
	cin >> N >> T >> k;

	for (int i = 0; i < N; i++) {
		work temp;
		cin >> temp.pay >> temp.day;
		table.push_back(temp);
	}
	for (int i = 0; i < T; i++) {
		sort(table.begin(), table.end(), compare);
	}

	for (int i = 0; i < T; i++) {
		for (int j = 0; j < k; j++) {
			work temp;
			temp.day = i + 1;
			machine_table[i].push_back(temp);
		}
	}
	for (int i = 0; i < table.size(); i++) {
		if (machine_table[table[i].day - 1].size() == k) {
			not_use.push_back(table[i]);
		}
		else {
			machine_table[table[i].day - 1].push_back(table[i]);
		}
	}

	for (int i = T - 1; i >= 0; i--) {
		for (int j = 0; j < k; j++) {
			for (int idx = 0; idx < not_use.size(); idx++) {
				if (not_use[idx].day >= i + 1&& not_use[idx].pay > machine_table[i][j].pay) {
					swap(not_use[idx], machine_table[i][j]);
				}
			}
		}
	}

	max_pay = sum_pay(machine_table, T);

	for (int i = T - 1; i >= 0; i--) {
		for (int j = 0; j < k; j++) {
			for (int idx = 0; idx < not_use.size(); idx++) {
				if (not_use[idx].day >= i + 1) {
					swap(not_use[idx], machine_table[i][j]);
					if (max_pay - sum_pay(machine_table, T) < second_p && max_pay != sum_pay(machine_table, T)) { 
						
						second_p = max_pay - sum_pay(machine_table, T); 
					}
					swap(not_use[idx], machine_table[i][j]);
				}
			}
		}
	}
	cout << max_pay << " " << max_pay - second_p << endl;
	
	return 0;
}
