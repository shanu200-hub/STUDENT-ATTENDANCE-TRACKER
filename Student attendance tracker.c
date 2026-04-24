#include <stdio.h>
#include <string.h>

#define MAX 100

// Structure for student
typedef struct {
    int id;
    char name[50];
    int attendance;  // number of days present
} Student;

Student students[MAX];
int count = 0;

// Add student
void addStudent() {
    if (count >= MAX) {
        printf("Student limit reached!\n");
        return;
    }

    printf("Enter ID: ");
    scanf("%d", &students[count].id);

    printf("Enter Name: ");
    scanf("%s", students[count].name);

    students[count].attendance = 0;
    count++;

    printf("Student added successfully!\n");
}

// Mark attendance
void markAttendance() {
    int id, found = 0;
    printf("Enter student ID: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            students[i].attendance++;
            printf("Attendance marked for %s\n", students[i].name);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student not found!\n");
    }
}

// Display all students
void displayStudents() {
    if (count == 0) {
        printf("No students available.\n");
        return;
    }

    printf("\nID\tName\tAttendance\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%d\n",
               students[i].id,
               students[i].name,
               students[i].attendance);
    }
}

// Search student
void searchStudent() {
    int id, found = 0;
    printf("Enter ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("Found: %s, Attendance: %d\n",
                   students[i].name,
                   students[i].attendance);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student not found!\n");
    }
}

// Main menu
int main() {
    int choice;

    while (1) {
        printf("\n--- Student Attendance Tracker ---\n");
        printf("1. Add Student\n");
        printf("2. Mark Attendance\n");
        printf("3. Display Students\n");
        printf("4. Search Student\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: markAttendance(); break;
            case 3: displayStudents(); break;
            case 4: searchStudent(); break;
            case 5: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}