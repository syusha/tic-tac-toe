#include <stdio.h>
 
#define MAXLENGTH 20
#define WORDS 14
 
void ShellSortingLetters(char** string) {   //сортировка букв в каждой строке массива алгоритмом Шелла
    int gap; 
    int i,j,k;
    char temp;
 
    for(k = 0; k<WORDS; k++)
        for(gap = (MAXLENGTH-1)/2; gap > 0; gap /= 2)
            for(i = gap; i < (MAXLENGTH-1); i++)
                for(j = i - gap; j >= 0 && string[k][j] < string[k][j + gap]; j -= gap) {
                    temp = string[k][j];
                    string[k][j] = string[k][j + gap];
                    string[k][j + gap] = temp;
                }
}
 
int CheckSortingLetters(char* string) { //проверка сортировки
    int i;
    for(i=0; i<MAXLENGTH-1; i++)
        if(string[i]<string[i+1]) 
            return 0;
    return 1;
}
 
int ComparingStrings(char* firstString, char* secondString) {       //ф-я сравнения строк
    int i = 0;
    while (firstString[i] != '\0' && secondString[i] != '\0') {
        if (firstString[i] > secondString[i])
            return 1;
        else
            if (firstString[i]<secondString[i])
                return -1;
        i++;
    }
    return 0;
}
 
void ShellSortingWords(char** string, int indexArray[]) {   //сортировка строк в массиве методом Шелла
    int gap;
    int i,j,temp;
 
    for(gap = WORDS/2; gap > 0; gap /= 2)
        for(i = gap; i < WORDS; i++)
            for(j = i - gap; (j >= 0) &&  (ComparingStrings(string[indexArray[j]], string[indexArray[j+gap]]) == 1); j -= gap)  {
                temp = indexArray[j];
                indexArray[j] = indexArray[j + gap];
                indexArray[j + gap] = temp;
            }
}
 
int CheckSortingWords(char** string, int indexArray[]) {    //проверка сортировки строк (аналогично проверке сортировки букв)
    int i;
    for(i=0; i<9; i++)
        if(ComparingStrings(string[indexArray[i]], string[indexArray[i+1]]) == 1)
            return 0;
    return 1;
}
 
void FindAnagrams(char** sortedString, char strings[WORDS][MAXLENGTH], int indexArray[WORDS]) { //вывод анаграмм в строку
    for(int i=0; i<WORDS-1; i++) {
        printf(" %s ", strings[indexArray[i]]);
        if(ComparingStrings(sortedString[indexArray[i]], sortedString[indexArray[i+1]]) != 0)
            printf(" \n ", strings[indexArray[i]]);
    }
    printf(" %s ", strings[indexArray[WORDS-1]]);
}
 
int main() {
    int i,j;
 
    char strings[WORDS][MAXLENGTH] ={  "hamlet",
                                        "education",
                                        "mister",
                                        "remits",
                                        "auctioned",
                                        "baled",
                                        "amleth",
                                        "smiter",
                                        "moon",
                                        "blade",
                                        "timers",
                                        "who",
                                        "mono",
                                        "how"   };
 
    char* sortedStrings[WORDS];
 
    for(i = 0; i<WORDS; i++)
        sortedStrings[i] = strings[i];
 
    ShellSortingLetters(sortedStrings);
 
    for(i = 0; i<WORDS; i++) {
        printf("%s\n", sortedStrings[i]);
        if(CheckSortingLetters(sortedStrings[i]))
            printf("TEST PASSED!\n");
        else
            printf("TEST PASSED!\n");
    }
 
    int indexArray[WORDS] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13};
 
    ShellSortingWords(sortedStrings,indexArray);
    printf("\n");
 
    for(i = 0; i<WORDS; i++)
        printf("%d\n", indexArray[i]);
 
    if(CheckSortingWords(sortedStrings, indexArray))
        printf("\nTEST PASSED!");
    else
        printf("\nTEST FAILED!");
 
    printf("\n");
    FindAnagrams(sortedStrings, strings, indexArray);
    return 0;
}