#include "kramer.cpp"

int main()
{
      for (int n = 50; n < 251; n += 50) {
        std::vector<std::vector<double> > matrix(n);
        for (int i = 0; i < n; ++i) {
          matrix[i].resize(n);
          for (int j = 0; j < n; ++j)
            matrix[i][j] = rand();
        }

        std::vector<double> column(n);
        for (int j = 0; j < n; ++j)
          column[j] = rand();
        double start_time = omp_get_wtime();
        std::vector<double> solution = cramer_solving(matrix, column, n);
        std::cout << n << " " << omp_get_wtime() - start_time << std::endl;
      }
      std::cout << "that's all!" << std::endl;
}
