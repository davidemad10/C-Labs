#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <dos.h>
#include <dir.h>
#include <dos.h>
#include <dir.h>
#define EMPLOYEE_DB 100
#define UP 72
#define DOWN 80
#define RIGHT 77
#define LEFT 75
#define ENTER 13
#define BACK 8
#define ESC 27

void SetColor(int ForgC){
     WORD wColor;

      HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
      CONSOLE_SCREEN_BUFFER_INFO csbi;
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
 }



void clearScreen() {
    printf("\033[2J\033[H");
}


void displayMenu(int selected) {
    clearScreen();

    for (int i = 1; i <= 4; i++) {
        if (i == selected) {
            SetColor(3);
        } else {
            SetColor(7);
        }

        if (i == 1) printf("1. New\n");
        if (i == 2) printf("2. Display\n");
        if (i == 3) printf("3. Modify\n");
        if (i == 4) printf("4. Exit\n");
    }
    SetColor(7);
}

struct employee {
    int id;
    char name[20];
    int salary;
    char BD;
    char BM;
    int BY;
};

struct employee employees[EMPLOYEE_DB];
int employeeCount=0;

void employeeData(){
    struct employee emp;
    int employeeAdded=0;
    int i=0;

    printf("Please Enter How Many Employee You Want To Add. \n");
    while (scanf("%d", &employeeAdded) != 1) {
        SetColor(4);
        printf("Error: Please enter an integer only!\n");
        SetColor(7);
        while (getchar() != '\n');
    }


    while(i<employeeAdded){
    SetColor(3);
    printf("Please Enter Employee no.%d \n",i+1);
    SetColor(7);
    int idExists = 1;
    while (idExists) {
        printf("Enter Employee Id===> ");
        while (scanf("%d", &emp.id) != 1) {
            SetColor(4);
            printf("Error: Please enter an integer only!\n");
            SetColor(7);
            while (getchar() != '\n');
        }

        idExists = 0;
        for (int j = 0; j < employeeCount; j++) {
            if (employees[j].id == emp.id) {
                SetColor(4);
                printf("Error: Employee ID %d already exists! Please enter a unique ID.\n", emp.id);
                SetColor(7);
                idExists = 1;
                break;
            }
        }
    }

    printf("Enter Employee Name===> ");
      while (scanf("%s", &emp.name) != 1) {
        SetColor(4);
        printf("Error: Please enter a valid string!\n");
        SetColor(7);
        while (getchar() != '\n');
    }

    printf("Enter Employee Salary===> ");
    while (scanf("%d", &emp.salary) != 1) {
        SetColor(4);
        printf("Error: Please enter an integer only!\n");
        SetColor(7);
        while (getchar() != '\n');
    }


    printf("Enter Employee Birthday (Day)===> ");
    while (scanf("%d", &emp.BD) != 1) {
        SetColor(4);
        printf("Error: Please enter an integer only!\n");
        SetColor(7);
        while (getchar() != '\n');
    }

    printf("Enter Employee Birthday (Month)===> ");
    while (scanf("%d", &emp.BM) != 1) {
        SetColor(4);
        printf("Error: Please enter an integer only!\n");
        SetColor(7);
        while (getchar() != '\n');
    }

    printf("Enter Employee Birthday (Year)===> ");
    while (scanf("%d", &emp.BY) != 1) {
        SetColor(4);
        printf("Error: Please enter an integer only!\n");
        SetColor(7);
        while (getchar() != '\n');
    }
    employees[employeeCount++]=emp;
    i++;
}
    SetColor(2);
    printf("\nEmployee added successfully!\n");
    SetColor(7);

}

void displayAllEmployees(){
    if (employeeCount == 0) {
        SetColor(20);
        printf("No employees to display!\n");
        SetColor(7);
        return;
    }

    SetColor(5);
    printf("\n--- All Employee Details ---\n\n");
    SetColor(7);
    for (int i = 0; i < employeeCount; i++) {
        printf("Employee %d:\n", i + 1);
        printf("ID: %d\n", employees[i].id);
        printf("Name: %s\n", employees[i].name);
        printf("Salary: %d\n", employees[i].salary);
        printf("Birth Date: %02d-%02d-%d\n\n", employees[i].BD, employees[i].BM, employees[i].BY);
        printf("=================================================== \n");
    }
}

