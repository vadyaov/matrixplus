#include "inc/s21_matrix_oop.h"

void f(S21Matrix&& a) {
  std::cout << "ffff\n";
  S21Matrix b (std::move(a));
}

int main() {
  try {
  S21Matrix a {};
  S21Matrix b {3, 3};

  /* std::cout << "a:" << std::endl; */
  /* std::cin >> a; */

  /* std::cout << "b:" << std::endl; */
  /* std::cin >> b; */

  /* S21Matrix c {a + b}; */

  /* std::cout << std::endl; */
  /* std::cout << "a:" << std::endl; */
  /* std::cout << a; */

  } catch (std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  return 0;
}
