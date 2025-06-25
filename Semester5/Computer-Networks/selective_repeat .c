#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WINDOW_SIZE 4
#define TOTAL_FRAMES 10

// Function to simulate sending a frame
void sendFrame(int frame) 
{
    printf("Sending frame: %d\n", frame);
}

// Function to simulate receiving a frame
void receiveFrame(int frame) 
{
    printf("Frame %d received successfully.\n", frame);
}

// Function to simulate a random frame loss
int isFrameLost() 
{
    return rand() % 2; // Returns 1 (true) or 0 (false) randomly
}

int main() {
    srand(time(0)); // Initialize random seed

    // Array to track acknowledgements of each frame
    int ack[TOTAL_FRAMES] = {0};
    int base = 0; // Base pointer for the sliding window

    // Simulate sending and receiving frames
    while (base < TOTAL_FRAMES) 
    {
        // Send frames in the current window
        for (int i = base; i < base + WINDOW_SIZE && i < TOTAL_FRAMES; i++) 
        {
            if (!ack[i]) 
            {
                sendFrame(i);        // Send frame i

                // Simulate frame loss
                if (isFrameLost()) 
                {
                    printf("Frame %d lost in transit.\n", i);
                } 
                else 
                {
                    receiveFrame(i); // Receive frame i successfully
                    ack[i] = 1; // Acknowledge the frame
                }
            }
        }

        // Move the base pointer to the next unacknowledged frame
        while (base < TOTAL_FRAMES && ack[base]) 
        {
            base++;
        }
    }

    printf("All frames sent and acknowledged successfully!\n");

    return 0;
}
