// Q.2 Write the simulation program to implement demand paging and show the page scheduling
// and total number of page faults for the following given page reference string. Give input n=3 as
// the number of memory frames.
// Reference String : 12,15,12,18,6,8,11,12,19,12,6,8,12,15,19,8
// Implement OPT

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

// Function to find the page with the longest time until the next reference
int findOptimalReplacement(int* memory, int* page_references, int num_frames, int current_index, int num_references) {
    int page_to_replace = -1;
    int farthest_distance = -1;

    for (int i = 0; i < num_frames; i++) {
        int page = memory[i];
        int distance = num_references;

        for (int j = current_index + 1; j < num_references; j++) {
            if (page_references[j] == page) {
                distance = j - current_index;
                break;
            }
        }

        if (distance > farthest_distance) {
            farthest_distance = distance;
            page_to_replace = i;
        }
    }

    return page_to_replace;
}

int main() {
    char reference_string[] = "12,15,12,18,6,8,11,12,19,12,6,8,12,15,19,8";
    int num_frames = 3;
    int page_references[100];
    int memory[3] = {-1, -1, -1};
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

            if (memory[current_index] == -1) {
                // If there are empty frames, fill them
                memory[current_index] = page_references[i];
            } else {
                // Otherwise, find the page with the longest time until the next reference and replace it
                int page_to_replace = findOptimalReplacement(memory, page_references, num_frames, i, num_references);
                memory[page_to_replace] = page_references[i];
            }

            current_index = (current_index + 1) % num_frames;

            printf("Page %d -> Frames: %d, %d, %d\n", page_references[i], memory[0], memory[1], memory[2]);
        }
    }

    printf("Total Page Faults: %d\n", page_faults);

    return 0;
}
