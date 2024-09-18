#include<stdio.h>
#include<stdlib.h>

int main() {
    int n;
    printf ("Enter the number of employees: ");
    scanf ("%d",&n);

    int age[n];
    int len = sizeof(age) / sizeof(age[0]);
    printf("Age: %d",len);
    
    for(int index=0;index<len;index++) {
        printf("Enter age: ");
        scanf("%d",&age[index]);
    }
    
    int target;
    printf("Enter the age to search: ");
    scanf("%d",&target);
    
    int last = age[len-1];
    
    int index=0;
    while(age[index]!=target) {
        index++;
    }
    
    age[len-1] = last;
    
    if(index<len-1 || age[len-1] == target) {
        printf("Age exists at position %d.",(index+1));
        exit(0);
    }
    
    printf("\nAge does not exist in the array.");

    return 0;
}
