#include <stdio.h>

#define BUFFER_SIZE 256

int main() {
  FILE *fp;
  char buffer[BUFFER_SIZE];

  // Open the file for reading in binary mode ("rb")
  fp = fopen("sample.txt", "rb");

  // Check if the file was opened successfully
  if (fp == NULL) {
    perror("Error opening file");
    return 1;
  }

  // Read data from the file into the buffer
  size_t elements_read = fread(buffer, sizeof(char), BUFFER_SIZE, fp);

  // Check for errors or end-of-file (EOF)
  if (ferror(fp) != 0) {
    perror("Error reading file");
    fclose(fp);
    return 1;
  }

  // Print the contents of the buffer (up to the number of elements read)
  printf("Contents of the file:\n");
  printf("%.*s\n", (int)elements_read, buffer);

  // Close the file
  fclose(fp);

  return 0;
}
