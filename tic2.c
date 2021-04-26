#include <stdio.h>
#include <stdlib.h>
#define LINE printf("+-----+-----+-----+ \n")
char board[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
void drawboard();
int checkwinner();
int main()
{
    int player = 1, i, choice;
    char move;
    do
        {
        drawboard();
        player = (player % 2) ? 1 : 2; 
        printf("\nPlay %d, enter your go: ", player);
        scanf("%d", &choice);
        move = (player==1) ? 'X': '0';
           if (choice == 1 && board[1] == '1')
            board[1] = move;
           else if (choice == 2 && board[2] == '2')
            board[2] = move;
           else if (choice == 3 && board[3] == '3')
            board[3] = move;
           else if (choice == 4 && board[4] == '4')
            board[4] = move;
           else if (choice == 5 && board[5] == '5')
            board[5] = move;
           else if (choice == 6 && board[6] == '6')
            board[6] = move;
           else if (choice == 7 && board[7] == '7')
            board[7] = move;
           else if (choice == 8 && board[8] == '8')
            board[8] = move;
           else if (choice == 9 && board[9] == '9')
            board[9] = move;
          else 
           {
                printf(" Error ");
                player--;
           }
           i = checkwinner();
           player++;
        } 
    while (i == -1);
    drawboard();
    if (i == 1)
    {
        printf(" Player %d win!\n ", --player);
    }
    else 
    printf(" Game draw :(\n");
    return 0;
}
void drawboard()
{
    system("cls");
    printf("....Game Tic Tac Toe....\n");
    printf("Player 1 (X) --- Player 2 (O)\n\n");
    printf("\n\n");
    LINE;
    printf("|  %c  |  %c  |  %c  |\n", board[1], board[2], board[3]);
    LINE;    
    printf("|  %c  |  %c  |  %c  |\n", board[4], board[5], board[6]);    
    LINE;    
    printf("|  %c  |  %c  |  %c  |\n", board[7], board[8], board[9]);    
    LINE;                
}
int checkwinner()
{
    if (board[1] == board[2] && board[2] == board[3])
    return 1;
    else if (board[4] == board[5] && board[5] == board[6])
    return 1;
    else if (board[7] == board[8] && board[8] == board[9])
    return 1;
    else if (board[1] == board[4] && board[4] == board[7])
    return 1;
    else if (board[2] == board[5] && board[5] == board[8])
    return 1;
    else if (board[3] == board[6] && board[6] == board[9])
    return 1;
    else if (board[1] == board[5] && board[5] == board[9])
    return 1;
    else if (board[3] == board[5] && board[5] == board[7])
    return 1;
    else if (board[1] != '1' && board[2] != '2' && board[3] != '3' && 
            board[4] != '4' && board[5] != '5' && board[6] != '6' && 
            board[7] != '7' && board[8] != '8' && board[9] != '9')
        return 0;
    else 
        return -1;
}