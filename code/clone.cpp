#include <cstdlib>
#include <iostream>

int main() {
    start:
    int i = 0;

    std::cout << "[1] clone\n";
    std::cout << "[2] add\n";
    std::cout << "[3] commit\n";
    std::cout << "[4] push\n";
    std::cout << "[5] exit\n";

    std::cin >> i;

    if (i == 1) {
        std::string clone_s1 = "git clone https://github.com/samuelelanzi/";
        std::string clone_s2;
        std::cin >> clone_s2;
        clone_s1.append(clone_s2);
        auto clone_s = clone_s1.c_str();
        std::system(clone_s);
        goto start;
    } else if (i == 2) {
        std::string add_s1 = "git add ";
        std::string add_s2;
        std::cin >> add_s2;
        add_s1.append(add_s2);
        auto add_s = add_s1.c_str();
        std::system(add_s);
        goto start;
    } else if(i == 3) {
        std::string commit_s1 = "git commit -m \"upload\" ";
        std::string commit_s2;
        std::cin >> commit_s2;
        commit_s1.append(commit_s2);
        auto commit_s = commit_s1.c_str();
        std::system(commit_s);
        goto start;
    } else if (i == 4) {
        std::system("git push");
        goto start;
    } else if (i == 5) {
        std::exit(0);
    } else {
        std::cout << "The item doesn't exist!\n";
        goto start;
    }
}