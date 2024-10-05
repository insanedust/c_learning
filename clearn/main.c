#include <stdio.h>
#include <stdlib.h>

int* populate_array(int array_size);
void print_array(const int* array, int array_size);
void delete_by_index();
void merge_two_arrays();
void print_menu();
void print_address_2d_array();

int main()
{
    int choice;

    do {
        print_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1: delete_by_index();
            break;
            case 2: merge_two_arrays();
            break;
            case 3: print_address_2d_array();
            break;
            default: choice = 0;
            break;
        }
    } while(choice);

    return 0;
}
void print_menu() {
    printf("Please select option\n");
    printf("(1) Arrays - delete by index\n");
    printf("(2) Arrays - merge two arrays\n");
    printf("(3) Arrays - Print element address of 2D array\n");
    printf("(0) Exit\n");
    printf("option: ");
    fflush(stdout);
}

int* populate_array(const int array_size) {
    int* array = (int*)malloc(sizeof(int) * array_size);
    printf("\nPlease enter %d integer numbers\n", array_size);

    for (int i = 0; i < array_size; i++) {
        printf("array[%d]: ", i);
        scanf(" %d", array+i);
    }
    return array;
}

void print_array(const int* array, const int array_size) {
    if(array == NULL) return;
    printf("\nArray values\n");

    for (int i = 0; i < array_size; i++)
            printf("[%d]: %d\n", i + 1, array[i]);

    printf("\n");
}

void delete_by_index() {
    int size, index;
    printf("Please enter size of array: ");
    scanf(" %d", &size);
    int *array = populate_array(size);
    print_array(array, size);
    printf("\nSelect index to delete: ");
    scanf(" %d", &index);

    for (int i = index; i < size - 1; i++) {
        array[i] = array[i + 1];
    }
    --size;

    printf("index %d removed\n", index);
    print_array(array, size);
    free(array);
}

void merge_two_arrays() {
    int array_size1;
    printf("Please enter size of array1: ");
    scanf(" %d", &array_size1);
    int *array1 = populate_array(array_size1);
    print_array(array1, array_size1);

    int array_size2;
    printf("Please enter size of array2: ");
    scanf(" %d", &array_size2);
    int *array2 = populate_array(array_size2);
    print_array(array2, array_size2);

    printf("Merge both arrays\n");
    const int array_size3 = array_size1 + array_size2;
    int* array3 = (int*)malloc(sizeof(int) * array_size3);

    for (int i = 0; i < array_size1; i++) {
        array3[i] = array1[i];
    }

    int j = 0;
    for (int i = array_size1; i < array_size3; i++) {
        array3[i] = array2[j];
        ++j;
    }

    print_array(array3, array_size3);

    free(array1);
    free(array2);
    free(array3);
}

void print_address_2d_array() {
    printf("\n");
    int array[3][5] = {
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15}
    };

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 5; j++) {
            printf("array[%d][%d]: %d\n", i, j, array[i][j]);
        }
    }

    for(int i = 0; i < 3; i++) {
        int* basePtr = &array[i][0];
        printf("\nbase address: %p\n", basePtr);
        for(int j = 0; j < 5; j++) {
            printf("array[%d][%d]: Address:%p Value: %d\n", i, j, basePtr + j, *(basePtr + j));
        }
    }

    printf("\n");
}

