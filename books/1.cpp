#include <iostream>
#include <string>
#include "Date.h"

#include "Counter.h"

using namespace std;

int main() {
	/*********************
	 * ch1. 基本文法
	 * ******************/	

	// 変数, 出力
	int age = 20;
	cout << age << endl;

	// if, switch
	if (1) {
		cout << "it's 1" << endl;
	}

	if (!false) {
		cout << "it's !false" << endl;
	}

	int num = 2;
	switch(num) {
		case 0:
			cout << "0" << endl;	break;
		case 1:
			cout << "1" << endl;	break;
		case 2:
			cout << "2" << endl;	break;
		default:
			cout << "default" << endl;
	}

	// do {} while()
	// while(){}
	// for(){}

	while(num < 5) {
		cout << num << endl;
		num++;
	}

	for(int i = 0; i < 10; i++) {
		cout << i << endl;
	}

	/*********************
	 * ch4. 基本的なデータ構造
	 * ******************/	
	// char, short, int, long, double, float, long double
	// bool. boolalpha, noboolalpha
	// bool
	// enum
	enum animal { Dog, Cat, Monkey, Invalid };
	int type;
	cin >> type;
	animal selected = static_cast<animal>(type);
	animal selected2 = animal(type);
	cout << "selected: " << selected << endl;
	cout << "selected2: " << selected2 << endl;

	switch(selected) {
		case Dog: cout << "Dog!!" << endl; break;
		case Cat: cout << "Cat!!" << endl; break;
		case Monkey: cout << "Monkey!!" << endl; break;
	}

	// 型キャスト
	int x = 10;
	int y = 20;
	double avg = (x + y) / 2.0;
	double avg2 = (double)(x + y) / 2;
	double avg3 = double(x + y) / 2;

	// sizeof, typeid(int).name()
	// typedef ... type alias / hoge_t type
	
	/*********************
	 * ch5. 配列
	 * ******************/	
	// 配列名は配列先頭要素のポインタと同じ
	// 配列の初期化
	string names[] = { "Hoge", "Geho", "Gaho", "HIHI" };
	// 配列の長さ求める公式
	cout << "the length of names is: " << (sizeof(names) / sizeof(string)) << endl;

	/*********************
	 * ch6. 関数の基本
	 * ******************/	
	// 関数の多重定義
	// インライン関数
	// 引数は値渡し。参照私は void hoge(int& a){}
	//     参照渡のほうがいい
	// namespaceとnamespaceのアクセッサ. 
	//     English::hello() 
	//     namespace English{}
	// 静的/自動/動的. コンパイル時に定数で配列の長さを定めるのが静的/自動. 動的な場合は自身でメモリを確保・開放する必要がある
	// bit演算
	// main関数 ... 引数はプログラム名とオプション
	
	
	/*********************
	 * ch7. ポインタ
	 * ******************/	
	// アドレス演算子と関節演算子
	int num2 = 20;
	int* pointer_of_num2 = &num2;
	int num2_from_pointer = *pointer_of_num2;

	// ポインタのincrement/decrement
	// ポインタの減算
	// 動的なオブジェクト生成
	int* num3 = new int(5); // 初期化子つき初期化
	delete num3;

	int asize = 10;
	int* num4 = new int[asize];
	
	/*********************
	 * ch8. 文字列とポインタ(Cを読むために)
	 * ******************/	
	// 文字列はcharの配列、すなわち戦闘要素のchar*である
	
	/*********************
	 * ch9. 関数の応用
	 * ******************/	
	// 関数テンプレート / テンプレート関数
	// 具体化 / 特殊化
	// ファイルの分割
	//     外部結合(open)と内部結合(closed)
	//         static, inline func, constで内部結合
	//     externで外部の変数を利用
	//	   headerファイルのinclude	
	// using宣言とusing指令. stdはusing指令、その他はusing宣言がよい
	
	/*********************
	 * ch10. クラスの定義
	 * ******************/	
	// private, public
	// constructor
	// attrは_attrという命名規則が一番良さそう. _attr / get_attr / get_alias_of_attr
	// classの拡張は関数内ではできない
	class Account {
	private:
		string _name;
		string _number;
		long _balance;
	public:
		Account(string n, string num, long b) {
			_name = n;
			_number = num;
			_balance = b; // thisがないのはちょっと面倒だな。 balance = balanceとかで認識してくれないし -> あった
			// this->name = name; // これはOK. 引数を同名にした時点でthis.nameを隠す
		}

		long balance() {
			return _balance;
		}

		string number(){
			return _number;
		}
			
		string name() {
			return _name;
		}

		void deposit(long num) {
			_balance += num;
		}
	};

	// void Account::deposit(long num) {
	// 	_balance += num;
	// }

	Account myAccount("Tom", "0000-0000-0000", 100000);
	cout << myAccount.balance() << endl;
	myAccount.deposit(100000);
	cout << myAccount.balance() << endl;

	/*********************
	 * ch11. 単純なクラスの作成
	 * ******************/	
	// header/実装を分けてみる
	//     date.h
	//     date.cpp
	//     headerにも実装が含まれている。使い分けがよくわからない
	// 初期化は3通り
	//     Date a(2019, 1, 1);
	//     Date b = a; // メンバ単位でコピーされる。コピーコンストラクタ Date::Date(const Date& x) {} がコンパイラによって用意される
	//     Date c = Date(2019, 1, 1); // これもいける
	// 引数を持たないコンストラクタ = デフォルトコンストラクタを設けておくと、 Date dates[] みたいな初期化子を伴わないユーザークラスの配列を宣言できる
	// constオブジェクト const Date d = Date();
	//     constオブジェクトはメンバ関数にアクセスできない。constメンバ関数にする必要がある
	//     constメンバ関数内で変更したいメンバは mutable int counter; のようにmutableを宣言する
	// thisポインタ
	//     メンバ関数内ではthisを刺すポインタが常にある
	// const メンバ関数
	// mutable メンバ
	// 文字列ストリーム. golangのbufferみたいな感じ。
	// コンストラクタ初期化子. 基本これを使ったほうがいいのかな
	//    コンストラクタの書き方
	//        1. 引数とフィールド名を別にする。
	//            - フィールドは_を使う
	//  		  - 完全に別の名前の引数にする
	// 	      2. thisを使う
	//        3. コンストラクタ初期化子を使う
	// インクルードガード

	// Date date1 = Date(2019, 1, 1);
	// Date date2 = Date();
	// cout << date1.year() << date1.month() << date1.date() << endl;
	// cout << date2.year() << date2.month() << date2.date() << endl;
	// Date dates[] = { Date(), Date(), Date() };

	Counter counter;
	cout << "current value is: " << counter.value() << endl;
	counter.increment();
	cout << "current value is: " << counter.value() << endl;
	counter.increment();
	cout << "current value is: " << counter.value() << endl;
	counter.increment();
	cout << "current value is: " << counter.value() << endl;

	// 変換関数: ユーザークラスを特定の例えばint, string型などに置き換える
	// operator Type const () { return hoge; } を実装する
	// constが必須(もとのオブジェクトに影響を与えないように)

	// 演算子関数. ! + - ++ -- [] =(代入) などもオーバ＝ロードできる
	// Counter operator!() const { return cnnt == 0; }
	// && || はオーバーロ＝度しないほうがいい
	// ユーザークラスにおいては代入演算子は多重定義したほうがいい。そうでないとでコンストラクタで消せないメモリ領域ができちゃう
	// != == は自動で付与されないのでこれも定義しておくべき。== != = は自ら定義する

	// 変換コンストラクタ: int -> ユーザークラスにする。変換関数の逆
	// 単に(デフォルト引数を除いた)引数が1個のコンストラクタのこと
	// 変換関数と合わせてユーザー定義変換という。
	// 例えば暗黙的な型変換などで使われる。 Date date = 2019; はこれのこと。

	// フレンド関数: 非メンバ関数でありながらpublic メンバにアクセスできる関数

	// const 参照渡し
	// C++ではポインタ値渡しなんてことはしない. ポインタチェックも面倒だし参照私が基本
	

	// 静的メンバ: class attr. 宣言はクラス内、初期化は別でやる。一緒にできない
	// 静的メンバ関数

	// 明示的コンストラクタ. Date date = 2019 を禁止する。 Date date = Date(2019) 出ないとだめ
	// explicit Date(int y){}

	// デコンストラクタ. -Date(){} 内部で例えば配列のようなものを確保する
	// しかし代入で全メンバを代入した際、デコンストラクタが走らないため解放されない配列などが出てきてしまう
	// それを回避するため代入演算子を定義しておく
	// Counter& Counter::operator=(const Counter& other){ return this; }
	// コピーコンストラクタも同様
	// Counter::Counter(const Counter& other) {...}


	/*
	// 例外処理
	throw なんでもいい
	    throw "bad arguments"
	    throw MyOriginalError
	    class MyOriginalError {} // からっぽのクラスでもOK
	
	try {
	
	} catch(const char* err_msg) {
	
	} catch(MyOriginalError& err) {
	
	}
	*/
}


/*
## memo
- [x] 基本文法への習熟
- [x] vector, map/unordered_map
- [ ] cast周り. const_cast, static_castなどの使い分け
- [ ] vector, singly_linked_list, doubly_linked_list, stack, queue, tree, heap, graphの実装
	- 「コンテナ」というっぽい: 
		- [x] vector
		- [x] array
		- [x] list
		- [x] forward_list(SLL)
		- [x] deque
		- [x] queue
		- [x] priority_queue
		- [x] stack
		- [x] map
		- [x] unordered_map
		- [x] set
	- コンテナからはイテレータが取れる
	- コンテナはbegin(), end()をもつ
		- 他: rbegin()/rend(), cbegin(), cend(), erbegin(), erend()
- [ ] 基本問題をとく
- [ ] leetcodeとく
- [x] 正規表現
- [x] autoってなに: 型推論だった。便利
- [ ] ムーブってなに / ムーブセマンティクスとは
- [x] ラムダ式があるのか
- [ ] smart pointerってなに
- [ ] C++11の機能
	- auto: 型推論
	- range-based for for(auto&& e : arr)
		- auto&& はおまじない. eは溶損の参照
- [ ] headerについて
*/