#include<stdio.h>
#include<stdlib.h>

int main() {
    int n;
    printf ("Enter the number of employees: ");
    scanf ("%d",&n);

    int age[n];
    
    for(int index=0;index<n;index++) {
        printf("Enter age: ");
        scanf("%d",&age[index]);
    }
    
    int target;
    printf("Enter the age to search: ");
    scanf("%d",&target);
    
    // Backup the last element, add the sentinel at the end.
    int last = age[n-1];
    age[n-1] = target;

    int index=0;
    while(age[index]!=target) {
        index++;
    }

    // Restore the sentinel element.
    age[n-1] = last;
    
    
    if(index<n-1 || age[n-1] == target) {
        printf("Age exists at position %d.",(index+1));
        exit(0);
    }
    
    printf("\nAge does not exist in the array.");

    return 0;
}
