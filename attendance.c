#include <stdio.h>
#include <string.h>

#define MAX 100

// Structure to store student data
struct Student {
    int id;
    char name[50];
    int totalDays;
    int presentDays;
};

// Function declarations
void addStudent(struct Student students[], int *count);
void markAttendance(struct Student students[], int count);
void viewReport(struct Student students[], int count);

int main() {
    struct Student students[MAX];
    int count = 0;
    int choice;

    while (1) {
        printf("\n=== Attendance Management System ===\n");
        printf("1. Add Student\n");
        printf("2. Mark Attendance\n");
        printf("3. View Attendance Report\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                markAttendance(students, count);
                break;
            case 3:
                viewReport(students, count);
                break;
            case 4:
                printf("\nExiting program. Thank you!\n");
                return 0;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
}

// Function to add a student
void addStudent(struct Student students[], int *count) {
    if (*count >= MAX) {
        printf("\nCannot add more students.\n");
        return;
    }

    printf("\nEnter student ID: ");
    scanf("%d", &students[*count].id);
    printf("Enter student name: ");
    getchar(); // clear newline from buffer
    fgets(students[*count].name, 50, stdin);
    students[*count].name[strcspn(students[*count].name, "\n")] = '\0'; // remove newline

    students[*count].totalDays = 0;
    students[*count].presentDays = 0;

    (*count)++;
    printf("\nStudent added successfully!\n");
}

// Function to mark attendance
void markAttendance(struct Student students[], int count) {
    if (count == 0) {
        printf("\nNo students found! Add students first.\n");
        return;
    }

    printf("\nMark Attendance for Today:\n");
    int i;
    for (i = 0; i < count; i++) {
        char status;
        printf("Is %s present? (y/n): ", students[i].name);
        scanf(" %c", &status);

        students[i].totalDays++;
        if (status == 'y' || status == 'Y') {
            students[i].presentDays++;
        }
    }

    printf("\nAttendance marked for all students!\n");
}

// Function to display attendance report
void viewReport(struct Student students[], int count) {
    if (count == 0) {
        printf("\nNo records found!\n");
        return;
    }

    printf("\n=== Attendance Report ===\n");
    printf("%-10s %-20s %-15s %-15s %-10s\n",
           "ID", "Name", "Total Days", "Present Days", "Percent");

    int i;
    for (i = 0; i < count; i++) {
        float percent = 0;
        if (students[i].totalDays != 0) {
            percent = (students[i].presentDays * 100.0f) / students[i].totalDays;
        }

        printf("%-10d %-20s %-15d %-15d %-10.2f%%\n",
               students[i].id,
               students[i].name,
               students[i].totalDays,
               students[i].presentDays,
               percent);
    }
}

