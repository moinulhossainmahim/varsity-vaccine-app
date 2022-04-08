#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Structures
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

// Global UserList
user userList[100];

// Prototype Initializing for functions
int createRandomID();
currentDate getCurrentDate();
user takeUserInfo();
void handleVaccinated();
void printWarning();
void PrintNextDoseDate(user users[], int id);
void handleNewRegistration(user users[], int i);

int main() {
  int i = 0;
  while(i<50) {
    char isInterested;
    printf("ARE YOU INTERESTED TO GET VACCINE? [Y/N]: ");

    scanf(" %c", &isInterested);

    if (isInterested == 'Y' || isInterested == 'y') {
      char isVaccinated;
      printf("ARE YOU VACCINATED? [Y/N]: ");
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
      printf("PLEASE GIVE VALID INFO\nTHANK YOU!\n");
    }
    i++;
  }
  return 0;
}


// Utility Functions
int createRandomID() {
  srand(time(0));
  int randomId = rand() % 500;
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
  singleUser.id = createRandomID();
  singleUser.date = getCurrentDate();
  return singleUser;
}

void handleVaccinated() {
  int num;
    printf("PRESS 1 IF YOU HAVE COMPLETED FIRST DOSE\n");
    printf("PRESS 2 IF YOU HAVE COMPLETED ALL VACCINE\n");
    scanf("%d", &num);
    int firstDoseid;
    switch(num) {
      case 1:
        printf("PLEASE GIVE YOUR FIRST DOSE REGISTRATION ID\n");
        scanf("%d", &firstDoseid);
        PrintNextDoseDate(userList, firstDoseid);
        break;
      case 2:
        printf("THANK YOU FOR TAKING VACCINE!\n");
        return;
      default:
        printf("PLEASE GIVE VALID INFO.THANK YOU\n");
    }
}

void PrintNextDoseDate(user users[100], int id) {
  int i=0;
  int isUserExists = 0;
  for(i=0; i<100; i++) {
    if(users[i].id == id) {
      printf("Hi %s! YOUR SECOND VACCINE DOSE DATE WILL BE - %d-%d-%d\n", users[i].name, users[i].date.day, users[i].date.month+1, users[i].date.year);
      isUserExists = 1;
      return;
    }
  }
  if(!isUserExists) {
    printf("THERE IS NO USER WITH THIS ID\n");
  }
}

void handleNewRegistration(user users[], int i) {
  printf("PLEASE GIVE YOUR INFO FOR NEW REGISTRATION\n");
  userList[i] = takeUserInfo();
  if (userList[i].gender[0] == 'F' || userList[i].gender[0] == 'f') {
    char isPregnant;
    printf("ARE YOU PREGNANT? [Y/N]: ");
    scanf(" %c", &isPregnant);
    if(isPregnant == 'Y' || isPregnant == 'y') {
      printf("SORRY YOU ARE NOT ELIGIBLE TO TAKE VACCINE\n");
      return;
    }
  }
  printf("✅ Thank you for completing First Dose Vaccine Registration\n");
  printf("\033[0;33m");
  printf("Please Remember your ID\n");
  printf("\033[0;32m");
  printf("Here is Your Registration Info");
  printf("\nID: %d \nName: %s \nAge: %d \nGender: %s \nDate: %02d-%02d-%02d\n", userList[i].id, userList[i].name, userList[i].age, userList[i].gender, userList[i].date.day, userList[i].date.month, userList[i].date.year);
  printf("\033[0m");
}

void printWarning() {
  printf("\033[0;33m");
  printf("Taking vaccine is must.You should take it as soon as possible.\n");
}