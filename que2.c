// Q.2 Write the simulation program to implement demand paging and show the page scheduling
// and total number of page faults for the following given page reference string. Give input n=3 as
// the number of memory frames.
// Reference String :3, 4, 5, 6, 3, 4, 7, 3, 4, 5, 6, 7, 2, 4, 6
// Implement FIFO 

#include <stdio.h>

#define MAX_FRAMES 3

int main() {
    int referenceString[] = {3, 4, 5, 6, 3, 4, 7, 3, 4, 5, 6, 7, 2, 4, 6};
    int n = sizeof(referenceString) / sizeof(referenceString[0]);
    int memoryFrames[MAX_FRAMES];
    int pageFaults = 0;

    int frameIndex = 0;

    for (int i = 0; i < n; i++) {
        int page = referenceString[i];
        int pageFound = 0;

        // Check if the page is already in memory
        for (int j = 0; j < MAX_FRAMES; j++) {
            if (memoryFrames[j] == page) {
                pageFound = 1;
                break;
            }
        }

        if (!pageFound) {
            // Page fault: page is not in memory
            pageFaults++;

            if (frameIndex < MAX_FRAMES) {
                // Memory is not full, add the page to an empty frame
                memoryFrames[frameIndex] = page;
                frameIndex++;
            } else {
                // Memory is full, replace the oldest page (FIFO)
                for (int j = 0; j < MAX_FRAMES - 1; j++) {
                    memoryFrames[j] = memoryFrames[j + 1];
                }
                memoryFrames[MAX_FRAMES - 1] = page;
            }
        }

        // Print the current state of memory frames
        printf("Page %d: [", page);
        for (int j = 0; j < MAX_FRAMES; j++) {
            printf("%d", memoryFrames[j]);
            if (j < MAX_FRAMES - 1) {
                printf(", ");
            }
        }
        printf("]\n");
    }

    printf("Total page faults: %d\n", pageFaults);

    return 0;
}
