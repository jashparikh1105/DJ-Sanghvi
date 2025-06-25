#include <stdio.h>

void leakyBucket(int incomingPacketSize, int bucketSize, int outputRate) {
    int bucketContent = 0; 
    int time = 0;         

    printf("Time\tIncoming\tBucket_Content\tSent\tDropped\n");
    while (incomingPacketSize > 0 || bucketContent > 0) 
    {
        int sent; 
        if(bucketContent < outputRate)
        {
            sent = bucketContent;
        }
        else
        {
            sent = outputRate;
        }
        int dropped = 0;
        if (incomingPacketSize > 0) 
        {
            if (bucketContent + incomingPacketSize <= bucketSize)
            {
                bucketContent += incomingPacketSize;
            } 
            else
            {
                dropped = incomingPacketSize - (bucketSize - bucketContent); 
                bucketContent = bucketSize;
            }
        }
        printf("%d\t\t%d\t\t\t%d\t\t\t\t%d\t\t%d\n", time, incomingPacketSize, bucketContent, sent, dropped);

        bucketContent -= sent; 
        incomingPacketSize = 0; 
        time++;                 
    }
}
int main() 
{
    int incomingPacketSize, bucketSize, outputRate;
    printf("Enter the size of incoming data: ");
    scanf("%d", &incomingPacketSize);
    printf("Enter the bucket size: ");
    scanf("%d", &bucketSize);
    printf("Enter the output rate: ");
    scanf("%d", &outputRate);
    leakyBucket(incomingPacketSize, bucketSize, outputRate);
    return 0;
}
