// or Q.2. Write the simulation program to implement demand paging and show the page scheduling
// and total number of page faults for the following given page reference string. Give input n =3 as
// the number of memory frames.
// Reference String : 12,15,12,18,6,8,11,12,19,12,6,8,12,15,19,8
// Implement OPT

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_FRAMES 3

void initialize(int frames[], int n) {
    for (int i = 0; i < n; i++) {
        frames[i] = -1;
    }
}

bool isPageInMemory(int page, int frames[], int n) {
    for (int i = 0; i < n; i++) {
        if (frames[i] == page) {
            return true;
        }
    }
    return false;
}

int findOptimalPage(int pageReference[], int frames[], int n, int currentPageIndex) {
    int farthestIndex = -1;
    int farthestPage = -1;
    
    for (int i = 0; i < n; i++) {
        int page = frames[i];
        bool isFuture = false;
        
        for (int j = currentPageIndex; j < MAX_FRAMES; j++) {
            if (page == pageReference[j]) {
                isFuture = true;
                break;
            }
        }
        
        if (!isFuture) {
            return i;
        }
    }
    
    return (farthestIndex == -1) ? 0 : farthestIndex;
}

int main() {
    int pageReference[] = {12, 15, 12, 18, 6, 8, 11, 12, 19, 12, 6, 8, 12, 15, 19, 8};
    int frames[MAX_FRAMES];
    int pageFaults = 0;

    initialize(frames, MAX_FRAMES);

    for (int i = 0; i < MAX_FRAMES; i++) {
        printf("Frame %d: ", i);
        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] != -1) {
                printf("%d ", frames[j]);
            }
        }
        printf("\n");
    }

    for (int i = 0; i < MAX_FRAMES; i++) {
        printf("-------");
    }
    printf("\n");

    for (int i = 0; i < MAX_FRAMES; i++) {
        printf("  Page ");
    }
    printf("\n");

    for (int i = 0; i < MAX_FRAMES; i++) {
        printf("-------");
    }
    printf("\n");

    for (int i = 0; i < MAX_FRAMES; i++) {
        printf("       ");
    }
    printf("\n");

    int currentPageIndex = MAX_FRAMES;

    for (int i = MAX_FRAMES; i < sizeof(pageReference) / sizeof(pageReference[0]); i++) {
        int currentPage = pageReference[i];

        if (!isPageInMemory(currentPage, frames, MAX_FRAMES)) {
            int pageToReplace = findOptimalPage(pageReference, frames, MAX_FRAMES, i);
            frames[pageToReplace] = currentPage;
            pageFaults++;
        }

        for (int j = 0; j < MAX_FRAMES; j++) {
            printf("  %d    ", frames[j]);
        }
        printf("\n");

        currentPageIndex++;

        if (i < sizeof(pageReference) / sizeof(pageReference[0]) - 1) {
            for (int j = 0; j < MAX_FRAMES; j++) {
                if (frames[j] == pageReference[currentPageIndex]) {
                    frames[j] = -1;
                }
            }
        }
    }

    printf("Total Page Faults: %d\n", pageFaults);

    return 0;
}


