#include <stdio.h>
#include <stdlib.h>

void partitionHelper(int finalSum, int currentSum, int depth, int array[finalSum], int count[1]){
    if(currentSum == finalSum){
        count[0]++;
        for(int j = 0; j < finalSum - 1; j++)
            printf("%d x %d  +  ", j+1, array[j]);
        printf("%d x %d\n", finalSum, array[finalSum-1]);
        return;
    }
   if(currentSum > finalSum || depth > finalSum)
        return;
    int numTerms = finalSum/depth;
    for(int i = 0; i <= numTerms; i++){
        //reset array
        for(int k = depth-1; k < finalSum; k++)
            array[k] = 0;
        array[depth-1] = i;
        partitionHelper(finalSum, currentSum + (i*depth), depth + 1, array, count);
    }
}

void partition(int finalSum){
    int count[1] = {0};
    printf("\npartition of %d:\n", finalSum);
    int *array = malloc(finalSum * sizeof(int));
    partitionHelper(finalSum, 0, 1, array, count);
    printf("%d combinations\n\n", count[0]);
}

int main(int argc, char **argv){
    int num = 0;
    printf("Enter positive integer to partition: ");
    scanf("%d", &num);
    partition(num);
    main(argc, argv);
}
