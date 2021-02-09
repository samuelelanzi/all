#include <iostream>

void print_square(int const& n, std::string const& s) {
  for(int i = 0; i != n; ++i) {
    for(int j = 0; j != n; ++j) {
      if(i == 0 || i == n - 1) {
        std::cout << s;
      } else {
        if (j == 0 || j == n - 1) {
          std::cout << s;
        } else {
          std::cout << "  ";
        }
      }
    }
    std::cout << '\n';
  }
}

int main() {
  int n;
  std::cin >> n;
  print_square(n, "# ");
}