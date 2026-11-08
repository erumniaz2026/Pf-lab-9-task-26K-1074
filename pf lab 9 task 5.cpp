#include <stdio.h>

void displayHall1(int (*ptr)[4]);
void displayHall2(int *hall[], int sizes[]);
int countVacantHall1(int (*ptr)[4]);
int countVacantHall2(int *hall[], int sizes[]);
void bookSeat(int *hall[], int sizes[]);

int main()
{
    int hall1[3][4] = {
        {1, 0, 1, 0},
        {0, 1, 0, 0},
        {1, 0, 0, 1}
    };

    int front[3] = {1, 0, 1};
    int middle[5] = {0, 1, 0, 1, 0};
    int back[7] = {1, 0, 0, 1, 0, 0, 1};

    int *hall2[3] = {front, middle, back};

    int sizes[3] = {3, 5, 7};

    printf("========== HALL 1 ==========\n");

    displayHall1(hall1);

    printf("Vacant Seats in Hall 1: %d\n",
           countVacantHall1(hall1));

    printf("\n========== HALL 2 ==========\n");

    displayHall2(hall2, sizes);

    printf("Vacant Seats in Hall 2: %d\n",
           countVacantHall2(hall2, sizes));

    bookSeat(hall2, sizes);

    printf("\n========== UPDATED HALL 2 ==========\n");

    displayHall2(hall2, sizes);

    printf("Vacant Seats in Hall 2: %d\n",
           countVacantHall2(hall2, sizes));

    return 0;
}

void displayHall1(int (*ptr)[4])
{
    int i, j;

    printf("0 = Vacant, 1 = Booked\n");

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%d ", *(*(ptr + i) + j));
        }

        printf("\n");
    }
}

void displayHall2(int *hall[], int sizes[])
{
    int i, j;

    printf("0 = Vacant, 1 = Booked\n");

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < sizes[i]; j++)
        {
            printf("%d ", *(*(hall + i) + j));
        }

        printf("\n");
    }
}

int countVacantHall1(int (*ptr)[4])
{
    int i, j, count = 0;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (*(*(ptr + i) + j) == 0)
                count++;
        }
    }

    return count;
}

int countVacantHall2(int *hall[], int sizes[])
{
    int i, j, count = 0;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < sizes[i]; j++)
        {
            if (*(*(hall + i) + j) == 0)
                count++;
        }
    }

    return count;
}

void bookSeat(int *hall[], int sizes[])
{
    int row, seat;

    printf("\nEnter row number (1-3): ");
    scanf("%d", &row);

    if (row < 1 || row > 3)
    {
        printf("Invalid row number.\n");
        return;
    }

    printf("Enter seat number (1-%d): ", sizes[row - 1]);
    scanf("%d", &seat);

    if (seat < 1 || seat > sizes[row - 1])
    {
        printf("Invalid seat number.\n");
        return;
    }

    if (*(*(hall + row - 1) + seat - 1) == 1)
    {
        printf("This seat is already booked.\n");
        return;
    }

    *(*(hall + row - 1) + seat - 1) = 1;

    printf("Seat booked successfully!\n");
}
