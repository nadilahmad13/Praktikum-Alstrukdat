// Ahmad Nadil
// 13521024
// file frekuensi.c

#include <stdio.h>

int main()
{
    // variable init
    char str[100];
    int arr[10] = {0,0,0,0,0,0,0,0,0,0};
    int i;
    scanf("%s", str);

    
    // count the length of str
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }

    // loop to count the char in the string
    for (i = 0; i < len; i++)
    {
        if (str[i] == '0')
        {
            arr[0]++;
        }
        if (str[i] == '1')
        {
            arr[1]++;
        }
        else if (str[i] == '2')
        {
            arr[2]++;
        }
        else if (str[i] == '3')
        {
            arr[3]++;
        }
        else if (str[i] == '4')
        {
            arr[4]++;
        }
        else if (str[i] == '5')
        {
            arr[5]++;
        }
        else if (str[i] == '6')
        {
            arr[6]++;
        }
        else if (str[i] == '7')
        {
            arr[7]++;
        }
        else if (str[i] == '8')
        {
            arr[8]++;
        }
        else if (str[i] == '9')
        {
            arr[9]++;
        }
    }

    for (i = 0; i < 10; i++)
    {
        printf("%d", arr[i]);
    }

    printf("\n");

    return 0;
}