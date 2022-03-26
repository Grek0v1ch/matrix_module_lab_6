#include <cstdio>
#include <cstdlib> // abs
#include "matrix.hpp"
#include "chek_io.hpp"

// �������, ������������� ������ ��� ���������� ������, ����� � ����� ����� ��������� "_sqr_"
// ��� ��������������� ����������� ����� ��������� �������.

// ������� ������� ������� ������� ������� str_count �� column_count.
matrix_ptr create_matrix(int str_count, int column_count) {
	matrix_ptr result = new double* [str_count];
	for (int i = 0; i < str_count; i++) {
		result[i] = new double[column_count];
		for (int j = 0; j < column_count; j++)
			result[i][j] = 0.0;
	}
	return result;
}

// ������� ������� ������� ���������� ������� ������� size_matrix � ���������� ��������� �� ���.
matrix_ptr create_sqr_matrix(int size_matrix) {
	matrix_ptr result = new double* [size_matrix];
	for (int i = 0; i < size_matrix; i++) {
		result[i] = new double[size_matrix];
		for (int j = 0; j < size_matrix; j++)
			result[i][j] = 0.0;
	}
	return result;
}

// ������� ������� ��������� ���������� ������� ������� size_matrix � ���������� ��������� �� ���.
matrix_ptr create_sqr_unit_matrix(int size_matrix) {
	matrix_ptr result = new double* [size_matrix];
	for (int i = 0; i < size_matrix; i++) {
		result[i] = new double[size_matrix];
		for (int j = 0; j < size_matrix; j++)
			result[i][j] = (i == j) ? 1.0 : 0.0;
	}
	return result;
}

// ������� ������� ������ ������� �������� � ������� ��������� �� ���.
void free_matrix(matrix_ptr matrix, int str_count, int column_count) {
	for (int i = 0; i < str_count; i++) {
		for (int j = 0; j < column_count; j++)
			matrix[i][j] = 0.0;
		delete[] matrix[i];
	}
	delete[] matrix;
	matrix = 0;
}

// ������� ������� ������ ������� ���������� �������� � ������� ��������� �� ���.
void free_sqr_matrix(matrix_ptr matrix, int size_matrix) {
	for (int i = 0; i < size_matrix; i++) {
		for (int j = 0; j < size_matrix; j++)
			matrix[i][j] = 0.0;
		delete[] matrix[i];
	}
	delete[] matrix;
	matrix = 0;
}

// ������� �������� ������� matrix_src � ������� matrix_dst (������� ������ ������ ���������).
void copy_matrix(matrix_ptr matrix_dst, matrix_ptr matrix_src, int str_count, int column_count) {
	for (int i = 0; i < str_count; i++)
		for (int j = 0; j < column_count; j++)
			matrix_dst[i][j] = matrix_src[i][j];
	return;
}

// ������� �������� ������� matrix_src � ������� matrix_dst (������� ������ ���� ����������� � �� ������ ���������)
void copy_sqr_matrix(matrix_ptr matrix_dst, matrix_ptr matrix_src, int size_matrix) {
	for (int i = 0; i < size_matrix; i++)
		for (int j = 0; j < size_matrix; j++)
			matrix_dst[i][j] = matrix_src[i][j];
	return;
}

// ������� ����� ������������ ������� ������� str_count �� column_count.
matrix_ptr input_matrix(int& str_count, int& column_count) {
	printf("������� ���������� ����� �������: ");
	str_count = one_natur_num_input();
	printf("������� ���������� �������� �������: ");
	column_count = one_natur_num_input();
	matrix_ptr matrix = create_matrix(str_count, column_count);
	for (int i = 0; i < str_count; i++)
		for (int j = 0; j < column_count; j++) {
			printf("matrix[%d][%d]: ", i + 1, j + 1);
			matrix[i][j] = one_double_input();
		}
	return matrix;
}

// ������� ����� ������������ ���������� �������.
matrix_ptr input_sqr_matrix(int& size_matrix) {
	printf("������� ������ ���������� �������: ");
	size_matrix = one_natur_num_input();
	matrix_ptr matrix = create_sqr_matrix(size_matrix);
	printf("������� �������� �������:\n");
	for (int i = 0; i < size_matrix; i++)
		for (int j = 0; j < size_matrix; j++) {
			printf("matrix[%d][%d]: ", i + 1, j + 1);
			matrix[i][j] = one_double_input();
		}
	return matrix;
}

