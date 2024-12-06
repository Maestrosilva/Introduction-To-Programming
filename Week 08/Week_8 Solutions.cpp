#include <iostream>
const size_t ARRAY_SIZE = 1e3;

void printArray(char a[], size_t length) {
	std::cout << "[";
	for (size_t i = 0; i < length - 1; i++) {
		std::cout << a[i] << ", ";
	}
	std::cout << a[length - 1] << "]" << std::endl << std::endl;
}

unsigned pow(int a, unsigned short power) {
	int result = 1;
	for (int i = 0; i < power; i++) {
		result *= a;
	}
	return result;
}

void swap(int& a, int& b) {
	a ^= b;
	b ^= a;
	a ^= b;
}

int max(int a, int b) {
	return a > b ? a : b;
}

int min(int a, int b) {
	return a < b ? a : b;
}

unsigned short countOfOnes(int a) {
	unsigned short count = 0;
	while (a) {
		count += a & 1;
		a >>= 1;
	}
	return count;
}

void readArray(char arr[], size_t length) {
	for (size_t i = 0; i < length; i++) {
		std::cin >> arr[i];
	}
}

void readArray(int arr[], size_t length) {
	for (size_t i = 0; i < length; i++) {
		std::cin >> arr[i];
	}
}

void changeBit(size_t& n, size_t p, bool b) {
	//100010, 1, 0
	//111101
	if ((n >> p) & 1 && !b) {
		n &= ~(1 << p);
	}
	else if (!((n >> p) & 1) && b) {
		n |= (1 << p);
	}
	//10001010, 0, 1
	//00000001
}

void ex1() {
	size_t x, m, n;
	std::cin >> x >> m >> n;
	int result = 0;
	unsigned short power = 0;
	for (size_t i = m - n + 1; i <= m; i++) {
		result += ((x >> i) & 1) * pow(2, power++);
	}
	std::cout << result;
	//10000
}

void ex2() {
	size_t n;
	std::cin >> n;
	std::cout << countOfOnes(n);
}

void ex3() {
	size_t n, k;
	std::cin >> n >> k;
	std::cout << n - ((n >> k) << k);
}

void ex4() {
	int a, b;
	std::cin >> a >> b;
	swap(a, b);
	std::cout << a << " " << b;
}

void ex5() {
	size_t n, p, b;
	std::cin >> n >> p >> b;
	changeBit(n, p, b);
	std::cout << n;
}

void ex6() {
	int a, b;
	std::cin >> a >> b;
	if (max(a, b) / min(a, b) >= 2) {
		std::cout << 0;
		return;
	}
	int aOnes = countOfOnes(a);
	int bOnes = countOfOnes(b);
	std::cout << (aOnes == bOnes);
}

void bonus1() {
	int arr[ARRAY_SIZE] = {};
	size_t length;
	std::cin >> length;
	readArray(arr, length);
	int result = 0;
	for (int i = 0; i < length; i++) {
		result ^= arr[i];
	}
	std::cout << result;
}

void bonus2() {
	char a[ARRAY_SIZE] = "";
	size_t length;
	std::cin >> length;
	readArray(a, length);
	printArray(a, length);
	for (size_t i = 0; i < (1 << length); i++) {
		std::cout << "{";
		bool first = true;
		for (size_t j = 0; j < length; j++) {
			if (i & (1 << j)) {
				if (!first) {
					std::cout << ", ";
				}
				std::cout << a[j];
				first = false;
			}
		}
		std::cout << "}" << std::endl;
	}
}

int main() {
	ex1();
	// 16 4 3
	
	//ex2();
	// 189
	
	//ex3();
	// 15 2 |  189 3 | 189 4
	
	//ex4();
	// 120 2 
	
	//ex5();
	// 120 4 0 | 120 2 1
	
	//ex6();
	// 7 11 

	//bonus1();
	// 7 9 18 9 12 18 15 12

	//bonus2();
	//4 1 2 3 4
}
