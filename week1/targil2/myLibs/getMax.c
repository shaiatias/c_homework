
int getMax(int num) {

    int temp = num % 10;
    int max = temp;

    num = num / 10;

    while (num > 0) {

        temp = num % 10;

        if (temp > max) {
            max = temp;
        }

        num = num / 10;
    }

    return max;
}