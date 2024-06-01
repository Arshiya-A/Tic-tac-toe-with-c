#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool isGameRuning = true;
int matrix[3][3] = {{0,0,0},{0,0,0}};

int playerScore = 0;
int botScore = 0;
int turn = 9;

void ScoreSystem(bool isPlayer,int column,int row)
{

    for(int i = 0; i < 3 ; i++)
    {
        int sumI = 0;
        int sumJ = 0;
        for(int j = 0 ; j < 3; j++)
        {
            sumI += pow(matrix[i][j],2);
            sumJ += pow(matrix[j][i],2);


            if(isPlayer)
            {
                if(sumI == 3 || sumJ == 3)
                {
                    playerScore++;
                    matrix[i][i] = 3;
                }

            }

            else
            {
                if(sumI == 12 || sumJ == 12)
                {
                    botScore++;
                    matrix[i][i] = 20;
                }
            }

        }

    }

}

bool IsFinishGame()
{
    turn-=2;
    printf("\n");
    printf("%d",turn);
    if(turn <= 0)
    {
        return true;
    }
    return false;
}

bool GroundCheck(int posX,int posY)
{
    if(matrix[posX][posY] != 0)
        return false;
    else
        return true;
}

void WinCheck()
{
    system("cls");
    printf("Game is Finish :)\n");
    printf("Winer is..............\n");

    if(playerScore > botScore)
        printf("Player");

    if(playerScore < botScore)
        printf("Robot");

    if(playerScore = botScore || playerScore ==0 && botScore ==0)
        printf("Tied");

    printf("\n");
    scanf("%d");
}

void BotSelect()
{
    if(turn != 1)
    {
        int botSelectI = rand() % 3;
        int botSelectJ = rand() % 3;
        while(!GroundCheck(botSelectI,botSelectJ))
        {
            botSelectI = rand() % 3;
            botSelectJ = rand() % 3;
            if(matrix[botSelectI][botSelectJ] == 0)
            {
                matrix[botSelectI][botSelectJ] = 2;
                break;
            }
        }

        matrix[botSelectI][botSelectJ] = 2;
    }

}

void DrawPlayGround()
{
    for(int i = 0; i < 3; i++)
    {
        printf("\n");
        for(int j = 0; j < 3; j++)
        {
            printf("%d",matrix[j][i]);
            printf("\t");
        }
    }

    printf("\n\nPlayer Score :");
    printf("%d",playerScore);
    printf("\nBot Score :");
    printf("%d",botScore);
}


int main()
{
    printf(".............................Tik-Tak Game...........................\n\n");
    printf("Producer : Arshia04\n");

    DrawPlayGround();

    while(isGameRuning)
    {

        printf("\n\n");
        int column = 0;
        printf("Enter Column : ");
        scanf("%d",&column);

        int row = 0;
        printf("Enter Row : ");
        scanf("%d",&row);
        system("cls");
        switch(matrix[column][row])
        {
        case 1:
            printf("\033[1;31m");
            printf("this ground selected by player before");
            printf("\033[0m");
            DrawPlayGround();
            break;

        case 2:
            printf("\033[1;31m");
            printf("this ground selected by bot before");
            printf("\033[0m");
            DrawPlayGround();
            break;

        default:
            if(GroundCheck(column,row))
            {

                matrix[column][row] = 1;
                BotSelect();
                ScoreSystem(true,column,row);
                ScoreSystem(false,column,row);
                DrawPlayGround();
                if(IsFinishGame())
                {
                    isGameRuning = false;
                }
            }
            break;
        }

    }

    WinCheck();


    return 0;
}
