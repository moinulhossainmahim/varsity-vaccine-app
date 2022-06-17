#include<stdio.h>

int main() {
  char str[50];
  int stringLengthCounter = 0;
  char *ptr = str;
  printf("Enter a string of 50 sizes: " );
  scanf(" %[^\n]%*c", str);
  while(*ptr != '\0') {
    stringLengthCounter++;
    ptr++;
  }
  printf("Size of this string is: %d\n", stringLengthCounter);
  return 0;
}

