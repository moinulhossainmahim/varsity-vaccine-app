#include<stdio.h>

void printOdd() {
  int n, i=0;
  printf("Enter the amount of numbers: ");
  scanf("%d", &n);
  int numbers[n];
  printf("Enter %d numbers: ", n);
  for(i=0; i<n; i++) {
    scanf("%d", &numbers[i]);
  }
  printf("Odd Values from these numbers is: ");
  for(i=0; i<n; i++) {
    if(numbers[i]%2 != 0) {
      printf("%d ", numbers[i]);
    }
  }
}

int main() {
  printOdd();
  return 0;
}
