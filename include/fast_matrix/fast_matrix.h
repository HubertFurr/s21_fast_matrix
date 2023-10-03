/* ************************************************************************** */
/*                                              ############       ####       */
/*                                              ############       ####       */
/*   fast_matrix.h                                          ####       ####   */
/*                                                          ####       ####   */
/*   By: hubertfu@student.21-school.ru              ########           ####   */
/*                                                  ########           ####   */
/*                                              ####                   ####   */
/*   Created: 2023-05-10                        ####                   ####   */
/*   Updated: 2023-05-24                            ############       ####   */
/*                                                  ############       ####   */
/* ************************************************************************** */

/**
 * @file fast_matrix.h
 * @author Hubert Furr (hubertfu@student.21-school.ru)
 * @brief Шаблонный класс матриц, реализующий быстрые операции над матрицами
 * (быстрее, чем CPP1_s21_matrix_plus).
 * @version 1.0
 * @date 2023-05-24
 *
 * @copyright School-21 (c) 2023
 *
 */

#ifndef S21_FAST_MATRIX_FAST_MATRIX_H_
#define S21_FAST_MATRIX_FAST_MATRIX_H_

#include <algorithm>  // std::fill | std::copy
#include <cmath>      // std::abs
#include <iostream>   // std::ostream
#include <stdexcept>  // length_error | logic_error | out_of_range
#include <utility>    // std::move | std::swap
#include <vector>     // std::vector

namespace s21 {

// TODO: Умножение с транспонированием через ref
// TODO: тесты на разные типы
// TODO: ограничить типы данных?
// TODO: странное покрытие
// TODO: тесты геммов
// TODO: неймспейсы тестов и хелперов

template <typename Type>
class FastMatrix {
 public:
  /**
   * @brief Конструктор по умолчанию (Default constructor). Создает объект
   * FastMatrix размером [0 x 0].
   */
  FastMatrix() noexcept : rows_(0), cols_(0), matrix_(nullptr) {}

  /**
   * @brief Параметризованный конструктор (Parameterized Constructor).
   * Создает объект FastMatrix размером [rows x cols], заполненный нулями
   */
  explicit FastMatrix(int rows, int cols) : rows_(rows), cols_(cols) {
    if (rows_ < 0 || cols_ < 0) {
      throw std::length_error("Matrix size must be greater or equal than 0");
    }
    matrix_ = new Type[rows_ * cols_]{};
  }

  /**
   * @brief Параметризованный конструктор (Parameterized Constructor).
   * Создает объект FastMatrix размером [rows x cols], заполненный value
   */
  explicit FastMatrix(int rows, int cols, Type value)
      : rows_(rows), cols_(cols) {
    if (rows_ < 0 || cols_ < 0) {
      throw std::length_error("Matrix size must be greater or equal than 0");
    }
    matrix_ = new Type[rows_ * cols_];
    std::fill(matrix_, matrix_ + rows_ * cols_, value);
  }

  /**
   * @brief Конструктор копирования (Copy Constructor).
   * Создает объект FastMatrix путем копирования данных из объекта other
   */
  FastMatrix(const FastMatrix& other)
      : rows_(other.rows_),
        cols_(other.cols_),
        matrix_(new Type[rows_ * cols_]) {
    std::copy(other.matrix_, other.matrix_ + rows_ * cols_, matrix_);
    // std::memcpy(matrix_, other.matrix_, rows_ * cols_ * sizeof(Type));
    // std::copy_n(other.matrix_, rows_ * cols_, matrix_);
  }

  /**
   * @brief Конструктор переноса (Move Constructor).
   * Создает объект FastMatrix путем передачи владения ресурсами от объекта
   * other
   */
  FastMatrix(FastMatrix&& other) noexcept
      : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
    other.matrix_ = nullptr;
    other.rows_ = 0;
    other.cols_ = 0;
  }

  /**
   * @brief Оператор присваивания копированием.
   *
   * @param other Копируемый объект FastMatrix
   * @return FastMatrix&
   */
  FastMatrix& operator=(const FastMatrix& other) {
    FastMatrix copy{other};
    *this = std::move(copy);
    return *this;
  }

  /**
   * @brief Оператор присваивания переносом.
   *
   * @param other Объект FastMatrix, у которого забираем владение ресурсами
   * @return FastMatrix&
   */
  FastMatrix& operator=(FastMatrix&& other) noexcept {
    std::swap(rows_, other.rows_);
    std::swap(cols_, other.cols_);
    std::swap(matrix_, other.matrix_);
    return *this;
  }

