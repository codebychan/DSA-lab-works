//addition of sparse polynomial`~
#include <stdio.h>

struct Poly
{
    int coeff;
    int exp;
};

int main()
{
    int n, m, i = 0, j = 0, k = 0;
    struct Poly P1[20], P2[20], P3[40];

    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n);

    printf("Enter coefficient and exponent:\n");
    for(i = 0; i < n; i++)
        scanf("%d%d", &P1[i].coeff, &P1[i].exp);

    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &m);

    printf("Enter coefficient and exponent:\n");
    for(i = 0; i < m; i++)
        scanf("%d%d", &P2[i].coeff, &P2[i].exp);

    i = j = k = 0;

    while(i < n)
    {
        if(j < m)
        {
            if(P1[i].exp == P2[j].exp)
            {
                P3[k].coeff = P1[i].coeff + P2[j].coeff;
                P3[k].exp = P1[i].exp;
                k++;
                i++;
                j++;
            }
            else if(P1[i].exp > P2[j].exp)
            {
                P3[k].coeff = P1[i].coeff;
                P3[k].exp = P1[i].exp;
                k++;
                i++;
            }
            else
            {
                P3[k].coeff = P2[j].coeff;
                P3[k].exp = P2[j].exp;
                k++;
                j++;
            }
        }
        else
        {
            P3[k].coeff = P1[i].coeff;
            P3[k].exp = P1[i].exp;
            k++;
            i++;
        }
    }

    while(j < m)
    {
        P3[k].coeff = P2[j].coeff;
        P3[k].exp = P2[j].exp;
        k++;
        j++;
    }

    printf("\nResultant Polynomial:\n");
    for(i = 0; i < k; i++)
    {
        printf("%dx^%d", P3[i].coeff, P3[i].exp);
        if(i != k - 1)
            printf(" + ");
    }

    return 0;
}