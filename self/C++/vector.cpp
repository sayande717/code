#include<iostream>
#include<vector>

int main() {
    std::vector<int> vec0{1,2,3,4,5};
    std::vector<std::string> vec1{"AAA","BBB","CCC"};

    for(int index: vec0) {
        std::cout << index << " ";
    }

    std::cout << std::endl;

    for(std::string index: vec1) {
        std::cout << index << " ";
    }


    return 0;
}
