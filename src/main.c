#include <stdio.h>

#define ROWS 20
#define COLS 40

char canvas[ROWS][COLS];

void initializeCanvas()
{
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            canvas[i][j] = '_';
        }
    }
}

void displayCanvas()
{
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
}
void drawRectangle(int row,int col,int height,int width)
{
    for(int i=col;i<col+width;i++)
    {
        canvas[row][i]='*';
        canvas[row+height-1][i]='*';
    }

    for(int i=row;i<row+height;i++)
    {
        canvas[i][col]='*';
        canvas[i][col+width-1]='*';
    }
}
void drawLine(int row,int startCol,int endCol)
{
    for(int i=startCol;i<=endCol;i++)
    {
        canvas[row][i] = '*';
    }
}
int main()
{
    initializeCanvas();

    drawRectangle(2,5,6,10);
    drawLine(12,5,25);

    displayCanvas();

    return 0;
}
