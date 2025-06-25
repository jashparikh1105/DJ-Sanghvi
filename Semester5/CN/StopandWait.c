#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

// Function to simulate random frame loss
int isFrameLost() 
{
    return rand() % 2; // Returns 1 (true) or 0 (false) randomly
}

// Function to simulate random acknowledgment loss
int isAckLost() 
{
    return rand() % 2; // Returns 1 (true) or 0 (false) randomly
}

int main() 
{
    srand(time(0)); // Initialize random seed

    int frame = 0; // Current frame being sent

    // Simulate Stop-and-Wait ARQ
    while (frame < TOTAL_FRAMES) 
    {
        // Send the current frame
        sendFrame(frame);

        // Simulate frame loss
        if (isFrameLost()) 
        {
            printf("Frame %d lost in transit. Retransmitting...\n", frame);
            continue; // Retransmit the same frame
        }

        // Simulate acknowledgment loss
        if (isAckLost()) 
        {
            printf("Acknowledgment for frame %d lost. Retransmitting...\n", frame);
            continue; // Retransmit the same frame
        }

        // If no loss occurs, frame is received successfully
        receiveFrame(frame);
        printf("Acknowledgment received for frame %d.\n\n", frame);

        // Move to the next frame
        frame++;
    }

    printf("All frames sent and acknowledged successfully!\n");

    return 0;
}
