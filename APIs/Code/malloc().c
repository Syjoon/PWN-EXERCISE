#include <cstdlib>
#include <iostream>
using namespace std;
int main()
{
	size_t s = 0;

	int* ptr = (int*)malloc(s);

	if (ptr == NULL) {
		cout << "Null pointer has been returned";
	}
    
	else {
		cout << "Memory has been allocated at address "
			<< ptr << endl;
	}

	free(ptr);
	return 0;
}
////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = malloc(10); // Cấp phát 10 byte
    ptr[0] = 1; // Gán giá trị cho phần tử đầu tiên
    ptr[9] = 2; // Gán giá trị cho phần tử thứ 10
    printf("%d %d\n", ptr[0], ptr[9]); // In ra giá trị của hai phần tử
    free(ptr); // Giải phóng bộ nhớ
    return 0;
}
