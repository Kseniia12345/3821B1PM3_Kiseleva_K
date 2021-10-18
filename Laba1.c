#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main()
{	setlocale(LC_ALL, "Rus");
	double n = 0.0, max = 0.0, min = 0.0, c = 0.0, sum = 0.0;
	double* mas;
	int* mass;
	printf("Введите количество значений ");
	scanf_s("%lf", &n);

	if (n <= 0) //проверка n
	{
		printf("Ошибка! Kоличество значений <=0");
		return 0;
	}

	printf("Введите значение min ");
	scanf_s("%lf", &min);
	printf("Введите значение max ");
	scanf_s("%lf", &max);

	if (min > max) //проверка max и min
	{
		printf("Ошибка! min>max \n");
		return 0;
	}

	mas = (double*)malloc(n * sizeof(double)); //создание массива
	mass = (int*)malloc(n * sizeof(int));
	if (mas == 0) //проверка создался ли массив
	{
		printf("Ошибка! Hе удалось создать массив \n");
		return 0;
	}

	if (mass == 0) //проверка создался ли массив
	{
		printf("Ошибка! Hе удалось создать массив \n");
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		mas[i] = rand();
		mas[i] = (mas[i] / RAND_MAX) * (max - min) + min;
	}
	for (int i = 0; i < n; i++)
	{
		mass[i] = ((mas[i] - (int) mas[i])*1000000);
		while (mass[i] % 10 == 0)
			mass[i] = mass[i] / 10;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == mass[j])
			{
				sum = sum - mas[i];
				mas[j] = 0.0;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		sum = sum + mas[i];
	}
	
	printf("sum = %lf", sum);

	free(mass);
	free(mas);
	return 0;
}