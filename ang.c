// буквы нужно сортировать по убыванию, начиная с конца
// массив индексов (слова) нужно сортировать по возрастанию, начиная с начала
// Вариант 16

#include <stdio.h>
#include <stdbool.h>
#define MAXLENGTH 20
#define SIZE 20
void sortB(char mas[MAXLENGTH][SIZE])
{	
	char c;
    int i, j, k;
	for (i = 0; i < SIZE ; i++)
	{
		for(j=0; mas[i][j] != '\0'; j++)
		{	
            for(k = j + 1 ; mas[i][j] != '\0'; k++)
		{	
       printf("%s\n", mas[i][j]);
        printf("%s\n", mas[i][k]);
			if(mas[i][j] > mas[i][k])
			{				
				c = mas[i][j];
				mas[i][j] = mas[i][k];
				mas[i][k] = c;
			}
		}
        }
        return;
	}
}

/*bool strEq(char a[MAXLENGTH], char b[MAXLENGTH]) {
  int i;
  for (i = 0; i < MAXLENGTH; i++) {
   if (a[i] != b[i]) return false;
   else if (a[i] == '\0') return true;
  }
}

void anagr(char mas[SIZE][MAXLENGTH], char *words[]) {
  char *pw;
  int i, j;
  bool checked[SIZE] = {false}, ep = false, eq = false;

  for (i = 0; i < SIZE - 1; i++) {
   if (checked[i]) continue;
   checked[i] = true;
    
   for (j = i + 1; j < SIZE; j++) {
    if (checked[j]) continue;
    ep = strEq(mas[i], mas[j]);
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

}*/
int main (void) 
{
  char *words[SIZE] = 
  {
   "кот",
   "ток",
   "кран",
   "клоун",
   "кора",
   "уклон",
   "рок",
   "колесо",
   "леска",
   "осока",
   "трава",
   "сор",
   "отвар",
   "кит",
   "тик",
   "товар",
   "лось",
   "отвар",
   "автор",
   "соль"
  };
   /*for (int i = 0; i < SIZE; i++)
  {
    printf("%s\n", words[i]);
  }
  */
  char mas[SIZE][MAXLENGTH];
  int i,k,f;
  char *j;

  for (i = 0; i < SIZE; i++) {
   for (j = words[i], k = 0; *j != '\0', k < MAXLENGTH; j++, k++)
    mas[i][k] = *j;
     printf("%s\n", mas[i][k]);
  }
  sortB(mas);
  /*for (int i = 0; i < SIZE; i++)
  {
  for (j , f = 0; *j != '\0', f < MAXLENGTH; j++, f++)
  {
    printf("%s\n", mas[i][f]);
  }
  }*/
  /*anagr(mas, words);*/
  return 0;
}