  /**
   * @brief Деструктор объекта (Destructor)
   */
  ~FastMatrix() noexcept { Free(); }

  /**
   * @brief Проверяет матрицы на равенство между собой
   *
   * @param other Сравниваемая матрица
   * @return true если матрицы равны
   * @return false если матрицы не равны
   */
  bool EqMatrix(const FastMatrix& other) const noexcept {
    if (rows_ != other.rows_ || cols_ != other.cols_) {
      return false;
    }

    for (int i = 0, size = rows_ * cols_; i < size; ++i) {
      if (std::abs(other.matrix_[i] - matrix_[i]) > kEpsilon) {
        return false;
      }
    }

    return true;
  }

  /**
   * @brief Прибавляет вторую матрицы к текущей
   *
   * @param other 2е слагаемое (матрица)
   */
  void SumMatrix(const FastMatrix& other) {
    if (rows_ != other.rows_ || cols_ != other.cols_) {
      throw std::logic_error("Incorrect matrix size for Sum");
    }

    for (int i = 0, size = rows_ * cols_; i < size; ++i) {
      matrix_[i] += other.matrix_[i];
    }
  }

  /**
   * @brief Вычитает из текущей матрицы другую
   *
   * @param other Вычитаемое (матрица)
   */
  void SubMatrix(const FastMatrix& other) {
    if (rows_ != other.rows_ || cols_ != other.cols_) {
      throw std::logic_error("Incorrect matrix size for Sub");
    }

    for (int i = 0, size = rows_ * cols_; i < size; ++i) {
      matrix_[i] -= other.matrix_[i];
    }
  }

  /**
   * @brief Умножает текущую матрицу на число
   *
   * @param number 2й множитель (число)
   */
  void MulNumber(const Type number) noexcept {
    for (int i = 0, size = rows_ * cols_; i < size; ++i) {
      matrix_[i] *= number;
    }
  }

  /**
   * @brief Умножает текущую матрицу на вторую
   *
   * @param other 2й множитель (матрица)
   */
  void MulMatrix(const FastMatrix& other) {
    if (cols_ != other.get_rows()) {
      throw std::logic_error("Incorrect matrix size for Multiplication");
    }
    FastMatrix result{rows_, other.get_cols()};
    // TODO: Выбирать GEMM, исходя из данных матриц?
    GemmV3Ref(matrix_, other.matrix_, result.matrix_, rows_, cols_,
              other.cols_);
    *this = std::move(result);
  }

