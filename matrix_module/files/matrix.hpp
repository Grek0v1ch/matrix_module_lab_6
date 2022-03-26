#ifndef MATRIX_HPP
#define MATRIX_HPP
// ����� ��� ���������� ������ -0.0
#define EPSILON 0.00000000001

// ��� ������: ��������� �� ��������� ������.
typedef double** matrix_ptr;

// �������, ������������� ������ ��� ���������� ������, ����� � ����� ����� ��������� "_sqr_"
// ��� ��������������� ����������� ����� ������������ �������.

// ������� ������� ������� ������� ������� str_count �� column_count.
matrix_ptr create_matrix(int str_count, int column_count);

// ������� ������� ������� ���������� ������� ������� size_matrix � ���������� ��������� �� ���.
matrix_ptr create_sqr_matrix(int size_matrix);

// ������� ������� ��������� ���������� ������� ������� size_matrix � ���������� ��������� �� ���.
matrix_ptr create_sqr_unit_matrix(int size_matrix);

// ������� ������� ������ ������� �������� � ������� ��������� �� ���.
void free_matrix(matrix_ptr matrix, int str_count, int column_count);

// ������� ������� ������ ������� ���������� �������� � ������� ��������� �� ���.
void free_sqr_matrix(matrix_ptr matrix, int size_matrix);

// ������� �������� ������� matrix_src � ������� matrix_dst (������� ������ ������ ���������).
void copy_matrix(matrix_ptr matrix_dst, matrix_ptr matrix_src, int str_count, int column_count);

// ������� �������� ������� matrix_src � ������� matrix_dst (������� ������ ���� ����������� � �� ������ ���������)
void copy_sqr_matrix(matrix_ptr matrix_dst, matrix_ptr matrix_src, int size_matrix);

// ������� ����� ������������ ������� ������� str_count �� column_count.
matrix_ptr input_matrix(int& str_count, int& column_count);

// ������� ����� ������������ ���������� �������.
matrix_ptr input_sqr_matrix(int& size_matrix);

// ������� ������ �������.
void output_matrix(matrix_ptr matrix, int str_count, int column_count);

// ������� ������ ���������� �������.
void output_sqr_matrix(matrix_ptr matrix, int size_matrix);

// ������� ���������� ������ ��� ���������� ������.
// ������� �������� ��� ���������� ������� ������� size_matrix � ���������� ��������� � matrix1.
void matrix_multip(matrix_ptr matrix1, matrix_ptr matrix2, int size_matrix);

// ������� ���������� ������ ��� ���������� ������.
// ������� ���������� � matrix1 matrix2 �� ������ operand � ���������� ��������� � matrix1.
void matrix_sum(matrix_ptr matrix1, matrix_ptr matrix2, int size_matrix, int operand);

// ������� ���������� ������ ��� ���������� ������.
// ������� �������� ������� �� ����� � ���������� ��������� � matrix.
void matrix_multip_by_number(matrix_ptr matrix, double number, int size_matrix);

// ������� ���������� ������� � ������������ ����.
void to_stepped_matrix_type(matrix_ptr matrix, int str_count, int column_count);

// ������� ������� ���� �������.
int rang_matrix(matrix_ptr matrix, int str_count, int column_count);

// ������� ���������� ������ ��� ���������� ������.
// ������� ���������� ���������� ���������� ������� ��� i-�� ������� � j-�� ������
double** matrix_minor(matrix_ptr matrix, int size_matrix, int str_number, int column_number);

// ������� ���������� ������ ��� ���������� ������.
// ������� ������� ������������ �������.
double matrix_determinant(matrix_ptr matrix, int size_matrix);

// ������� ���������� ���������������� ������� matrix.
matrix_ptr matrix_transpose(matrix_ptr matrix, int str_count, int column_count);

// ������� ���������� ������ ��� ���������� ������.
// ������� ������� �������� ��� ������� matrix ������� � ���������� �� � ������� invr_matrix.
// ������ true ���� �������� ������� ���� �������� � false � ��������� ������.
bool inverse_matrix(matrix_ptr invr_matrix, matrix_ptr matrix, int size_matrix);

// ������� ���������� ������ ��� ���������� ������.
// ������� ������� �������� ��������� 2x^2 - x, ��� � - ���������� �������.
matrix_ptr function_f(matrix_ptr matrix_A, int size_matrix);

// ������� ���������� ������ ��� ���������� ������.
// ������� ������� �������� ��������� 2x^3 - x + 3, ��� � - ���������� �������.
matrix_ptr function_g(matrix_ptr matrix_A, int size_matrix);

//������� ��� ������� ���������� ��������� A*x - 3*x = B
matrix_ptr matrix_equal(matrix_ptr matrix_A, matrix_ptr matrix_B, int size_matrix);

#endif // MATRIX_HPP
