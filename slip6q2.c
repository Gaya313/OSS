// Q.2 Write the simulation program to implement demand paging and show the page scheduling
// and total number of page faults for the following given page reference string. Give input n as the
// number of memory frames.
// Reference String :3, 4, 5, 6, 3, 4, 7, 3, 4, 5, 6, 7, 2, 4, 6
// Implement FIFO 

#include <stdio.h>
#include <stdbool.h>

// Function to check if a page is present in memory
bool isPagePresent(int memoryFrames[], int n, int page) {
    for (int i = 0; i < n; i++) {
        if (memoryFrames[i] == page) {
            return true;
        }
    }
    return false;
}

int main() {
    int pageReferenceString[] = {3, 4, 5, 6, 3, 4, 7, 3, 4, 5, 6, 7, 2, 4, 6};
    int n; // Number of memory frames

    printf("Enter the number of memory frames: ");
    scanf("%d", &n);

    int memoryFrames[n];
    int pageQueue[n];
    int pageFaults = 0;
    int queueIndex = 0;

    for (int i = 0; i < n; i++) {
        memoryFrames[i] = -1;
        pageQueue[i] = -1;
    }

    for (int i = 0; i < sizeof(pageReferenceString) / sizeof(pageReferenceString[0]); i++) {
        int page = pageReferenceString[i];

        if (!isPagePresent(memoryFrames, n, page)) {
            pageFaults++;

            int victimPage = pageQueue[queueIndex];
            for (int j = 0; j < n; j++) {
                if (memoryFrames[j] == victimPage) {
                    memoryFrames[j] = page;
                    break;
                }
            }

            pageQueue[queueIndex] = page;
            queueIndex = (queueIndex + 1) % n;
        }

        printf("Page Reference: %d\n", page);
        printf("Memory Frames: ");
        for (int j = 0; j < n; j++) {
            printf("%d ", memoryFrames[j]);
        }
        printf("\nPage Queue: ");
        for (int j = 0; j < n; j++) {
            printf("%d ", pageQueue[j]);
        }
        printf("\n\n");
    }

    printf("Total Page Faults: %d\n", pageFaults);

    return 0;
}
