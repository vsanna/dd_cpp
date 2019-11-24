#include <iostream>

using namespace std;

int calc(int &num)
{
	cout << num << endl;
	return num;
}

int main()
{
	int num = 100;
	calc(num);
}

