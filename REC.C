#include <stdio.h>
#include <math.h>

int main() {
    int hamming[32], n, i, r = 0, error_position = 0;

    printf("Enter the total number of bits in Hamming code: ");
    scanf("%d", &n);

    printf("Enter the Hamming code (space separated):\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &hamming[i]);
    }

    while (pow(2, r) < (n + 1)) {
        r++;
    }

    for (i = 0; i < r; i++) {
        int parity_pos = (int)pow(2, i);
        int parity = 0;

        for (int j = parity_pos - 1; j < n; j += 2 * parity_pos) {
            for (int k = j; k < j + parity_pos && k < n; k++) {
                parity ^= hamming[k];
            }
        }

        if (parity != 0) {
            error_position += parity_pos;
        }
    }

    if (error_position == 0) {
        printf("\nNo error detected.\n");
    } else {
        printf("\nError at bit position: %d\n", error_position);
        hamming[error_position - 1] = 1 - hamming[error_position - 1];
        printf("Corrected Hamming code: ");
        for (i = 0; i < n; i++) {
            printf("%d", hamming[i]);
        }
        printf("\n");
    }

    return 0;
}
