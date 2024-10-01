// Q.2 Write the simulation program to implement demand paging and show the page scheduling
// and total number of page faults for the following given page reference string. Give input n as the
// number of memory frames.
// Reference String: 0, 2, 1, 6, 4, 0, 1, 0, 3, 1, 2, 1
// Implement FIFO 
//output:
// Enter the number of memory frames: 3
// Enter the number of pages in the reference string: 12
// Enter the page reference string: 0 2 1 6 4 0 1 0 3 1 2 1
// 
// Page Scheduling using FIFO:
// Page Reference: 0
// 0 -1 -1 
// Page Reference: 2
// 0 2 -1 
// Page Reference: 1
// 0 2 1 
// Page Reference: 6
// 6 2 1 
// Page Reference: 4
// 6 4 1 
// Page Reference: 0
// 6 4 0 
// Page Reference: 1
// 1 4 0 
// Page Reference: 0
// Page 0 is already in memory.
// Page Reference: 3
// 1 3 0 
// Page Reference: 1
// Page 1 is already in memory.
// Page Reference: 2
// 1 3 2 
// Page Reference: 1
// Page 1 is already in memory.
// 
// Total Page Faults: 9


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

// Function to display the content of memory frames
void displayMemory(int* memory, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", memory[i]);
    }
    printf("\n");
}

int main() {
    int n; // Number of memory frames
    printf("Enter the number of memory frames: ");
    scanf("%d", &n);

    int* memory = (int*)malloc(n * sizeof(int)); // Memory frames
    int* pageReferenceString; // Page reference string

    printf("Enter the number of pages in the reference string: ");
    int numPages;
    scanf("%d", &numPages);

    pageReferenceString = (int*)malloc(numPages * sizeof(int));

    printf("Enter the page reference string: ");
    for (int i = 0; i < numPages; i++) {
        scanf("%d", &pageReferenceString[i]);
    }

    int pageFaults = 0; // Counter for page faults
    int index = 0; // Index for the memory frame replacement (FIFO)

    for (int i = 0; i < n; i++) {
        memory[i] = -1; // Initialize memory frames to -1
    }

    printf("\nPage Scheduling using FIFO:\n");

    for (int i = 0; i < numPages; i++) {
        printf("Page Reference: %d\n", pageReferenceString[i]);

        if (!isPageInMemory(pageReferenceString[i], memory, n)) {
            // Page fault
            pageFaults++;

            // Replace the oldest page with the new page (FIFO)
            memory[index] = pageReferenceString[i];
            index = (index + 1) % n; // Circular index

            displayMemory(memory, n);
        } else {
            // Page hit
            printf("Page %d is already in memory.\n", pageReferenceString[i]);
        }
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);

    free(memory);
    free(pageReferenceString);

    return 0;
}
