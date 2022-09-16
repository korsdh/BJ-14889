#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
#include <cmath>

using namespace std;

int ability[21][21];
int n;
int answer = INT_MAX;
bool visit[21];
vector<int> A;
vector<int> B;
vector<pair<int, int>> team_A;
int team_An = 0;
int team_Bn = 0;
vector<pair<int, int>> team_B;

void P(int num) {
	for (int i = 1; i < A.size(); i++) {
		if ((num + i) >= A.size()) return;
		team_A.push_back(make_pair(A[num], A[num + i]));
		team_B.push_back(make_pair(B[num], B[num + 1]));
		P(num + 1);
	}
	
}

void make_team(int num) {
	if (num == (n / 2)) {
		for (int i = 0; i < n; i++) {
			if (visit[i] == false) {
				B.push_back(i);
			}
		}
		P(0);
		for (int i = 0; i < team_A.size(); i++) {
			team_An += (ability[team_A[i].first][team_A[i].second] + ability[team_A[i].second][team_A[i].first]);
			team_Bn += (ability[team_B[i].first][team_B[i].second] + ability[team_B[i].second][team_B[i].first]);
		}
		int result = abs(team_An - team_Bn);
		answer = min(answer, result);
	}
	for (int i = 0; i < n;i++) {
		A.push_back(i);
		visit[i] = true;
		make_team(num + 1);
		visit[i] = false;
	}
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> ability[i][j];
		}
	}
}