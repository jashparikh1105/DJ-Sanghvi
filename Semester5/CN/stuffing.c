#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void characterCountFraming();
void byteStuffing();
void bitStuffing();

int main() 
{
    int choice;

    do {
        printf("\nSelect Framing Technique:\n");
        printf("1. Character Count Framing\n");
        printf("2. Byte Stuffing\n");
        printf("3. Bit Stuffing\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                characterCountFraming();
                break;

            case 2:
                byteStuffing();
                break;

            case 3:
                bitStuffing();
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please select a valid option.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}
void characterCountFraming() 
{
    int frames;
    char data[100], transmittedFrame[1000] = "";

    printf("Enter number of frames: "); 
    scanf("%d", &frames);

    for (int i = 0; i < frames; i++) 
    {
        printf("Enter frame %d: ", i + 1);
        scanf("%s", data);
        char lengthStr[10];
        sprintf(lengthStr, "%lu", strlen(data) + 1); 
        strcat(transmittedFrame, lengthStr);
        strcat(transmittedFrame, data);
    }

    printf("\nTransmitted Frame: %s\n", transmittedFrame);
    printf("\nDecoded Data: ");
    int i = 0;
    while (i < strlen(transmittedFrame)) 
    {
        int length = transmittedFrame[i] - '0'; 
        for (int j = 1; j < length; j++)
        {
            printf("%c", transmittedFrame[i + j]);
        }
        printf(" ");
        i += length;
    }
    printf("\n");
}
void byteStuffing() 
{
    char data[100], stuffedData[1000] = "";
    char flag[] = "FLAG", esc[] = "ESC";

    printf("Enter the data: ");
    scanf("%s", data);

    strcat(stuffedData, flag);

    for (int i = 0; i < strlen(data); i++) 
    {
        if (data[i] == 'F' && data[i + 1] == 'L' && data[i + 2] == 'A' && data[i + 3] == 'G') 
        {
            strcat(stuffedData, esc); 
        }
        else if (data[i] == 'E' && data[i + 1] == 'S' && data[i + 2] == 'C') 
        {
            strcat(stuffedData, esc); 
        }
        strncat(stuffedData, &data[i], 1);
    }

    strcat(stuffedData, flag);
    printf("\nTransmitted Frame: %s\n", stuffedData);
    
    printf("\nDecoded Data: ");
    for (int i = 4; i < strlen(stuffedData) - 4; i++) 
    { 
        if (stuffedData[i] == 'E' && stuffedData[i + 1] == 'S' && stuffedData[i + 2] == 'C') 
        {
            i += 3; 
        }
        printf("%c", stuffedData[i]);
    }
    printf("\n");
}
void bitStuffing() 
{
    char data[100], stuffedData[1000] = "", decoded[100] = "";
    char flag[] = "01111110";
    int count = 0;
    printf("Enter the binary data: ");
    scanf("%s", data);
    strcat(stuffedData, flag);

    for (int i = 0; i < strlen(data); i++) 
    {
        if (data[i] == '1') 
        {
            count++;
            strcat(stuffedData, "1");
            if (count == 5) 
            {
                strcat(stuffedData, "0");
                count = 0;
            }
        } 
        else 
        {
            count = 0;
            strcat(stuffedData, "0"); 
        }
    }
    strcat(stuffedData, flag);
    printf("\nTransmitted Frame: %s\n", stuffedData);
    for (int i = 8; i < strlen(stuffedData) - 8; i++) 
    { 
        char bit = stuffedData[i];
        if (bit == '1') 
        {
            count++;
        } 
        else 
        {
            count = 0;
        }
        strncat(decoded, &bit, 1);
        if (count == 5 && stuffedData[i + 1] == '0') 
        {
            i++; 
            count = 0;
        }
    }
    printf("\nDecoded Data : %s", decoded);
}