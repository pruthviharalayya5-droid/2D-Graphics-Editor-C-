#include <stdio.h>
#include <math.h>

#define ROWS 20
#define COLS 40

char canvas[ROWS][COLS];
typedef struct
{
    int id;
    int type;
    int row;
    int col;
    int height;
    int width;
    int radius;
    int active;
} Shape;

Shape shapes[100];
int shapeCount = 0;
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
void redrawAll()
{
    initializeCanvas();

    for(int i=0;i<shapeCount;i++)
    {
        if(shapes[i].active)
        {
            if(shapes[i].type == 1)
                drawRectangle(shapes[i].row, shapes[i].col, shapes[i].height, shapes[i].width);

            else if(shapes[i].type == 2)
                drawLine(shapes[i].row, shapes[i].col, shapes[i].width);

            else if(shapes[i].type == 3)
                drawTriangle(shapes[i].row, shapes[i].col, shapes[i].height);

            else if(shapes[i].type == 4)
                drawCircle(shapes[i].row, shapes[i].col, shapes[i].radius);
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
        printf("1. Add Rectangle\n");
        printf("2. Add Line\n");
        printf("3. Add Triangle\n");
        printf("4. Add Circle\n");
        printf("5. Delete Object\n");
        printf("6. Modify Object\n");
        printf("7. Display Canvas\n");
        printf("8. Exit\n");

        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            {
                Shape s;
                s.id = shapeCount;
                s.type = 1;
                s.active = 1;

                printf("Enter row: ");
                scanf("%d",&s.row);

                printf("Enter column: ");
                scanf("%d",&s.col);

                printf("Enter height: ");
                scanf("%d",&s.height);

                printf("Enter width: ");
                scanf("%d",&s.width);

                shapes[shapeCount] = s;
                shapeCount++;

                redrawAll();

                printf("Rectangle added with ID %d\n", s.id);
                break;
            }

            case 2:
{
    Shape s;
    s.id = shapeCount;
    s.type = 2;
    s.active = 1;

    printf("Enter row: ");
    scanf("%d",&s.row);

    printf("Enter start column: ");
    scanf("%d",&s.col);

    printf("Enter end column: ");
    scanf("%d",&s.width);

    shapes[shapeCount] = s;
    shapeCount++;

    redrawAll();

    printf("Line added with ID %d\n", s.id);
    break;
}

           case 3:
{
    Shape s;
    s.id = shapeCount;
    s.type = 3;
    s.active = 1;

    printf("Enter row: ");
    scanf("%d",&s.row);

    printf("Enter column: ");
    scanf("%d",&s.col);

    printf("Enter size: ");
    scanf("%d",&s.height);

    shapes[shapeCount] = s;
    shapeCount++;

    redrawAll();

    printf("Triangle added with ID %d\n", s.id);
    break;
}

          case 4:
{
    Shape s;
    s.id = shapeCount;
    s.type = 4;
    s.active = 1;

    printf("Enter center row: ");
    scanf("%d",&s.row);

    printf("Enter center column: ");
    scanf("%d",&s.col);

    printf("Enter radius: ");
    scanf("%d",&s.radius);

    shapes[shapeCount] = s;
    shapeCount++;

    redrawAll();

    printf("Circle added with ID %d\n", s.id);
    break;
}

            case 5:
{
    int id;

    printf("Enter object ID to delete: ");
    scanf("%d",&id);

    if(id >= 0 && id < shapeCount)
    {
        shapes[id].active = 0;
        redrawAll();
        printf("Object deleted successfully\n");
    }
    else
    {
        printf("Invalid object ID\n");
    }

    break;
}

          case 6:
{
    int id;

    printf("Enter object ID to modify: ");
    scanf("%d",&id);

    if(id >= 0 && id < shapeCount && shapes[id].active)
    {
        printf("Enter new row: ");
        scanf("%d",&shapes[id].row);

        printf("Enter new column: ");
        scanf("%d",&shapes[id].col);

        if(shapes[id].type == 1)
        {
            printf("Enter new height: ");
            scanf("%d",&shapes[id].height);

            printf("Enter new width: ");
            scanf("%d",&shapes[id].width);
        }
        else if(shapes[id].type == 2)
        {
            printf("Enter new end column: ");
            scanf("%d",&shapes[id].width);
        }
        else if(shapes[id].type == 3)
        {
            printf("Enter new size: ");
            scanf("%d",&shapes[id].height);
        }
        else if(shapes[id].type == 4)
        {
            printf("Enter new radius: ");
            scanf("%d",&shapes[id].radius);
        }

        redrawAll();

        printf("Object modified successfully\n");
    }
    else
    {
        printf("Invalid object ID\n");
    }

    break;
}
            case 7:
                displayCanvas();
                break;

            case 8:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
