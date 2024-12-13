#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "users.txt"

struct User {
    int id;
    char name[50];
    int age;
};

// new user
void createUser() {
    struct User user;

    // check for unique id
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }
    int id ;

    printf("Enter User ID: ");
    scanf("%d", &id);
    getchar();

    int found =0;

    while (fscanf(file, "%d,%49[^,],%d\n", &user.id, user.name, &user.age) != EOF) {
        if (id == user.id) {
            found = 1;
            break;
        }
    }

    fclose(file);
    if (found) {
        printf("User with ID %d already exists.\n", id);
    }

    else
    {

    FILE *file = fopen(FILENAME, "a+"); // open files to write
    user.id = id;
    printf("Enter Name: ");
    fgets(user.name, sizeof(user.name), stdin);
    user.name[strcspn(user.name, "\n")] = '\0';
    printf("Enter Age: ");
    scanf("%d", &user.age);

    // Write user to file
    fprintf(file, "%d,%s,%d\n", user.id, user.name, user.age);
    fclose(file);
    printf("User added successfully.\n");
}}

// display function
void readUsers() {
    struct User user;
    FILE *file = fopen(FILENAME, "r");

    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    printf("ID\tName\t\tAge\n");
    printf("**********************************\n");

    while (fscanf(file, "%d,%49[^,],%d\n", &user.id, user.name, &user.age) != EOF) {
        printf("%d\t%s\t\t%d\n", user.id, user.name, user.age);
    }

    fclose(file);
}


// Function to update a user by ID
void updateUser() {
    int id;
    struct User user;
    struct User users[100]; // Array to store users
    int userCount = 0;
    FILE *file = fopen(FILENAME, "r"); // Open file for reading

    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter User ID to update: ");
    scanf("%d", &id);
    getchar();  // Clear the newline left by scanf

    // Read all users into the array
    while (fscanf(file, "%d,%49[^,],%d\n", &user.id, user.name, &user.age) != EOF) {
        users[userCount++] = user;
    }

    fclose(file); // Close file after reading

    int found = 0;
    // Find and update the user with the matching ID
    for (int i = 0; i < userCount; i++) {
        if (users[i].id == id) {
            found = 1;
            printf("User found! Current details: %d, %s, %d\n", users[i].id, users[i].name, users[i].age);

            // Get new details
            printf("Enter new Name: ");
            fgets(users[i].name, sizeof(users[i].name), stdin);
            users[i].name[strcspn(users[i].name, "\n")] = '\0'; // Remove newline character
            printf("Enter new Age: ");
            scanf("%d", &users[i].age);

            printf("User updated successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("User with ID %d not found.\n", id);
        return;
    }

    // Open file for writing (overwrite mode)
    file = fopen(FILENAME, "w"); // Open file to overwrite the content

    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    // Write all users back to the file, including the updated user
    for (int i = 0; i < userCount; i++) {
        fprintf(file, "%d,%s,%d\n", users[i].id, users[i].name, users[i].age);
    }

    fclose(file); // Close the file after writing
}

// Function to delete a user by ID
void deleteUser() {
    int id;
    struct User user;
    FILE *file = fopen(FILENAME, "r");

    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    FILE *tempFile = fopen("temp.txt", "w"); // Temporary file to store updated records

    if (!tempFile) {
        printf("Error opening temporary file!\n");
        fclose(file);
        return;
    }

    printf("Enter User ID to delete: ");
    scanf("%d", &id);

    int found = 0;
    while (fscanf(file, "%d,%49[^,],%d\n", &user.id, user.name, &user.age) != EOF) {
        if (user.id == id) {
            found = 1;
            printf("User with ID %d has been deleted.\n", id);
        } else {
            // Copy user to temp file if not deleted
            fprintf(tempFile, "%d,%s,%d\n", user.id, user.name, user.age);
        }
    }

    if (!found) {
        printf("User with ID %d not found.\n", id);
    }

    fclose(file);
    fclose(tempFile);

    // Remove original file and rename temp file to original name
    remove(FILENAME);
    rename("temp.txt", FILENAME);
}

// Main menu function
void menu() {
    int choice;

    do {
        printf("\nCRUD Operations Menu:\n");
        printf("1. Add User\n");
        printf("2. Display Users\n");
        printf("3. Update User\n");
        printf("4. Delete User\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createUser();
                break;
            case 2:
                readUsers();
                break;
            case 3:
                updateUser();
                break;
            case 4:
                deleteUser();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);
}

int main() {
    menu();
    return 0;
}
