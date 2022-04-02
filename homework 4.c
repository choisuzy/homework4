#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Method Declaration */
int** create_matrix(int row, int col);                                      /* 2차원 배열의 동적 메모리 할당하는 함수 선언 */
void print_matrix(int** matrix, int row, int col);                          /* 이중포인터 matrix를 통해 int형 row와 col 행렬 출력하는 함수 */
int free_matrix(int** matrix, int row, int col);                            /* 이중포인터 matrix에 할당했던 메모리를 해제하는 함수 선언 */
int fill_data(int** matrix, int row, int col);                              /* 이중포인터 matrix에 랜덤값으로 채우는 함수 선언 */
int addition_matrix(int** matrix_a, int** matrix_b, int row, int col);      /* 이중포인터 matrix_a와 이중포인터 matrix_b에서 둘을 더하는 함수 선언 */
int subtraction_matrix(int** matrix_a, int** matrix_b, int row, int col);   /* 이중포인터 matrix_a와 이중포인터 matrix_b에서 둘을 빼는 함수 선언 */
int transpose_matrix(int** matrix, int** matrix_t, int row, int col);       /* 이중포인터 matrix와 matrix_t를 매개변수로 하여 전치행렬을 구현하는 함수 선언 */
int multiply_matrix(int** matrix_a, int** matrix_t, int row, int col);      /* 이중포인터 matrix_a와 matrix_t 매개변수를 통해 행렬을 곱하는 함수 선언 */

int main()
{  
    char command;       /* char형 command 선언 */                                    
    printf("[----- [Choi Suzy]  [2021024135] -----]\n");   

		int row, col;       /* int형 row와 col 선언 */  
		srand(time(NULL));  /* 초 단위의 랜덤 값 */  

		printf("Input row and col : ");                /* print */  
		scanf("%d %d", &row, &col);                    /* int형 row와 col을 입력자에게 입력받음 */ 
    int** matrix_a = create_matrix(row, col);      /* 2차원 배열의 동적 메모리 할당하는 함수를 이중포인터 matrix_a에 넣음 */ 
		int** matrix_b = create_matrix(row, col);      /* 2차원 배열의 동적 메모리 할당하는 함수를 이중포인터 matrix_b에 넣음 */ 
    int** matrix_a_t = create_matrix(col, row);    /* 2차원 배열의 동적 메모리 할당하는 함수를 이중포인터 matrix_a_t에 넣음 */ 

		printf("Matrix Created.\n");    /* print */ 

		if (matrix_a == NULL || matrix_b == NULL) {return -1;}   /* matrix_a가 null이거나 matrix_b가 null이면 -1 return */ 

		do{
			printf("----------------------------------------------------------------\n");   /* print */ 
			printf("                     Matrix Manipulation                        \n");   /* print */ 
			printf("----------------------------------------------------------------\n");   /* print */ 
			printf(" Initialize Matrix   = z           Print Matrix        = p \n");        /* print */ 
			printf(" Add Matrix          = a           Subtract Matrix     = s \n");        /* print */ 
			printf(" Transpose matrix_a  = t           Multiply Matrix     = m \n");        /* print */ 
			printf(" Quit                = q \n");                                          /* print */ 
			printf("----------------------------------------------------------------\n");   /* print */ 

			printf("Command = ");      /* print */ 
			scanf(" %c", &command);    /* char형 command 값을 입력자에게 입력받음 */ 

			switch(command) {                    /* command가 ~이면 조건문 */ 
			case 'z': case 'Z':                     /* command가 Z나 z이면 */ 
		    	printf("Matrix Initialized\n");  	/* print */ 
					fill_data(matrix_a, row, col);  	/* fill_data 함수 호출 */ 
					fill_data(matrix_b, row, col);   	/* fill_data 함수 호출 */
					break;                                  /* 조건식 빠져나옴 */
        	case 'p': case 'P':                     /* command가 P나 p이면 */
            	printf("Print matrix\n");           /* print */ 
            	printf("matrix_a\n");               /* print */ 
				print_matrix(matrix_a, row, col);   /* matrix_a에서의 print_matrix 함수 호출 */
				printf("matrix_b\n");               /* print */ 
				print_matrix(matrix_b, row, col);   /* matrix_b에서의 print_matrix 함수 호출 */
			break;                                  /* 조건식 빠져나옴 */
        	case 'a': case 'A':                     /* command가 A나 a이면 */
				printf("Add two matrices\n");       /* print */
				addition_matrix(matrix_a, matrix_b, row, col);     /* matrix_a에서 matrix_b를 더하는 addition_matrix 함수 호출 */
			break;                                  /* 조건식 빠져나옴 */
        	case 's': case 'S':                     /* command가 s나 S이면 */
				printf("Subtract two matrices \n"); /* print */
            	subtraction_matrix(matrix_a, matrix_b, row, col);  /* matrix_a에서 matrix_b를 빼는 subtraction_matrix 함수 호출 */
			break;                                  /* 조건식 빠져나옴 */
        	case 't': case 'T':                     /* command가 t나 T이면 */
				printf("Transpose matrix_a \n");    /* print */
				printf("matrix_a\n");               /* print */
            	transpose_matrix(matrix_a, matrix_a_t, col, row);  /* matrix_a의 전치행렬 matrix_a_t를 구현하는 transpose_matrix 함수 호출 */
            	print_matrix(matrix_a_t, col, row);                /* matrix_a_t에서의 print_matrix 함수 호출 */
			break;     /* 조건식 빠져나옴 */
        	case 'm': case 'M':                    /* command가 m이나 M이면 */
				printf("Multiply matrix_a with transposed matrix_a \n");  /* print */
				transpose_matrix(matrix_a, matrix_a_t, col, row);         /* transpose_matrix 함수 호출 */
            	multiply_matrix(matrix_a, matrix_a_t, row, col);          /* multiply_matrix 함수 호출 */
			break;     /* 조건식 빠져나옴 */
        	case 'q': case 'Q':                   /* command가 q나 Q이면 */
            	printf("Free all matrices..\n");  /* print */
            	free_matrix(matrix_a_t, col, row);  /* matrix_a_t에 할당했던 메모리를 해제하는 free_matrix 함수 호출 */
            	free_matrix(matrix_a, row, col);    /* matrix_a에 할당했던 메모리를 해제하는 free_matrix 함수 호출 */
            	free_matrix(matrix_b, row, col);    /* matrix_b에 할당했던 메모리를 해제하는 free_matrix 함수 호출 */
			break;     /* 조건식 빠져나옴 */
			default:   /* 나머지 조건들이 다 거짓일때 */
				printf("\n       >>>>>   Concentration!!   <<<<<     \n");  /* print */
			break;     /* 조건식 빠져나옴 */
		}

	}while(command != 'q' && command != 'Q');     /* command가 q가 아니고 Q가 아니라면 do루프 계속 돎 */

	return 1;  /* 1을 return함 */
}

