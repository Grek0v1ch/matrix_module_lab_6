#include <iostream>
#include <cstdio>
#include "matrix.hpp"
#include "chek_io.hpp"

// Функции, опеределенные только для квадратных матриц, имеют в своем имени подстроку "_sqr_"
// или соответствующий комментарий перед описанием функции.

// Функция создает нулевую матрицу размера str_count на column_count.
matrix_ptr create_matrix(int str_count, int column_count) {
	matrix_ptr result = new double *[str_count];
	for (int i = 0; i < str_count; i++) {
		result[i] = new double[column_count];
		for (int j = 0; j < column_count; j++)
			result[i][j] = 0.0;
	}
	return result;
}

// Функция создает нулевую квадратную матрицу размера size_matrix и возвращает указатель на нее.
matrix_ptr create_sqr_matrix(int size_matrix) {
	matrix_ptr result = new double *[size_matrix];
	for (int i = 0; i < size_matrix; i++) {
		result[i] = new double[size_matrix];
		for (int j = 0; j < size_matrix; j++)
			result[i][j] = 0.0;
	}
	return result;
}

// Функция создает единичную квадратную матрицу размера size_matrix и возвращает указатель на нее.
matrix_ptr create_sqr_unit_matrix(int size_matrix) {
	matrix_ptr result = new double *[size_matrix];
	for (int i = 0; i < size_matrix; i++) {
		result[i] = new double[size_matrix];
		for (int j = 0; j < size_matrix; j++)
			result[i][j] = (i == j) ? 1.0 : 0.0;
	}
	return result;
}

// Функция очищает память занятую матрицей и стирает указатель на нее.
void free_matrix(matrix_ptr matrix, int str_count, int column_count) {
	for (int i = 0; i < str_count; i++) {
		for (int j = 0; j < column_count; j++)
			matrix[i][j] = 0.0;
		delete[] matrix[i];
	}
	delete[] matrix;
	matrix = 0;
}

// Функция очищает память занятую квадратной матрицей и стирает указатель на нее.
void free_sqr_matrix(matrix_ptr matrix, int size_matrix) {
	for (int i = 0; i < size_matrix; i++) {
		for (int j = 0; j < size_matrix; j++)
			matrix[i][j] = 0.0;
		delete[] matrix[i];
	}
	delete[] matrix;
	matrix = 0;
}

// Функция копирует матрицу matrix_src в матрицу matrix_dst (размеры матриц должны совпадать).
void copy_matrix(matrix_ptr matrix_dst, matrix_ptr matrix_src, int str_count, int column_count) {
	for (int i = 0; i < str_count; i++)
		for (int j = 0; j < column_count; j++)
			matrix_dst[i][j] = matrix_src[i][j];
	return;
}

// Функция копирует матрицу matrix_src в матрицу matrix_dst (матрицы должны быть квадратными и их размер совпадать)
void copy_sqr_matrix(matrix_ptr matrix_dst, matrix_ptr matrix_src, int size_matrix) {
	for (int i = 0; i < size_matrix; i++)
		for (int j = 0; j < size_matrix; j++)
			matrix_dst[i][j] = matrix_src[i][j];
	return;
}

// Функция ввода вещественной матрицы размера str_count на column_count.
matrix_ptr input_matrix(int &str_count, int &column_count) {
	printf("Введите количество строк матрицы: ");
	str_count = one_natur_num_input();
	printf("Введите количество столбцов матрицы: ");
	column_count = one_natur_num_input();
	matrix_ptr matrix = create_matrix(str_count, column_count);
	for (int i = 0; i < str_count; i++)
		for (int j = 0; j < column_count; j++) {
			printf("matrix[%d][%d]: ", i + 1, j + 1);
			matrix[i][j] = one_double_input();
		}
	return matrix;
}

// Функция ввода вещественной квадратной матрицы.
matrix_ptr input_sqr_matrix(int &size_matrix) {
	printf("Введите размер квадратной матрицы: ");
	size_matrix = one_natur_num_input();
	matrix_ptr matrix = create_sqr_matrix(size_matrix);
	printf("Введите элементы матрицы:\n");
	for (int i = 0; i < size_matrix; i++)
		for (int j = 0; j < size_matrix; j++) {
			printf("matrix[%d][%d]: ", i + 1, j + 1);
			matrix[i][j] = one_double_input();
		}
	return matrix;
}

// Функция вывода матрицы.
void output_matrix(matrix_ptr matrix, int str_count, int column_count) {
	for (int i = 0; i < str_count; i++) {
		for (int j = 0; j < column_count; j++)
			printf("%.2lf\t", matrix[i][j]);
		printf("\n");
	}
}

