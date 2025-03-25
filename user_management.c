#include <stdio.h>
#include <string.h>

#define LENGTH_USER_NAME_PASS 30
#define MAX_SIZE 10

void registers();
int login();
void fix_fgets_input(char *);
void input_password(char *);

typedef struct {
    char user_name[LENGTH_USER_NAME_PASS];
    char password[LENGTH_USER_NAME_PASS];
} Person;

Person user[MAX_SIZE];
int user_count = 0;
int index_number;

int main() {
    while (1) {
        printf("\n\n1. Register \n");
        printf("2. Login \n");
        printf("3. Exit \n");
        int choice;
        printf("Enter your option: ");
        scanf("%d", &choice);
        getchar();  //Consume extra enter
        switch (choice) {
            case 1:
                registers();
                break;
            case 2:
                index_number = login();
                if (index_number >= 0) {
                    printf("Login successful %s \n");
                } else {
                    printf("Login Failed!!! Please check your Username and Password\n");
                }
                break;
            case 3:
                printf("Exiting\n");
                return 0;
            default:
                printf("Invalid Option, please try again.\n");
                break;
        }
    }
    return 0;
}

void registers() {
    if (user_count == MAX_SIZE) {
        fprintf(stderr, "Maximum %d user limit exceeded.\n", user_count);
        printf("Sorry, registration is not allowed!\n");
        return;
    }
    int new_index = user_count;
    printf("Register as a new user.\n");

    printf("Enter username: ");
    getchar();  // Consume leftover newline
    fgets(user[new_index].user_name, LENGTH_USER_NAME_PASS, stdin);
    fix_fgets_input(user[new_index].user_name);

    input_password(user[new_index].password);
    
    user_count++;
    printf("\nRegistration Successful!\n");
}

int login() {
    char username[LENGTH_USER_NAME_PASS], password[LENGTH_USER_NAME_PASS];

    printf("Enter username: ");
    getchar();  // Consume leftover newline
    fgets(username, LENGTH_USER_NAME_PASS, stdin);
    fix_fgets_input(username);

    input_password(password);

    for (int i = 0; i < user_count; i++) {
        if (strcmp(username, user[i].user_name) == 0 && strcmp(password, user[i].password) == 0) {
            return i;
        }
    }
    return -1;
}

void fix_fgets_input(char *string) {
    int index = strcspn(string, "\n");
    string[index] = '\0';
}

void input_password(char *password) {
    printf("Enter Password: ");
    fgets(password, LENGTH_USER_NAME_PASS, stdin);
    fix_fgets_input(password);
}
