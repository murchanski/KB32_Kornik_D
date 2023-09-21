#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char surname[50];
    int age;
} Student;

int main() {
    int n = 0;
    Student *students = NULL;
    char command[10];
    int i;

    while (1) {
        printf("Enter command (add/view/exit): ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            students = realloc(students, (n + 1) * sizeof(Student));

            if (students == NULL) {
                printf("Memory allocation failed.\n");
                return 1;
            }

            printf("Enter name: ");
            scanf("%s", students[n].name);

            printf("Enter surname: ");
            scanf("%s", students[n].surname);

            printf("Enter age: ");
            scanf("%d", &students[n].age);
            fflush(stdin);

            n++;
        } else if (strcmp(command, "view") == 0) {
            for (i = 0; i < n; i++) {
                printf("Student #%d\n", i + 1);
                printf("Name: %s\n", students[i].name);
                printf("Surname: %s\n", students[i].surname);
                printf("Age: %d\n", students[i].age);
            }
            if (n == 0) {
                printf("No students in the list.\n");
            }
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command, please enter 'add', 'view' or 'exit'.\n");
        }
    }
    free(students);
    return 0;
}
