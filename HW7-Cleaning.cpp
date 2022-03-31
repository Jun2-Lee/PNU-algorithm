#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<vector <pair<int, int>>> calender(1096);
	int pay[1096] = { 0 };
	int short_date[1096] = { 0 };
	int n, start_date,time,money, ans_pay = 0, ans_date = 1096;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		pair<int, int> temp;
		cin >> start_date >> time >> money;
		time = time - start_date + 1; money -= 10;
		temp.first = time; temp.second = money;
		calender[start_date].push_back(temp);
	}

	for (int i = 1; i < 1096; i++) {
		for (int j = 1; j < i; j++) {
			if (pay[i] < pay[j]) {
				pay[i] = pay[j];
				short_date[i] = short_date[j];
			}
			if(pay[i] == pay[j] && short_date[i] > short_date[j]) {
				short_date[i] = short_date[j];
			}
			for (int k = 0; k < calender[j].size(); k++) {
				if (j + calender[j][k].first == i) {
					if (pay[i] < pay[j] + calender[j][k].second) {
						pay[i] = pay[j] + calender[j][k].second;
						short_date[i] = short_date[j] + calender[j][k].first;
					}
					if (pay[i] == pay[j] + calender[j][k].second && short_date[i] > short_date[j] + calender[j][k].first) {
						short_date[i] = short_date[j] + calender[j][k].first;
					}
				}
			}
		}
		ans_pay = max(ans_pay, pay[i]);
	}
	/*for (int i = 0; i < 11; i++) {
		cout << "----------------" << i << "-----------------" << endl;
		for (int j = 0; j < calender[i].size(); j++) {
			cout << calender[i][j].first << " " << calender[i][j].second << endl;
		}
	}*/
	for (int i = 0; i < 1096; i++) {
		if (pay[i] == ans_pay) {
			ans_date = min(ans_date, short_date[i]);
		}
	}
	cout << ans_pay + 10 << " " << ans_date;
	return 0;
}
