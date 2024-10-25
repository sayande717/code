#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Iterative Interpolation Search
bool interpolationSearchAndRemove(int* arr, int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high && arr[low] <= target && arr[high] >= target) {
        if (arr[low] == arr[high]) {
            if (arr[low] == target) {
                arr[low] = -1;
                return true;
            }
            break;
        }

        int mid = low + ((target - arr[low]) * (high - low) / (arr[high] - arr[low]));

        if (arr[mid] < target) {
            low = mid + 1;
        } else if (arr[mid] > target) {
            high = mid - 1;
        } else {
            arr[mid] = -1;
            return true;
        }
    }

    return false;
}

int main() {
    int size, target;
    printf("Enter number of elements: ");
    scanf("%d", &size);
    int* heights = (int*)malloc(sizeof(int) * size);
    for (int index = 0; index < size; index++) {
        printf("Enter height (in cm): ");
        scanf("%d", &heights[index]);
    }

    printf("\nEnter height to remove: ");
    scanf("%d", &target);

    while (interpolationSearchAndRemove(heights, size, target)) {
        // Continue removing all instances
    }

    printf("Updated heights: ");
    for (int index = 0; index < size; index++) {
        if (heights[index] != -1) {
            printf("%d ", heights[index]);
        }
    }
    printf("\n");

    free(heights);
    return EXIT_SUCCESS;
}

