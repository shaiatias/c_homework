#include <stdio.h>

int degree(double arr[], int size);

int is_zero(double arr[], int size);

void div(double arr1[], double arr2[], int n1, int n2);

void mult(double arr1[], double arr2[], int n1, int n2, double res[]);

void sub(double arr1[], double arr2[], int n1, int n2);

void add(double arr1[], double arr2[], int n1, int n2);

void show(double arr[], int size);

void init(double arr[], int size);

void copy(double arr1[], double arr2[], int size);

void div_lead(double rem[], double div[], int rem_len, int div_len, double temp[]);

int main() {
    double A[] = {1, 2, 3};
    double B[] = {3, 4, 5};

    printf("F1: ");
    show(A, 3);

    printf("F2: ");
    show(B, 3);

    div(A, B, 3, 3);
}

void div(double arr1[], double arr2[], int n1, int n2) {

    int length = (n1 > n2) ? n1 : n2;
    double q[length];
    init(q, length);
    int r_len = n1;

    double r[r_len];
    copy(r, arr1, r_len);

    while (!is_zero(r, r_len) && (degree(r, r_len) >= degree(arr2, n2))) {
        double t[length];
        init(t, length);
        div_lead(r, arr2, r_len, n2, t);
        add(q, t, length, length);

        double temp[length];
        init(temp, length);
        mult(t, arr2, length, n2, temp);
        sub(r, temp, r_len, r_len);
    }

    printf("REMAINDER: ");
    show(q, length);

    printf("QUOTIENT: ");
    show(r, r_len);
}

void sub(double arr1[], double arr2[], int n1, int n2) {

    for (int i = 0; i < n1; i++) {
        arr1[i] -= arr2[i];
    }
}

void add(double arr1[], double arr2[], int n1, int n2) {

    for (int i = 0; i < n1; i++) {
        arr1[i] += arr2[i];
    }
}

int degree(double arr[], int size) {

    while (arr[--size] == 0 && size >= 0);
    return size;
}

void mult(double arr1[], double arr2[], int n1, int n2, double res[]) {

    double tmp[n1];
    init(tmp, n1);

    for (int i = 0; i < n1; i++) {
        if (arr1[i] != 0) {
            tmp[i] = arr1[i];
            break;
        }
    }

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            res[i + j] += (tmp[i] * arr2[j]);
        }
    }
}

void show(double arr[], int size) {

    for (int i = 0; i < size; i++) {

        if (arr[i] == 0) continue;

        if (i == 0) {
            printf("%.1lf", arr[i]);
        }

        else {
            if (arr[i] > 0) {
                printf("+%.1lf", arr[i]);
            }
            if (arr[i] < 0) {
                printf("%.1lf", arr[i]);
            }
            if (i == 1) {
                printf("X");
            } else {
                printf("X^%d", i);
            }
        }
    }

    printf("\n");
}

void init(double arr[], int size) {

    for (int i = 0; i < size; i++) {
        arr[i] = 0;
    }
}

int is_zero(double arr[], int size) {

    for (int i = 0; i < size; i++) {
        if (arr[i] != 0) {
            return 0;
        }
    }

    return 1;
}

void copy(double arr1[], double arr2[], int size) {

    for (int i = 0; i < size; i++) {
        arr1[i] = arr2[i];
    }
}

void div_lead(double rem[], double div[], int rem_len, int div_len, double temp[]) {

    int r_leading = 0, d_leading = 0;

    for (int i = rem_len - 1; i >= 0; i--) {
        if (rem[i] != 0) {
            r_leading = i;
            break;
        }
    }

    for (int i = div_len - 1; i >= 0; i--) {
        if (div[i] != 0) {
            d_leading = i;
            break;
        }
    }

    temp[r_leading - d_leading] = rem[r_leading] / div[d_leading];
}
