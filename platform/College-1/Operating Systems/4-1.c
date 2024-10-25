#include <stdio.h>
#include <stdlib.h>
#define INIT_HEAD 50
#define MAX_REQUESTS 5

int distance(int pos1, int pos2) {
    if(pos1>pos2) {
        return (pos1-pos2);
    }
    return (pos2-pos1);
}

void printSeekTime(int total_distance) {
    printf("\nSeek Time: %d",total_distance);
}

void FCFS(int* requests) {
    printf("\n\nAlgorithm: First Come First Serve (FCFS)");
    int current_pos = INIT_HEAD;
    int total_distance = 0;
    for(int request=0;request<MAX_REQUESTS;request++) {
        int current_req = requests[request];
        int current_distance = distance(current_pos,current_req);
        printf("\nHead moving from %d to %d, distance covered: %d",current_pos \
                                                                ,current_req \
                                                                ,current_distance);
        total_distance+=current_distance;
	current_pos = current_req;
    }

    printSeekTime(total_distance);

}

void SSTF(int* requests) {
    printf("\n\nAlgorithm: Shortest Seek Time First (SSTF)");
    int current_pos = INIT_HEAD;
    int* diff = (int*)malloc(sizeof(int)*MAX_REQUESTS);

    int total_distance = 0;
    int min_distance = 100;
    int min_index = MAX_REQUESTS;
    // Calculate ALL distances between data locations (only once).
    for(int request=0;request<MAX_REQUESTS;request++) {
	int current_req = requests[request];
	diff[request] = distance(current_pos,current_req);
    }

    // Get minimum distance -> process data -> set arr[index] = -1 -> exclude that location next time.
    for(int iter=0;iter<MAX_REQUESTS;iter++) {
	for(int request=0;request<MAX_REQUESTS;request++) {
	    if((requests[request]!=-1) && (diff[request] < min_distance)) {
		min_index = request;
		min_distance = diff[request];
	    }
	}

	total_distance+=min_distance;
        printf("\nHead moving from %d to %d, distance covered: %d",current_pos \
	    	    					          ,requests[min_index] \
							          ,min_distance);
    	requests[min_index] = -1;
	min_distance = 100;
    }
    printSeekTime(total_distance);
}


int main() {
    int* requests = (int*)malloc(sizeof(int)*MAX_REQUESTS);
    if(requests==NULL) {
        fprintf(stderr,"Memory Allocation failed");
        exit(EXIT_FAILURE);
    }
    requests[0] = 63;
    requests[1] = 34;
    requests[2] = 45;
    requests[3] = 20;
    requests[4] = 98;

    printf("Maximum number of requests: %d",MAX_REQUESTS);

    FCFS(requests);
    SSTF(requests);

    printf("\n");
    free(requests);
    return EXIT_SUCCESS;
}
