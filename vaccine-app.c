#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

// Structures
typedef struct CurrentDate {
  int day;
  int month;
  int year;
}currentDate;

typedef struct User {
  int id;
  char name[30];
  int age;
  char gender[10];
  char vaccineCenter[50];
  currentDate date;
}user;

// Global UserList
user userList[100];

// Prototype for functions
currentDate getCurrentDate();
user takeUserInfo();
int createRandomID(int limit);
void handleVaccinated();
void printWarning();
void printVaccineCard(int i);
void PrintNextDoseInfo(user users[], int id);
void handleNewRegistration(user users[], int i);
const char *createVaccineCenter();

int main() {
  int i = 0;
  while(i<50) {
    char isInterested;
    printf("Are You Interested To Get Vaccine? [Y/N]: ");
    scanf(" %c", &isInterested);

    if (isInterested == 'Y' || isInterested == 'y') {
      char isVaccinated;
      printf("Are You Vaccinated? [Y/N]: ");
      scanf(" %c", &isVaccinated);

      if(isVaccinated == 'Y' || isVaccinated == 'y') {
        handleVaccinated();
      } else {
        handleNewRegistration(userList, i);
      }

    } else if (isInterested == 'N' || isInterested == 'n') {
      printWarning();
      return 0;
    } else {
      printf("Please Give Valid Info\nThank You!\n");
    }
    i++;
  }
  return 0;
}


// Utility Functions
int createRandomID(int limit) {
  srand(time(0));
  int randomId = rand() % limit;
  return randomId;
}

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

user takeUserInfo() {
  user singleUser;
  printf("Enter Your Name: ");
  scanf(" %[^\n]%*c", singleUser.name);
  printf("Enter Your Age: ");
  scanf("%d", &singleUser.age);
  printf("Enter Your Gender: ");
  scanf(" %[^\n]%*c", singleUser.gender);
  strcpy(singleUser.vaccineCenter, createVaccineCenter());
  singleUser.id = createRandomID(500);
  singleUser.date = getCurrentDate();
  return singleUser;
}

void handleVaccinated() {
  int num;
  printf("PRESS 1 IF YOU HAVE COMPLETED FIRST DOSE\n");
  printf("PRESS 2 IF YOU HAVE COMPLETED ALL DOSE\n");
  scanf("%d", &num);
  int firstDoseid;
  switch(num) {
    case 1:
      printf("Please Give Your First Dose Registration ID\n");
      scanf("%d", &firstDoseid);
      PrintNextDoseInfo(userList, firstDoseid);
      break;
    case 2:
      printf("Thank You For Taking Vaccine\n");
      return;
    default:
      printf("Please Give Valid Info\nThank You\n");
  }
}

void PrintNextDoseInfo(user users[100], int id) {
  int i=0;
  int isUserExists = 0;
  for(i=0; i<100; i++) {
    if(users[i].id == id) {
      printf("Hi %s!", users[i].name);
      printf("\nSecond Dose Date: %02d-%02d-%02d",  users[i].date.day, users[i].date.month+1, users[i].date.year);
      printf("\nVaccination Center: %s\n", users[i].vaccineCenter);
      isUserExists = 1;
      return;
    }
  }
  if(!isUserExists) {
    printf("There Is No User With This ID\n");
  }
}

void handleNewRegistration(user users[], int i) {
  printf("Please Give Your Info For New Registration\n");
  userList[i] = takeUserInfo();
  if (userList[i].gender[0] == 'F' || userList[i].gender[0] == 'f') {
    char isPregnant;
    printf("Are You Pregnant? [Y/N]: ");
    scanf(" %c", &isPregnant);
    if(isPregnant == 'Y' || isPregnant == 'y') {
      printf("Sorry Your'e Not Eligible To Take Vaccine\n");
      return;
    }
  }
  printVaccineCard(i);
}

void printWarning() {
  printf("\033[0;33m");
  printf("Taking vaccine is must.You should take it as soon as possible.\n");
}

const char *createVaccineCenter() {
  char hospitals[10][50] = {
    "Kurmitola General Hospital",
    "DNCC Hospital",
    "Kuwait Bangladesh Friendship Hospital",
    "UTPS Hospital",
    "Dhaka Medical College",
    "Dhaka Dental College",
    "Dhaka Infectious Diseases Hospital",
    "Uttara Crescent Hospital",
    "Combined Military Hospital(CMH)",
    "Bangladesh Shishu Hospital and Institute"
  };
  int hospitalIndex = createRandomID(10);
  char *hospitalPtr = hospitals[hospitalIndex];
  return hospitalPtr;
}

void printVaccineCard(int i) {
  printf("✅ Thank you for completing First Dose Vaccine Registration\n");
  printf("\033[0;33m");
  printf("Please Remember your ID\n");
  printf("\033[0;32m");
  printf("Here is Your Registration Info");
  printf("\nID: %d", userList[i].id);
  printf("\nName: %s", userList[i].name);
  printf("\nAge: %d", userList[i].age);
  printf("\nGender: %s", userList[i].gender);
  printf("\nDate: %02d-%02d-%02d", userList[i].date.day, userList[i].date.month, userList[i].date.year);
  printf("\nVaccination Center: %s\n", userList[i].vaccineCenter);
  printf("\033[0m");
}
