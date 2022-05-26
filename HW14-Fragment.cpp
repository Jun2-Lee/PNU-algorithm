#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
struct frag {
	int num = 0;
	string fragment;
};
vector<frag> fragments;
int ans_line;

int alpa_arr(char ch) {
	switch (ch) {
	case 'a':
		return 0;
	case 'c':
		return 1;
	case 'g':
		return 2;
	case 'n':
		return 3;
	case 't':
		return 4;
	}
}

void msd_radix(int start, int end, int index, vector<frag>& t_f) {
	if (end <= start + 1) return;
	if (start > ans_line) return;
	if (end < ans_line - 2) return;

	int count[6] = { 0, };
	int temp_count[6];

	for (int i = start; i < end; i++) {
		count[alpa_arr(fragments[i].fragment[index]) + 1]++;
	}
	for (int i = 0; i < 5; i++) {
		count[i + 1] += count[i];
	}
	copy(count, count + 6, temp_count);
	for (int i = start; i < end; i++) {
		t_f[start + temp_count[alpa_arr(fragments[i].fragment[index])]++] = fragments[i];
	}
	for (int i = start; i < end; i++) {
		fragments[i] = t_f[i];
	}
	
	for (int i = 0; i < 5; i++) 
		msd_radix(start + count[i], start + count[i + 1], index + 1, t_f);
}


int main() {
	int max_size = 0, cnt = 1;
	
	string temp;
	frag temp_f;
	cin >> ans_line;
	getline(cin, temp);

	while (1) {
		getline(cin, temp);
		if (temp == "") break;
		if (temp.size() > max_size) max_size = temp.size();
		temp_f.fragment = temp; temp_f.num = cnt; cnt++;
		fragments.push_back(temp_f);
	}
	vector<frag> t_f(fragments.size());
	msd_radix(0,fragments.size(), 0,t_f);

	for (int i = 0; i < fragments.size(); i++) {
		if (i == ans_line - 2 || i == ans_line -1|| i == ans_line)
			cout << fragments[i].num << '\n';
	}
}
