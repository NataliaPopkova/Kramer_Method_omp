#pragma once

#include <iostream>
#include <time.h>
#include <omp.h>
#include <vector>
#include "omp.h"

template <typename T>
std::vector<T> cramer_solving(std::vector<std::vector<T> > &matrix, std::vector<T> &free_term_column, int n);

template <typename T>
T gauss_determinant(std::vector<std::vector<T> > &matrix, int n);

template <typename T>
T swap_column(std::vector<std::vector<T> > &matrix, std::vector<T> &free_term_column, int i, int n);

template <typename T>
int triangulation(std::vector<std::vector<T> > &matrix, int n);

template <typename T>
int col_max(const std::vector<std::vector<T> > &matrix, int col, int n);