/* create a 2d array whose size is row x col using malloc() */
int** create_matrix(int row, int col)   /* 2차원 배열의 동적 메모리 생성하는 함수 */ /* 전처리 및 후처리 검사를 수행하여 비정상적인 입력과 결과값에 대비 */          
{
	/* Check pre conditions */  /* 전처리기 검사 */
	if (row <= 0 || col <= 0) {         /* row가 0보다 작거나 같거나 col이 0보다 작거나 같다면 */
		printf("Check the size of row and col!\n");  /* print */
		return NULL;    /* null return */
	}

	int** matrix = (int**)malloc(sizeof(int*) * row);  /* 정수형 포인터의 크기에 row의 개수를 곱한만큼 int형 동적 메모리를 이중포인터 matrix에 할당*/
	for (int r = 0; r < row; r++) {   /* r이 row번 도는 for루프 */
		matrix[r] = (int*)malloc(sizeof(int) * col);   /* 정수형의 크기에 col의 개수를 곱한만큼 int형 동적 메모리를 matrix 배열에 할당 */
	}

	/* Check post conditions */   /* 후처리기 검사 */
	if (matrix == NULL) {     /* matrix가 비었다면 */
		printf("Memory Allocation Failed.\n");   /* print */
		return NULL;          /* null을 return */
	}

	return matrix;            /* matrix을 return */
}

/* print matrix whose size is row x col */
void print_matrix(int** matrix, int row, int col)     /* 이중포인터 matrix를 통해 int형 row와 col 행렬 출력하는 함수 */
{
	/* Check pre conditions */
	if (row <= 0 || col <= 0) {     /* row가 0보다 적거나 같거나 col이 0보다 작거나 같으면 */
		printf("Check the size of row and col!\n");   /* print */
		return;  /* return */
	}
    for (int matrix_row = 0; matrix_row < row; matrix_row++) {    /* matrix_row를 row번 동안 for루프 돈다. */
		for (int matrix_col = 0; matrix_col < col; matrix_col++)  /* matrix_col을 col번 동안 for루프 돈다. */
			printf("%3d ", matrix[matrix_row][matrix_col]);       /* matrix배열을 print */
		printf("\n");   /* print */
	}
	printf("\n");       /* print */
	/* Check post conditions */
	 if (matrix == NULL) {    /* matrix가 null이면 */
		printf("Memory Allocation Failed.\n");    /* 메모리 할당 실패라는 문구 print */
		return;          /* return */
	}


	return;              /* return */
}


