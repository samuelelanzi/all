#include <iostream>
#include <string>
#include <stdexcept>
#include <cmath>

class Expression {
private:
  std::string s_;
public:
  Expression(std::string s) : s_{s} {}

  void print_str() {
    std::cout << s_ << '\n';
  }

  int find_poln() {
    auto pol_pos = s_.find("x^");
    if (pol_pos < 0 || pol_pos > s_.size()) {
      return 0;
    } else {
      return static_cast<int>(s_[pol_pos + 2] - '0');
    }
  }

  int find_exp() {
    auto e_pos = s_.find("e^");
    if (e_pos >= 0 && e_pos < s_.size()) {
      return 0;
    }
    return -1;
  }

  int find_sin() {
    auto trigo_pos = s_.find("sin");
    if (trigo_pos >= 0 && trigo_pos < s_.size()) {
      return 0;
    }
    return -1;
  }
};

double integral(double const& inf, double const& sup, int const& n_intervals, int const& exponent) {
  double delta_x = (sup - inf) / static_cast<double>(n_intervals);
  double result = 0.;
  for (int i = 0; i != n_intervals; ++i) {
    result += delta_x * std::pow(inf + i * delta_x, exponent);
  }
  return result;
}

int main() {
  std::string s1;
  std::cout << "Function: ";
  std::cin >> s1;
  
  Expression e1 {s1};

  double x_min;
  std::cout << "x min: ";
  std::cin >> x_min;

  double x_max;
  std::cout << "x max: ";
  std::cin >> x_max;

  int n_int;
  std::cout << "intervals: ";
  std::cin >> n_int;

  std::cout << "The integral between " << x_min << " and " 
            << x_max << " is: " << integral(x_min, x_max, n_int, e1.find_poln()) << '\n';
}