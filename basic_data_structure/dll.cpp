#include <vector>
#include <list>
#include <iostream>

using namespace std;

/*
listは doubly linked listのこと
*/

int main(){
  /*
  list<int> li{1, 2, 3}
  list<int> li(10, 5); // 長さ10, 5で初期化

  int org[] = {1, 2, 3};
  list<int> li(org, org + 3);
  */
  list<int> li{4, 6, 5};

  li.push_back(123);
  li.push_front(12);

  auto it = find(li.begin(), li.end(), 4);

  if(it != li.end()) {
    li.insert(it, 100);
  }

  for(int n : li) {
    cout << n << endl;
  }

  li.push_back(12);
  cout << "size:" << li.size() << endl;
  cout << "empty:" << li.empty() << endl;
  li.sort();
  li.unique(); // 連続して重複したものを削除するのでsortしてから
  cout << "size:" << li.size() << endl;
}