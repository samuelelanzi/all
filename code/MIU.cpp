#include <iostream>
#include <cstring>
#include <vector>
#include <random>

class MIU {
private:
  static std::vector<char> miu_;
  static int n_el;

public:
  MIU() {}

  void add(char const& c) { 
    ++n_el;
    miu_.push_back(c); 
  }

  void print() {
    for(auto const& i : miu_) {
      std::cout << i;
    }
    std::cout << '\n';
  }

  void printN() { std::cout << n_el << '\n'; }

  static void addU() {
    if(miu_[n_el - 1] == 'i') {
      ++n_el;
      miu_.push_back('u');
    }
  }

  static void add2() {
    int n2 = n_el;
    for(int i = 1; i < n2; ++i) {
      ++n_el;
      miu_.push_back(miu_[i]);
    }
  }

  static void iiiU() {
    for(int i = 0; i < n_el; ++i) {
      if ((miu_[i] == 'i') && (miu_[i + 1] == 'i') && (miu_[i + 2] == 'i')) {
        n_el = n_el - 2;
        miu_[i] = 'u';
        miu_.erase(miu_.begin() + i + 1);
        miu_.erase(miu_.begin() + i + 1);
        break;
      }
    }
  }

  static void uu() {
    for(int i = 0; i < n_el; ++i) {
      if ((miu_[i] == 'u') && (miu_[i + 1] == 'u')) {
        n_el = n_el - 2;
        miu_.erase(miu_.begin() + i);
        miu_.erase(miu_.begin() + i);
        break;
      }
    }
  }

  static bool stop() {
    if(n_el > 1e3) {
      return false;
    }
    return true;
  }
};

std::vector<char> MIU::miu_ {'m'};
int MIU::n_el = 1;

int main() {
  const char m = 'm';
  const char i = 'i';
  const char u = 'u';

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dist(1, 3);

  MIU s;
  s.add(i);
  s.print();
  s.printN();
  
  while(MIU::stop()) {
    int p = dist(gen);
    if(p == 1) {
      s.addU();
      s.print();
      s.printN();
    } else if(p == 2) {
      s.add2();
      s.print();
      s.printN();
    } else if(p == 3) {
      s.iiiU();
      s.print();
      s.printN();
    } else {
      s.uu();
      s.print();
      s.printN();
    }
  }
}