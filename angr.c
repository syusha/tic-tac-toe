#include <stdio.h>
#include <stdbool.h>
#define MAXLENGTH 20
#define SIZE 14

void sort (char sorted[SIZE][MAXLENGTH]) {
  int i, j, k;
  char temp;

  for (i = 0; i < SIZE; i++) {
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

bool strEq (char a[MAXLENGTH], char b[MAXLENGTH]) {
  int i;
  for (i = 0; i < MAXLENGTH; i++) {
   if (a[i] != b[i]) return false;
   else if (a[i] == '\0') return true;
  }
}

void anagr (char sorted[SIZE][MAXLENGTH], char *words[]) {
  char *pw;
  int i, j;
  bool checked[SIZE] = {false}, ep = false, eq = false;

  for (i = 0; i < SIZE - 1; i++) {
   if (checked[i]) continue;
   checked[i] = true;
    
   for (j = i + 1; j < SIZE; j++) {
    if (checked[j]) continue;
    ep = strEq(sorted[i], sorted[j]);
    if (ep) {
     eq = true;
     printf("%s ", words[j]);
     checked[j] = true;
    }
   }
   if (eq) printf("%s\n", words[i]);
   eq = false;
  }

  return;
}

int main (void) {
  char *words[SIZE] ={  "автор",
                                        "апельсин",
                                        "товар",
                                        "отвар",
                                        "спаниель",
                                        "тавро",
                                        "моль",
                                        "соль",
                                        "лось",
                                        "кот",
                                        "табуретка",
                                        "кит",
                                        "ток",
                                        "тик"   };
  char sorted[SIZE][MAXLENGTH];
  int i,k;
  char *j;

  for (i = 0; i < SIZE; i++) {
   for (j = words[i], k = 0; *j != '\0', k < MAXLENGTH; j++, k++)
    sorted[i][k] = *j;
  }
  sort(sorted);
  anagr(sorted, words);
   
  return 0;
}
