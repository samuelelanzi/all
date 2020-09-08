// MOVE SEMANTIC
#include <iostream>
#include <cstring>

class Image {
private:
  char* bitmap_ = nullptr;
  std::string path_ = "";

public:
	Image(std::string path_file) {
		std::cout << "Invocato il costruttore non vuoto\n";
    path_ = path_file;
    bitmap_ = new char[4 * 1920 * 1080];
	}

	Image() {
		std::cout << "Invocato il costruttore vuoto\n";
    bitmap_ = new char[4 * 1920 * 1080];
	}

  // COPY COSTRUCTOR
  Image(Image&& img) { // rvalue
    std::cout << "Invocato il costruttore MOVE\n";
    path_ = std::move(img.path_);
    bitmap_ = img.bitmap_;
    img.bitmap_ = nullptr;
  } 

  // ASSIGNEMENT OPERATOR
  Image& operator=(Image&& img) {
    std::cout << "Invocato MOVE operatore =\n";
    
    path_ = img.path_;
    delete [] bitmap_;

    bitmap_ = img.bitmap_;
    img.bitmap_ = nullptr;

    return *this;
  }

  ~Image() {
    std::cout << "Distruttore Image\n";
    delete [] bitmap_;
  }
};

class UseImage {
private:
  Image img_;

public:
  UseImage(Image img) { this -> img_ = std::move(img); }
};

int main() {
  UseImage x(Image("Immagini/panorama.png"));
}

