#include<iostream>
#include<cassert>

using namespace std;
#include "ArrayClass.h"

int main() {
  ArrayADT<int> array(100);

  for (int i = 0; i < 10; i++)
  {
    array.addAt(i, i);
  }
  int num = 5;

  array.print();

  array.addNoDuplicates(67);

  array.print();

  array.removeItem(5);
  array.print();
  cout << "Capacity: " << array.capacity() << endl;
  cout << "Size: " << array.size() << endl;
  cout << "Element at 5: " << array.search(num) << endl;
  cout << endl;

  return 0;
}