/*
Лабораторная работа номер 6, задание 1.
Автор: Воронов Иван, группа ПМИ-13БО, 24.11.2021
Задание: https://drive.google.com/drive/folders/15yKHeAngX7l9xRRhunCuTFr0ydBLB33W
*/
#include <iostream>
#include <cstdio>
#include "matrix.hpp"

int main() {
	int number_str, number_column;
	printf("Программа считает ранг матрицы. \nВведите матрицу\n");
	matrix_ptr matrix = input_matrix(number_str, number_column);
	int rang = rang_matrix(matrix, number_str, number_column);
	printf("Ранг матрицы: %d\n", rang);
	free_matrix(matrix, number_str, number_column);
	return 0;
}

// g++ -g source/*.cpp -I headers -o ../product/laba_6_2 -Wall