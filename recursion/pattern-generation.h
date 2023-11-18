void generatePattern(int n) {
  for(int i = 0; i < n; i++) {
    std::cout << '*';
  }
  generatePattern(n - 1);
}