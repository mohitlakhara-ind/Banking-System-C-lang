#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// Declaring all the functions
void checkbalance(char*);
void transfermoney(void);
void display(char*);
void person(char*);
void login(void);
void loginsu(void);
void account(void);
void accountcreated(void);
void afterlogin(void);
void logout(void);
void showCredits(void);

// Declaring gotoxy function for setting cursor position
void gotoxy(int x, int y) {
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

// Creating a structure to store data of the user
struct pass {
    char username[50];
    int date, month, year;
    char pnumber[15];
    char adharnum[20];
    char fname[20];
    char lname[20];
    char fathname[20];
    char mothname[20];
    char address[50];
    char typeaccount[20];
};

// Structure to keep track of amount transfer
struct money {
    char usernameto[50];
    char userpersonfrom[50];
    long int money1;
};

struct userpass {
    char password[50];
};

// Driver Code
int main() {
    int choice;

    gotoxy(20, 3);
    printf("WELCOME TO BANK ACCOUNT SYSTEM\n\n");
    gotoxy(18, 5);
    printf("**********************************");
    gotoxy(25, 7);
    printf("DEVELOPER: Mohit Lakhara");

    gotoxy(20, 10);
    printf("1.... CREATE A BANK ACCOUNT");

    gotoxy(20, 12);
    printf("2.... ALREADY A USER? SIGN IN");
    gotoxy(20, 14);
    printf("3.... EXIT\n\n");

    printf("\n\nENTER YOUR CHOICE..");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            system("cls");
            printf("\n\n USERNAME 50 CHARACTERS MAX!!");
            printf("\n\n PASSWORD 50 CHARACTERS MAX!!");
            account();
            break;

        case 2:
            login();
            break;

        case 3:
            showCredits();
            exit(0);
            break;

        getch();
    }
}

// Function to create accounts of users
void account(void) {
    char password[20];
    int i;
    char ch;
    FILE *fp;
    struct pass u1;

    // Opening file to write data of a user
    fp = fopen("username.txt", "ab");

    // Inputs
    system("cls");
    printf("\n\n!!!!!CREATE ACCOUNT!!!!!");

    printf("\n\nFIRST NAME..");
    scanf("%s", &u1.fname);

    printf("\n\n\nLAST NAME..");
    scanf("%s", &u1.lname);

    printf("\n\nFATHER's NAME..");
    scanf("%s", &u1.fathname);

    printf("\n\nMOTHER's NAME..");
    scanf("%s", &u1.mothname);

    printf("\n\nADDRESS..");
    scanf("%s", &u1.address);

    printf("\n\nACCOUNT TYPE");
    scanf("%s", &u1.typeaccount);

    printf("\n\nDATE OF BIRTH..");
    printf("\nDATE-");
    scanf("%d", &u1.date);
    printf("\nMONTH-");
    scanf("%d", &u1.month);
    printf("\nYEAR-");
    scanf("%d", &u1.year);

    printf("\n\nADHAR NUMBER");
    scanf("%s", u1.adharnum);

    printf("\n\nPHONE NUMBER");
    scanf("%s", u1.pnumber);

    printf("\n\nUSERNAME.. ");
    scanf("%s", &u1.username);

    printf("\n\nPASSWORD..");

    // Taking password in the form of stars
    for (i = 0; i < 50; i++) {
        ch = getch();
        if (ch != 13) {
            password[i] = ch;
            ch = '*';
            printf("%c", ch);
        } else
            break;
    }

    // Writing to the file
    fwrite(&u1, sizeof(u1), 1, fp);

    // Closing file
    fclose(fp);

    // Successful account creation
    accountcreated();
}

// Function after successful account creation
void accountcreated(void) {
    int i;
    system("cls");
    printf("PLEASE WAIT....\n\nYOUR DATA IS PROCESSING....");
    for (i = 0; i < 200000000; i++) {
        i++;
        i--;
    }

    gotoxy(30, 10);
    printf("ACCOUNT CREATED SUCCESSFULLY....");
    gotoxy(0, 20);
    printf("Press enter to login");

    getch();
    login();
}

// Login function to check the username of the user
void login(void) {
    system("cls");

    char username[50];
    char password[50];

    int i;
    char ch;
    FILE *fp;
    struct pass u1;

    // Opening file of user data
    fp = fopen("username.txt", "rb");

    if (fp == NULL) {
        printf("ERROR IN OPENING FILE");
    }
    gotoxy(34, 2);
    printf(" ACCOUNT LOGIN ");
    gotoxy(35, 10);
    printf("==== LOG IN ====");

    // Take input
    gotoxy(35, 12);
    printf("USERNAME.. ");
    scanf("%s", &username);

    gotoxy(35, 14);
    printf("PASSWORD..");

    // Input the password
    for (i = 0; i < 50; i++) {
        ch = getch();
        if (ch != 13) {
            password[i] = ch;
            ch = '*';
            printf("%c", ch);
        } else
            break;
    }

    // Checking if username exists in the file or not
    while (fread(&u1, sizeof(u1), 1, fp)) {
        if (strcmp(username, u1.username) == 0) {
            loginsu();
            display(username);
        }
    }

    // Closing the file
    fclose(fp);
}

