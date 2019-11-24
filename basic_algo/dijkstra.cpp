#include <iostream>

using namespace std;

// 渡ってきた文字列がuniqなcharだけであることを判定する

bool is_uniq(char msg[]) {
	for(auto ch: msg) {
		cout << ch << endl;
	}

	return false;
}

int main() {
	char msg[] = "hogehoge";
	is_uniq(msg);
}