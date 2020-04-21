#include <stdio.h>
#include <math.h>

long long countFactorial (long long number) {
    if (number <= 1) {
        return 1;
    } else return number*countFactorial(number - 1);
}
int checkAccuracy(double x, double err) {
    double sum = x, result = 1;
   
    while (fabs(sin(x) - sum) >= err) {
        sum += pow(-1, result - 1) * (pow(x, 2*result - 1)/countFactorial(2*result - 1));
        result++;
    }
    return result;
}

int main() {
    double x, error;
    int result;
    
    printf("Pogreshnost: ");
    scanf("%lfouble", &error);
    fflush(stdin);
    printf("x: ");
    scanf("%lfouble", &x);
    result = checkAccuracy(x, error);
    printf("%s%d%s", "if number is = ", result, " it`s your accuracy\n");
}



