#include <clocale>
#include <random>
#include <chrono>
#include <vector>
#include <iostream>


std::vector<float> multiplying(int n) {
	srand(time(NULL));
	std::vector<float> first_matrix(n * n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			first_matrix[i * n + j] = std::rand() % 100;
		}
	}
	std::vector<float> second_matrix(n * n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			second_matrix[i * n + j] = std::rand() % 100;;
		}
	}
	std::vector<float> result_matrix(n * n);
	auto t1 = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			result_matrix[i * n + j] = 0;
			for (int k = 0; k < n; ++k) {
				result_matrix[i * n + j] += first_matrix[i * n + k] * second_matrix[k * n + j];
			}
		}
	}
	auto t2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> time = (t2 - t1);
	std::cout << "Для матриц размером " << n << ": " << time.count() << " секунд" << std::endl;
	return result_matrix;
}


std::vector<float> transposed_multiplying(int n) {
	srand(time(NULL));
	std::vector<float> first_matrix(n * n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			first_matrix[i * n + j] = std::rand() % 100;
		}
	}
	std::vector<float> second_matrix(n * n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			second_matrix[i * n + j] = std::rand() % 100;;
		}
	}
	std::vector<float> result_matrix(n * n);
	auto t1 = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			result_matrix[i * n + j] = 0;
			for (int k = 0; k < n; ++k) {
				result_matrix[i * n + j] += first_matrix[i * n + k] * second_matrix[j * n + k];
			}
		}
	}
	auto t2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> time = (t2 - t1);
	std::cout << "Для матриц размером " << n << ": " << time.count() << " секунд" << std::endl;
	return result_matrix;
}


int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	std::cout << "Введите размер матриц: ";
	std::cin >> n;
	auto matrix1 = multiplying(n);
	auto matrix2 = transposed_multiplying(n);
	return 0;
}
