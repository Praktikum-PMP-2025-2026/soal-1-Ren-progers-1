#include <stdio.h>

#include <stdio.h>

int main(void) {
    int N, sum = 0;
    scanf ("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++){
        scanf ("%d", &arr[i]);
    }
    for (int i = 0 ; i < N; i++){
        int sumbuff = 0;
        int valid = 0;
        if (arr[i] == -1){
            int k = i-1;
            while (valid == 0 && k >= 0){
                if (arr[k] != -1){
                    sumbuff += arr[k];
                    valid = 1;
                }
                k--;
            }
            valid = 0;
            int j = i+1;
            while (valid == 0 && j < N){
                if (arr[j] != -1){
                    sumbuff += arr[j];
                    valid = 1;
                }
                j++;
            }
            
            arr[i] = sumbuff/2;
        }
    }
    printf ("RECOVERED ");
    for (int i = 0; i < N ; i++){
        printf ("%d ", arr[i]);
        sum += arr[i];
    }
    printf ("\n");
    printf ("MAX_SUM %d\n", sum);
    return 0;
}
