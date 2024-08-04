#include<stdio.h>
#define rows 2
#define columns 2

int main() {
    // Total number of values: (Rows*Columns)*2 Matrices
    // values[0] = a,values[1] = b ... and so on.
    int values[(rows*columns)*2];
    int iterValue = 0;

    // Creating 2 matrices isn't needed for this algorithm since we're only concerned with the values.
    for(int iterMatrix=1;iterMatrix<=2;iterMatrix++) {
        printf("\nMatrix %d: \n",iterMatrix);
        for(int iterRow=1;iterRow<=rows;iterRow++) {
            for(int iterColumn=1;iterColumn<=columns;iterColumn++) {
                printf("Row %d, Column %d: ",(iterRow),(iterColumn));
                // Assigning value to the respective variable.
                scanf("%d",&values[iterValue++]);
            }
        }
    }

    // Calculate intermediate
    int p1 = values[0]*(values[5]-values[7]);               // p1=a(f-h)
    int p2 = (values[0]+values[1])*values[7];               // p2=(a+b)h
    int p3 = (values[2]+values[3])*values[4];               // p3=(c+d)e
    int p4 = values[3]*(values[6]-values[4]);               // p4=d(g-e)
    int p5 = (values[0]+values[3])*(values[4]+values[7]);   // p5=(a+d)(e+h)
    int p6 = (values[1]-values[3])*(values[6]+values[7]);   // p6=(b-d)(g+h)
    int p7 = (values[0]-values[2])*(values[4]+values[5]);   // p7=(a-c)(e+f)

    int resultMatrix[rows][columns] = {
        {(p5+p4-p2+p6),(p1+p2)},
        {(p3+p4),(p1+p5-p3-p7)}
    };
    
    // OUTPUT
    printf("\nResult: \n");
    for(int iter0=0;iter0<rows;iter0++) {
        for(int iter1=0;iter1<columns;iter1++) {
            printf("%d ",resultMatrix[iter0][iter1]);
        }
        printf("\n");
    }
}