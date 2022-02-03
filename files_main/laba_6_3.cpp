/*
Лабораторная работа номер 6, задание 1.
Автор: Воронов Иван, группа ПМИ-13БО, 24.11.2021
Задание: https://drive.google.com/drive/folders/15yKHeAngX7l9xRRhunCuTFr0ydBLB33W
*/
#include <iostream>
#include <cstdio>
#include "matrix.hpp"

int main() {
	int size_matrix;
	printf("Программа находит решение уравнения А*X - 3*X = B\n"
		   "Матрицы А и В должны быть квадратными и одинакового размера!\n");
	matrix_ptr matrix_A = input_sqr_matrix(size_matrix);
	matrix_ptr matrix_B = input_sqr_matrix(size_matrix);
	// Дальше находим неизвестную матрицу Х = (A - 3 * E)^-1 * B.
	// Создаются две матрицы для хранения промежуточных вычислений.
	matrix_ptr buff1 = create_sqr_unit_matrix(size_matrix);
	matrix_ptr buff2 = create_sqr_matrix(size_matrix);
	// Записываем свободный член.
	matrix_multip_by_number(buff1, 3.0, size_matrix);
	copy_sqr_matrix(buff2, matrix_A, size_matrix);
	// Считаем разность матрицы А и свободного члена.
	matrix_sum(buff2, buff1, size_matrix, -1);
	// Находим обратную матрицу.
	bool is_inverse_matrix = inverse_matrix(buff1, buff2, size_matrix);
	if (not is_inverse_matrix)
		printf("Нет решений\n");
	else {
		// Находим матрицу Х.
		matrix_multip(buff1, matrix_B, size_matrix);
		printf("Матрица Х равна:\n");
		output_sqr_matrix(buff1, size_matrix);
	}
	free_sqr_matrix(matrix_A, size_matrix);
	free_sqr_matrix(matrix_B, size_matrix);
	free_sqr_matrix(buff1, size_matrix);
	free_sqr_matrix(buff2, size_matrix);
	return 0;
}

// g++ source/*.cpp -I headers -o ../product/laba_6_3 -Wall