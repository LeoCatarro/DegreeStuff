#include <stdio.h>

void ordena(int *a, int *b, int *c)
{   
    
    int max = *a;       //Consider a as max!
    int temp;

    //Check Max
    if(*b > max)
        max = *b;
    
    if(*c > max)
        max = *c;
    

    //Check others
    if(max == *a)
    {
        //A > C > B
        if(*b < *c) 
        {
            temp = *b;
            *b = *c;
            *c = temp;
        }

        //A > B >C
        if(*b > *c)
            //Ordenado logo de inicio!
            return;
    }

    if(max == *b)
    {
        if(*a > *c)
        {
            temp = *a;
            *a = *b;
            *b = temp;
        }

        if(*a < *c)
        {
            temp = *a;
            *a = *b;
            *b = *c;
            *c = temp;
        }
    }

    if(max == *c)
    {
        if(*a > *b)
        {
            temp = *a;
            *a = *c;
            *c = *b;
            *b = temp;
        }

        //*a < *b
        if(*a < *b)
        {
            temp = *a;
            *a = *c;
            *c = temp;

        }
    }
}   

int main() 
{
    int n1, n2, n3;

    printf("Insira os valores a ordenar: ");
    scanf("%d %d %d", &n1, &n2, &n3);
    
    ordena(&n1, &n2, &n3);

    printf("Valores a, b, c ordenados por ordem decrescente: %d %d %d\n", n1, n2, n3);

    return 0;
}