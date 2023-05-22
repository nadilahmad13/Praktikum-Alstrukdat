// NIM              : 13521024
// Nama             : Ahmad Nadil
// Tanggal          : 17 November 2022
// Topik praktikum  : Queue dan Stack dengan struktur berkait
// Deskripsi        : File "parserkurung.c"

#include <stdio.h>
#include "charmachine.h"
#include "stacklinked.h"
#include "boolean.h"

int main() {
	Stack S;
	ElType val;
	boolean valid = true;
	CreateStack(&S);
	int count0 = 0;
	int count1 = 0;
	int count2 = 0;
	int count3 = 0;
	int count4 = 0;
	int len = 0;
	int max = 0;
	char currentChar;
	scanf("%c", &currentChar);
	while (currentChar != '.') {
		if (currentChar == '[') {
			push(&S, 0);
			len++;
			DisplayStack(S);
			printf("\n");
			count0++;
		} 
        else if (currentChar == ']') {
			if (!isEmpty(S) && TOP(S) == 0){
				pop(&S, &val);
				len--;
			} 
            else {
				valid = false;
			}
			DisplayStack(S);
			printf("\n");
		} 
        else if (currentChar == '(') {
			push(&S, 1);
			len++;
			DisplayStack(S);
			printf("\n");
			count1++;
		} 
        else if (currentChar == ')') {
			if (!isEmpty(S) && TOP(S) == 1) {
				pop(&S, &val);
				len--;
			} 
            else {
				valid = false;	
			}
			DisplayStack(S);
			printf("\n");
		} 
        else if (currentChar == '|' && (isEmpty(S) || TOP(S) != 2)) {
			push(&S, 2);
			len++;
			DisplayStack(S);
			printf("\n");
			count2++;
		} 
        else if (currentChar == '|' && !isEmpty(S) && TOP(S) == 2) {
			pop(&S, &val);
			len--;
			DisplayStack(S);
			printf("\n");
		} 
        else if (currentChar == '{') {
			push(&S, 3);
			len++;
			DisplayStack(S);
			printf("\n");
			count3++;
		} 
        else if (currentChar == '}') {
			if (!isEmpty(S) && TOP(S) == 3){
				pop(&S, &val);
				len--;
			} 
            else {
				valid = false;
			}
			DisplayStack(S);
			printf("\n");
		} 
        else if (currentChar == '<') {
			push(&S, 4);
			len++;
			DisplayStack(S);
			printf("\n");
			count4++;
		} 
        else if (currentChar == '>') {
			if (!isEmpty(S) && TOP(S) == 4){
				pop(&S, &val);
				len--;
			} 
            else {
				valid = false;
			}
			DisplayStack(S);
			printf("\n");
		}
		if (len > max) {
            max = len;
        }
		scanf("%c", &currentChar);
	}
	if (!valid || !isEmpty(S)) {
		printf("kurung tidak valid\n");
	} 
    else {
		printf("kurung valid\n");
		printf("[%d] (%d) |%d| {%d} <%d>\n", count0, count1, count2, count3, count4);
		printf("MAX %d\n", max);
	}
	return 0;
}