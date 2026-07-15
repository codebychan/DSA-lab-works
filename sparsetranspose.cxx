//transpose
#include <stdio.h>

struct sparse
{
    int row;
    int col;
    int value;
};

int main()
{
    struct sparse A[20], T[20];
    int i, j, k = 1;

    printf("Enter rows, columns and number of non-zero elements: ");
    scanf("%d%d%d", &A[0].row, &A[0].col, &A[0].value);

    printf("Enter row column value:\n");
    for(i = 1; i <= A[0].value; i++)
        scanf("%d%d%d", &A[i].row, &A[i].col, &A[i].value);

  
    T[0].row = A[0].col;
    T[0].col = A[0].row;
    T[0].value = A[0].value;

  
    for(i = 0; i < A[0].col; i++)
    {
        for(j = 1; j <= A[0].value; j++)
        {
            if(A[j].col == i)
            {
                T[k].row = A[j].col;
                T[k].col = A[j].row;
                T[k].value = A[j].value;
                k++;
            }
        }
    }

    printf("\nTranspose Matrix:\n");
    printf("Row Col Value\n");

    for(i = 0; i <= T[0].value; i++)
        printf("%d %d %d\n", T[i].row, T[i].col, T[i].value);

    return 0;
}