void modifyEmployeeData() {
    if (employeeCount == 0) {
        SetColor(20);
        printf("No employees available to modify!\n");
        SetColor(7);
        return;
    }

    displayAllEmployees();

    int id, choice = 0;
    printf("Enter Employee ID to modify: ");
    scanf("%d", &id);

    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == id) {

            while (choice != 6) {
                SetColor(3);
                printf("\nModifying details for Employee ID %d:\n", id);
                SetColor(7);

                printf("1. Modify Name (current: %s)\n", employees[i].name);
                printf("2. Modify Salary (current: %d)\n", employees[i].salary);
                printf("3. Modify Birth Day (current: %02d)\n", employees[i].BD);
                printf("4. Modify Birth Month (current: %02d)\n", employees[i].BM);
                printf("5. Modify Birth Year (current: %d)\n", employees[i].BY);
                printf("6. Exit Modification\n");

                printf("Enter your choice: ");
                if (scanf("%d", &choice) != 1 || choice < 1 || choice > 6) {
                    SetColor(4);
                    printf("Invalid input! Please enter a number between 1 and 6.\n");
                    SetColor(7);
                    while (getchar() != '\n'); // Clear invalid input
                    choice = 0; // Reset choice
                    continue;
                }

                switch (choice) {
                    case 1:
                        printf("Enter New Name: ");
                        scanf("%s", employees[i].name);
                        SetColor(2);
                        printf("Name updated successfully!\n");
                        SetColor(7);
                        break;
                    case 2:
                        printf("Enter New Salary: ");
                        scanf("%d", &employees[i].salary);
                        SetColor(2);
                        printf("Salary updated successfully!\n");
                        SetColor(7);
                        break;
                    case 3:
                        printf("Enter New Birth Day: ");
                        scanf("%d", &employees[i].BD);
                        SetColor(2);
                        printf("Birth Day updated successfully!\n");
                        SetColor(7);
                        break;
                    case 4:
                        printf("Enter New Birth Month: ");
                        scanf("%d", &employees[i].BM);
                        SetColor(2);
                        printf("Birth Month updated successfully!\n");
                        SetColor(7);
                        break;
                    case 5:
                        printf("Enter New Birth Year: ");
                        scanf("%d", &employees[i].BY);
                        SetColor(2);
                        printf("Birth Year updated successfully!\n");
                        SetColor(7);
                        break;
                    case 6:
                        SetColor(3);
                        printf("Exiting modification menu.\n");
                        SetColor(7);
                        break;
                    default:
                        break;
                }
            }
            break;
        }
    }


}

int main() {
    int selected = 1;
    int exitLoop=0;
    int ch;

    displayMenu(selected);

     while (exitLoop==0) {
        ch = _getch();

        if (ch == 0 || ch == 224) {
            ch = _getch();
            if (ch == UP) {
                selected = (selected == 1) ? 4 : selected - 1;
            } else if (ch == DOWN) {
                selected = (selected == 4) ? 1 : selected + 1;
            }
        } else if (ch == ENTER) {
            if (selected == 4) {
                clearScreen();
                SetColor(20);
                printf("Exiting program...\n");
                SetColor(7);
                exit(0);
            } else {
                clearScreen();
                if (selected == 1){
                    SetColor(5);
                    printf("Add new employee data:\n");
                    SetColor(7);
                    employeeData();
                }
                if (selected == 2){
                    displayAllEmployees();
                }
                if (selected == 3 ){
                    modifyEmployeeData();
                }
                printf("Press Backspace to return to the menu...\n");
                int flag =1;
                while (flag) {
                    ch = _getch();
                    if (ch == BACK) {
                        displayMenu(selected);
                        flag=0;
                    }
                }
            }
        }

        displayMenu(selected);
    }

    return 0;
}
