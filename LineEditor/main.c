#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define UP 72
#define DOWN 80
#define RIGHT 77
#define LEFT 75
#define ENTER 13
#define BACK 8
#define ESC 27
#define HOME 71
#define END 79
#define DELETE 83
#define INSERT 82
#define WHITE 14
#define EXTENDED -32

void gotoxy(int x, int y)
{
    COORD coord = {0, 0};
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main()
{
    char line[100] = {0};
    char c = 'a';
    int size = 0;
    int position = 5;
    int insertMode = 0;

    gotoxy(0,0);
    printf("-------------------Line Editor-----------------");

    while (1)
    {
        gotoxy(position, 1);
        c = getch();

        if (c == EXTENDED)
        {
            c = getch();
        }

        switch (c)
        {
        case LEFT:
            if (position > 5)
                position--;
            break;

        case RIGHT:
            if (position < size + 5)
                position++;
            break;

        case HOME:
            position = 5;
            break;

        case END:
            position = size + 5;
            break;

        case BACK:
            if (position > 5)
            {

                for (int i = position - 5 - 1; i < size - 1; i++)
                {
                    line[i] = line[i + 1];
                }
                line[size - 1] = '\0';
                size--;
                position--;

                gotoxy(5, 1);
                printf("                                                                                           ");

                gotoxy(5, 1);
                printf("%s", line);
            }
            break;

        case DELETE:
            if (position - 5 < size)
            {
                for (int i = position - 5; i < size; i++)
                {
                    line[i] = line[i + 1];
                }
                size--;
                gotoxy(5, 1);
                printf("                    ");
                gotoxy(5, 1);
                printf("%s", line);
            }
            break;

        case ENTER:
            gotoxy(5, 3);
            printf("Entered text: %s", line);
            memset(line, 0, sizeof(line));
            size = 0;
            position = 5;
            gotoxy(5, 1);
            printf("                    ");
            break;

        case ESC:
            exit(0);

        case INSERT:
            insertMode = !insertMode;
            gotoxy(5, 2);
            if (insertMode)
                printf("Insert Mode: ON ");
            else
                printf("Insert Mode: OFF");
            break;

        default:
            if (position - 5 < 100 && size < 99 && c >= 32 && c <= 126) // Allow up to 100 characters
            {

                for (int i = size; i >= position - 5; i--)
                {
                    line[i + 1] = line[i];
                }
                line[position - 5] = c;
                size++;
                position++;
                gotoxy(5, 1);
                printf("                                                                     ");
                gotoxy(5, 1);
                printf("%s", line);
            }
            break;
        }
    }

    return 0;
}
