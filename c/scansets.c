#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
	char a[100];
	scanf("%[^\n]s", a);
	printf("%s\n", a);
	return 0;
}

