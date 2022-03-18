#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include "timebomb.h"
using namespace std;

int main() {
    int N = 0, result = 0, ans = 0, max_idx = 0;
    vector<int> large_idx;
    vector<pair<int, int>> tornament;
    vector<int> second;
    box_ready();
    N = box_size();

    for (int i = 1; i < N + 1; i++) {
        if (i == N) {
            large_idx.push_back(i);
            break; 
        }
        if (box_comp(i, i + 1) == -1) {
            large_idx.push_back(i + 1);
            tornament.push_back({ i , i + 1 });
        }
        else {
            large_idx.push_back(i);
            tornament.push_back({ i , i + 1 });
        }
        i++;
    }

    while (large_idx.size() != 1) {
        vector<int> temp;
        for (int i = 0; i < large_idx.size(); i++) {
            if (i == large_idx.size() - 1) { temp.push_back(large_idx[i]); break; }
            if (box_comp(large_idx[i], large_idx[i + 1]) == -1) {
                temp.push_back(large_idx[i + 1]);
                tornament.push_back({ large_idx[i] , large_idx[i+1] });
            }
            else {
                temp.push_back(large_idx[i]);
                tornament.push_back({ large_idx[i] , large_idx[i + 1] });
            }
            i++;
        }
        large_idx.clear();
        large_idx = temp;
    }
    max_idx = large_idx[0];

    for (int i = 0; i < tornament.size(); i++) {
        if (max_idx == tornament[i].first) second.push_back(tornament[i].second);
        else if (max_idx == tornament[i].second) second.push_back(tornament[i].first);
    }

    while (second.size() != 1) {
        vector<int> temp;
        for (int i = 0; i < second.size(); i++) {
            if (i == second.size() - 1) { temp.push_back(second[i]); break; }
            if (box_comp(second[i], second[i + 1]) == -1) temp.push_back(second[i + 1]);
            else temp.push_back(second[i]);
            i++;
        }
        second.clear();
        second = temp;
    }
    ans = second[0];
    box_report(ans);

    return 0;
}
