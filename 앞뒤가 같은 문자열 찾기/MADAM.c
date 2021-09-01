#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100
#define TRUE 1
#define FALSE 0

typedef int element;

typedef struct {
	element data[MAX];
	int top;
}Stacktype;

// 스택 초기화 함수
void init_stack(Stacktype* s)
{
	s->top = -1;
}

//공백 상태 검출 함수
int is_empty(Stacktype* s)
{
	return (s->top == -1);
}

//포화 상태 검출 함수
int is_full(Stacktype * s)
{
	return (s->top == (MAX - 1));
}

//삽입함수
void push(Stacktype * s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->data[++(s->top)] = item;
}
//삭제 함수
element pop(Stacktype * s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}
//피크 함수
element peek(Stacktype * s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[s->top];
}

int check(char palindrome[]) {

	Stacktype sent;
	
	int i = 0;
	char ch_in, ch_out;
	int length = 0;
	
	init_stack(&sent);
	length = strlen(palindrome);

	for (i = 0; i < length; i++) {
		ch_in = palindrome[i];
		if (ch_in == ' ' || ch_in == ',') continue;
			ch_in = tolower(ch_in);
			push(&sent,ch_in);
	}
	for (i = 0; i < length; i++) {
		ch_in = palindrome[i];
		if (ch_in == ' ' || ch_in == ',') continue;
		ch_in = tolower(ch_in);
		ch_out = pop(&sent);
		if (ch_in != ch_out) return FALSE;
	}
	return TRUE;
}

int main() {
	
	char sentence[MAX];
	int end = 0;

	printf("원하는 영어단어를 입력하세요.\n");
	scanf_s("%s",&sentence,MAX);

	end = check(sentence);

	if (end != TRUE) {
		printf("회문이아닙니다.\n");
	}
	else {
		printf("회문입니다.\n");
	}
}