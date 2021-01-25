#include <iostream>
#include <string>
using namespace std;

int kingX, kingY, stoneX, stoneY;
string command[8] = { "R","L","B","T","RT","LT","RB","LB" };
int moveY[8] = { 1,-1,0,0,1,-1,1,-1 };
int moveX[8] = { 0,0,-1,1,1,1,-1,-1 };

bool in_range(int x, int y) {
	if (x < 9 && x>0 && y < 9 && y>0) return true;
	else return false;
}

bool isCrushStone(int kx, int ky, int sx, int sy) {
	if (kx == sx && ky == sy) return true;
	else return false;
}

void move(string cmd) {
	for (int i = 0;i < 8;i++) {
		if (cmd == command[i]) {
			int nextKingX = kingX + moveX[i];
			int nextKingY = kingY + moveY[i];

			if (!in_range(nextKingX, nextKingY)) return;

			if (isCrushStone(nextKingX, nextKingY, stoneX, stoneY)) {
				int nextStoneX = stoneX + moveX[i];
				int nextStoneY = stoneY + moveY[i];

				if (!in_range(nextStoneX, nextStoneY)) return;

				stoneX = nextStoneX;
				stoneY = nextStoneY;
			}
			kingX = nextKingX;
			kingY = nextKingY;
			return;
		}
	}
}

int main() {
	string s1, s2;
	int n;
	cin >> s1 >> s2 >> n;

	kingX = s1[1] - '0';
	kingY = s1[0] - 'A' + 1;

	stoneX = s2[1] - '0';
	stoneY = s2[0] - 'A' + 1;

	for (int i = 0;i < n;i++) {
		string s;
		cin >> s;
		move(s);
	}

	cout << (char)('A' + kingY - 1) << kingX << '\n';
	cout << (char)('A' + stoneY - 1) << stoneX << endl;

}