#include <vector>
#include <forward_list>
#include <iostream>

using namespace std;

/*
listは doubly linked listのこと
*/

int size(forward_list<int> li) {
  if(li.empty()) return 0;
  int size = 0;
  for(int n: li) {
    size++;
  }
  return size;
}

int main(){
  /*
  list<int> li{1, 2, 3}
  list<int> li(10, 5); // 長さ10, 5で初期化

  int org[] = {1, 2, 3};
  list<int> li(org, org + 3);
  */
  forward_list<int> li{4, 6, 5};

  li.push_front(12);

  auto it = find(li.begin(), li.end(), 4);

  if(it != li.end()) {
    li.insert_after(it, 100);
  }

  for(int n : li) {
    cout << n << endl;
  }

  li.push_front(12);
  cout << "size:" << size(li) << endl;
  cout << "empty:" << li.empty() << endl;
  li.sort();
  li.unique();
  cout << "size:" << size(li) << endl;
}