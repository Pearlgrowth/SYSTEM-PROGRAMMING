#include <stdio.h>

int main() {
    FILE *fp;
    fp = fopen("sample.txt", "wt");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }
    fprintf(fp, "This is a test file\n");
    fclose(fp);
    printf("File 'sample.txt' created successfully.\n");
    return 0;
}
