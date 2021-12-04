#include <cstdio>
#include "chek_io.hpp"

// Функция возвращает введенное пользователем натуральное число в случае корректного ввода.
int one_natur_num_input() {
	int num;
	num = one_int_input();
	while (num <= 0) {
		printf("Некорректный ввод, повторите: ");
		num = one_int_input();
	}
	return num;
}

// Функция возвращает введенное пользователем целое число в случае корректного ввода.
int one_int_input() {
	double num;
	int res = scanf("%lf", &num);
	while (res != 1 or num - static_cast<int>(num) != 0) {
		fflush(stdin);
		printf("Некорректный ввод, повторите: ");
		res = scanf("%lf", &num);
	}
	return static_cast<int>(num);
}

// Функция возвращает введенное пользователем вещественное число в случае корректного ввода.
double one_double_input() {
	double num;
	int res = scanf("%lf", &num);
	while (res != 1) {
		fflush(stdin);
		printf("Некорректный ввод, повторите: ");
		res = scanf("%lf", &num);
	}
	return num;
}