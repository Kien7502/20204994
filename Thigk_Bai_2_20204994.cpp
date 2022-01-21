#include <stdio.h>
#include <iostream>
#include <string>

#define MAX 200

struct Stack{
	float DATA[MAX];
	int TOP;
};

void init(Stack *S){
	S->TOP = -1;
}

int isEmpty(Stack *S){
	return S->TOP == -1 ? 1 : 0;
}

void Push(struct Stack* S, float item){
		++S->TOP;
		S->DATA[S->TOP] = item;
}

int top(Stack *S){
	return (S->DATA[S->TOP]);
}

float Pop(struct Stack* S){
	float ret = -1;
	ret = S->DATA[S->TOP];
	--S->TOP;
	return ret;
}

int Pre(char x){
	if (x == '(')
		return 0;
	if (x == '+' || x == '-')
		return 1;
	if (x == '*' || x == '/' || x == '%')
		return 2;
	return 3;
}

void Trungto_Sang_Hauto(char A[], char B[]){
	Stack S;
	char x, token;
	int i = 0, j = 0;
	init(&S);
	for (i = 0; A[i] != '\0'; i++){
		token = A[i];
		if (isalnum(token)){
			B[j] = token;
			j++;
		}
		else{
			if (token == '('){
				Push(&S, '(');
			}
			else{
				if (token == ')'){
					while ((x = Pop(&S)) != '(')
						B[j] = x;
						j++;
				}
				else{
					while (Pre(token) <= Pre(top(&S)) && !isEmpty(&S))
					{
						x = Pop(&S);
						B[j] = x;
						j++;
					}
					Push(&S, token);
				}
			}
		}
	}

	while (!isEmpty(&S)){
		x = Pop(&S);
		B[j] = x;
		j++;
	}
	B[j] = '\0';
}

float Gia_tri(char *B)
{
	struct Stack S;
	char *p;
	float op1, op2, result;
	S.TOP = -1; 
	p = &B[0];
	while (*p != '\0'){
		while (*p == ' ' || *p == '\t')
		{
			p++;
		}
		if (isdigit(*p)){
			int num = 0;
			while (isdigit(*p))
			{
				num = num * 10 + *p - 48;
				*p++;
			}
			Push(&S, num);
		}
		else{
			op1 = Pop(&S);
			op2 = Pop(&S);
			switch (*p)
			{
			case '+':
				result = op2 + op1;
				break;
			case '-':
				result = op2 - op1;
				break;
			case '/':
				result = op2 / op1;
				break;
			case '*':
				result = op2 * op1;
				break;
			default:
				printf("\nCo mot ky tu khong hop le");
				return 0;
			}
			Push(&S, result);
		}
		p++;
	}
	result = Pop(&S);
	return result;
}

int main(){
	char A[MAX], B[MAX];
	int dk = 1;
	while (dk == 1) {
		printf("\nMenu:\n1. Chuyen tu trung to sang hau to.\n2. Tinh gia tri cua bieu thuc trung to\n3.Thoat chuong trinh\nNhap(1,2,3)de chon: ");
		int choose;
		scanf("%d", &choose);
		printf("\n");
		if (choose == 1) {
			printf("*Luu y: Cac ky tu va chu so phai cach nhau 1 dau cach*\nBieu thuc trung to : ");
			fflush(stdin);
			gets(A);
			Trungto_Sang_Hauto(A, B);
			printf("Bieu thuc hau to la: %s\n", B);
		}
		else if (choose == 2) {
			fflush(stdin);
			printf("*Luu y: Cac ky tu va chu so phai cach nhau 1 dau cach*\nBieu thuc trung to : ");
			gets(A);
			Trungto_Sang_Hauto(A, B);			
			printf("Gia tri cua bieu thuc tren la: %f\n", Gia_tri(&B[0]));
			gets(A);
		}
		else if (choose == 3) {
			printf("\nNhan mot phim bat ky de thoat chuong trinh.");
			dk = 0;
		}
		else {
			printf("*So ban chon phai tu (1-3)*\n   *Vui long nhap lai*\n\n");
		};
	};
	return 0;
}
