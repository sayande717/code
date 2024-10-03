#include <stdio.h>
#include <stdlib.h>

void generateSequence(int* arr, int size) {
    for(int index=0;index<size;index++) {
        arr[index] = rand()%10; // Generate number between 0 to 9
    }
}

void printSequence(int* arr, int size) {
    printf("\nSequence: ");
    for(int index=0;index<size;index++) {
        printf("%d ",arr[index]);
    }
    printf("\n");
}

void printInfo(char *algorithm, int pageFaults, int hits, int sequences) {
    float hitRatio = (float) hits / sequences;
    float missRatio = 1 - hitRatio;
    printf("\nAlgorithm used: %s \
            \n- Page Faults: %d \
            \n- Hit Ratio: %.2f \
            \n- Miss Ratio: %.2f\n", algorithm, pageFaults, hitRatio, missRatio);
}

void FIFO(int pages[], int sequences, int capacity) {
    int frame[capacity], index = 0, pageFaults = 0, hits = 0;
    for (int i = 0; i < capacity; i++) {
        frame[i] = -1;
    }

    for (int i = 0; i < sequences; i++) {
        int found = 0;
        for (int j = 0; j < capacity; j++) {
            if (frame[j] == pages[i]) {
                found = 1;
                hits++;
                break;
            }
        }

        if (!found) {
            frame[index] = pages[i];
            index = (index + 1) % capacity;
            pageFaults++;
        }
    }

    printInfo("FIFO", pageFaults, hits, sequences);
}

void LRU(int pages[], int sequences, int capacity) {
    int frame[capacity], time[capacity], pageFaults = 0, hits = 0;
    
    for (int i = 0; i < capacity; i++) {
        frame[i] = -1;
    }

    for (int i = 0; i < sequences; i++) {
        int found = 0, lruIndex = 0;
        for (int j = 0; j < capacity; j++) {
            if (frame[j] == pages[i]) {
                found = 1;
                hits++;
                time[j] = i;
                break;
            }
            if (time[j] < time[lruIndex]) lruIndex = j;
        }
        if (!found) {
            frame[lruIndex] = pages[i];
            time[lruIndex] = i;
            pageFaults++;
        }
    }

    printInfo("LRU", pageFaults, hits, sequences);
}

void OPR(int pages[], int sequences, int capacity) {
    int frame[capacity], pageFaults = 0, hits = 0;

    for (int i = 0; i < capacity; i++) {
        frame[i] = -1;
    }

    for (int i = 0; i < sequences; i++) {
        int found = 0, replaceIndex = -1, farthest = i + 1;
        for (int j = 0; j < capacity; j++) {
            if (frame[j] == pages[i]) {
                found = 1;
                hits++;
                break;
            }
            if (frame[j] == -1) {
                replaceIndex = j;
                break;
            }
        }

        if (!found) {
            if (replaceIndex == -1) {
                for (int j = 0; j < capacity; j++) {
                    int k;
                    for (k = i + 1; k < sequences; k++) {
                        if (frame[j] == pages[k]) break;
                    }
                    if (k > farthest) {
                        farthest = k;
                        replaceIndex = j;
                    }
                }
            }
            frame[replaceIndex] = pages[i];
            pageFaults++;
        }
    }

    printInfo("OPR", pageFaults, hits, sequences);
}

int main() {
    // input
    int sequences,capacity;
    printf("Enter number of sequences: "); scanf("%d",&sequences);
    printf("Enter capacity (frame size): "); scanf("%d",&capacity);

    int* pages = (int*)malloc(sizeof(int)*sequences);
    generateSequence(pages,sequences);
    printSequence(pages,sequences);

    // process, output
    FIFO(pages, sequences, capacity);
    LRU(pages, sequences, capacity);
    OPR(pages, sequences, capacity);

    return EXIT_SUCCESS;
}
