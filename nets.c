#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int r;

int calculate_total_bits(int data_bits) {
    r = 0;
    while (pow(2, r) < (data_bits + r + 1)) {
        r++;
    }
    return data_bits + r;
}

void paritybit(int hamming[], int total_bits) {
    int count = 0, i;
    for (i = 0; i < total_bits; i++) {
        if (hamming[i] == 1) {
            count++;
        }
    }
    if (count % 2 == 1) {
        hamming[total_bits + 1] = 1;
    }
}

void fill_parity_bits(int hamming[], int total_bits) {
    for (int i = 0; i < r; i++) {
        int parity_pos = 1 << i;
        int parity_index = parity_pos - 1;
        int parity = 0;

        for (int j = parity_index; j < total_bits; j += 2 * parity_pos) {
            for (int k = j; k < j + parity_pos && k < total_bits; k++) {
                if (k != parity_index)
                    parity ^= hamming[k];
            }
        }

        hamming[parity_index] = parity;
    }
}

int main() {
    int d;
    printf("Enter the number of data bits: ");
    scanf("%d", &d);

    int total_bits = calculate_total_bits(d) + 1;
    int hamming[total_bits];

    

    int i, j = 0, data_index = 0;
    for (i = 0; i < total_bits; i++) {
        if ((i + 1) == (int)pow(2, j)) {
            hamming[i] = 0;
            j++;
        } else {
            printf("Enter data : ");
            scanf("%d", &hamming[i]);
            data_index++;
        }
    }

    fill_parity_bits(hamming, total_bits);
    paritybit(hamming, total_bits - 1);

    printf("\nGenerated Hamming Code: ");
    for (i = 0; i < total_bits; i++) {
        printf("%d", hamming[i]);
    }
    printf("\n");

    return 0;
}
