#include <stdio.h>

// Function to calculate the average of an array of sales
double calculateAverage(double sales[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += sales[i];
    }
    return sum / n;
}

// Function to find the minimum and maximum sales
void findMinMax(double sales[], int n, double *minSales, double *maxSales, int *minMonthIndex, int *maxMonthIndex) {
    *minSales = sales[0];
    *maxSales = sales[0];
    *minMonthIndex = 0;
    *maxMonthIndex = 0;
    for (int i = 1; i < n; i++) {
        if (sales[i] < *minSales) {
            *minSales = sales[i];
            *minMonthIndex = i;
        }
        if (sales[i] > *maxSales) {
            *maxSales = sales[i];
            *maxMonthIndex = i;
        }
    }
}

// Function to calculate the six-month moving average
double calculateMovingAverage(double sales[], int startIndex) {
    double sum = 0;
    for (int i = startIndex; i < startIndex + 6; i++) {
        sum += sales[i];
    }
    return sum / 6;
}

// Function to sort sales in descending order
void sortSalesDescending(double sales[], int n) {
    int i, j;
    double temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (sales[j] < sales[j + 1]) {
                // Swap the elements if they are in the wrong order
                temp = sales[j];
                sales[j] = sales[j + 1];
                sales[j + 1] = temp;
            }
        }
    }
}

// Function to get the month name based on the month index
const char* getMonthName(int monthIndex) {
    static const char* monthNames[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    return monthNames[monthIndex];
}

int main() {
    // Array to store monthly sales
    double sales[12] = {
        23458.01, 40112.00, 56011.85, 37820.88, 37904.67, 60200.22,
        72400.31, 56210.89, 67230.84, 68233.12, 80950.34, 95225.22
    };

    // Calculate the minimum and maximum sales along with their month indices
    double minSales, maxSales;
    int minMonthIndex, maxMonthIndex;
    findMinMax(sales, 12, &minSales, &maxSales, &minMonthIndex, &maxMonthIndex);

    // Calculate the average sales
    double averageSales = calculateAverage(sales, 12);

    // Print the sales report
    printf("Monthly sales report for 2022:\n");
    printf("Month Sales\n");
    for (int i = 0; i < 12; i++) {
        printf("%s $%.2lf\n", getMonthName(i), sales[i]);
    }

    // Print the sales summary
    printf("Sales summary:\n");
    printf("Minimum sales: $%.2lf (%s)\n", minSales, getMonthName(minMonthIndex));
    printf("Maximum sales: $%.2lf (%s)\n", maxSales, getMonthName(maxMonthIndex));
    printf("Average sales: $%.2lf\n", averageSales);

    // Calculate and print six-month moving averages
    printf("Six-Month Moving Average Report:\n");
    for (int i = 0; i < 7; i++) {
        double movingAverage = calculateMovingAverage(sales, i);
        printf("%s - %s $%.2lf\n", getMonthName(i), getMonthName(i + 5), movingAverage);
    }

    // Sort sales in descending order
    sortSalesDescending(sales, 12);

    // Print the sorted sales report
    printf("Sales Report (Highest to Lowest):\n");
    printf("Month Sales\n");
    for (int i = 0; i < 12; i++) {
        printf("%s $%.2lf\n", getMonthName(11 - i), sales[i]);
    }

    return 0;
}
