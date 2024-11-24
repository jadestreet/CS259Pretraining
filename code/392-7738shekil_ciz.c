void ucgen_ciz(int x) {
	int i, j;
	for (i = 1 ; i <= x ; i++) {
		for (j = 1 ; j <= i ; j++) {
			printf("*");
		}
		printf("\n");
	}
}
int main() {
	ucgen_ciz(3);
	ucgen_ciz(2);
	ucgen_ciz(4);
	return 0;
}
