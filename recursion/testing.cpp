#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int largestBand(vector<int> arr) {
  int n = arr.size();
  unordered_set<int> us;

  for(auto x : arr) {
    us.insert(x);
  }

  int largestBand = 0;
  for(auto x : arr) {
    int parent = x - 1;
    if(us.find(parent) == us.end()) {
      int nextNo = x + 1, count = 1;
      while(us.find(nextNo) != us.end()) {
        nextNo++;
        count++;
      }
      largestBand = max(count, largestBand);
    }
  }
  return largestBand;
}

int main() {
  vector <int> arr = { 1, 9, 3, 0, 18, 5, 2, 4, 10, 7, 12, 6 };
  cout << largestBand(arr) << endl;
}