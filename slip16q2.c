// Q.2 Write the simulation program to implement demand paging and show the page scheduling
// and total number of page faults for the following given page reference string. Give input n =3 as
// the number of memory frames.
// Reference String : 12,15,12,18,6,8,11,12,19,12,6,8,12,15,19,8
// Implement OPT

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

// Function to check if a page is in memory
bool isPageInMemory(int page, int* memory, int n) {
    for (int i = 0; i < n; i++) {
        if (memory[i] == page) {
            return true;
        }
    }
    return false;
}

// Function to find the page to be replaced using the Optimal algorithm
int findPageToReplace(int* memory, int* pageReferenceString, int n, int currentIndex) {
    int pageToReplace = -1;
    int farthestDistance = -1;

    for (int i = 0; i < n; i++) {
        int page = memory[i];
        int distance = INT_MAX;

        for (int j = currentIndex; j < n; j++) {
            if (pageReferenceString[j] == page) {
                distance = j;
                break;
            }
        }

        if (distance > farthestDistance) {
            farthestDistance = distance;
            pageToReplace = i;
        }
    }

    return pageToReplace;
}

int main() {
    int n = 3; // Number of memory frames
    int pageReferenceString[] = {12, 15, 12, 18, 6, 8, 11, 12, 19, 12, 6, 8, 12, 15, 19, 8};
    int numPages = sizeof(pageReferenceString) / sizeof(pageReferenceString[0]);
    int memory[n];
    int pageFaults = 0;

    for (int i = 0; i < n; i++) {
        memory[i] = -1; // Initialize memory frames to -1
    }

    printf("Page Scheduling using OPT:\n");

    for (int i = 0; i < numPages; i++) {
        int currentPage = pageReferenceString[i];

        if (!isPageInMemory(currentPage, memory, n)) {
            // Page fault
            pageFaults++;

            // Find the page to be replaced using the Optimal algorithm
            int pageToReplace = findPageToReplace(memory, pageReferenceString, n, i);

            // Replace the page with the new page
            memory[pageToReplace] = currentPage;

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
