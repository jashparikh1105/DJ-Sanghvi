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

// Function to simulate random frame loss (50% chance)
int isFrameLost() 
{
    return rand() % 2;
}

int main() 
{
    // Initialize random seed
    srand(time(NULL));

    int base = 0; // Base of the sliding window
    int nextFrameToSend = 0; // Next sequence number to send

    // Send and receive frames in a sliding window manner
    while (base < TOTAL_FRAMES) 
    {
        // Send frames within the window
        while (nextFrameToSend < base + WINDOW_SIZE && nextFrameToSend < TOTAL_FRAMES) 
        {
            sendFrame(nextFrameToSend);
            nextFrameToSend++;
        }

        // Simulate the receiving side and frame loss
        for (int i = base; i < nextFrameToSend; i++) 
        {
            if (isFrameLost()) 
            {
                printf("Frame %d lost in transit. Resending window...\n", i);
                nextFrameToSend = base; // Resend the window from the base
                break;
            } 
            else 
            {
                receiveFrame(i);
                base++; // Move base forward after successful reception
            }
        }
    }

    printf("All frames sent and acknowledged successfully!\n");

    return 0;
}
