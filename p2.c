#include <stdio.h>
#include <string.h>

void createFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error creating file.\n");
        return;
    }
    printf("File '%s' created successfully.\n", filename);
    fclose(file);
}

void writeFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    printf("Enter text to write to the file (type 'END' to stop):\n");
    char buffer[256];
    while (1) {
        fgets(buffer, sizeof(buffer), stdin);
        if (strncmp(buffer, "END", 3) == 0)
            break;
        fputs(buffer, file);
    }

    printf("Data written to file successfully.\n");
    fclose(file);
}

void appendFile(const char *filename) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        printf("Error opening file for appending.\n");
        return;
    }

    printf("Enter text to append to the file (type 'END' to stop):\n");
    char buffer[256];
    while (1) {
        fgets(buffer, sizeof(buffer), stdin);
        if (strncmp(buffer, "END", 3) == 0)
            break;
        fputs(buffer, file);
    }

    printf("Data appended to file successfully.\n");
    fclose(file);
}

void readFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    printf("Contents of the file '%s':\n", filename);
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    fclose(file);
}

int main() {
    char filename[100];
    int choice;

    printf("Enter the file name: ");
    scanf("%s", filename);
    getchar(); // To consume the newline character left by scanf

    do {
        printf("\nMenu:\n");
        printf("1. Create a file\n");
        printf("2. Write to the file\n");
        printf("3. Append to the file\n");
        printf("4. Read the file\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character left by scanf

        switch (choice) {
            case 1:
                createFile(filename);
                break;
            case 2:
                writeFile(filename);
                break;
            case 3:
                appendFile(filename);
                break;
            case 4:
                readFile(filename);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