// Function after successful login
void loginsu(void) {
    int i;
    system("cls");
    printf("Fetching account details.....\n");
    for (i = 0; i < 20000; i++) {
        i++;
        i--;
    }

    gotoxy(30, 10);
    printf("LOGIN SUCCESSFUL....");
    gotoxy(0, 20);
    printf("Press enter to continue");

    getch();
}

// Display function to show the data of the user on screen
void display(char username1[]) {
    system("cls");
    FILE* fp;
    int choice;
    fp = fopen("username.txt", "rb");
    struct pass u1;

    if (fp == NULL) {
        printf("error in opening file");
    }

    while (fread(&u1, sizeof(u1), 1, fp)) {
        if (strcmp(username1, u1.username) == 0) {
            gotoxy(30, 1);
            printf("WELCOME, %s %s", u1.fname, u1.lname);
            gotoxy(28, 2);
            printf("..........................");
            gotoxy(55, 6);
            printf("==== YOUR ACCOUNT INFO ====");
            gotoxy(55, 8);
            printf("***************************");
            gotoxy(55, 10);
            printf("NAME..%s %s", u1.fname, u1.lname);
            gotoxy(55, 12);
            printf("FATHER's NAME..%s %s", u1.fathname, u1.lname);
            gotoxy(55, 14);
            printf("MOTHER's NAME..%s", u1.mothname);
            gotoxy(55, 16);
            printf("ADHAR CARD NUMBER..%s", u1.adharnum);
            gotoxy(55, 18);
            printf("MOBILE NUMBER..%s", u1.pnumber);
            gotoxy(55, 20);
            printf("DATE OF BIRTH.. %d-%d-%d", u1.date, u1.month, u1.year);
            gotoxy(55, 22);
            printf("ADDRESS..%s", u1.address);
            gotoxy(55, 24);
            printf("ACCOUNT TYPE..%s", u1.typeaccount);
        }
    }

    fclose(fp);

    gotoxy(0, 6);

    // Menu to perform different actions by user
    printf(" HOME ");
    gotoxy(0, 7);
    printf("******");
    gotoxy(0, 9);
    printf(" 1....CHECK BALANCE");
    gotoxy(0, 11);
    printf(" 2....TRANSFER MONEY");
    gotoxy(0, 13);
    printf(" 3....LOG OUT\n\n");
    gotoxy(0, 15);
    printf(" 4....EXIT\n\n");

    printf(" ENTER YOUR CHOICE..");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            checkbalance(username1);
            break;

        case 2:
            transfermoney();
            break;

        case 3:
            logout();
            login();
            break;

        case 4:
            showCredits();
            exit(0);
    }
}

// Function to check balance
void checkbalance(char username1[]) {
    system("cls");

    FILE *fptr;
    fptr = fopen("amount.txt", "r");

    if (fptr == NULL) {
        printf("Error in opening file..");
    }

    struct money m1;

    while (fread(&m1, sizeof(m1), 1, fptr)) {
        if (strcmp(username1, m1.userpersonfrom) == 0) {
            printf("YOUR CURRENT BALANCE IS %ld", m1.money1);
        }
    }

    fclose(fptr);

    getch();
    display(username1);
}

// Function to transfer money
void transfermoney(void) {
    system("cls");
    char usernamefrom[50];
    char usernameto[50];
    struct money m1;
    FILE *fptr;

    // Opening file in append mode
    fptr = fopen("amount.txt", "ab");

    if (fptr == NULL) {
        printf("ERROR IN OPENING FILE");
    }

    printf("USERNAME OF SENDER.. ");
    scanf("%s", &usernamefrom);
    printf("USERNAME OF RECEIVER.. ");
    scanf("%s", &usernameto);
    printf("ENTER THE AMOUNT TO TRANSFER.. ");
    scanf("%ld", &m1.money1);

    strcpy(m1.userpersonfrom, usernamefrom);
    strcpy(m1.usernameto, usernameto);

    fwrite(&m1, sizeof(m1), 1, fptr);

    fclose(fptr);

    printf("YOUR MONEY IS BEING TRANSFERRED....");
    for (int i = 0; i < 20000; i++) {
        i++;
        i--;
    }

    printf("TRANSACTION SUCCESSFUL....");

    getch();
}

// Function to logout from the account
void logout(void) {
    system("cls");
    printf("YOU ARE LOGGED OUT SUCCESSFULLY");
    getch();
}

// Function to display credits
void showCredits(void) {
    system("cls");
    gotoxy(20, 5);
    printf("THIS PROJECT IS DEVELOPED BY:");
    gotoxy(20, 7);
    printf("NAME: Mohit Lakhara");
    gotoxy(20, 9);
    printf("GITHUB: https://github.com/mohitlakhara-ind");
    getch();
}
