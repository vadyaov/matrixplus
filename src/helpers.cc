#include "matrix_oop.h"

// imho it would be better to be private function but task doesn't allow
void S21Matrix::resize() {
  S21Matrix tmp {rows_, cols_};
  for (auto i = 0; i < rows_; i++)
    for (auto j = 0; j < cols_; j++)
      tmp(i, j) = this->operator()(i, j);

  this->~S21Matrix();
  matrix_ = new double[rows_ * cols_];

  for (auto i = 0; i < rows_; i++)
    for (auto j = 0; j < cols_; j++)
      this->operator()(i, j) = tmp(i, j);
}

double multiply(int i, int j, const S21Matrix& left, const S21Matrix& right) {
  double ij{0.0};
  for (auto k = 0; k < left.getCols(); k++)
    ij += left(i, k) * right(k, j);
  return ij;
}

S21Matrix SimpleMinor(const S21Matrix& other) {
  S21Matrix tmp{2, 2};
  tmp(0, 0) = other(1, 1);
  tmp(0, 1) = -other(1, 0);
  tmp(1, 0) = -other(0, 1);
  tmp(1, 1) = other(0, 0);
  return tmp;
}

double CalcMinor(const S21Matrix& other, const int i, const int j) {
  S21Matrix smaller = CreateSmaller(other, i, j);
  double minor = Det(smaller);
  return minor;
}

S21Matrix CreateSmaller(const S21Matrix& other, const int i, const int j) {
  S21Matrix smaller {other.getRows() - 1, other.getCols() - 1};
  auto sz = other.getRows();
  for (auto k = 0, n = 0; k < sz; k++) {
    if (i == k) continue;
    for (auto l = 0, m = 0; l < sz; l++) {
      if (l == j) continue;
      smaller(n, m) = other(k, l);
      m++;
    }
    n++;
  }
  return smaller;
}

double Det(const S21Matrix& other) {
  double det = 0.0;
  if (other.getRows() == 2) {
    det = other(0, 0) * other(1, 1) - other(0, 1) * other(1, 0);
    return det;
  }
  for (auto j = 0; j < other.getCols(); j++) {
    S21Matrix smaller = CreateSmaller(other, 0, j);
    det += std::pow(-1.0, j) * Det(smaller) * other(0, j);
  }
  return det;
}

std::ostream& operator<<(std::ostream& os, const S21Matrix& m) {
  for (int i = 0; i < m.getRows(); i++) {
    for (int j = 0; j < m.getCols(); j++) {
      os << m(i, j) << " ";
    }
    os << std::endl;
  }
  return os;
}

std::istream& operator>>(std::istream& is, const S21Matrix& m) {
  for (int i = 0; i < m.getRows(); i++)
    for (int j = 0; j < m.getCols(); j++)
      is >> m(i, j);
  return is;
}