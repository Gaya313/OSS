// Q.2 Write the simulation program to implement demand paging and show the page scheduling
// and total number of page faults for the following given page reference string. Give input n as the
// number of memory frames.
// Reference String :7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2
// Implement LRU 

#include <stdio.h>

#define MAX_PAGES 100

// Function to check if a page is in memory
int isPageInMemory(int page, int* memory, int n) {
    for (int i = 0; i < n; i++) {
        if (memory[i] == page) {
            return 1;
        }
    }
    return 0;
}

// Function to find the index of the least recently used page
int findLRUIndex(int* memory, int* pageUsage, int n) {
    int minIndex = 0;
    int minUsage = pageUsage[0];

    for (int i = 1; i < n; i++) {
        if (pageUsage[i] < minUsage) {
            minIndex = i;
            minUsage = pageUsage[i];
        }
    }

    return minIndex;
}

int main() {
    int n = 3; // Number of memory frames
    int pageReferenceString[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int numPages = sizeof(pageReferenceString) / sizeof(pageReferenceString[0]);
    int memory[n];
    int pageUsage[n];
    int pageFaults = 0;

    for (int i = 0; i < n; i++) {
        memory[i] = -1;  // Initialize memory frames to -1
        pageUsage[i] = 0; // Initialize page usage counters to 0
    }

    printf("Page Scheduling using LRU:\n");

    for (int i = 0; i < numPages; i++) {
        int currentPage = pageReferenceString[i];

        if (!isPageInMemory(currentPage, memory, n)) {
            // Page fault
            pageFaults++;

            // Find the index of the least recently used page
            int lruIndex = findLRUIndex(memory, pageUsage, n);

            // Replace the least recently used page with the new page
            memory[lruIndex] = currentPage;

            // Update page usage for the new page
            pageUsage[lruIndex] = i;

            // Display memory frames
            for (int j = 0; j < n; j++) {
                printf("%d ", memory[j]);
            }
            printf("\n");
        } else {
            // Update page usage for the existing page
            for (int j = 0; j < n; j++) {
                if (memory[j] == currentPage) {
                    pageUsage[j] = i;
                    break;
                }
            }
        }
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);

    return 0;
}

