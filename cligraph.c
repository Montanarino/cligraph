#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define cs 51

int main(int argc, char *argv[])
{
    float m = atof(argv[1]);
    int y, l, len2, calc = 1, s;
    char ar[cs][cs];
    //Changing console text color
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    //Cleaning the array
    for (int i = 1; i < cs; i++)
    {
        for (int j = 1; j < cs; j++)
        {
            ar[i][j] = 32;
        }
    }
    //Populating the array
    for (int x = 1; x < cs; x++)
    {
        if (m * x <= cs)
        {
            y = round(m * x);
            ar[y][x] = 43;
        }
    }
    //Calculating total length
    for (l = 0; calc > 0; l++)
    {
        calc = cs / pow(10, l);
    }
    //Printing the graphic
    for (int i = (cs - 1); i > 0; i--)
    {
        calc = 1;
        //Calculating the number of spaces needed
        for (len2 = 0; calc > 0; len2++)
        {
            calc = i / pow(10, len2);
        }
        s = l - len2;
        //Printing ordinate number
        printf("%d", i);
        //Printing spaces
        for (int n = s; n > 0; n--)
        {
            printf(" ");
        }
        printf("-");
        for (int j = 1; j < cs; j++)
        {
            printf("%c ", ar[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < l; i++)
    {
        printf(" ");
    }
    for (int i = 0; i < cs; i++)
    {
        printf("| ");
    }
    //Set console text color back to normal
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
    return 0;
}