  /**
   * @brief Создает новую транспонированную матрицу из текущей и возвращает ее.
   *
   * @return FastMatrix Транспонированная матрица
   */
  FastMatrix Transpose() const {
    FastMatrix result{cols_, rows_};

    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < cols_; ++j) {
        result(j, i) = (*this)(i, j);
      }
    }

    return result;
  }

  /**
   * @brief Метод для заполнения указателя matrix_result данными умножения
   * матрицы A на матрицу B (Вариант 0).
   *
   * @details
   * GEMM - General Matrix Multiplication
   * A * B = C
   * [rows_a x cols_a] * [rows_b x cols_b] = [rows_c x cols_c]
   * cols_a == rows_b
   * rows_c == rows_a
   * cols_c == cols_b
   * Поэтому нам требуется передать только rows_a, cols_a, cols_b
   *
   * Самый очевидный и простой вариант умножения - соответственно, самый
   * медленный.
   *
   * @param matrix_a Указатель на первый элемент первого множителя
   * @param matrix_b Указатель на первый элемент второго множителя
   * @param matrix_result Указатель на первый элемент матрицы-результата
   * @param rows_a Количество строк матрицы A
   * @param cols_a Количество столбцов матрицы A
   * @param cols_b Количество столбцов матрицы B
   */
  static void GemmV0Ref(const Type* matrix_a, const Type* matrix_b,
                        Type* matrix_result, int rows_a, int cols_a,
                        int cols_b) {
    for (int i = 0; i < rows_a; ++i) {
      for (int j = 0; j < cols_b; ++j) {
        for (int k = 0; k < cols_a; ++k) {
          matrix_result[i * cols_b + j] +=
              matrix_a[i * cols_a + k] * matrix_b[k * cols_b + j];
        }
      }
    }
  }

  // TODO: add brief - переменная аккуммуляции, куча работает медленнее стека,
  // нет лишних разыменовываний
  /**
   * @brief Метод для заполнения указателя matrix_result данными умножения
   * матрицы A на матрицу B (Вариант 1).
   *
   * @details
   *
   *
   * @param matrix_a Указатель на первый элемент первого множителя
   * @param matrix_b Указатель на первый элемент второго множителя
   * @param matrix_result Указатель на первый элемент матрицы-результата
   * @param rows_a Количество строк матрицы A
   * @param cols_a Количество столбцов матрицы A
   * @param cols_b Количество столбцов матрицы B
   */
  static void GemmV1Ref(const Type* matrix_a, const Type* matrix_b,
                        Type* matrix_result, int rows_a, int cols_a,
                        int cols_b) {
    for (int i = 0; i < rows_a; ++i) {
      for (int j = 0; j < cols_b; ++j) {
        Type acc = 0;
        for (int k = 0; k < cols_a; ++k) {
          acc += matrix_a[i * cols_a + k] * matrix_b[k * cols_b + j];
        }
        matrix_result[i * cols_b + j] = acc;
      }
    }
  }

  // TODO: add brief - упрощение вычисления адресов элементов массивов - вынос
  // постоянных частей за пределы цикла. Сомнительный результат.
  /**
   * @brief Метод для заполнения указателя matrix_result данными умножения
   * матрицы A на матрицу B (Вариант 2).
   *
   * @details
   *
   *
   * @param matrix_a Указатель на первый элемент первого множителя
   * @param matrix_b Указатель на первый элемент второго множителя
   * @param matrix_result Указатель на первый элемент матрицы-результата
   * @param rows_a Количество строк матрицы A
   * @param cols_a Количество столбцов матрицы A
   * @param cols_b Количество столбцов матрицы B
   */
  static void GemmV2Ref(const Type* matrix_a, const Type* matrix_b,
                        Type* matrix_result, int rows_a, int cols_a,
                        int cols_b) {
    for (int i = 0; i < rows_a; ++i) {
      const Type* matrix_a_const = matrix_a + i * cols_a;
      Type* result_const = matrix_result + i * cols_b;
      for (int j = 0; j < cols_b; ++j) {
        Type acc = 0;
        const Type* matrix_b_const = matrix_b + j;
        for (int k = 0; k < cols_a; ++k) {
          acc += matrix_a_const[k] * matrix_b_const[k * cols_b];
        }
        result_const[j] = acc;
      }
    }
  }

  /**
   * @brief Метод для заполнения указателя matrix_result данными умножения
   * матрицы A на матрицу B (Вариант 3).
   *
   * @details
   * 1) Упрощение вычисления адресов элементов массивов - вынос постоянных
   * частей за пределы цикла.
   * 2) В GemmV0 доступ к элементам массива B производится не последовательно.
   * Его можно упорядочить, если поменять порядок вычисления таким образом,
   * чтобы внутренним циклом был последовательный обход по строчкам для всех
   * трех матриц.
   *
   * @param matrix_a Указатель на первый элемент первого множителя
   * @param matrix_b Указатель на первый элемент второго множителя
   * @param matrix_result Указатель на первый элемент матрицы-результата
   * @param rows_a Количество строк матрицы A
   * @param cols_a Количество столбцов матрицы A
   * @param cols_b Количество столбцов матрицы B
   */
  static void GemmV3Ref(const Type* matrix_a, const Type* matrix_b,
                        Type* matrix_result, int rows_a, int cols_a,
                        int cols_b) {
    for (int i = 0; i < rows_a; ++i) {
      Type* result_const = matrix_result + i * cols_b;
      for (int k = 0; k < cols_a; ++k) {
        const Type* matrix_b_const = matrix_b + k * cols_b;
        Type matrix_a_value = matrix_a[i * cols_a + k];
        for (int j = 0; j < cols_b; ++j) {
          result_const[j] += matrix_a_value * matrix_b_const[j];
        }
      }
    }
  }

  // TODO: add brief - CPU cache-friendly версия с умножением транспонированием
  /**
   * @brief Метод для заполнения указателя matrix_result данными умножения
   * матрицы A на матрицу B (Вариант 4).
   *
   * @details
   *
   * @param matrix_a Указатель на первый элемент первого множителя
   * @param matrix_b Указатель на первый элемент второго множителя
   * @param matrix_result Указатель на первый элемент матрицы-результата
   * @param rows_a Количество строк матрицы A
   * @param cols_a Количество столбцов матрицы A
   * @param cols_b Количество столбцов матрицы B
   */
  static void GemmV4Ref(const Type* matrix_a, const Type* matrix_b,
                        Type* matrix_result, int rows_a, int cols_a,
                        int cols_b) {
    std::vector<Type> tmp(cols_b * cols_a);

    for (int i = 0; i < cols_a; ++i) {
      const Type* matrix_b_const = matrix_b + i * cols_b;
      for (int j = 0; j < cols_b; ++j) {
        tmp[j * cols_a + i] = matrix_b_const[j];
      }
    }

    for (int i = 0; i < rows_a; ++i) {
      const Type* matrix_a_const = matrix_a + i * cols_a;
      Type* result_const = matrix_result + i * cols_b;
      for (int j = 0; j < cols_b; ++j) {
        Type acc = 0;
        const Type* tmp_const = tmp.data() + j * cols_a;
        for (int k = 0; k < cols_a; ++k) {
          acc += matrix_a_const[k] * tmp_const[k];
        }
        result_const[j] = acc;
      }
    }
  }

  static void GemmM2TransposeV0Ref(const Type* matrix_a, const Type* matrix_b,
                                   Type* matrix_result, int rows_a, int cols_a,
                                   int rows_b) {
    for (int i = 0; i < rows_a; ++i) {
      for (int j = 0; j < rows_b; ++j) {
        matrix_result[i * rows_b + j] = Type{};
        for (int k = 0; k < cols_a; ++k) {
          matrix_result[i * rows_b + j] +=
              matrix_a[i * cols_a + k] * matrix_b[j * cols_a + k];
        }
      }
    }
  }

  static void GemmM1TransposeV0Ref(const Type* matrix_a, const Type* matrix_b,
                                   Type* matrix_result, int rows_a, int cols_a,
                                   int cols_b) {
    for (int i = 0; i < cols_a; ++i) {
      for (int j = 0; j < cols_b; ++j) {
        matrix_result[i * cols_b + j] = Type{};
        for (int k = 0; k < rows_a; ++k) {
          matrix_result[i * cols_b + j] +=
              matrix_a[k * cols_a + i] * matrix_b[k * cols_b + j];
        }
      }
    }
  }

  static void GemmM1TransposeV1Ref(const Type* matrix_a, const Type* matrix_b,
                                   Type* matrix_result, int rows_a, int cols_a,
                                   int cols_b) {
    for (int i = 0; i < cols_a; ++i) {
      for (int j = 0; j < cols_b; ++j) {
        Type acc{};
        Type* result_const = matrix_result + i * cols_b + j;
        const Type* matrix_a_const = matrix_a + i;
        const Type* matrix_b_const = matrix_b + j;
        for (int k = 0; k < rows_a; ++k) {
          acc += matrix_a_const[k * cols_a] * matrix_b_const[k * cols_b];
        }
        *result_const = acc;
      }
    }
  }

  /**
   * @brief Accessor (Getter) поля rows_.
   *
   * @return int значение поля rows_
   */
  int get_rows() const noexcept { return rows_; }

  /**
   * @brief Accessor (Getter) поля cols_.
   *
   * @return int значение поля cols_
   */
  int get_cols() const noexcept { return cols_; }

  /**
   * @brief Возвращает указатель на базовый массив, служащий хранилищем
   * элементов. Указатель таков, что диапазон всегда является допустимым
   * диапазоном, даже если контейнер пуст ( в этом случае он не может быть
   * разыменован)
   *
   * @details
   * Если размер матрицы 0, data() может возвращать или не возвращать нулевой
   * указатель.
   *
   * В целом метод по своей сути аналогичен std::vector::data()
   *
   * @return Type* Указатель на базовое хранилище элементов. Для непустых
   * контейнеров возвращаемый указатель сравнивается с адресом первого элемента.
   */
  Type* data() noexcept { return matrix_; }

  /**
   * @brief Индексация по элементам матрицы (строка row, колонка col).
   *
   * @param row номер столбца запрашиваемого элемента
   * @param col номер строки запрашиваемого элемента
   * @return Type& ссылка на значение (row, col)
   */
  Type& operator()(int row, int col) & {
    return const_cast<Type&>(GetMatrixElement(row, col));
  }

  Type& operator()(int row, int col) && = delete;

  /**
   * @brief Индексация по элементам матрицы (строка row, колонка col).
   *
   * @param row номер столбца запрашиваемого элемента
   * @param col номер строки запрашиваемого элемента
   * @return Type& const-ссылка на значение (row, col)
   */
  const Type& operator()(int row, int col) const& {
    return GetMatrixElement(row, col);
  }

  const Type& operator()(int row, int col) const&& = delete;

  /**
   * @brief Перегрузка оператора == для объекта
   *
   * @param other сравниваемая матрица
   * @return true если матрицы равны
   * @return false если матрицы не равны
   */
  bool operator==(const FastMatrix& other) const noexcept {
    return EqMatrix(other);
  }

  /**
   * @brief Перегрузка оператора + для объекта
   *
   * @param other 2е слагаемое (матрица)
   * @return FastMatrix Результат сложения двух матриц
   */
  FastMatrix operator+(const FastMatrix& other) const {
    FastMatrix tmp{*this};
    tmp.SumMatrix(other);
    return tmp;
  }

  /**
   * @brief Перегрузка оператора += для объекта
   *
   * @param other 2е слагаемое (матрица)
   * @return FastMatrix& Результат сложения двух матриц
   */
  FastMatrix& operator+=(const FastMatrix& other) {
    SumMatrix(other);
    return *this;
  }

  /**
   * @brief Перегрузка оператора - для объекта
   *
   * @param other Вычитаемое (матрица)
   * @return FastMatrix Результат вычитания двух матриц (матрица)
   */
  FastMatrix operator-(const FastMatrix& other) const {
    FastMatrix tmp{*this};
    tmp.SubMatrix(other);
    return tmp;
  }

  /**
   * @brief Перегрузка оператора -= для объекта
   *
   * @param other Вычитаемое (матрица)
   * @return FastMatrix& Результат вычитания двух матриц (матрица)
   */
  FastMatrix& operator-=(const FastMatrix& other) {
    SubMatrix(other);
    return *this;
  }

  /**
   * @brief Перегрузка оператор * для умножения объекта на число
   *
   * @param number Число, на которое умножается объект
   * @return FastMatrix Результат умножения текущей матрицы на число
   */
  FastMatrix operator*(Type number) const noexcept {
    FastMatrix tmp{*this};
    tmp.MulNumber(number);
    return tmp;
  }

  /**
   * @brief Перегрузка оператор * для умножения числа на объект FastMatrix
   *
   * @param number Число, на которое умножается объект FastMatrix
   * @param matrix Объект FastMatrix, на который умножается число
   * @return FastMatrix Результат умножения числа на объект FastMatrix
   */
  friend FastMatrix operator*(Type number, const FastMatrix& matrix) noexcept {
    FastMatrix tmp = matrix * number;
    return tmp;
  }

  /**
   * @brief Перегрузка оператор *= для умножения объекта на число
   *
   * @param number Число, на которое умножается объект
   * @return FastMatrix& Результат умножения текущей матрицы на число
   */
  FastMatrix& operator*=(Type number) {
    MulNumber(number);
    return *this;
  }

  /**
   * @brief Перегрузка оператора * для перемножения двух объектов FastMatrix
   *
   * @param other 2й множитель (матрица)
   * @return FastMatrix Результат умножения двух матриц (матрица)
   */
  FastMatrix operator*(const FastMatrix& other) const {
    FastMatrix tmp{*this};
    tmp.MulMatrix(other);
    return tmp;
  }

  /**
   * @brief Перегрузка оператора *= для перемножения двух объектов FastMatrix
   *
   * @param other 2й множитель (матрица)
   * @return FastMatrix& Результат умножения двух матриц (матрица)
   */
  FastMatrix& operator*=(const FastMatrix& other) {
    MulMatrix(other);
    return *this;
  }

  friend std::ostream& operator<<(std::ostream& os, const FastMatrix& matrix) {
    // os.precision(10);
    // os.setf(std::ios::fixed);
    os << "[" << matrix.get_rows() << " x " << matrix.get_cols() << "]"
       << std::endl;
    for (int i = 0; i < matrix.get_rows(); ++i) {
      for (int j = 0; j < matrix.get_cols(); ++j) {
        os << matrix(i, j);
        if (j != matrix.get_cols() - 1) {
          os << " ";
        }
      }
      os << "\n";
    }
    os << std::endl;
    return os;
  }

 private:
  /**
   * @brief Освобождает память, выделенную под массив matrix_. Этот метод будет
   * вызываться из других методов в случаях, когда требуется выполнить
   * перераспределение памяти или освобождение памяти.
   */
  void Free() noexcept {
    delete[] matrix_;
    rows_ = 0;
    cols_ = 0;
    matrix_ = nullptr;
  }

  const Type& GetMatrixElement(int row, int col) const {
    if (row >= rows_ || col >= cols_ || row < 0 || col < 0) {
      throw std::out_of_range("Incorrect input for (), index is out of range.");
    }
    return matrix_[row * cols_ + col];
  }

  int rows_, cols_;
  Type* matrix_;
  // TODO: Специализации epsilon
  // https://stackoverflow.com/questions/22727850/creating-a-value-constant-that-depends-on-the-template-type)
  const float kEpsilon = 1e-6;
};

}  // namespace s21

#endif  // S21_FAST_MATRIX_FAST_MATRIX_H_