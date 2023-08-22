#include <stdio.h>
#include <string.h>

int main()
{
    char str[10];
    int angka[10] = {0,0,0,0,0,0,0,0,0,0};
    int i;

    scanf("%s",str);

    for (i = 0 ; i < strlen(str) ; i++)
    {
        if (str[i] >= 48 && str[i] <= 57)
        {
            angka[str[i] - 48]++;
        }
    }

    for (i = 0 ; i < 10 ; i++)
    {
        printf("%d",angka[i]);
    }

    printf("\n");

    return 0;

}