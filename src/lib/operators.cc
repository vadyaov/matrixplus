#include "../inc/s21_matrix_oop.h"

S21Matrix operator+(const S21Matrix& a, const S21Matrix& b) {
  S21Matrix res{a};
  res.SumMatrix(b);
  return res;
}

S21Matrix operator-(const S21Matrix& a, const S21Matrix& b) {
  S21Matrix res{a};
  res.SubMatrix(b);
  return res;
}

S21Matrix operator*(const S21Matrix& a, const S21Matrix& b) {
  S21Matrix res{a};
  return res *= b;
}

S21Matrix operator*(const S21Matrix& a, const double n) {
  S21Matrix tmp{a};
  tmp.MulNumber(n);
  return tmp;
}

bool operator==(const S21Matrix& a, const S21Matrix& b) noexcept {
  return a.EqMatrix(b);
}

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  if (rows_ != other.rows_) set_rows(other.rows_);
  if (cols_ != other.cols_) set_cols(other.cols_);

  std::copy(other.matrix_, other.matrix_ + other.size(), matrix_);
  return *this;
}

S21Matrix& S21Matrix::operator=(S21Matrix&& other) noexcept {
  std::swap(rows_, other.rows_);
  std::swap(cols_, other.cols_);
  std::swap(matrix_, other.matrix_);
  return *this;
}

S21Matrix& operator+=(S21Matrix& a, const S21Matrix& b) {
  a.SumMatrix(b);
  return a;
}

S21Matrix& operator-=(S21Matrix& a, const S21Matrix& b) {
  a.SubMatrix(b);
  return a;
}

S21Matrix& operator*=(S21Matrix& a, const S21Matrix& b) {
  a.MulMatrix(b);
  return a;
}

S21Matrix& operator*=(S21Matrix& a, const double n) noexcept {
  a.MulNumber(n);
  return a;
}

double& S21Matrix::operator()(int row, int col) const {
  if (row >= rows_ || col >= cols_ || row < 0 || col < 0)
    throw std::out_of_range("Incorrect index in S21Matrix& operator()(i, j)");

  return matrix_[col + cols_ * row];
}

S21Matrix operator-(const S21Matrix& a) {
  S21Matrix tmp{a};
  for (int i = 0; i < tmp.get_rows(); ++i)
    for (int j = 0; j < tmp.get_cols(); ++j) tmp(i, j) *= -1.0;
  return tmp;
}
