#include<stdio.h>

typedef struct Teacher {
  char name[30];
  int age;
  char gender[20];
  char department[30];
}teacher;


void printTeacherInfo(teacher *t) {
  printf("Name: %s", t->name);
  printf("\nAge: %d", t->age);
  printf("\nGender: %s", t->gender);
  printf("\nDepartment: %s\n", t->department);
}


int main() {
  teacher t;
  teacher *ptr = &t;
  printf("Enter Teacher Name: ");
  scanf(" %[^\n]%*c", t.name);
  printf("Enter Teacher Gender: ");
  scanf(" %[^\n]%*c", t.gender);
  printf("Enter Department Name: ");
  scanf(" %[^\n]%*c", t.department);
  printf("Enter Age: ");
  scanf("%d", &t.age);
  printTeacherInfo(ptr);
  return 0;
}

