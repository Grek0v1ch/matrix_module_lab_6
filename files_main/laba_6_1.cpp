/*
Лабораторная работа номер 6, задание 1.
Автор: Воронов Иван, группа ПМИ-13БО, 24.11.2021
Задание: https://drive.google.com/drive/folders/15yKHeAngX7l9xRRhunCuTFr0ydBLB33W
*/
#include <iostream>
#include "matrix.hpp"

int main() {
	// Переменная хранит размер квадратной матрицы.
	int size_matrix;
	matrix_ptr matrix1 = input_sqr_matrix(size_matrix);

	printf("\nВычисление функции f(A):\n");
	matrix_ptr res1 = function_f(matrix1, size_matrix);
	printf("Значение 2x^2 - x\n");
	output_sqr_matrix(res1, size_matrix);
	printf("\n\n");

	printf("Вычисление функции g(A):\n");
	matrix_ptr res2 = function_g(matrix1, size_matrix);
	printf("Значение 2x^3 - x + 3\n");
	output_sqr_matrix(res2, size_matrix);
	printf("\n\n");

	printf("Значение f(A) + g(A):\n");
	matrix_sum(res1, res2, size_matrix, 1);
	output_sqr_matrix(res1, size_matrix);
	// Добавлены строчки кода
	printf("Привет");
	// [f[f[f[f[f[[ff[]]]]]]]]

	free_sqr_matrix(res1, size_matrix);
	free_sqr_matrix(res2, size_matrix);
	free_sqr_matrix(matrix1, size_matrix);
	return 0;
}
// g++ sourse/*.cpp -I headers -o ../product/laba_6_1 -std=c++14