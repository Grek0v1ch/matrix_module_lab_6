#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <string>
#include "chek_io.hpp"
#include "matrix.hpp"
using namespace std;

 int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int str_count, column_count, size_matrix_a, size_matrix_b;

	cout << "������� ������ ��� ������� �:" << endl;
	matrix_ptr matrix_a = input_sqr_matrix(size_matrix_a);
	cout << "������� ������ ��� ������� B:" << endl;
	matrix_ptr matrix_b = input_sqr_matrix(size_matrix_b);

	if (size_matrix_a != size_matrix_b) 
		return 0;

	matrix_ptr sqr_unit_matrix = create_sqr_unit_matrix(size_matrix_a);
	matrix_multip_by_number(sqr_unit_matrix, 3, size_matrix_a);
	matrix_sum(matrix_a, sqr_unit_matrix, size_matrix_a, +1);
	matrix_multip(matrix_b, matrix_a, size_matrix_a);

	//1 �������
	matrix_ptr matrix_new_a = function_f(matrix_a, size_matrix_a);
	matrix_ptr matrix_new_b = function_f(matrix_b, size_matrix_b); 
 
	//2 �������
	cout << "���� ������� " << rang_matrix(matrix_new_a, size_matrix_a, size_matrix_a) << "\n";

	//3 �������
	matrix_ptr answer = matrix_equal(matrix_new_a, matrix_new_b, size_matrix_a);

	free_sqr_matrix(matrix_a, size_matrix_a);
	free_sqr_matrix(matrix_b, size_matrix_a);
	free_sqr_matrix(matrix_new_a, size_matrix_a);
	free_sqr_matrix(matrix_new_b, size_matrix_a);
	free_sqr_matrix(sqr_unit_matrix, size_matrix_a);
	free_sqr_matrix(answer, size_matrix_a);
	return 0;
}
