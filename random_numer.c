#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gen_random_numbers(int *array, int len, int min, int max){
    for (int i = 0; i < len; i++)
        array[i] = rand() % (max - min + 1) + min;
}

int main() {
    system("cls");
    srand(time(0));

    int numbers[100] = {};
    gen_random_numbers(numbers, 100, 50, 70);
    // create 100 arrays, each of them is in range of [50, 70]
    
    return 0;
}
