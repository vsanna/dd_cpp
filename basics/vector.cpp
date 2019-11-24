#include <iostream>
#include <string>
#include <vector>

#include <algorithm>

using namespace std;

int main() {
	// map
	vector<int> v = {1, 2};
	transform(v.begin(), v.end(), v.begin(), [](int i) {
		return i * 2;
	});
	cout << v[0] << endl;
	
	
	// split
	// この実装がなんとない
	auto split = [](string str, string delimiter = "") -> vector<string> {
		vector<string> result;
		if(str.size() == 0) return result;

		if(delimiter.empty()) {
			for(int i = 0; i < str.size(); i++) {
				char c = str[i];
				result.push_back(string{c});
			}
			return result;
		} else {
			int from = 0;
			while(true) {
				auto to = str.find_first_of(delimiter, from);
				string sub;
				if(to == string::npos) {
					sub = str.substr(from);
				} else {
					sub = str.substr(from, (to-from));
				}
				result.push_back(sub);
				if(to == string::npos) break;
				from = to + 1;
			}
		}
		return result;
	};

	// joinも実装がない
	auto join = [](vector<string> words, string delimiter = "") -> string {
		string result;
		for(auto itr = words.begin(); itr != words.end(); itr++) {
			result += *itr;
			if(!delimiter.empty() && itr+1 != words.end()) {
				result += delimiter;
			}
		}
		return result;
	};

	string e = "hello,hoge,gaho,world";
	cout << join(split(e, ","), "-") << endl;
}