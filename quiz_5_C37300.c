#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INITIAL_ROWS  3

#define INITIAL_COLUMNS 3

void allocateMatrix(int ***matrix, int row_size, int column_size){

    *matrix = (int **)malloc(row_size * sizeof(int*));

    if (matrix == NULL){
        perror("Error al reservar memoria para las filas");

    }

    for (int i=0; i < row_size; i++){
        (*matrix)[i] = (int*)malloc(column_size * sizeof(int));

        if ((*matrix)[i] == NULL) {
            perror("Fallo al reservar memoria en fila");
        
        }
    }
}



int numero_aleatorio(){
        int num;
    do{
        num = rand() % 100;

    } while(num == 0);
    return num;
}

void fillMatrix(int **matrix, int row_size, int column_size) {
   

    for (int i = 0; i < row_size; i++){
        int *fila = *(matrix + i);
        for (int j = 0; j < column_size; j++) {
            *(fila + j) = numero_aleatorio();
        }
    }

}

void reallocateMatrix(int ***matrix, int row_size, int column_size){
    *matrix = realloc(*matrix, row_size * sizeof(int *));
    for (int i = 0; i < row_size; i++){
        (*matrix)[i] = realloc((*matrix)[i], column_size * sizeof(int));
    }
}

void refillMatrix(int **matrix, int row_size, int column_size){

    for (int i = INITIAL_ROWS; i < row_size; i++){
        int *fila = *(matrix + i);
        for (int j = 0; j < column_size; j++) {
                *(fila + j) = numero_aleatorio();
        }
    }

    for (int i = 0; i < row_size; i++){
        int *fila = *(matrix + i);
        for (int j = INITIAL_COLUMNS; j < column_size; j++) {
                *(fila + j) = numero_aleatorio();
        }
    }
}

void printMatrix(int **matrix, int row_size, int column_size){
    printf("Matrix(%dx%d):\n", row_size, column_size);
    for (int i = 0; i< row_size; i++){
        for (int j = 0; j < column_size; j++){
            printf(" %d", *(*(matrix + i) + j));
        }
        printf("\n");
    }
}

void freeMatrix(int **matrix, int row_size, int column_size){
    for(int i = 0; i < row_size; i++){
        free(matrix[i]);
    }
    free(matrix);
}


int main(){
    srand(time(NULL));
    int row_size, column_size;
    int **matrix = NULL;
    allocateMatrix(&matrix, INITIAL_ROWS, INITIAL_COLUMNS);
    fillMatrix(matrix, INITIAL_ROWS, INITIAL_COLUMNS);
    printMatrix(matrix, INITIAL_ROWS, INITIAL_COLUMNS);

    printf("Ingrese la cantidad de filas que quiere aumentar:\n");
    scanf("%d", &row_size);
    row_size = row_size + INITIAL_ROWS;
    printf("Ingrese la cantidad de columnas que quiere aumentar:\n");
    scanf("%d", &column_size);
    column_size = column_size + INITIAL_COLUMNS;

    reallocateMatrix(&matrix, row_size, column_size);
    refillMatrix(matrix, row_size, column_size);
    printMatrix(matrix, row_size, column_size);

    freeMatrix(matrix, row_size, column_size);




}