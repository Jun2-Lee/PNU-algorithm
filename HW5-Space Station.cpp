#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
	int x, y, z;
};

int main() {
	vector <Point> p_list;
	int rateA = 0, rateB = 0;
	for (int i = 0; i < 4; i++) {
		Point temp;
		cin >> temp.x >> temp.y >> temp.z;
		p_list.push_back(temp);
	}
	rateA = abs(p_list[0].x - p_list[1].x);
	if (abs(p_list[0].y - p_list[1].y) > abs(p_list[0].z - p_list[1].z)) rateA = max(abs(p_list[0].y - p_list[1].y), rateA);
	else rateA = max(abs(p_list[0].z - p_list[1].z), rateA);
	rateB = abs(p_list[2].x - p_list[3].x);
	if (abs(p_list[2].y - p_list[3].y) > abs(p_list[2].z - p_list[3].z)) rateB = max(abs(p_list[2].y - p_list[3].y), rateB);
	else rateB = max(abs(p_list[2].z - p_list[3].z), rateB);
	double max_len = 1000000;

	for (int i = 0; i < rateA+1; i++) {
		double pre_len = 0.0, cur_len = 0.0;
		double temp_x1 = p_list[0].x - (double((p_list[0].x) - double(p_list[1].x)) / rateA)*i;
		double temp_y1 = p_list[0].y - (double((p_list[0].y) - double(p_list[1].y)) / rateA)*i;
		double temp_z1 = p_list[0].z - (double((p_list[0].z) - double(p_list[1].z)) / rateA)*i;
		for (int j = 0; j < rateB+1; j++) {
			double temp_x2 = p_list[2].x - (double((p_list[2].x) - double(p_list[3].x)) / rateB)*j;
			double temp_y2 = p_list[2].y - (double((p_list[2].y) - double(p_list[3].y)) / rateB)*j;
			double temp_z2 = p_list[2].z - (double((p_list[2].z) - double(p_list[3].z)) / rateB)*j;
			double temp_len = sqrt(pow((temp_x1 - temp_x2),2) + pow((temp_y1 - temp_y2),2) + pow((temp_z1 - temp_z2),2));
			if (j == 0) {
				pre_len = temp_len;
			}
			else if (j != 0) {
				cur_len = temp_len;
				if (pre_len < cur_len) break;
				else pre_len = cur_len;			
			}
			if (temp_len < max_len) max_len = temp_len;
		}
	}
	cout << int(ceil(max_len)) << endl;
	return 0;
}
