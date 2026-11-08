#include <stdio.h>

float calculateTotal(float price, int quantity);
float calculateDiscount(float total);
float calculateFinalBill(float total, float discount);
float findHigherPrice(float price1, float price2);

int main()
{
    float price1, price2, total1, total2;
    float total, discount, finalBill, higher;
    int quantity1, quantity2;

    printf("Enter price of first item: ");
    scanf("%f", &price1);

    while (price1 < 0)
    {
        printf("Invalid price. Enter again: ");
        scanf("%f", &price1);
    }

    printf("Enter quantity of first item: ");
    scanf("%d", &quantity1);

    while (quantity1 < 0)
    {
        printf("Invalid quantity. Enter again: ");
        scanf("%d", &quantity1);
    }

    printf("Enter price of second item: ");
    scanf("%f", &price2);

    while (price2 < 0)
    {
        printf("Invalid price. Enter again: ");
        scanf("%f", &price2);
    }

    printf("Enter quantity of second item: ");
    scanf("%d", &quantity2);

    while (quantity2 < 0)
    {
        printf("Invalid quantity. Enter again: ");
        scanf("%d", &quantity2);
    }

    total1 = calculateTotal(price1, quantity1);
    total2 = calculateTotal(price2, quantity2);

    total = total1 + total2;
    discount = calculateDiscount(total);
    finalBill = calculateFinalBill(total, discount);
    higher = findHigherPrice(price1, price2);

    printf("\n========== CANTEEN RECEIPT ==========\n");

    printf("Item 1 Price: Rs. %.2f\n", price1);
    printf("Item 1 Quantity: %d\n", quantity1);
    printf("Item 1 Total: Rs. %.2f\n", total1);

    printf("\nItem 2 Price: Rs. %.2f\n", price2);
    printf("Item 2 Quantity: %d\n", quantity2);
    printf("Item 2 Total: Rs. %.2f\n", total2);

    printf("\nCombined Total: Rs. %.2f\n", total);
    printf("Discount: Rs. %.2f\n", discount);
    printf("Final Bill: Rs. %.2f\n", finalBill);

    if (price1 == price2)
        printf("Both items have equal prices.\n");
    else
        printf("Higher Unit Price: Rs. %.2f\n", higher);

    printf("=====================================\n");

    return 0;
}

float calculateTotal(float price, int quantity)
{
    return price * quantity;
}

float calculateDiscount(float total)
{
    if (total > 1000)
        return total * 0.10;

    return 0;
}

float calculateFinalBill(float total, float discount)
{
    return total - discount;
}

float findHigherPrice(float price1, float price2)
{
    if (price1 > price2)
        return price1;

    return price2;
}
