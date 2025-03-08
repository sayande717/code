#include<stdio.h>
#include<stdbool.h>

int main() {
    int n, target;

    printf("Enter n: ");
    scanf("%d",&n);
    
    int ageArray[n];
    for(int index=0;index<n;index++) {
        printf("Enter age: ");
        scanf("%d",&ageArray[index]);
        
        int currentElement=ageArray[index];
        int sum=0;
        for(int iter=1;iter<currentElement;iter++) {
            if(currentElement%iter==0) {
                sum+=iter;
            }
        }

        // Age cannot be -1, so this denotes that this age isn't a perfect value.
        if(sum!=currentElement) {
            ageArray[index]=-1;
        }
    }
    
    bool noPerfect = false;
    printf("\nPerfect numbers among these: ");
    for(int index=0;index<n;index++) {
        if(ageArray[index]!=-1) {
            noPerfect = true;
            printf("%d, ",ageArray[index]);
        }
    }
    
    if(!noPerfect) {
        printf("There are no perfect values.");
    }
    
    return 0;
}