/* free memory allocated by create_matrix() */
int free_matrix(int** matrix, int row, int col)  /* 이중포인터 matrix에 할당했던 메모리를 해제하는 함수 */
{
	/* Check pre conditions */
	if (row <= 0 || col <= 0) {    /* row가 0보다 적거나 같거나 col이 0보다 작거나 같으면 */
		printf("Check the size of row and col!\n");      /* 행과 열의 사이즈를 체크하라는 문구 print */
		return -1;   /* -1을 return */
	} 

	for (int matrix_row = 0; matrix_row < row; matrix_row++) {   /* matrix_row를 row번 동안 for루프 돈다. */
		free(matrix[matrix_row]);    /* matrix_row의 matrix배열을 해제함 */        
	}

	free(matrix);       /* matrix 해제함 */ 
	return 1;           /* 1을 return */
}


/* assign random values to the given matrix */
int fill_data(int** matrix, int row, int col)   /* 이중포인터 matrix에 랜덤값으로 채우는 함수 */
{
	/* Check pre conditions */
	if (row <= 0 || col <= 0) {     /* row가 0보다 적거나 같거나 col이 0보다 작거나 같으면 */
		printf("Check the size of row and col!\n"); /* print */
		return -1; /* -1 return */
	}
    for (int matrix_row = 0; matrix_row < row; matrix_row++)      /* matrix_row를 row번 동안 for루프 돈다. */
		for (int matrix_col = 0; matrix_col < col; matrix_col++)  /* matrix_col를 col번 동안 for루프 돈다. */
			matrix[matrix_row][matrix_col] = rand() % 20;         /* 설정한 row와 col만큼의 배열에 0~19 사이의 값을 갖는 랜덤값으로 채운다. */
	/* Check post conditions */
    if (matrix == NULL) {   /* matrix가 null이라면 */
		printf("Memory Allocation Failed.\n");   /* 메모리 할당 실패라는 문구 print */
		return -1;    /* -1 return */
	}
	return 1; /* 1 return */
}

/* mmatrix_sum = matrix_a + matrix_b */
int addition_matrix(int** matrix_a, int** matrix_b, int row, int col)  /* 이중포인터 matrix_a와 이중포인터 matrix_b에서 배열의 같은 행열을 가진 원소를 각각 더하는 함수 */
{
    int** matrix_sum = create_matrix(row, col);  /* 이중포인터 matrix_sum에 create_matrix 함수 넣음 */
	/* Check pre conditions */
	if (row <= 0 || col <= 0) {    /* row가 0보다 적거나 같거나 col이 0보다 작거나 같으면 */
		printf("Check the size of row and col!\n");  /* print */
		return -1; /* -1 return */
	}
	for (int matrix_row = 0; matrix_row < row; matrix_row++) {  /* matrix_row를 row번 동안 for루프 돈다. */
		for (int matrix_col = 0; matrix_col < col; matrix_col++)   /* matrix_col를 col번 동안 for루프 돈다. */
			matrix_sum[matrix_row][matrix_col] = matrix_a[matrix_row][matrix_col] + matrix_b[matrix_row][matrix_col]; /* 배열의 같은 행열을 가진 matrix_a의 원소와 matrix_b의 원소를 각각 더한 다음 matrix_sum에 넣음 */
	}
	/* Check post conditions */
	if (matrix_a == NULL || matrix_b == NULL || matrix_sum == NULL) {  /* matrix_a가 비거나 matrix_b가 비거나 matrix_sum이 비면 */
		printf("Memory Allocation Failed.\n");  /* 메모리 할당 실패라는 문구 print */
		return -1;  /* -1 return */
	}

	print_matrix(matrix_sum, row, col);  /* print_matrix 함수 호출 */
	free_matrix(matrix_sum, row, col);   /* free_matrix 함수 호출 */
	return 1;       /* 1 return */
}

