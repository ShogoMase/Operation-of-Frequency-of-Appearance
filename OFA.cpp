#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

#define MAX_ELEMENT 12
#define MAX_LINE 200

void calculate(vector<vector<int>>& calcVec) {
	map<int, int> calcMap, checkMap;
	int cnt, i, j;
	bool check;
	for (i = 0; i < calcVec.size(); i++) {
		for (j = 0; j < calcVec[i].size(); j++) {
			calcMap[calcVec[i][j]]++;
		}
		cnt = 1;
		while (cnt) {
			check = true;
			for (j = 0; j < calcVec[i].size(); j++) {
				calcVec[i][j] = calcMap[calcVec[i][j]];
				checkMap[calcVec[i][j]]++;
			}
			for (j = 0; j < calcVec[i].size(); j++) {
				check &= (calcVec[i][j] == checkMap[calcVec[i][j]]);
			}
			if (check)break;
			calcMap = checkMap;
			checkMap.clear();
			cnt++;
		}
		printf("%d\n",cnt);
		for (j = 0; j < calcVec[i].size(); j++) {
			printf("%d ", calcVec[i][j]);
		}
		printf("\n");
		calcMap.clear();
		checkMap.clear();
	}
}

void getInputValue(vector<vector<int>>& calcVec) {
	string num, buf1, buf2;
	vector<int> vec;
	for (int i = 0; i < MAX_LINE; i++) {
		getline(cin, num);

		int ele_length = atoi(num.c_str());
		if (!ele_length) { break; }

		vec.reserve(ele_length);
		getline(cin, buf1);
		stringstream ss(buf1);
		while (getline(ss, buf2, ' ')) {
			int value = atoi(buf2.c_str());
			if (!value) { break; }
			if (ele_length == vec.size()) { break; }
			vec.emplace_back(value);
		}
		calcVec.push_back(vec);
		vec.clear();
	}
}


int main() {
	vector<vector<int>> calcVec;
	getInputValue(calcVec);
	calculate(calcVec);
	return 0;
}
