 #include <stdio.h>

int calculateTotal(int marks[], int size);
float calculateAverage(int total, int size);
int findHighest(int marks[], int size);
int findLowest(int marks[], int size);
int countPass(int marks[], int size, int threshold);
int countTopScorers(int marks[], int size, int highest);
void applyBonus(int marks[], int size, int bonus);
void displayReport(int marks[], int size, int threshold);

int main()
{
    int marks[10];
    int threshold, bonus;
    int i;

    for (i = 0; i < 10; i++)
    {
        printf("Enter marks of student %d: ", i + 1);
        scanf("%d", &marks[i]);

        while (marks[i] < 0 || marks[i] > 100)
        {
            printf("Invalid marks. Enter again: ");
            scanf("%d", &marks[i]);
        }
    }

    printf("\nEnter passing threshold: ");
    scanf("%d", &threshold);

    displayReport(marks, 10, threshold);

    printf("\nEnter bonus marks: ");
    scanf("%d", &bonus);

    while (bonus < 0)
    {
        printf("Enter a non-negative bonus: ");
        scanf("%d", &bonus);
    }

    applyBonus(marks, 10, bonus);

    printf("\n========== AFTER BONUS ==========\n");

    displayReport(marks, 10, threshold);

    return 0;
}

int calculateTotal(int marks[], int size)
{
    int total = 0;
    int i;

    for (i = 0; i < size; i++)
    {
        total = total + marks[i];
    }

    return total;
}

float calculateAverage(int total, int size)
{
    return (float) total / size;
}

int findHighest(int marks[], int size)
{
    int highest = marks[0];
    int i;

    for (i = 1; i < size; i++)
    {
        if (marks[i] > highest)
            highest = marks[i];
    }

    return highest;
}

int findLowest(int marks[], int size)
{
    int lowest = marks[0];
    int i;

    for (i = 1; i < size; i++)
    {
        if (marks[i] < lowest)
            lowest = marks[i];
    }

    return lowest;
}

int countPass(int marks[], int size, int threshold)
{
    int count = 0;
    int i;

    for (i = 0; i < size; i++)
    {
        if (marks[i] >= threshold)
            count++;
    }

    return count;
}

int countTopScorers(int marks[], int size, int highest)
{
    int count = 0;
    int i;

    for (i = 0; i < size; i++)
    {
        if (marks[i] == highest)
            count++;
    }

    return count;
}

void applyBonus(int marks[], int size, int bonus)
{
    int i;

    for (i = 0; i < size; i++)
    {
        marks[i] = marks[i] + bonus;

        if (marks[i] > 100)
            marks[i] = 100;
    }
}

void displayReport(int marks[], int size, int threshold)
{
    int total, highest, lowest;
    int pass, topScorers;

    total = calculateTotal(marks, size);
    highest = findHighest(marks, size);
    lowest = findLowest(marks, size);
    pass = countPass(marks, size, threshold);
    topScorers = countTopScorers(marks, size, highest);

    printf("\n========== MARKS REPORT ==========\n");
    printf("Class Total: %d\n", total);
    printf("Class Average: %.2f\n", calculateAverage(total, size));
    printf("Highest Marks: %d\n", highest);
    printf("Lowest Marks: %d\n", lowest);
    printf("Students Passed: %d\n", pass);
    printf("Top Scorers: %d\n", topScorers);
}
