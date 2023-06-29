#include <stdio.h>

// max = [
//     [7, 5, 3],
//     [3, 2, 2],
//     [9, 0, 2],
// ]

// all = [
//     [0, 1, 0],
//     [2, 0, 0],
//     [3, 0, 2],
// ]

// resource = [10,5,7] # total resources

// need = [
//     [7, 4, 3],
//     [1, 2, 2],
//     [6, 0, 0],
// ]

// total allocation = [5, 1, 2]

// available = [5, 4, 5]

int main() {
    int process_size, resource_size;
    printf("process size: ");
    scanf("%d", &process_size);
    printf("resource size: ");
    scanf("%d", &resource_size);

    int max[process_size][resource_size];
    int all[process_size][resource_size];

    printf("Enter Max Matrix\n");
    for (int i = 0; i < process_size; i++) {
        for (int j = 0; j < resource_size; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter Allocation Matrix\n");
    for (int i = 0; i < process_size; i++) {
        for (int j = 0; j < resource_size; j++) {
            scanf("%d", &all[i][j]);
        }
    }

    printf("max:\n");
    for (int i = 0; i < process_size; i++) {
        for (int j = 0; j < resource_size; j++) {
            printf("%d ", max[i][j]);
        }
        printf("\n");
    }

    printf("allocation:\n");
    for (int i = 0; i < process_size; i++) {
        for (int j = 0; j < resource_size; j++) {
            printf("%d ", all[i][j]);
        }
        printf("\n");
    }

    int resource[resource_size];
    printf("enter resources array:\n");
    for (int i = 0; i < resource_size; i++) {
        scanf("%d", &resource[i]);
    }

    int need[process_size][resource_size];
    for (int i = 0; i < process_size; i++) {
        for (int j = 0; j < resource_size; j++) {
            need[i][j] = max[i][j] - all[i][j];
        }
    }

    printf("need:\n");
    for (int i = 0; i < process_size; i++) {
        for (int j = 0; j < resource_size; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    int ABC[resource_size];
    for (int i = 0; i < resource_size; i++) {
        ABC[i] = 0;
        for (int j = 0; j < process_size; j++) {
            ABC[i] += all[j][i];
        }
    }

    printf("total allocation:\n");
    for (int i = 0; i < resource_size; i++) {
        printf("%d ", ABC[i]);
    }
    printf("\n");

    int available[resource_size];
    int safe = 1;
    for (int i = 0; i < resource_size; i++) {
        available[i] = resource[i] - ABC[i];
        if (available[i] < 0) {
            safe = 0;
        }
    }

    printf("available:\n");
    for (int i = 0; i < resource_size; i++) {
        printf("%d ", available[i]);
    }
    printf("\n");

    if (!safe) {
        printf("Not a Safe State\n");
    }

    return 0;
}
