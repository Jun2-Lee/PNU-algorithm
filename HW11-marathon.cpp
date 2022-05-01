#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int table[26][26] = { 0 };
vector <vector<char>> map(26, vector<char>());
vector <string> ans;
bool is_visit[26] = { false };
void make_line(int start, vector<int> line,int length) {
	if (!line.empty() && line[line.size() - 1] == 0) {
		if (length == 42) {
			string temp_ans = "a";
			for (int i = 0; i < line.size()-1;i++) {
				temp_ans += char(line[i] + 'a');
			}
			ans.push_back(temp_ans);
			return;
		}
		else return;
	}
	else if (length > 42) return;

	for (int i = 0; i < map[start].size(); i++) {
		if (!is_visit[map[start][i] - 'a']) {
			is_visit[map[start][i] - 'a'] = true;
			length += table[start][map[start][i] - 'a'];
			line.push_back(map[start][i] - 'a'); 
			make_line(map[start][i] - 'a', line, length);
			is_visit[map[start][i] - 'a'] = false;
			length -= table[start][map[start][i] - 'a'];
			line.pop_back();
		}
	}

}
void make_ans() {
	int max_size = 0;
	string answer;
	vector<string> temp_ans;
	if (ans.empty()) {
		cout << "None";
		return;
	}
	for (auto i : ans) {
		if (i.size() > max_size) max_size = i.size();
	}
	for (auto i : ans) {
		if (i.size() == max_size) temp_ans.push_back(i);
	}
	answer = *min_element(temp_ans.begin(), temp_ans.end());
	cout << max_size << endl;
	for (int i = 0; i < max_size; i++) {
		cout << answer[i] << " ";
	}
	return;
}
void make_table(int M) {
	char start, end;
	int edge;
	for (int i = 0; i < M; i++) {
		cin >> start >> end >> edge;
		map[start - 'a'].push_back(end);
		map[end - 'a'].push_back(start);
		table[start - 'a'][end - 'a'] = edge;
		table[end - 'a'][start - 'a'] = edge;
	}
}
int main() {
	vector<int> line;
	int N, M;
	cin >> N >> M;
	
	make_table(M);
	make_line(0, line, 0);
	make_ans();

	return 0;
}