/* matrix_sub = matrix_a - matrix_b */
int subtraction_matrix(int** matrix_a, int** matrix_b, int row, int col)  /* 이중포인터 matrix_a와 이중포인터 matrix_b에서 둘을 빼는 함수 */
{
    int** matrix_sub = create_matrix(row, col);  /* create_matrix 함수를 이중포인터 matrix_sub에 넣음 */
	/* Check pre conditions */
	if (row <= 0 || col <= 0) {    /* row가 0보다 적거나 같거나 col이 0보다 작거나 같으면 */
		printf("Check the size of row and col!\n");  /* print */
		return -1;  /* -1 return */
	}
	for (int matrix_row = 0; matrix_row < row; matrix_row++) {    /* matrix_row를 row번 동안 for루프 돈다. */
		for (int matrix_col = 0; matrix_col < col; matrix_col++)  /* matrix_col을 col번 동안 for루프 돈다. */
			matrix_sub[matrix_row][matrix_col] = matrix_a[matrix_row][matrix_col] - matrix_b[matrix_row][matrix_col]; /* 배열의 같은 행열을 가진 matrix_a의 원소와 matrix_b의 원소를 각각 뺀 다음 matrix_sum에 넣음 */
	}
	/* Check post conditions */
    if (matrix_a == NULL || matrix_b == NULL || matrix_sub == NULL) {  /* matrix_a가 비거나 matrix_b가 비거나 matrix_sum이 비면 */
		printf("Memory Allocation Failed.\n");  /* 메모리 할당 실패라는 문구 print */
		return -1;  /* -1 return */
	}
	print_matrix(matrix_sub, row, col);   /* print_matrix 함수 호출 */
	free_matrix(matrix_sub, row, col);    /* free_matrix 함수 호출 */

	return 1;      /* 1 return */
}

/* transpose the matrix to matrix_t */
int transpose_matrix(int** matrix, int** matrix_t, int row, int col)  /* 이중포인터 matrix와 matrix_t를 매개변수로 하여 전치행렬을 구현하는 함수 */
{
	/* Check pre conditions */
	if (row <= 0 || col <= 0) {   /* row가 0보다 적거나 같거나 col이 0보다 작거나 같으면 */
		printf("Check the size of row and col!\n");  /* print */
		return -1;  /* -1 return */
	}
	for (int matrix_row = 0; matrix_row < row; matrix_row++) {    /* matrix_row를 row번 동안 for루프 돈다. */
		for (int matrix_col = 0; matrix_col < col; matrix_col++)  /* matrix_col을 col번 동안 for루프 돈다. */
			matrix_t[matrix_row][matrix_col] = matrix[matrix_col][matrix_row]; /* matrix의 각 원소의 행렬을 열 우선으로 전치해 matrix_t에 대입 */
	}
	/* Check post conditions */
    if (matrix == NULL || matrix_t ==NULL) {  /* matrix가 null이거나 matrix_t가 null이면 */
		printf("Memory Allocation Failed.\n"); /* print */
		return -1;  /* -1 return */
	}

	return 1;   /* 1 return */
}

/* matrix_axt - matrix_a x matrix_t */
int multiply_matrix(int** matrix_a, int** matrix_t, int row, int col)   /* 이중포인터 matrix_a와 matrix_t 매개변수를 통해 행렬을 곱하는 함수 */
{
    int** matrix_axt = create_matrix(row, row); /* create_matrix 함수를 이중포인터 matrix_axt에 넣음 */
	/* Check pre conditions */ 
	if (row <= 0 || col <= 0) {    /* row가 0보다 적거나 같거나 col이 0보다 작거나 같으면 */
		printf("Check the size of row and col!\n");  /* print */
		return -1;  /* -1 return */
	}
	for (int matrix_a_row = 0; matrix_a_row < row; matrix_a_row++) {      /* matrix_a_row를 row번 동안 for루프 돈다. */
		for (int matrix_t_row = 0; matrix_t_row < row; matrix_t_row++) {  /* matrix_t_row를 row번 동안 for루프 돈다. */
			int temp = 0;   /* temp를 0으로 설정 */
			for (int matrix_col = 0; matrix_col < col; matrix_col++) /* matrix_col을 col번 동안 for루프 돈다. */
				temp += matrix_a[matrix_a_row][matrix_col] * matrix_t[matrix_col][matrix_t_row]; /* 행렬 matrix_a와 행렬 matrix_t에 있는 원소의 값을 각각 곱해서 temp에 더해서 저장 */
			matrix_axt[matrix_a_row][matrix_t_row] = temp; /* temp값을 matrix_axt에 넣음 */
		}
	}
	/* Check post conditions */
    if (matrix_t == NULL || matrix_axt ==NULL) {  /* matrix_t가 null이거나 matrix_axt가 null이면 */
		printf("Memory Allocation Failed.\n");    /* print */
		return -1;  /* -1 return */
	}
	print_matrix(matrix_axt, row, row);   /* print_matrix 함수 호출 */
	free_matrix(matrix_axt, row, col);    /* free_matrix 함수 호출 */
	return 1;  /* 1 return */
}