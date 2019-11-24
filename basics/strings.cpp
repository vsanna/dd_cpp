#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>

using namespace std;

int main() {
	string a = "Hello";
	string b = "worlD";

	// join
	cout << a + b << endl;

	// compare
	cout << (a == b ? "true" : "false") << endl;
	cout << (a+b == "HelloworlD" ? "true" : "false") << endl;

	// length
	cout << a.size() << " " << b.size() << endl;

	// capitalize
	// string c{b};
	string c = b; // 値渡しでコピーされる. bに影響はない
	c[0] = toupper(c[0]);
	cout << c << endl;
	cout << b << endl;

	// upcase
	string d = c;
	// 破壊的な変更. 第三引数であるdistも当人にする
	// transform(c.begin(), c.end(), c.begin(), [](char ch) {
	// 	return toupper(ch);
	// });

	// 非破壊的な変更	
	transform(c.begin(), c.end(), d.begin(), [](char ch) {
		return toupper(ch);
	});
	cout << c << endl;
	cout << d << endl;

	// each_char
	// use string as char[]
	// TODO: もう一度 char[]とchar*の確認をする

	// include?
	cout << ((d.find_first_of("O") != string::npos) ? "true" : "false") << endl;

	// to_i
	string num = "123";
	cout << stoi(num) + 100 << endl;

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

	// replace
	string f = "a-b-c-b-e";

	// charのreplace
	replace(f.begin(), f.end(), '-', '/');
	cout << f << endl;

	// stringのreplace
	// 全置換
	auto replace = [](string before, string target, string replacement) -> string{
		string result = before; // 元のデータを壊さない	
		int from = 0;
		while(true) {
			// fromからtargetを探す
			auto pos = result.find(target, from);
			if(pos == string::npos) break;
			// 見つかったところからreplace対象の長さをreplacementに差し替える(spliceっぽい)
			result.replace(pos, target.length(), replacement);
			// 差し替えた先から探す
			from = pos + replacement.length();
		}
		return result;
	};
	cout << replace(f, "/b", "_") << endl;

	// match
	// 部分一致: regex_search(string, regex) -> bool
	cout << (regex_search("aiueo", regex("[0-9]")) ? "true" : "false") << endl;
	cout << (regex_search("aiueo", regex("[a-z]")) ? "true" : "false") << endl;
	// 完全一致: regex_match
	cout << (regex_match("aiueo", regex("[a-z]")) ? "true" : "false") << endl;
	cout << (regex_match("aiueo", regex("[a-z]*")) ? "true" : "false") << endl;
	
	// 抽出
	// 1箇所matchならregex_searchとcmatch. regeex_searchの台に引数に変数を入れる
	cmatch results;
	if(regex_search("Shop 99", results, regex("(\\w+) (\\d+)"))) {
		cout << "string: " << results.str() << endl;
		cout << "position: " << results.position() << endl;
		cout << "length: " << results.length() << endl;
	}
	// キャプチャ月matchならregex_resultとcmatch. regeex_searchの台に引数に変数を入れる
	smatch sresults;
	if(regex_match("Shop 99", sresults, regex("(\\w+) (\\d+)"))) {
		cout << "string: " << sresults.str() << endl;
		// cout << "position: " << sresults.position() << endl;
		// cout << "length: " << sresults.length() << endl;
		
		cout << "string: " << sresults[0].str() << endl;
		// cout << "position: " << sresults[0].position() << endl;
		// cout << "length: " << sresults[0].length() << endl;
		
		cout << "string: " << sresults[1].str() << endl;
		// cout << "position: " << sresults[1].position() << endl;
		// cout << "length: " << sresults[1].length() << endl;
	}
}