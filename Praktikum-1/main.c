#include <stdio.h>

int main()
{
    int detik;
    scanf("%d", &detik);
    int jam = detik / 3600;
    int menit = (detik % 3600) / 60;
    int detik2 = (detik % 3600) % 60;
    printf("%d detik = %d jam %d menit %d detik\n", detik, jam, menit, detik2);
    return 0;
}