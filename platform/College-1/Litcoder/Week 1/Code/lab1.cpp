#include <iostream>
#include <cstdio>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int len;
    std::cin >> len;
    int *arr = new int[len];
    int positive=0, negative=0, zero=0;
    
    for(int i=0;i<len;i++) {
        std::cin >> arr[i];
        if(arr[i] < 0) {
            negative++;
        } else if(arr[i]>0) {
            positive++;
        } else {
            zero++;
        }
    }
    
    std::cout << std::fixed << std::setprecision(3);
    std::cout << (float)positive/len << endl;
    std::cout << (float)negative/len << endl;
    std::cout << (float)zero/len;
    
    free(arr);
    return 0;
}