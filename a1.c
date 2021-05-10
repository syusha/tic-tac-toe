// �㪢� �㦭� ���஢��� �� �뢠���, ��稭�� � ����
// ���ᨢ �����ᮢ (᫮��) �㦭� ���஢��� �� �����⠭��, ��稭�� � ��砫�
// ��ਠ�� 16


#include <stdio.h>
#include <stdbool.h>

#define MAXLENGTH 20
#define WORDS 14
 
 void sort(char** sorted) {
  int i, j, k;
  char temp;

  for (i = 0; i < WORDS; i++) {
   for (j = 0; sorted[i][j] != '\0'; j++) {
    for (k = j + 1; sorted[i][k] != '\0'; k++)
     if (sorted[i][j] > sorted[i][k]) {
      temp = sorted[i][j];
      sorted[i][j] = sorted[i][k];
      sorted[i][k] = temp;
     }
   }
  }
   
  return;
}

int check_sortL(char* str) // проверка сортировки букв в каждой строке
{
    int i, f=1;
    for(i=0; i<MAXLENGTH-1; i++)
    if(str[i]>str[i+1]) f=0;
    return f;
}


int sravnenie(char* str, char* str2) //ф-я сравнения строк
{
int i=0;
while(str[i] != '\0' && str2[i] != '\0' )
    {
        if (str[i] > str2[i])
            return 1;
        else
        if (str[i]<str2[i])
            return -1;
        i++;
    }
    return 0;
}

void ShellSortingWords(char** str, int indexArray[]) {   //сортировка строк в массиве 
    int k;
    int i,j,m;
 
    for(k = WORDS/2; k > 0; k /= 2)
        for(i = k; i < WORDS; i++)
            for(j = i - k; (j >= 0) &&  (sravnenie(str[indexArray[j]], str[indexArray[j+k]]) == 1); j -= k)  {
                m = indexArray[j];
                indexArray[j] = indexArray[j + k];
                indexArray[j + k] = m;
            }
}
 
int CheckSortingWords(char** string, int indexArray[]) {    //проверка сортировки строк (аналогично проверке сортировки букв)
    int i;
    for(i=0; i<9; i++)
        if(sravnenie(string[indexArray[i]], string[indexArray[i+1]]) == 1)
            return 0;
    return 1;
}
 
void FindAnagrams(char** sortedString, char strings[WORDS][MAXLENGTH], int indexArray[WORDS]) { //вывод анаграмм в строку
    for(int i=0; i<WORDS-1; i++) {
        printf(" %s ", strings[indexArray[i]]);
        if(sravnenie(sortedString[indexArray[i]], sortedString[indexArray[i+1]]) != 0)
            printf(" \n ", strings[indexArray[i]]);
    }
    printf(" %s ", strings[indexArray[WORDS-1]]);
}
 
int main() {
    int i,j;
 
    char strings[WORDS][MAXLENGTH] = {  "����",
                                        "�����ᨭ",
                                        "⮢��",
                                        "�⢠�",
                                        "ᯠ�����",
                                        "⠢�",
                                        "����",
                                        "᮫�",
                                        "����",
                                        "���",
                                        "⠡��⪠",
                                        "���",
                                        "⮪",
                                        "⨪"   };
 
    char* sortedStrings[WORDS];
 
    for(i = 0; i<WORDS; i++)
        sortedStrings[i] = strings[i];
 
    sort(sortedStrings);
 
    for(i = 0; i<WORDS; i++) {
        printf("%s\n", sortedStrings[i]);
        if(check_sortL(sortedStrings[i]))
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
    for ( i = 0; i < WORDS-1; i++)
    {
        printf(" %s ", strings[indexArray[i]]);   
    }
    
    return 0;
}