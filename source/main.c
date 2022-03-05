// 1. Программа запрашивает у пользователя число N. 
//    Затем генерирует строку из случайных символов длиной N. 
//    Случайные символы в данном случае - это любые символы латинского алфавита 
//    (кроме символов 'C', 'P', 'S' и 'X' - т.е. этих символов в строке быть не должно), цифры, а также символы '+', '-', '_', '$' и '~'. 
//    Сгенерированная строка выводится на экран.
// 2. Далее программа запрашивает у пользователя один символ.
//    Заменяет все буквы в сгенерированной на шаге 1 строке на этот символ.
// 3. Запрашивает второй символ.
//    Заменяет все цифры в сгенерированной на шаге 2 строке на второй символ.
//    Выводит получившуюся строку.
// 4. Выводит количество повторов первого символа, количество повторов второго символа, а также количество символов, которые не были заменены.

#include <ctype.h>
#include <stdio.h>
#include <time.h>

void fill(char* S, int N)
{
	char alphabet[] = "ABDEFGHIJKLMNOQRTUVWYZabdefghijklmnoqrtuvwyz0123456789+-_$~";
	int alphabet_length = 59;

	srand(time(NULL));
	for (int i = 0; i < N; i++)
	{
		int r = rand() % alphabet_length;
		S[i] = alphabet[r];
	}
}

int replace_a(char* S, int N, char C)
{
	int counter = 0;

	for (int i = 0; i < N; i++)
	{
		if (isalpha(S[i]))
		{
			S[i] = C;
			counter++;
		}
			
	}

	return counter;
}

int replace_d(char* S, int N, char C)
{
	int counter = 0;

	for (int i = 0; i < N; i++)
	{
		if (isdigit(S[i]))
		{
			S[i] = C;
			counter++;
		}

	}

	return counter;
}

int main()
{
	int N;
	printf("Enter number N: ");
	scanf("%d", &N);
	
	char* S = malloc(N * sizeof(char));
	fill(S, N);
	printf("Generated string: %.*s\n", N, S);

	char C1;
	printf("Enter symbol C1: ");
	scanf(" %c", &C1);
	
	char C2;
	printf("Enter symbol C2: ");
	scanf(" %c", &C2);


	int R1 = replace_a(S, N, C1);
	int R2 = replace_d(S, N, C2);
	int NR = N - (R1 + R2);
	printf("Modified string: %.*s\n", N, S);
	printf("Repeat count R1: %d\n", R1);
	printf("Repeat count R2: %d\n", R2);
	printf("Non-replaced count NR: %d\n", NR);
}
