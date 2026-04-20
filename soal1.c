#include <stdio.h>
int main(void) {
    int N, sum = 0,  maxmin = -1000;
    scanf ("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++){
        scanf ("%d", &arr[i]);
    }
    for (int i = 0 ; i < N; i++){
        int sumbuff = 0;
        int valid = 0, lr = 0;
        if (arr[i] == -1){
            int k = i-1;
            while (valid == 0 && k >= 0){
                if (arr[k] != -1){
                    sumbuff += arr[k];
                    valid = 1;
                    lr++;

                }
                k--;
            }
            valid = 0;
            int j = i+1;
            while (valid == 0 && j < N){
                if (arr[j] != -1){
                    sumbuff += arr[j];
                    valid = 1;
                    lr++;
                }
                j++;
            }
            if (lr != 2){
                arr [i] = sumbuff;
            }
            else if (lr == 2 && sumbuff < 0 && sumbuff %2 != 0){
                arr[i] = sumbuff/2 - 1;
            }
            else {
                arr [i] = (sumbuff/2);
            }
        }
    }
    printf ("RECOVERED ");
    for (int i = 0; i < N ; i++){
        if (i == N-1){
            printf ("%d", arr[i]);
        }
        else {
            printf ("%d ", arr[i]);
        }
        if (arr [i] > 0){
            sum += arr[i];
        }
        else if (arr [i] < 0){
            if (arr[i] > maxmin){
                maxmin = arr[i];
            }
        }
    }
    if (maxmin != -1000){
        sum += maxmin;        
    }
    printf ("\n");
    printf ("MAX_SUM %d\n", sum);
    return 0;
}
