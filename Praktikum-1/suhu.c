#include <stdio.h>

int main(){
    float t;
    char k;

    printf("Masukkan suhu dalam derajat celsius: ");
    scanf("%f", &t);
    printf("\n");
    printf("Masukkan karakter (R/F/K): ");
    scanf("%s", &k);
    printf("\n");

    if (k == 'R'){
        printf("Suhu dalam derajat reamur adalah %.2f", t*4/5);
    }
    else if (k == 'F'){
        printf("Suhu dalam derajat fahrenheit adalah %.2f", t*9/5+32);
    }
    else if (k == 'K'){
        printf("Suhu dalam derajat kelvin adalah %.2f", t+273.15);
    }
    else{
        printf("Karakter yang anda masukkan salah");
    }

}