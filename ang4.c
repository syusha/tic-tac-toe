#include "stdio.h"

void sort(char* str, int n)
{
int t=0, p, f;
char temp;
for (int i = n-1; i >=0; i--) {
        for (int j = n-i-1; j >=0, str[j] != '\0'; j--) {
            if (str[j] > str[j - 1]) {
                // ���塞 ������ ���⠬�
                temp = str[j];
                str[j] = str[j - 1];
                str[j - 1] = temp;
            }
        }
        printf("massive - %s\n", str);
	}
/*while(t<n)
{
f=n-1;
for(p=n-t; p>t; p--)
if(str[p]<str[p+1])
{
m=str[p];
str[p]=str[p+1];
str[p+1]=m;
f=p;
}
#ifdef DEBUG_SORT
printf("massive - %s, f=%i\n", str, f);
#endif
t=f;
}*/
}

int check_sort(char* str, int n)
{
int i, f=1;
for(i=0; i<n-1; i++)
if(str[i]>str[i+1]) f=0;
return f;
}

int sravnenie(char* str, char* str2)
{
int i=0,g=0;
while(str[i]&&str2[i])
{
if (str[i]>str2[i]) {g= 1; break;}
else if (str[i]<str2[i]) {g=-1; break;}
i++;
}
return(g); //����頥�: 0 - �᫨ ��ப� ࠢ�� 1 - �᫨ ��ࢠ� ����� ��ன -1 - �᫨ ��ࢠ� ����� ��ன
}
int main()
{
char a[11][10] = {"�������",
"��ᮢ��",
"⥯���",
"⠫�ﭪ�",
"��஡��",
"��⫨�",
"᮫����",
"ࠡ�⪠",
"��⠫��",
"��ࠡ�⪠",
"�������"};
int i;

for(i=0; i<11; i++)
{
printf("test %i\n", i);
printf("massive - %s\n", a[i]);
sort(a[i], 10);
printf("sort - %s\n", a[i]);
if(check_sort(a[i], 10)) printf("test passed\n\n");
else printf("test failed\n\n");
}
}