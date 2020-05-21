#include "kramer.hpp"

template <typename T>
T gauss_determinant(std::vector<std::vector<T> > &matrix, int n) {
  unsigned int swapCount = triangulation(matrix, n);
  T determinanit = 1;
  if (swapCount % 2 == 1)
    determinanit = -1;
  for (int i = 0; i < n; ++i) {
    determinanit *= matrix[i][i];
  }
  return determinanit;
}

template <typename T>
T swap_column(std::vector<std::vector<T> > &matrix, std::vector<T> &free_term_column, int i, int n){
    for (int j = 0; j < n; ++j) {
        matrix[i][j] = free_term_column[i];
    }
    return i;
}

template <typename T>
int col_max(const std::vector<std::vector<T> > &matrix, int col, int n) {
  T max = std::abs(matrix[col][col]);
  int maxPos = col;
  for (int i = col+1; i < n; ++i) {
    T element = std::abs(matrix[i][col]);
    if (element > max) {
      max = element;
      maxPos = i;
    }
  }
  return maxPos;
}

template <typename T>
int triangulation(std::vector<std::vector<T> > &matrix, int n) {
  unsigned int swapCount = 0;
  for (int i = 0; i < n-1; ++i) {
    unsigned int imax = col_max(matrix, i, n);
    if (i != imax) {
      swap(matrix[i], matrix[imax]);
      ++swapCount;
    }
    for (int j = i + 1; j < n; ++j) {
      T mul = -matrix[j][i]/matrix[i][i];
      for (int k = i; k < n; ++k) {
        matrix[j][k] += matrix[i][k]*mul;
      }
    }
  }
  return swapCount;
}

template <typename T>
std::vector<T> cramer_solving(std::vector<std::vector<T> > &matrix,
                              std::vector<T> &free_term_column, int n) {
  T mainDet = gauss_determinant(matrix, n);
  if (std::abs(mainDet) < 0.0001){
    //throw NoSolution();
      std::cout << " No solution" << std::endl;
      }

  std::vector<T> solution(n);
  #pragma omp parallel
  {
    std::vector<std::vector<T> > private_matrix = matrix;
  #pragma omp for
    for (int i = 0; i < n; ++i) {
      swap_column(private_matrix, free_term_column, i, n);
      solution[i] = gauss_determinant(private_matrix, n) / mainDet;
      swap_column(private_matrix, free_term_column, i, n);
    }
  }
  return solution;
}

