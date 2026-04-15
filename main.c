#include <stdio.h>
#include <string.h>

#define MAX 100

struct item {
    int id;
    char cat[50];
    char desc[100];
    int status; // 0 = pending, 1 = matched
};

struct item lost_arr[MAX], found_arr[MAX];
int lost_cnt = 0, found_cnt = 0;
int id_counter = 101;

// Add Lost Item
void addLost() {
    if (lost_cnt >= MAX) {
        printf("Storage full!\n\n");
        return;
    }

    struct item temp;
    temp.id = id_counter++;
    temp.status = 0;

    printf("Enter category: ");
    scanf("%49s", temp.cat);

    printf("Enter description: ");
    scanf(" %99[^\n]", temp.desc);

    lost_arr[lost_cnt++] = temp;

    printf("Item added successfully. ID is %d\n\n", temp.id);
}

// Add Found Item
void addFound() {
    if (found_cnt >= MAX) {
        printf("Storage full!\n\n");
        return;
    }

    struct item temp;
    temp.id = id_counter++;
    temp.status = 0;

    printf("Enter category: ");
    scanf("%49s", temp.cat);

    printf("Enter description: ");
    scanf(" %99[^\n]", temp.desc);

    found_arr[found_cnt++] = temp;

    printf("Item added successfully. ID is %d\n\n", temp.id);
}

// Search by Category
void searchItem() {
    char key[50];
    int found = 0;

    printf("Enter category to search: ");
    scanf("%49s", key);

    printf("\n-- LOST ITEMS --\n");
    for (int i = 0; i < lost_cnt; i++) {
        if (strcmp(lost_arr[i].cat, key) == 0) {
            printf("ID: %d | Desc: %s | Status: %s\n",
                   lost_arr[i].id,
                   lost_arr[i].desc,
                   lost_arr[i].status ? "Matched" : "Pending");
            found = 1;
        }
    }

    printf("\n-- FOUND ITEMS --\n");
    for (int i = 0; i < found_cnt; i++) {
        if (strcmp(found_arr[i].cat, key) == 0) {
            printf("ID: %d | Desc: %s | Status: %s\n",
                   found_arr[i].id,
                   found_arr[i].desc,
                   found_arr[i].status ? "Matched" : "Pending");
            found = 1;
        }
    }

    if (!found) {
        printf("No items found.\n");
    }

    printf("\n");
}

// Matching Function
void doMatching() {
    int match_found = 0;

    printf("\n--- Matcher ---\n");

    for (int i = 0; i < lost_cnt; i++) {
        if (lost_arr[i].status == 1)
            continue;

        for (int j = 0; j < found_cnt; j++) {
            if (found_arr[j].status == 1)
                continue;

            if (strcmp(lost_arr[i].cat, found_arr[j].cat) == 0) {
                printf("Potential match found!\n");
                printf("Lost  -> ID: %d | %s\n", lost_arr[i].id, lost_arr[i].desc);
                printf("Found -> ID: %d | %s\n", found_arr[j].id, found_arr[j].desc);

                char ch;
                printf("Match them? (y/n): ");
                scanf(" %c", &ch);

                if (ch == 'y' || ch == 'Y') {
                    lost_arr[i].status = 1;
                    found_arr[j].status = 1;
                    printf("Matched successfully!\n\n");
                    match_found = 1;
                    break;
                } else {
                    printf("Skipped.\n\n");
                }
            }
        }
    }

    if (!match_found) {
        printf("No matches right now.\n\n");
    }
}

// Main Function
int main() {
    int choice;

    while (1) {
        printf("=== Lost and Found System ===\n");
        printf("1. Add Lost item\n");
        printf("2. Add Found item\n");
        printf("3. Search by category\n");
        printf("4. Match items\n");
        printf("5. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            printf("Invalid input!\n\n");
            continue;
        }

        if (choice == 1) {
            addLost();
        } else if (choice == 2) {
            addFound();
        } else if (choice == 3) {
            searchItem();
        } else if (choice == 4) {
            doMatching();
        } else if (choice == 5) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid choice!\n\n");
        }
    }

    return 0;
}
