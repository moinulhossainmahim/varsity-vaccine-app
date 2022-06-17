#include<stdio.h>

int main() {
  int wordCounter = 0;
  FILE *fptr;
  char fName[20];
  char str;
  printf("Enter File Name: ");
  scanf("%s", fName);
  fptr = fopen(fName, "r");
  str=fgetc(fptr);
  while(str != EOF) {
    if(str == ' ' || str == '\n' || str == '\0' || str == '\t') {
      wordCounter++;
    }
    str=fgetc(fptr);
  }
  fclose(fptr);
  printf("Number of Words in this file is: %d\n", wordCounter);
  return 0;
}
