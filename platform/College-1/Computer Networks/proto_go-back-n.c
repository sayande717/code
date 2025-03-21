#include <stdio.h>
#include <stdbool.h>

int main() {
	int windowsize, sent = 0, ack;
	printf("Enter window size: ");
	scanf("%d", &windowsize);
	while (true) {
		for (int i = 0; i < windowsize; i++) {
			printf("Frame %d has been transmitted.\n", sent);
			sent++;
			if (sent == windowsize)
				break;
		}
		printf("\nPlease enter the last Acknowledgement received: ");
		scanf("%d", &ack);

		if (ack == windowsize) {
			printf("All frames have been transmitted successfully.\n");
			break;
		}
		else {
			sent = ack;
		}
	}
	return 0;
}