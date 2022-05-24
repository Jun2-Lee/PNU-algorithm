#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <array>

using namespace std;

int table[26][26] = { 0 };
vector <vector<char>> map(26, vector<char>());
vector<bool> is_visit(26,0);
int max_len = 0;

int BFS(int start) {
	queue<int> q;
	vector<bool> temp_visit(26, 0);
	copy(is_visit.begin(), is_visit.end(), temp_visit.begin());
	q.push(start);
	while (!q.empty()) {
		start = q.front() - 'a';
		q.pop();
		for (int i = 0; i < map[start].size(); i++) {
			if (!temp_visit[map[start][i] - 'a']) {
				q.push(map[start][i]);
				if (map[start][i] == 'a') return 1;
				temp_visit[map[start][i] - 'a'] = true;
			}
		}
	}
	return 0;
}

void make_line(int start, vector<int> line, int length) {
	if (!line.empty() && line[line.size() - 1] == 0) {
		if (length > max_len) {
			max_len = length;
			return;
		}
		else return;
	}if (BFS(start + 'a') == 0)
		return; 


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
	cout << max_len;

	return 0;
}