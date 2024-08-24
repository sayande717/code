#include<stdio.h>

int main() {
    int a[3][4] = {{10,2,3,4},
                   {5,6,7,8},
                   {9,10,11,12}
                  };

    printf("%p \n %u \n %u \n %u",a[0],a[0]+1,*(a[1]),*(a[0]+1)+1);
     // is a and a[0] pointing to same thing?
    return 0;
}