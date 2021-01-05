#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define LIST_SIZE 255
#define STRING_SIZE 255

void listAllEmployees(char employeeNames[LIST_SIZE][STRING_SIZE], int employeeNumbers[]);
void choice();
int addNewEmployee(char employeeNames[LIST_SIZE][STRING_SIZE], int dbIndex);

int main() {

    // Run choices.
    choice();

    return 0;
}

void choice()
{
    char choice, choiceLowerCase;

    // Okay, let's make a "database"
    int dbEmployeeNumbers[LIST_SIZE];
    char dbEmployeeNames[LIST_SIZE][STRING_SIZE];
    int dbIndex = 0;

    while(choiceLowerCase != 'q')
    {
        printf("====================\n");
        printf("\tMENU\n");
        printf("====================\n");
        printf("\nN - NEW EMPLOYEES");//mani ni ug perform
        printf("\nV - VIEW LIST OF EMPLOYEES");//use bubble sort in ascending
        printf("\nS - FIND EMPLOYEES");//linear search
        printf("\nT - TOTAL NUMBER OF EMPLOYEES");//guide totalsales function
        printf("\nQ - QUIT PROGRAM");// quit
        printf("\nEnter a choice: ");
        scanf("%s", &choice);

        // Convert choice to lowercase 
        choiceLowerCase = tolower(choice);

        switch(choiceLowerCase)
        {
            case 'n':
                dbIndex = addNewEmployee(dbEmployeeNames, dbIndex);
                break;
            case 'v':
                listAllEmployees(dbEmployeeNames, dbEmployeeNumbers);
                break;
            case 'q':
                printf("You can now exit\n\n\n");
                break;
        }
    }
    return 0;
}

int addNewEmployee(char employeeNames[LIST_SIZE][STRING_SIZE], int inputDbIndex) {

    char name[STRING_SIZE];
    int n, i, j;

    printf("How many employees do you wish to add?\n");
    scanf("%d", &n); //3

    // For every employees queued.
    for (i = 0; i < n; i++) {
        printf("(%d/%d) Enter employee name: ", (i+1), n);
        scanf(" %[^\n]", name);
        strcpy(employeeNames[inputDbIndex], name);
        inputDbIndex++;
    }

    printf("DB Index is: %d\n", inputDbIndex);
    return inputDbIndex;
}

void listAllEmployees(char employeeNames[LIST_SIZE][STRING_SIZE], int employeeNumbers[]) {
    int i;
    for (i = 0; i < LIST_SIZE; i++) {
        // Task: update condition so that it only shows up the valid indexes
        //  (i.e.) those only given by the user.
        if (strlen(employeeNames[i]) > 0) {
            printf("%d. %s\n", (i+1), employeeNames[i]);
        }
    }
    // printf("%s", employeeNames[0]);
}