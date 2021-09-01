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

// ���� �ʱ�ȭ �Լ�
void init_stack(Stacktype* s)
{
	s->top = -1;
}

//���� ���� ���� �Լ�
int is_empty(Stacktype* s)
{
	return (s->top == -1);
}

//��ȭ ���� ���� �Լ�
int is_full(Stacktype * s)
{
	return (s->top == (MAX - 1));
}

//�����Լ�
void push(Stacktype * s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else s->data[++(s->top)] = item;
}
//���� �Լ�
element pop(Stacktype * s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}
//��ũ �Լ�
element peek(Stacktype * s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
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

	printf("���ϴ� ����ܾ �Է��ϼ���.\n");
	scanf_s("%s",&sentence,MAX);

	end = check(sentence);

	if (end != TRUE) {
		printf("ȸ���̾ƴմϴ�.\n");
	}
	else {
		printf("ȸ���Դϴ�.\n");
	}
}