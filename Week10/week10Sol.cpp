#include <iostream>
void swap(char& a, char& b) {
	a ^= b;
	b ^= a;
	a ^= b;
}
size_t strLength(const char* str) {
	if (str == nullptr) {
		return 0;
	}
	size_t counter = 0;
	while (str[counter++]);
	return counter - 1;
}
void myReverse(char* arr) {
	size_t length = strLength(arr);
	for (int i = 0; i < length / 2; i++) {
		swap(arr[i], arr[length - 1 - i]);
	}
}
char toUpper(char symbol) {
	if (symbol >= 'a' && symbol <= 'z') {
		return symbol - ('a' - 'A');
	}
	return symbol;
}
char toLower(char symbol) {
	if (symbol >= 'A' && symbol <= 'Z') {
		return symbol + ('a' - 'A');
	}
	return symbol;
}
void modify(char* arr) {
	size_t length = strLength(arr);
	toLower(arr);
	for (size_t i = 0; i < length; i++) {
		switch (arr[i])
		{
		case 'a':
		case 'o':
		case 'i':
		case 'e':
		case 'u':
			arr[i] = toUpper(arr[i]);
			break;
		default:
			arr[i] = toLower(arr[i]);
		}
	}
}
bool removeAt(char* str, size_t index) {
	if (str == nullptr) {
		return 0;
	}
	bool found = false;
	size_t length = strLength(str);
	for (int i = index; i < length; i++) {
		str[i] = str[i + 1];
		found = true;
	}
	return found;
}

void insert(char* str, size_t index, char element) {
	if (str == nullptr) {
		return;
	}
	size_t length = strLength(str);
	for (int i = length - 1; i >= index; i--) {
		str[i] = str[i - 1];
	}
	str[index] = element;
}

void censureDigits(char* arr) {
	size_t length = strLength(arr);
	for (size_t i = 0; i < length; i++) {
		if (arr[i] >= '0' && arr[i] <= '9') {
			while (arr[i] >= '0' && arr[i] <= '9') {
				removeAt(arr, i);
			}
			insert(arr, i, '*');
		}
	}
}

void toLower(char* text) {
	if (text == nullptr) {
		return;
	}
	size_t length = strLength(text);
	for (size_t i = 0; i < length; i++) {
		text[i] = toLower(text[i]);
	}
}

void sortCharacters(char* arr) {
	toLower(arr);
	size_t length = strLength(arr);
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

void swap(int*& a, int*& b) {
	int* temp = a;
	a = b;
	b = temp;
}

char** separateWords(const char* text) {
	if (text == nullptr) {
		return nullptr;
	}
	size_t length = strLength(text);
	char** result = new char* [1e2];
	for (size_t i = 0; i < 1e2; i++) {
		result[i] = new char[1e2] {0};
	}
	size_t wordIndex = 0;
	size_t currentWordLength = 0;
	for (size_t i = 0; i < length; i++) {
		if (text[i] != ' ') {
			result[wordIndex][currentWordLength++] = text[i];
		}
		else if (currentWordLength > 0) {
			result[wordIndex][currentWordLength] = 0;
			wordIndex++;
			currentWordLength = 0;
		}
	}
	if (currentWordLength > 0) {
		result[wordIndex][currentWordLength] = 0;
		wordIndex++;
	}
	result[wordIndex][0] = 0;
	return result;
}

size_t matrixLength(char** matrix) {
	if (matrix == nullptr) {
		return 0;
	}
	size_t counter = 0;
	while (matrix[counter][0]) {
		counter++;
	}
	return counter;
}

void ex1() {
	char* arr = new char[1e3];
	std::cin.getline(arr, 1e3);
	myReverse(arr);
	std::cout << arr;
}
void ex2() {
	char* arr = new char[1e3];
	std::cin.getline(arr, 1e3);
	modify(arr);
	std::cout << arr;
}

void ex3() {
	char* arr = new char[1e3];
	std::cin.getline(arr, 1e3);
	censureDigits(arr);
	std::cout << arr;
}

void ex4() {
	char* arr = new char[1e3];
	std::cin.getline(arr, 1e3);
	sortCharacters(arr);
	std::cout << arr;
}

void ex5() {
	int a, b;
	std::cin >> a >> b;
	int* aPtr = &a;
	int* bPtr = &b;
	swap(aPtr, bPtr);
	std::cout << *aPtr << " " << *bPtr;
}

void ex6() {
	char* arr = new char[1e4];
	std::cin.getline(arr, 1e4);
	char** result = separateWords(arr);
	for (int i = 0; i < matrixLength(result); i++) {
		std::cout << "[\"" << result[i] << "\"]" << std::endl;
	}
}
int main()
{
	//ex1();
	//ex2();
	//ex3();
	//ex4();
	//ex5();
	//ex6();
}
