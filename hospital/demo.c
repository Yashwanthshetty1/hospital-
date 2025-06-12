#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Patient {
    char name[50];
    int age;
    char disease[100];
};

void addPatient() {
    FILE *f = fopen("patients.txt", "a");
    struct Patient p;
    printf("Enter patient name: ");
    scanf("%s", p.name);
    printf("Enter age: ");
    scanf("%d", &p.age);
    printf("Enter disease: ");
    scanf("%s", p.disease);
    fprintf(f, "%s %d %s\n", p.name, p.age, p.disease);
    fclose(f);
    printf("✅ Patient added successfully!\n");
}

void viewPatients() {
    FILE *f = fopen("patients.txt", "r");
    struct Patient p;
    printf("\n--- All Patient Records ---\n");
    while (fscanf(f, "%s %d %s", p.name, &p.age, p.disease) != EOF) {
        printf("Name: %s | Age: %d | Disease: %s\n", p.name, p.age, p.disease);
    }
    fclose(f);
}

void searchPatient() {
    FILE *f = fopen("patients.txt", "r");
    struct Patient p;
    char searchName[50];
    int found = 0;
    printf("Enter name to search: ");
    scanf("%s", searchName);
    while (fscanf(f, "%s %d %s", p.name, &p.age, p.disease) != EOF) {
        if (strcmp(p.name, searchName) == 0) {
            printf("✅ Found: Name: %s | Age: %d | Disease: %s\n", p.name, p.age, p.disease);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("❌ Patient not found.\n");
    }
    fclose(f);
}

void clearAll() {
    FILE *f = fopen("patients.txt", "w");
    fclose(f);
    printf("🗑️ All records deleted.\n");
}

int main() {
    int choice;
    while(1) {
        printf("\n🏥 Hospital Management System\n");
        printf("1. Add Patient\n2. View Patients\n3. Search Patient\n4. Delete All\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: addPatient(); break;
            case 2: viewPatients(); break;
            case 3: searchPatient(); break;
            case 4: clearAll(); break;
            case 5: exit(0);
            default: printf("❗ Invalid choice\n");
        }
    }
    return 0;
}
