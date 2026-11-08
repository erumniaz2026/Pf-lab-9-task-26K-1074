#include <stdio.h>

int main()
{
    int readings[7];
    int *ptr = readings;
    int *linkedMeter = NULL;
    int i, total = 0;
    int highest, highestDay;
    int threshold;

    for (i = 0; i < 7; i++)
    {
        printf("Enter reading for day %d: ", i + 1);
        scanf("%d", ptr + i);
    }

    printf("\n========== MEMORY INSPECTION ==========\n");

    for (i = 0; i < 7; i++)
    {
        printf("Day %d Reading: %d\n", i + 1, *(ptr + i));
        printf("Memory Address: %p\n", (void *)(ptr + i));
    }

    printf("\nAddress Difference:\n");

    for (i = 0; i < 6; i++)
    {
        printf("Day %d to Day %d: %td bytes\n",
               i + 1, i + 2,
               (char *)(ptr + i + 1) - (char *)(ptr + i));
    }

    highest = *ptr;
    highestDay = 1;

    for (i = 0; i < 7; i++)
    {
        total = total + *(ptr + i);

        if (*(ptr + i) > highest)
        {
            highest = *(ptr + i);
            highestDay = i + 1;
        }
    }

    printf("\nWeekly Total: %d\n", total);
    printf("Highest Consumption: %d\n", highest);
    printf("Highest Consumption Day: %d\n", highestDay);

    printf("\nEnter peak tariff threshold: ");
    scanf("%d", &threshold);

    for (i = 0; i < 7; i++)
    {
        if (*(ptr + i) > threshold)
        {
            *(ptr + i) = *(ptr + i) * 2;
        }
    }

    printf("\nReadings After Peak Adjustment:\n");

    for (i = 0; i < 7; i++)
    {
        printf("Day %d: %d\n", i + 1, *(ptr + i));
    }

    printf("\nLinked Meter Test:\n");

    if (linkedMeter == NULL)
        printf("Linked meter is not assigned.\n");

    linkedMeter = ptr + 2;

    if (linkedMeter != NULL)
        printf("Linked meter is assigned to Day 3.\n");

    printf("Linked Meter Reading: %d\n", *linkedMeter);

    return 0;
}