// Функция вывода квадратной матрицы.
void output_sqr_matrix(matrix_ptr matrix, int size_matrix) {
	for (int i = 0; i < size_matrix; i++) {
		for (int j = 0; j < size_matrix; j++)
			printf("%.2lf\t", matrix[i][j]);
		printf("\n");
	}
}

// Функция определена только для квадратных матриц.
// Функция умножает две матрицы размера size_matrix и записывает результат в matrix1.
void matrix_multip(matrix_ptr matrix1, matrix_ptr matrix2, int size_matrix) {
	matrix_ptr matrix_res = create_sqr_matrix(size_matrix);
	// Пеереходим в элемент matrix_res[i][j].
	for (int i = 0; i < size_matrix; i++)
		for (int j = 0; j < size_matrix; j++)
			// Вычисляем элемент matrix_res[i][j].
			for (int l = 0; l < size_matrix; l++)
				matrix_res[i][j] += matrix1[i][l] * matrix2[l][j];
	// Копируем результат в matrix1 и удаляем matrix_res.
	copy_sqr_matrix(matrix1, matrix_res, size_matrix);
	free_sqr_matrix(matrix_res, size_matrix);
	return;
}

// Функция определена только для квадратных матриц.
// Функция прибавляет к matrix1 matrix2 со знаком operand и записывает результат в matrix1.
void matrix_sum(matrix_ptr matrix1, matrix_ptr matrix2, int size_matrix, int operand) {
	// operand задает знак сложения: -1 - вычитание, 1 - сложение.
	// Блок для отладки.
	if (abs(operand) != 1) {
		printf("error in matrix_sum\n");
		return;
	}
	matrix_ptr matrix_res = create_sqr_matrix(size_matrix);
	for (int i = 0; i < size_matrix; i++)
		for (int j = 0; j < size_matrix; j++)
			matrix_res[i][j] = matrix1[i][j] + static_cast<double>(operand) * matrix2[i][j];
	// Копируем результат в matrix1 и удаляем matrix_res.
	copy_sqr_matrix(matrix1, matrix_res, size_matrix);
	free_sqr_matrix(matrix_res, size_matrix);
	return;
}

// Функция определена только для квадратных матриц.
// Функция умножает матрицу на число и записывает результат в matrix.
void matrix_multip_by_number(matrix_ptr matrix, double number, int size_matrix) {
	matrix_ptr matrix_res = create_sqr_matrix(size_matrix);
	for (int i = 0; i < size_matrix; i++)
		for (int j = 0; j < size_matrix; j++)
			matrix_res[i][j] = number * matrix[i][j];
	// Копируем результат в matrix1 и удаляем matrix_res.
	copy_sqr_matrix(matrix, matrix_res, size_matrix);
	free_sqr_matrix(matrix_res, size_matrix);
	return;
}

// Функция приведения матрицы к ступенчатому виду.
void to_stepped_matrix_type(matrix_ptr matrix, int str_count, int column_count) {
	for (int i = 0; i < str_count - 1; i++)
		for (int j = 0; j < column_count; j++) {
			// Находим ненулевой элемент.
			if (matrix[i][j] == 0.0)
				continue;
			// Вычитаем верхнюю строку из нижней, зануляя первый элемент.
			for (int k = i + 1; k < str_count; k++) {
				for (int l = j + 1; l < column_count; l++)
					matrix[k][l] = matrix[i][j] * matrix[k][l] - matrix[k - 1][l] * matrix[i + 1][j];
				matrix[k][j] = 0.0;
			}
			break;
		}
	return;
}

// Функция считает ранг матрицы.
int rang_matrix(matrix_ptr matrix, int str_count, int column_count) {
	matrix_ptr matrix_src = create_matrix(str_count, column_count);
	copy_matrix(matrix_src, matrix, str_count, column_count);
	to_stepped_matrix_type(matrix_src, str_count, column_count);
	int count_nzero_str = 0;
	bool is_all_zero = true;
	for (int i = 0; i < str_count; i++) {
		is_all_zero = true;
		for (int j = 0; j < column_count and is_all_zero; j++)
			if (matrix_src[i][j] != 0.0)
				is_all_zero = false;
		if (not is_all_zero)
			count_nzero_str++;
	}
	free_matrix(matrix_src, str_count, column_count);
	return count_nzero_str;
}

// Функция определена только для квадратных матриц.
// Функция возвращает подматрицу квадратной матрицы без i-го столбца и j-ой строки
matrix_ptr matrix_minor(matrix_ptr matrix, int size_matrix, int str_number, int column_number) {
	matrix_ptr minor = create_sqr_matrix(size_matrix - 1);
	int minor_str = 0, minor_column = 0;
	for (int i = 0; i < size_matrix; i++) {
		if (i == str_number)
			continue;
		for (int j = 0; j < size_matrix; j++) {
			if (j == column_number)
				continue;
			minor[minor_str][minor_column++] = matrix[i][j];
			if (minor_column == size_matrix - 1) {
				minor_str++;
				minor_column = 0;
			}
		}
	}
	return minor;
}

