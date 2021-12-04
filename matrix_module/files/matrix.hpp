#ifndef MATRIX_HPP
#define MATRIX_HPP
// Число для устранения ошибки -0.0
#define EPSILON 0.00000000001

// Тип данных: указатель на двумерный массив.
typedef double ** matrix_ptr;

// Функции, опеределенные только для квадратных матриц, имеют в своем имени подстроку "_sqr_"
// или соответствующий комментарий перед определением функции.

// Функция создает нулевую матрицу размера str_count на column_count.
matrix_ptr create_matrix(int str_count, int column_count);

// Функция создает нулевую квадратную матрицу размера size_matrix и возвращает указатель на нее.
matrix_ptr create_sqr_matrix(int size_matrix);

// Функция создает единичную квадратную матрицу размера size_matrix и возвращает указатель на нее.
matrix_ptr create_sqr_unit_matrix(int size_matrix);

// Функция очищает память занятую матрицей и стирает указатель на нее.
void free_matrix(matrix_ptr matrix, int str_count, int column_count);

// Функция очищает память занятую квадратной матрицей и стирает указатель на нее.
void free_sqr_matrix(matrix_ptr matrix, int size_matrix);

// Функция копирует матрицу matrix_src в матрицу matrix_dst (размеры матриц должны совпадать).
void copy_matrix(matrix_ptr matrix_dst, matrix_ptr matrix_src, int str_count, int column_count);

// Функция копирует матрицу matrix_src в матрицу matrix_dst (матрицы должны быть квадратными и их размер совпадать)
void copy_sqr_matrix(matrix_ptr matrix_dst, matrix_ptr matrix_src, int size_matrix);

// Функция ввода вещественной матрицы размера str_count на column_count.
matrix_ptr input_matrix(int &str_count, int &column_count);

// Функция ввода вещественной квадратной матрицы.
matrix_ptr input_sqr_matrix(int &size_matrix);

// Функция вывода матрицы.
void output_matrix(matrix_ptr matrix, int str_count, int column_count);

// Функция вывода квадратной матрицы.
void output_sqr_matrix(matrix_ptr matrix, int size_matrix);

// Функция определена только для квадратных матриц.
// Функция умножает две квадратные матрицы размера size_matrix и записывает результат в matrix1.
void matrix_multip(matrix_ptr matrix1, matrix_ptr matrix2, int size_matrix);

// Функция определена только для квадратных матриц.
// Функция прибавляет к matrix1 matrix2 со знаком operand и записывает результат в matrix1.
void matrix_sum(matrix_ptr matrix1, matrix_ptr matrix2, int size_matrix, int operand);

// Функция определена только для квадратных матриц.
// Функция умножает матрицу на число и записывает результат в matrix.
void matrix_multip_by_number(matrix_ptr matrix, double number, int size_matrix);

// Функция приведения матрицы к ступенчатому виду.
void to_stepped_matrix_type(matrix_ptr matrix, int str_count, int column_count);

// Функция считает ранг матрицы.
int rang_matrix(matrix_ptr matrix, int str_count, int column_count);

// Функция определена только для квадратных матриц.
// Функция возвращает подматрицу квадратной матрицы без i-го столбца и j-ой строки
double **matrix_minor(matrix_ptr matrix, int size_matrix, int str_number, int column_number);

// Функция определена только для квадратных матриц.
// Функция находит определитель матрицы.
double matrix_determinant(matrix_ptr matrix, int size_matrix);

// Функция возвращает транспонированую матрицу matrix.
matrix_ptr matrix_transpose(matrix_ptr matrix, int str_count, int column_count);

// Функция определена только для квадратных матриц.
// Функция находит обратную для матрицы matrix матрицу и записывает ее в матрицу invr_matrix.
// Вернет true если обратная матрица была найденна и false в противном случае.
bool inverse_matrix(matrix_ptr invr_matrix, matrix_ptr matrix, int size_matrix);

// Функция определена только для квадратных матриц.
// Функция считает значение выражения 2x^2 - x, где х - квадратная матрица.
matrix_ptr function_f(matrix_ptr matrix_A, int size_matrix);

// Функция определена только для квадратных матриц.
// Функция считает значение выражения 2x^3 - x + 3, где х - квадратная матрица.
matrix_ptr function_g(matrix_ptr matrix_A, int size_matrix);

#endif // MATRIX_HPP