// ������� ������ �������.
void output_matrix(matrix_ptr matrix, int str_count, int column_count) {
	for (int i = 0; i < str_count; i++) {
		for (int j = 0; j < column_count; j++)
			printf("%.2lf\t", matrix[i][j]);
		printf("\n");
	}
}

// ������� ������ ���������� �������.
void output_sqr_matrix(matrix_ptr matrix, int size_matrix) {
	for (int i = 0; i < size_matrix; i++) {
		for (int j = 0; j < size_matrix; j++)
			printf("%.2lf\t", matrix[i][j]);
		printf("\n");
	}
}

// ������� ���������� ������ ��� ���������� ������.
// ������� �������� ��� ������� ������� size_matrix � ���������� ��������� � matrix1.
void matrix_multip(matrix_ptr matrix1, matrix_ptr matrix2, int size_matrix) {
	matrix_ptr matrix_res = create_sqr_matrix(size_matrix);
	// ���������� � ������� matrix_res[i][j].
	for (int i = 0; i < size_matrix; i++)
		for (int j = 0; j < size_matrix; j++)
			// ��������� ������� matrix_res[i][j].
			for (int l = 0; l < size_matrix; l++)
				matrix_res[i][j] += matrix1[i][l] * matrix2[l][j];
	// �������� ��������� � matrix1 � ������� matrix_res.
	copy_sqr_matrix(matrix1, matrix_res, size_matrix);
	free_sqr_matrix(matrix_res, size_matrix);
	return;
}

// ������� ���������� ������ ��� ���������� ������.
// ������� ���������� � matrix1 matrix2 �� ������ operand � ���������� ��������� � matrix1.
void matrix_sum(matrix_ptr matrix1, matrix_ptr matrix2, int size_matrix, int operand) {
	// operand ������ ���� ��������: -1 - ���������, 1 - ��������.
	// ���� ��� �������.
	if (abs(operand) != 1) {
		printf("error in matrix_sum\n");
		return;
	}
	matrix_ptr matrix_res = create_sqr_matrix(size_matrix);
	for (int i = 0; i < size_matrix; i++)
		for (int j = 0; j < size_matrix; j++)
			matrix_res[i][j] = matrix1[i][j] + static_cast<double>(operand) * matrix2[i][j];
	// �������� ��������� � matrix1 � ������� matrix_res.
	copy_sqr_matrix(matrix1, matrix_res, size_matrix);
	free_sqr_matrix(matrix_res, size_matrix);
	return;
}

// ������� ���������� ������ ��� ���������� ������.
// ������� �������� ������� �� ����� � ���������� ��������� � matrix.
void matrix_multip_by_number(matrix_ptr matrix, double number, int size_matrix) {
	matrix_ptr matrix_res = create_sqr_matrix(size_matrix);
	for (int i = 0; i < size_matrix; i++)
		for (int j = 0; j < size_matrix; j++)
			matrix_res[i][j] = number * matrix[i][j];
	// �������� ��������� � matrix1 � ������� matrix_res.
	copy_sqr_matrix(matrix, matrix_res, size_matrix);
	free_sqr_matrix(matrix_res, size_matrix);
	return;
}

// ������� ���������� ������� � ������������ ����.
void to_stepped_matrix_type(matrix_ptr matrix, int str_count, int column_count) {
	for (int i = 0; i < str_count - 1; i++)
		for (int j = 0; j < column_count; j++) {
			// ������� ��������� �������.
			if (matrix[i][j] == 0.0)
				continue;
			// �������� ������� ������ �� ������, ������� ������ �������.
			for (int k = i + 1; k < str_count; k++) {
				for (int l = j + 1; l < column_count; l++)
					matrix[k][l] = matrix[i][j] * matrix[k][l] - matrix[k - 1][l] * matrix[i + 1][j];
				matrix[k][j] = 0.0;
			}
			break;
		}
	return;
}

// ������� ������� ���� �������.
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

// ������� ���������� ������ ��� ���������� ������.
// ������� ���������� ���������� ���������� ������� ��� i-�� ������� � j-�� ������
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

// ������� ���������� ������ ��� ���������� ������.
// ������� ������� ������������ �������.
double matrix_determinant(matrix_ptr matrix, int size_matrix) {
	double answer = 0.0;
	if (size_matrix == 1)
		return matrix[0][0];
	if (size_matrix == 2) {
		answer = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
		return answer;
	}
	// ������������ ���������� �� ������ ������ �������.
	for (int i = 0; i < size_matrix; i++) {
		matrix_ptr minor = matrix_minor(matrix, size_matrix, 0, i);
		double sign = (i % 2 == 0) ? 1.0 : -1.0;
		answer += sign * matrix[0][i] * matrix_determinant(minor, size_matrix - 1);
		free_sqr_matrix(minor, size_matrix - 1);
	}
	return answer;
}

