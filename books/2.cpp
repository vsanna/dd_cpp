#include <iostream>
#include <string>
#include <vector>

using namespace std;

int useFor(int &num)
{
	for (int i = 0; i < num; i++)
	{
		cout << "for: " << i << endl;
	}
	return num;
}

bool useIf(bool &flag)
{
	if (flag)
	{
		cout << "flag is true" << endl;
	}
	else
	{
		cout << "flag is false" << endl;
	}
	return !flag;
}

int useWhile(int &num)
{
	while (true)
	{
		if (num % 2 == 0)
		{
			num++;
			continue;
		}
		if (num > 100)
			break;
		num++;
		cout << "while: " << num << endl;
	}
	return num;
}

enum keywords
{
	A,
	B,
	C,
	D
};
string useSwitch(keywords key)
{
	string result;

	switch (key)
	{
	case A:
		result = "this is A";
		break;
	case B:
		result = "this is B";
		break;
	default:
		result = "this is not A nor B";
		break;
	}
	cout << result << endl;
	return result;
}

int useError(bool &throwError)
{
	try
	{
		cout << "例外を起こすかもしれない処理" << endl;
		if (throwError)
		{
			throw "BAD THINGS!!";
		}
		return 0;
	}
	catch (...)
	{
		cout << "error occured!" << endl;
		return 1;
	}

	return 3;
}

int main()
{
	int num = 100;
	int num2 = num - 10;
	string msg = "hello world";
	bool flag = false;
	bool throwError = true;

	useFor(num);
	useWhile(num2); // 参照引数に直に数字は渡せない
	useIf(flag);
	useSwitch(keywords::A);
	useError(throwError);

	class Dog
	{
		string name;
		int age;

	  public:
		Dog(string &name, int age);
		operator string() const { return name; }
	};

	// vector<string> names(10); // forで回すと空文字が7回表示される
	vector<string> names;
	names.push_back("hoge");
	names.push_back("geho");
	names.push_back("gaha");
	// vector<string>::size_type => i にcastっされてる
	for (int i = 0; i < names.size(); i++)
	{
		cout << i << names[i] << endl;
	}

	// vector for loop
	for (vector<string>::iterator p = names.begin(); p != names.end(); p++)
	{
		cout << *p << endl;
	}
}