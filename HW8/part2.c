#include <stdlib.h>

#include <time.h>

#include <stdio.h>

char* find_operations(int arr[], int expected_val, char operations[], size_t arr_len, int cursor, int current);

int main(){
    size_t arr_len;
    srand(time(NULL));
    int i,expected_val, cursor=1, current=0;
    printf("Enter the length of array\n");
    scanf("%lu", &arr_len);
    int arr[arr_len];
    char operations[arr_len-1];
    printf("Enter : %lu numbers for array\n",arr_len);
    /*Get the numbers*/
    for(i=0; i<arr_len; i++){
        scanf("%d",&arr[i]);
    }
    /*operations string has n-1 spaces at the beginning */
    for(i=0; i<arr_len; i++){
        operations[i]=' ';

    }
    printf("Enter the expected value:\n");
    scanf("%d",&expected_val);
    find_operations(arr, expected_val,operations, arr_len, cursor, current);
    printf("Expected value found with this operators: \n");
    for(i=0; i<arr_len; i++){
        printf("%c",operations[i]);
    }
    return 0;
}
/*find_operations functions doesn't work completely.
 * it only works if there's n-1 operators for find the expected value
 * i can't do the return part if there's no solution. */

char* find_operations(int arr[], int expected_val, char operations[], size_t arr_len, int cursor, int current) {
    int i;
    int operator = rand() % 3 + 1;
    /*Choose a random operator for first and second element of array */
    if (cursor == 1) {
        if (operator == 1) {
            current = arr[0] + arr[1];
            operations[0] = '+';
            printf("%d+%d=%d \n", arr[0], arr[1], current);
        } else if (operator == 2) {
            current = arr[0] - arr[1];
            operations[0] = '-';
            printf("%d-%d=%d \n", arr[0], arr[1], current);
        } else if (operator == 3) {
            current = arr[0] * arr[1];
            operations[0] = '*';
            printf("%d*%d=%d \n", arr[0], arr[1], current);
        }
        if (expected_val != current) {
            find_operations(arr + 2, expected_val, operations + 2, arr_len - 2, cursor + 1, current);
        }
    }
    /*Increase or decrease the current value with operations */
    else {
        if (operator == 1) {
            current += arr[0];
            operations[0] = '+';
            printf("%d+%d=%d \n", current - arr[0], arr[0], current);

        } else if (operator == 2) {
            current -= arr[0];
            operations[0] = '-';
            printf("%d-%d=%d \n", current + arr[0], arr[0], current);

        } else if (operator == 3) {
            current *= arr[0];
            operations[0] = '*';
            printf("%d*%d=%d \n", current / arr[0], arr[0], current);
        }
        if (arr_len - 2 != 0) {
            find_operations(arr + 1, expected_val, operations + 1, arr_len - 1, cursor + 1, current);
        }

        /*If cursor = arr_len-2 and at the next operation if the current value is not
         * equal to the expected value, the program calls the function in itself
         * from the beginning*/
        if ((arr_len - 2 == 0)) {
            int a=current+arr[1], b=current*arr[1],c=current-arr[1];
            if (a!= expected_val && b!=expected_val && c!=expected_val){
                printf("Expected value not found with this operators , trying again... \n");
                arr_len = cursor + 2;
                arr-=cursor;
                operations=operations-cursor;
                for(i=0; i<arr_len-2; i++){
                    operations[i]=' ';
                }
                cursor = 1;
                current = 0;
                find_operations(arr, expected_val, operations, arr_len, cursor, current);
            }
            else {

                if(current+arr[1]==expected_val){
                    current += arr[1];
                    operations[1]='+';
                    printf("%d+%d=%d \n", current - arr[1], arr[1], current);
                }
                else if(current-arr[1]==expected_val){
                    current -= arr[1];
                    operations[1]='-';
                    printf("%d-%d=%d \n", current + arr[1], arr[1], current);
                }
                else {
                    current *= arr[1];
                    operations[1] = '*';
                    printf("%d*%d=%d \n", current / arr[1], arr[1], current);
                }
            }
        }
        /*If current value=expected value return the operations */
        if (current == expected_val) {
            return operations;
        }
    }
}