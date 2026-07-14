//addition of two sparse matrix
#include <stdio.h>

struct sparse
{
    int row;
    int col;
    int value;
};

int main()
{
    struct sparse A[20], B[20], SUM[40];
    int i = 1, j = 1, k = 1;

    printf("Enter rows, columns and number of non-zero elements of Matrix A: ");
    scanf("%d%d%d", &A[0].row, &A[0].col, &A[0].value);

    printf("Enter row column value of Matrix A:\n");
    for (i = 1; i <= A[0].value; i++)
        scanf("%d%d%d", &A[i].row, &A[i].col, &A[i].value);

    printf("Enter rows, columns and number of non-zero elements of Matrix B: ");
    scanf("%d%d%d", &B[0].row, &B[0].col, &B[0].value);

    printf("Enter row column value of Matrix B:\n");
    for (i = 1; i <= B[0].value; i++)
        scanf("%d%d%d", &B[i].row, &B[i].col, &B[i].value);

    if (A[0].row != B[0].row || A[0].col != B[0].col)
    {
        printf("Matrices cannot be added");
        return 0;
    }

    SUM[0].row = A[0].row;
    SUM[0].col = A[0].col;

    i = 1;
    j = 1;
    k = 1;

    while (i <= A[0].value && j <= B[0].value)
    {
        if (A[i].row < B[j].row ||
           (A[i].row == B[j].row && A[i].col < B[j].col))
        {
            SUM[k++] = A[i++];
        }
        else if (A[i].row > B[j].row ||
                (A[i].row == B[j].row && A[i].col > B[j].col))
        {
            SUM[k++] = B[j++];
        }
        else
        {
            SUM[k].row = A[i].row;
            SUM[k].col = A[i].col;
            SUM[k].value = A[i].value + B[j].value;

            if (SUM[k].value != 0)
                k++;

            i++;
            j++;
        }
    }

    while (i <= A[0].value)
        SUM[k++] = A[i++];

    while (j <= B[0].value)
        SUM[k++] = B[j++];

    SUM[0].value = k - 1;

    printf("\nResultant Sparse Matrix:\n");
    printf("Row Col Value\n");

    for (i = 0; i <= SUM[0].value; i++)
        printf("%d %d %d\n", SUM[i].row, SUM[i].col, SUM[i].value);

    return 0;
}
