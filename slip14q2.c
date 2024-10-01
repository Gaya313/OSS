// Q.2 Write the simulation program to implement demand paging and show the page scheduling
// and total number of page faults for the following given page reference string. Give input n =3 as
// the number of memory frames.
// Reference String : 0, 2, 1, 6, 4, 0, 1, 0, 3, 1, 2, 1
// Implement FIFO 

#include <stdio.h>
#include <stdlib.h>

// Function to check if a page is in memory
int isPageInMemory(int page, int* memory, int n) {
    for (int i = 0; i < n; i++) {
        if (memory[i] == page) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int n = 3; // Number of memory frames
    int pageReferenceString[] = {0, 2, 1, 6, 4, 0, 1, 0, 3, 1, 2, 1};
    int numPages = sizeof(pageReferenceString) / sizeof(pageReferenceString[0]);
    int memory[n];
    int pageFaults = 0;
    int currentIndex = 0; // Index for the memory frame replacement (FIFO)

    for (int i = 0; i < n; i++) {
        memory[i] = -1; // Initialize memory frames to -1
    }

    printf("Page Scheduling using FIFO:\n");

    for (int i = 0; i < numPages; i++) {
        int currentPage = pageReferenceString[i];

        if (!isPageInMemory(currentPage, memory, n)) {
            // Page fault
            pageFaults++;

            // Replace the oldest page with the new page (FIFO)
            memory[currentIndex] = currentPage;
            currentIndex = (currentIndex + 1) % n; // Circular index

            // Display memory frames
            for (int j = 0; j < n; j++) {
                printf("%d ", memory[j]);
            }
            printf("\n");
        }
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);

    return 0;
}
