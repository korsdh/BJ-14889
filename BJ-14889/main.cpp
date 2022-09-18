#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
#include <cmath>

using namespace std;

int ability[20][20];
int n;
int answer = 999;
bool team[21];
vector<int> A;
vector<int> B;
vector<int> team_A;
vector<int> team_B;
int team_An = 0; // 팀A의 능력치의 합
int team_Bn = 0; // 팀B의 능력치의 합
int testA[21];
int testB[21];


void make_team(int pos, int cnt) {
	team_A.clear();
	team_B.clear();
	team_An = 0;
	team_Bn = 0;
	if (cnt == (n / 2)) {
		for (int i = 0; i < n; i++) {
			if (team[i] == true) {
				team_A.push_back(i);
			}
			else {
				team_B.push_back(i);
			}
		}
		for (int i = 0; i < (n / 2); i++) {
			for (int j = 0; j < (n / 2); j++) {
				team_An += ability[team_A[i]][team_A[j]];
				team_Bn += ability[team_B[i]][team_B[j]];
			}
		}
		if (abs(team_An - team_Bn) < answer) {
			answer = abs(team_An - team_Bn);
		}
		return;
	}
	for (int i = pos; i < n; i++) {
		if (team[i] == true) continue;
		team[i] = true;
		make_team(i, cnt + 1);
		team[i] = false;
	}
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> ability[i][j];
		}
	}
	make_team(0,0);
	cout << answer << endl;
	cout << "***** test *****" << endl;
	cout << "team A: ";
	for (int i = 0; i < (n / 2); i++) {
		
		cout << testA[i] + 1 << " ";
	}
	cout << endl;
	cout << "team B: ";

	for (int i = 0; i < (n / 2); i++) {
		cout << testB[i] + 1 << " ";
	}
	cout << endl;
	return 0;
}