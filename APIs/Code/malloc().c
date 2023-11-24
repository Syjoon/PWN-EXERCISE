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