// Функция определена только для квадратных матриц.
// Функция находит определитель матрицы.
double matrix_determinant(matrix_ptr matrix, int size_matrix) {
	double answer = 0.0;
	if (size_matrix == 1)
		return matrix[0][0];
	if (size_matrix == 2) {
		 answer = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
		 return answer;
	}
	// Используется разложение по первой строке матрицы.
	for (int i = 0; i < size_matrix; i++) {
		matrix_ptr minor = matrix_minor(matrix, size_matrix, 0, i);
		double sign = (i % 2 == 0) ? 1.0 : -1.0;
		answer += sign * matrix[0][i] * matrix_determinant(minor, size_matrix - 1);
		free_sqr_matrix(minor, size_matrix - 1);
	}
	return answer;
}

// Функция возвращает транспонированую матрицу matrix.
matrix_ptr matrix_transpose(matrix_ptr matrix, int str_count, int column_count) {
	matrix_ptr matrix_t = create_matrix(column_count, str_count);
	for (int i = 0; i < column_count; i++)
		for (int j = 0; j < str_count; j++)
			matrix_t[i][j] = matrix[j][i];
	return matrix_t;
}

// Функция определена только для квадратных матриц.
// Функция находит обратную для матрицы matrix матрицу и записывает ее в матрицу invr_matrix.
// Вернет true если обратная матрица была найденна и false в противном случае.
bool inverse_matrix(matrix_ptr invr_matrix, matrix_ptr matrix, int size_matrix) {
	double determinant = matrix_determinant(matrix, size_matrix);
	if (determinant == 0.0)
		return false;
	for (int i = 0; i < size_matrix; i++)
		for (int j = 0; j < size_matrix; j++){
			matrix_ptr minor = matrix_minor(matrix, size_matrix, i, j);
			double sign = ((i + j) % 2 == 0) ? 1.0 : -1.0;
			invr_matrix[i][j] = sign * matrix_determinant(minor, size_matrix - 1) / determinant;
			if (abs(invr_matrix[i][j]) < EPSILON)
				invr_matrix[i][j] = 0.0;
			free_sqr_matrix(minor, size_matrix - 1);
		}
	matrix_ptr temp_matrix = matrix_transpose(invr_matrix, size_matrix, size_matrix);
	copy_sqr_matrix(invr_matrix, temp_matrix, size_matrix);
	free_sqr_matrix(temp_matrix, size_matrix);
	return true;
}

// Функция определена только для квадратных матриц.
// Функция считает значение выражения 2x^2 - x, где х - квадратная матрица.
matrix_ptr function_f(matrix_ptr matrix_A, int size_matrix) {
	matrix_ptr answer = create_sqr_matrix(size_matrix);
	copy_sqr_matrix(answer, matrix_A, size_matrix);
	matrix_multip(answer, matrix_A, size_matrix);
	matrix_multip_by_number(answer, 2.0, size_matrix);
	printf("Значение 2*x^2:\n");
	output_sqr_matrix(answer, size_matrix);
	printf("Значение х\n");
	output_sqr_matrix(matrix_A, size_matrix);
	matrix_sum(answer, matrix_A, size_matrix, -1);
	return answer;
}

// Функция определена только для квадратных матриц.
// Функция считает значение выражения 2x^3 - x + 3, где х - квадратная матрица.
matrix_ptr function_g(matrix_ptr matrix_A, int size_matrix) {
	matrix_ptr answer = create_sqr_matrix(size_matrix);
	copy_sqr_matrix(answer, matrix_A, size_matrix);
	matrix_multip(answer, matrix_A, size_matrix);
	matrix_multip(answer, matrix_A, size_matrix);
	matrix_multip_by_number(answer, 2.0, size_matrix);
	printf("Значение 2*x^3:\n");
	output_sqr_matrix(answer, size_matrix);
	printf("Значение х\n");
	output_sqr_matrix(matrix_A, size_matrix);
	matrix_sum(answer, matrix_A, size_matrix, -1);
	printf("Значение 2*x^3 - x:\n");
	output_sqr_matrix(answer, size_matrix);
	matrix_ptr matrix_number = create_sqr_unit_matrix(size_matrix);
	matrix_multip_by_number(matrix_number, 3.0, size_matrix);
	printf("Значение 3*E\n");
	output_sqr_matrix(matrix_number, size_matrix);
	matrix_sum(answer, matrix_number, size_matrix, 1);
	free_sqr_matrix(matrix_number, size_matrix);
	return answer;
}
