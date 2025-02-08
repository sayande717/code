#include <iostream>
#include <cmath>
using namespace std;

int min(int num1, int num2) {
    return (num1<num2)?num1:num2;
}

int max(int num1, int num2) {
    return (num1>num2)?num1:num2;
}

int main() {
    int hours;
    int devices;
    std::cin >> hours;
    std::cin >> devices;
    if(hours<4) {
        std::cout << "Invalid Input";
        return 0;
    }
    
    int comp_devices=min(std::floor(hours/4.0),devices);
    int rem_devices=max(devices-comp_devices,0);
    
    std::cout<<comp_devices << endl;
    std::cout<<rem_devices;
    return 0;
}
                                                                                                                            