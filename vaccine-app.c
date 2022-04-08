#include<stdio.h>

int main() {
  char isInterested;
  printf("Are You interested to get vaccine?Y/N:");
  scanf("%c", &isInterested);

  if(isInterested == 'Y' || isInterested == 'y') {
    char isGetFirstDose;
    printf("Did you get first dose?Y/N:");
    scanf("%c\n", &isGetFirstDose);
    if(isGetFirstDose == 'Y' || isGetFirstDose == 'y') {
      printf("Let him know next dose date");
    } else {
      printf("Take his all info for registration");
    }

  } else if(isInterested == 'N' || isInterested == 'n') {
    printf("Take vaccine is a must. You should get it as soon as possible.");
    return 0;
  } else {
    printf("Please input valid info");
  }
  return 0;
}
