#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>

#define WINDOW_SIZE 3
#define TOTAL_PACKETS 4

typedef struct {
    int seq_num;
    bool ack;
} Packet;

void send_packet(Packet *packet) {
    printf("Sending packet %d\n", packet->seq_num);
    packet->ack = false;
}

bool receive_ack(int seq_num) {
    // Simulate packet loss
    return rand() % 2 == 0;
}

void selective_repeat() {
    Packet window[WINDOW_SIZE];
    int base = 0;
    int next_seq_num = 0;

    // Initialize window
    for (int i = 0; i < WINDOW_SIZE; i++) {
        window[i].seq_num = -1;
        window[i].ack = false;
    }

    while (base < TOTAL_PACKETS) {
        // Send packets in the window
        while (next_seq_num < base + WINDOW_SIZE && next_seq_num < TOTAL_PACKETS) {
            window[next_seq_num % WINDOW_SIZE].seq_num = next_seq_num;
            send_packet(&window[next_seq_num % WINDOW_SIZE]);
            next_seq_num++;
        }

        // Wait for ACKs
        sleep(1);

        // Check for ACKs
        for (int i = 0; i < WINDOW_SIZE; i++) {
            if (window[i].seq_num != -1 && !window[i].ack) {
                if (receive_ack(window[i].seq_num)) {
                    printf("Received ACK %d\n", window[i].seq_num);
                    window[i].ack = true;
                } else {
                    printf("Packet %d lost, Resending it.\n", window[i].seq_num);
                    send_packet(&window[i]);
                }
            }
        }

        // Slide window
        while (window[base % WINDOW_SIZE].ack && base < TOTAL_PACKETS) {
            base++;
        }
    }
}

int main() {
    srand(time(NULL));
    printf("\nWindow Size: %d\n\n",WINDOW_SIZE);
    selective_repeat();
    return 0;
}