// ������� ���������� ���������������� ������� matrix.
matrix_ptr matrix_transpose(matrix_ptr matrix, int str_count, int column_count) {
	matrix_ptr matrix_t = create_matrix(column_count, str_count);
	for (int i = 0; i < column_count; i++)
		for (int j = 0; j < str_count; j++)
			matrix_t[i][j] = matrix[j][i];
	return matrix_t;
}

// ������� ���������� ������ ��� ���������� ������.
// ������� ������� �������� ��� ������� matrix ������� � ���������� �� � ������� invr_matrix.
// ������ true ���� �������� ������� ���� �������� � false � ��������� ������.
bool inverse_matrix(matrix_ptr invr_matrix, matrix_ptr matrix, int size_matrix) {
	double determinant = matrix_determinant(matrix, size_matrix);
	if (determinant == 0.0)
		return false;
	for (int i = 0; i < size_matrix; i++)
		for (int j = 0; j < size_matrix; j++) {
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

// ������� ���������� ������ ��� ���������� ������.
// ������� ������� �������� ��������� 2x^2 - x, ��� � - ���������� �������.
matrix_ptr function_f(matrix_ptr matrix_A, int size_matrix) {
	matrix_ptr answer = create_sqr_matrix(size_matrix);
	copy_sqr_matrix(answer, matrix_A, size_matrix);
	matrix_multip(answer, matrix_A, size_matrix);
	matrix_multip_by_number(answer, 2.0, size_matrix);
	printf("�������� 2*x^2:\n");
	output_sqr_matrix(answer, size_matrix);
	printf("�������� �\n");
	output_sqr_matrix(matrix_A, size_matrix);
	matrix_sum(answer, matrix_A, size_matrix, -1);
	return answer;
}

// ������� ���������� ������ ��� ���������� ������.
// ������� ������� �������� ��������� 2x^3 - x + 3, ��� � - ���������� �������.
matrix_ptr function_g(matrix_ptr matrix_A, int size_matrix) {
	matrix_ptr answer = create_sqr_matrix(size_matrix);
	copy_sqr_matrix(answer, matrix_A, size_matrix);
	matrix_multip(answer, matrix_A, size_matrix);
	matrix_multip(answer, matrix_A, size_matrix);
	matrix_multip_by_number(answer, 2.0, size_matrix);
	printf("�������� 2*x^3:\n");
	output_sqr_matrix(answer, size_matrix);
	printf("�������� �\n");
	output_sqr_matrix(matrix_A, size_matrix);
	matrix_sum(answer, matrix_A, size_matrix, -1);
	printf("�������� 2*x^3 - x:\n");
	output_sqr_matrix(answer, size_matrix);
	matrix_ptr matrix_number = create_sqr_unit_matrix(size_matrix);
	matrix_multip_by_number(matrix_number, 3.0, size_matrix);
	printf("�������� 3*E\n");
	output_sqr_matrix(matrix_number, size_matrix);
	matrix_sum(answer, matrix_number, size_matrix, 1);
	free_sqr_matrix(matrix_number, size_matrix);
	return answer;
}

//������� ��� ������� ���������� ��������� A*x - 3*x = B
matrix_ptr matrix_equal(matrix_ptr matrix_A, matrix_ptr matrix_B, int size_matrix) {
	matrix_ptr buff1 = create_sqr_unit_matrix(size_matrix);
	matrix_ptr buff2 = create_sqr_matrix(size_matrix);
	//3.0 - ����� ��� ���������  
	matrix_multip_by_number(buff1, 3.0, size_matrix);
	copy_sqr_matrix(buff2, matrix_A, size_matrix);
	matrix_sum(buff2, buff1, size_matrix, -1);
	bool is_inverse_matrix = inverse_matrix(buff1, buff2, size_matrix);
	if (not is_inverse_matrix)
		printf("��� �������\n");
	else {
		matrix_multip(buff1, matrix_B, size_matrix);
		printf("������� � �����:\n");
		output_sqr_matrix(buff1, size_matrix);
	}
	free_sqr_matrix(buff2, size_matrix);
	return buff1;
}