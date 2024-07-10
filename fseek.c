#include <stdio.h>

int main() {
  FILE *fp;
  char buffer[20];

  // Open the file "sample.txt" for reading and writing ("r+").
  // You can replace "sample.txt" with your desired filename.
  fp = fopen("sample.txt", "r+");
  if (fp == NULL) {
    perror("Error opening file");
    return 1;
  }

  // Move the file pointer to the 5th byte from the beginning (SEEK_SET).
  int seek_result = fseek(fp, 5, SEEK_SET);
  if (seek_result != 0) {
    perror("Error seeking in the file");
    fclose(fp);
    return 1;
  }

  // Read 10 characters from the current position.
  size_t elements_read = fread(buffer, sizeof(char), 10, fp);

  // Check for errors or EOF.
  if (ferror(fp) != 0) {
    perror("Error reading file");
    fclose(fp);
    return 1;
  }

  // Print the read characters.
  printf("Read %zu characters: %.*s\n", elements_read, (int)elements_read, buffer);

  // Close the file.
  fclose(fp);

  return 0;
}
