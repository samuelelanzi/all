#include <iostream>
#include <random>
#include <stdexcept>
#include <vector>

std::vector<int> VectorRi (int const& n, int const& A, int const& B) {
  if (n <= 0) {
    throw std::invalid_argument("Il vettore è vuoto");
  }

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrib(A, B);
  std::vector<int> v {};
  for (int i = 0; i != n; ++i) {
    v.push_back(distrib(gen));
  }
  return v;
}

void print(std::vector<int> const& v) {
  for(auto const& i : v) {
    std::cout << i << ' ';
  }
  std::cout << '\n';
}


int main() {
  try {
    int N;
    std::cin >> N;
    std::vector<int> v1 = VectorRi(N, 0, 50);
    print(v1);
  } catch (std::invalid_argument& e) {
    std::cerr << e.what() << '\n';
  }
}
