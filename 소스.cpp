#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_fish(vector <int> fish_bread) {
	for (int i = 0; i < fish_bread.size(); i++) {
		cout << fish_bread[i] << " ";
	}
	cout << endl;

}

int find_num(vector <int> fish_bread, int num) {
	for (int i = 0; i < fish_bread.size(); i++) {
		if (num == fish_bread[i] || num == fish_bread[i] * -1) return i;
	}
}

bool check_bread(vector <int> fish_bread) {
	for (int i = 0; i < fish_bread.size(); i++) {
		if (i + 1 != fish_bread[i]) return false;
	}
	return true;
}

vector<int> reverse_fish_bread(vector <int> fish_bread, int start) {
	for (int i = start; i < fish_bread.size(); i++) {
		if (fish_bread[i] != i + 1) {
			int temp = find_num(fish_bread, i + 1);
			if (temp > i) {
				reverse(fish_bread.begin() + i, fish_bread.begin() + temp+1);
				for (int j = i; j < temp + 1; j++) {
					fish_bread[j] *= -1;
				}
				return fish_bread;
			}
			else if (temp < i) {
				reverse(fish_bread.begin() + temp, fish_bread.begin() + i+1);
				for (int j = temp; j < i + 1; j++) {
					fish_bread[j] *= -1;
				}
				return fish_bread;
			}
			else {
				fish_bread[temp] *= -1;
				return fish_bread;
			}
		}
	}
	return fish_bread;
}

void make_ans(vector <int> fish_bread) {
	vector<int> temp_bread; bool flag = false;
	if (check_bread(fish_bread)) {
		cout << "zero" << endl; flag = true;
	}
	else {
		for (int i = 0; i < fish_bread.size(); i++) {
			temp_bread = reverse_fish_bread(fish_bread, i);
			if (check_bread(temp_bread)) {
				cout << "one" << endl; flag = true; break;
			}
			else {
				temp_bread = reverse_fish_bread(temp_bread, 0);
				if (check_bread(temp_bread))  {
					cout << "two" << endl; flag = true; break;
				}
			}
		}
	}
	if(flag == false) cout << "over" << endl;
}



void make_input(int n) {
	int temp;
	for (int j = 0; j < 5; j++) {
		vector <int> fish_bread;
		for (int i = 0; i < n; i++) {
			cin >> temp;
			fish_bread.push_back(temp);
		}
		make_ans(fish_bread);
	}
}

int main() {
	int n;

	cin >> n;
	make_input(n);

	return 0;

}