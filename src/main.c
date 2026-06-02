#include <stdio.h>
#include <math.h>

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
void drawTriangle(int row,int col,int size)
{
    for(int i=0;i<size;i++)
    {
        canvas[row+i][col-i] = '*';
        canvas[row+i][col+i] = '*';
    }

    for(int i=col-size;i<=col+size;i++)
    {
        canvas[row+size][i] = '*';
    }
}
void drawCircle(int xc,int yc,int r)
{
    for(int angle=0;angle<360;angle++)
    {
        double rad = angle * 3.14159 / 180.0;

        int x = xc + r * cos(rad);
        int y = yc + r * sin(rad);

        if(x>=0 && x<ROWS && y>=0 && y<COLS)
        {
            canvas[x][y] = '*';
        }
    }
}
int main()
{
    int choice;

    initializeCanvas();

    while(1)
    {
        printf("\n===== 2D GRAPHICS EDITOR =====\n");
        printf("1. Draw Rectangle\n");
        printf("2. Draw Line\n");
        printf("3. Draw Triangle\n");
        printf("4. Draw Circle\n");
        printf("5. Display Canvas\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                drawRectangle(2,5,6,10);
                break;

            case 2:
                drawLine(12,5,25);
                break;

            case 3:
                drawTriangle(5,30,5);
                break;

            case 4:
                drawCircle(14,30,4);
                break;

            case 5:
                displayCanvas();
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
