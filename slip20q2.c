// Q.2 Write the simulation program to implement demand paging and show the page scheduling
// and total number of page faults for the following given page reference string. Give input n=3 as
// the number of memory frames.
// Reference String : 7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2
// i. Implement LRU

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a page is in memory
int isPageInMemory(int page, int* memory, int num_frames) {
    for (int i = 0; i < num_frames; i++) {
        if (memory[i] == page) {
            return 1;
        }
    }
    return 0;
}

// Function to find the index of the least recently used page in memory
int findLRUPage(int* memory, int* page_references, int num_frames, int current_index) {
    int page_to_replace = -1;
    int min_index = current_index;

    for (int i = 0; i < num_frames; i++) {
        int page = memory[i];
        for (int j = current_index - 1; j >= 0; j--) {
            if (page_references[j] == page) {
                if (j < min_index) {
                    min_index = j;
                    page_to_replace = i;
                }
                break;
            }
        }
    }

    return page_to_replace;
}

int main() {
    char reference_string[] = "7,0,1,2,0,3,0,4,2,3,0,3,2";
    int num_frames = 3;
    int page_references[100];
    int memory[3];
    int page_faults = 0;
    int current_index = 0;
    int num_references = 0;

    char* token = strtok(reference_string, ",");
    while (token != NULL) {
        page_references[num_references] = atoi(token);
        num_references++;
        token = strtok(NULL, ",");
    }

    for (int i = 0; i < num_references; i++) {
        if (!isPageInMemory(page_references[i], memory, num_frames)) {
            // Page fault
            page_faults++;

            if (i < num_frames) {
                // If there are empty frames, fill them
                memory[i] = page_references[i];
            } else {
                // Otherwise, find the least recently used page and replace it
                int page_to_replace = findLRUPage(memory, page_references, num_frames, i);
                memory[page_to_replace] = page_references[i];
            }

            printf("Page %d -> Frames: %d, %d, %d\n", page_references[i], memory[0], memory[1], memory[2]);
        }
    }

    printf("Total Page Faults: %d\n", page_faults);

    return 0;
}
