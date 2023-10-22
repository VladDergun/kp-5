










#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
double getInput(const char *prompt);
void sort(char **array, int num);
bool isScientificNotation(const char *input);

int main(void) {
    int n_str, str_size;
    n_str = getInput("Enter the number of strings: ");
    str_size = getInput("Enter the size of strings: ");


    char *stringArr[n_str];
    for (int i = 0; i < n_str; i++) {
        while(1){
            // повертає адресу першого байту цієї області
            stringArr[i] = (char *)malloc(str_size + 1);

            if (stringArr[i] == NULL) {
                printf("Memory allocation failed. \n");

            }
            else{
                break;
            }
        }
        printf("\n");
            printf("Enter string %d: ", i + 1);
            scanf("%s", stringArr[i]);
        }

    sort(stringArr, n_str);
    for (int i = 0; i < n_str; i++) {
            free(stringArr[i]);
        }

    return 0;
}
void sort (char **ptrArrStr, int num){
//    A pointer to an array of pointers to strings (in this case, a string is represented as an array of characters, and each element of it points to an individual string). In other words, it's a two-dimensional array, where each element is a pointer to the  string.
    int i,j;
    for(i=0;i<num-1;i++){
        for(j=i+1;j<num;j++){
            if ( strcmp(ptrArrStr[i],ptrArrStr[j]) >0 ){
                char *tmp;
                tmp=ptrArrStr[i];
                ptrArrStr[i]=ptrArrStr[j];
                ptrArrStr[j]=tmp;
            }
        }
    }
    printf("\nArray after sorting:\n");
    for (int i = 0; i < num; i++) {
         printf("%d -> %s\n", i+1, ptrArrStr[i]);
     }



}

double getInput(const char *prompt) {
    char input[15];
    double number;

    do {
        printf("%s", prompt);
        scanf("%s", input);

        int invalidInput = 0;
        for (int i = 0; input[i]; i++) {
            if (isdigit(input[i]) == 0 && input[i] != '.' && input[i] != '-' && !isScientificNotation(input)) {
                printf("\nYour input is invalid\n");
                invalidInput = 1;
                break;
            }
        }

        if (!invalidInput) {
            number = atof(input);
            break;
        }
    } while (1);

    return number;
}
bool isScientificNotation(const char *input) {
    int len = strlen(input);
    int eCount = 0;
    int digitsBeforeE = 0;
    int digitsAfterE = 0;

    for (int i = 0; i < len; i++) {
        char c = input[i];
        if (c == 'e' || c == 'E') {
            eCount++;
        } else if (isdigit(c) && eCount == 0) {
            digitsBeforeE++;
        } else if (isdigit(c) && eCount == 1) {
            digitsAfterE++;
        }
    }


    return (eCount == 1) && (digitsBeforeE > 0) && (digitsAfterE > 0);
}














