
#include <stdio.h>
#include <xlocinfo>

int lu_decomposition(){

	int n; double z; double** a; int i, j;
	printf("请输入矩阵A的大小:\n");
	scanf("%d", &n);
	a = (double**)malloc(sizeof(double*) * n);//
	for (i = 0; i < n; i++)a[i] = (double*)malloc(sizeof(double) * n);
	double** a_temp; a_temp = (double**)malloc(sizeof(double*) * n);//
	for (i = 0; i < n; i++)a_temp[i] = (double*)malloc(sizeof(double) * n);

	//LU
	int k; double** m; double max;
	m = (double**)malloc(sizeof(double*) * n);
	for (i = 0; i < n; i++) {
		m[i] = (double*)malloc(sizeof(double) * n);
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			m[i][j] = 0;
	}
	printf("please input matrix A\n");
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) {
			scanf("%lf ", &z);
			a_temp[i][j] = a[i][j] = z;
		}
	printf("A:\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			printf(" %lf ", a[i][j]);
		printf("\n");
	}
	double* b, * b_temp;
	double s;
	b = (double*)malloc(sizeof(double) * n);
	b_temp = (double*)malloc(sizeof(double) * n);
	printf("please give vector b\n");
	scanf("%lf", &s);
	for (i = 0; i < n; i++) {
		scanf("%lf", &s);
		b_temp[i] = b[i] = s;
	}
	printf("b is:\n");
	for (i = 0; i < n; i++)
		printf("%lf ", b[i]);
	printf("\n");

	//start LU
	for (k = 0; k < n - 1; k++) {
		if (a[k][k] == 0) {
			printf("zero zhuyuan！\n");
			return 0;
		}
		//
		for (i = k + 1; i < n; i++)
			m[i][k] = a[i][k] / a[k][k];

		for (j = k + 1; j < n; j++)
			for (i = k + 1; i < n; i++)
				a[i][j] = a[i][j] - m[i][k] * a[k][j];
	}

	printf("m is:\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			printf("%lf ", m[i][j]);
		printf("\n");
	}
	printf("L is:\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			printf("%lf ", m[i][j]);
		printf("\n");
	}
	printf("U is:\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (i > j)
				a[i][j] = 0;
			printf("%lf ", a[i][j]);
		}
		printf("\n");
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			if (i == j)
				m[i][j] = 1;
	}

	printf("the solution of the equ. is:\n");
	//solve Ly=b;
	//下三角的前代法
	double* y;
	y = (double*)malloc(sizeof(double) * n);
	for (i = 0; i < n; i++)
		y[i] = 0;

	for (j = 0; j < n; j++) {
		if (m[j][j] == 0) {
			printf("err: sigular\n");
			return 0;
		}
		y[j] = b[j] / m[j][j];
		for (i = j + 1; i < n; i++) {
			b[i] = b[i] - m[i][j] * y[j];
		}
	}
	printf("y\n");
	for (i = 0; i < n; i++)
		printf("%lf ", y[i]);
	printf("\n");

	//solve Ux=y;
	//上三角回代法
	double* x;
	x = (double*)malloc(sizeof(double) * n);
	for (i = 0; i < n; i++)
		x[i] = 0;
	for (j = n - 1; j >= 0; j--) {
		if (a[j][j] == 0) {
			printf("矩阵奇异\n");
			return 0;
		}
		x[j] = y[j] / a[j][j];
		for (i = 0; i < j; i++)
			y[i] = y[i] - a[i][j] * x[j];
	}
	printf("输出x值\n");
	for (i = 0; i < n; i++)
		printf("%lf ", x[i]);
	printf("\n ");

	//计算残差
	printf("输出残差\n");
	double* r;
	r = (double*)malloc(sizeof(double) * n);
	for (i = 0; i < n; i++)
		r[i] = 0;
	for (i = 0; i < n; i++) {//i是行，遍历所有行
		for (j = 0; j < n; j++) {//一行中从左到右
			r[i] += a_temp[i][j] * x[j];
		}
	}

	double* can;
	can = (double*)malloc(sizeof(double) * n);
	for (i = 0; i < n; i++)
		can[i] = b_temp[i] - r[i];
	for (i = 0; i < n; i++)
		printf("%lf ", can[i]);

	free(r);
	free(can);
	free(x);
	free(y);
	free(m);
	free(b);
	free(a);
	free(b_temp);
	free(a_temp);
}