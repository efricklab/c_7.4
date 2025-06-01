#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *file;
    char line[100];

    // Open the file for reading
    file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    printf("Reading data from file:\n\n");

    while (fgets(line, sizeof(line), file)) {
        // Remove newline character
        line[strcspn(line, "\n")] = '\0';

        // Parse the line using strtok
        char *name = strtok(line, ",");
        char *ageStr = strtok(NULL, ",");

        if (name && ageStr) {
            printf("Name: %s, Age: %s\n", name, ageStr);
        }
    }

    fclose(file);
    return 0;
}
