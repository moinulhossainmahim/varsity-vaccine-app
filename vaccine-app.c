#include<stdio.h>
#include<time.h>

typedef struct CurrentDate {
  int day;
  int month;
  int year;
}currentDate;
typedef struct User {
  int id;
  char name[20];
  int age;
  char gender[10];
  currentDate date;
}user;

currentDate getCurrentDate() {
  currentDate date;
  time_t now;
  time(&now);
  struct tm *local = localtime(&now);
  date.day   = local->tm_mday;
  date.month = local->tm_mon + 1;
  date.year  = local->tm_year + 1900; 
  return date;
}

user userInfo() {
  user singleUser;
  printf("Enter Your Name: ");
  scanf(" %[^\n]%*c", singleUser.name);
  printf("Enter Your Age: ");
  scanf("%d", &singleUser.age);
  printf("Enter Your Gender: ");
  scanf(" %[^\n]%*c", singleUser.gender);
  singleUser.date = getCurrentDate();
  return singleUser;
}

int main() {
  user userList[100];
  int i;
  char isInterested;
  printf("Are You interested to get vaccine? [Y/N] : ");
  scanf("%c", &isInterested);

  if(isInterested == 'Y' || isInterested == 'y') {
    char isFirstDoseDone;
    printf("Did you get first dose? [Y/N] : ");
    scanf(" %c", &isFirstDoseDone);
    if(isFirstDoseDone == 'Y' || isFirstDoseDone == 'y') {
      printf("Let him know next dose date");
    } else {
      for(i=0; i<1; i++) {
       userList[i] = userInfo();
      }
      for(i=0; i<1; i++) {
        printf("Name: %s \nAge: %d \nGender: %s \nDate: %02d-%02d-%02d", userList[i].name, userList[i].age, userList[i].gender, userList[i].date.day, userList[i].date.month, userList[i].date.year);
      }
    }
  } else if(isInterested == 'N' || isInterested == 'n') {
    printf("Take vaccine is must.You should take it as soon as possible.");
    return 0;
  } else {
    printf("Please input valid info");
  }
  return 0;
}
