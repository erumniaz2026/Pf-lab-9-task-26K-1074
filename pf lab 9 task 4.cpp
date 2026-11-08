#include <stdio.h>

void swapValues(int a, int b);
void repairCounters(int *a, int *b);
void calculateOccupancy(int daily[], int size, int *total,
                        int *highest, int *lowest);

int main()
{
    int wardA = 20, wardB = 35;
    int wardC = 10, wardD = 15;

    int daily[7] = {20, 25, 30, 18, 35, 28, 22};

    int total, highest, lowest;

    printf("========== PASS BY VALUE ==========\n");

    printf("Before Function:\n");
    printf("Ward C: %d\n", wardC);
    printf("Ward D: %d\n", wardD);

    printf("Address of Ward C: %p\n", (void *)&wardC);
    printf("Address of Ward D: %p\n", (void *)&wardD);

    swapValues(wardC, wardD);

    printf("\nAfter Pass by Value:\n");
    printf("Ward C: %d\n", wardC);
    printf("Ward D: %d\n", wardD);

    printf("\n========== PASS BY ADDRESS ==========\n");

    printf("Before Repair:\n");
    printf("Ward A: %d\n", wardA);
    printf("Ward B: %d\n", wardB);

    printf("Address of Ward A: %p\n", (void *)&wardA);
    printf("Address of Ward B: %p\n", (void *)&wardB);

    repairCounters(&wardA, &wardB);

    printf("\nAfter Repair:\n");
    printf("Ward A: %d\n", wardA);
    printf("Ward B: %d\n", wardB);

    printf("\n========== OCCUPANCY REPORT ==========\n");

    calculateOccupancy(daily, 7, &total, &highest, &lowest);

    printf("Total Occupancy: %d\n", total);
    printf("Highest Occupancy: %d\n", highest);
    printf("Lowest Occupancy: %d\n", lowest);

    return 0;
}

void swapValues(int a, int b)
{
    int temp;

    printf("\nInside Pass by Value Function:\n");
    printf("Address of a: %p\n", (void *)&a);
    printf("Address of b: %p\n", (void *)&b);

    temp = a;
    a = b;
    b = temp;

    printf("Inside Function Ward C: %d\n", a);
    printf("Inside Function Ward D: %d\n", b);
}

void repairCounters(int *a, int *b)
{
    int temp;

    printf("\nInside Pass by Address Function:\n");
    printf("Address stored in a: %p\n", (void *)a);
    printf("Address stored in b: %p\n", (void *)b);

    temp = *a;
    *a = *b;
    *b = temp;
}

void calculateOccupancy(int daily[], int size, int *total,
                        int *highest, int *lowest)
{
    int i;

    *total = 0;
    *highest = daily[0];
    *lowest = daily[0];

    printf("\nInside Occupancy Function:\n");
    printf("Address of daily array: %p\n", (void *)daily);
    printf("Address of total: %p\n", (void *)total);
    printf("Address of highest: %p\n", (void *)highest);
    printf("Address of lowest: %p\n", (void *)lowest);

    for (i = 0; i < size; i++)
    {
        *total = *total + daily[i];

        if (daily[i] > *highest)
            *highest = daily[i];

        if (daily[i] < *lowest)
            *lowest = daily[i];
    }
}
