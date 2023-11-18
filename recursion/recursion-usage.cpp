#include<iostream>
#include "largest-element.h"

using namespace std;

void generatePattern(int n) {
  if(n == 0) {
    return;
  }
  for(int i = 0; i < n; i++) {
    cout << '*';
  }
  cout << endl;
  generatePattern(n - 1);
}

int main() {
  int arr[8] = {10, 15, 89, 88, 99, 34, 54, 78};
  generatePattern(4);

  // cout << "Largest Element in array is: " << largest(arr, 0, 7) << endl;
}
