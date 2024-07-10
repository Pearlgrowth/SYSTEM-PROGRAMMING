#include <stdio.h>

#define BUFFER_SIZE 10

int main() {
  FILE *fp;
  int data_to_write[BUFFER_SIZE] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

  // Open the file "sample.txt" for writing in binary mode ("wb").
  fp = fopen("sample.txt", "wb");
  if (fp == NULL) {
    perror("Error opening file");
    return 1;
  }

  // Write data to the file using fwrite.
  size_t elements_written = fwrite(data_to_write, sizeof(int), BUFFER_SIZE, fp);

  // Check for errors during writing.
  if (ferror(fp) != 0) {
    perror("Error writing to file");
    fclose(fp);
    return 1;
  }

  printf("Wrote %zu elements to the file.\n", elements_written);

  // Close the file.
  fclose(fp);

  return 0;
}
