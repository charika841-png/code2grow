#include <stdio.h>

int main() {
    int prices[5] = {50, 30, 80, 120, 60};
    int qty[5] = {0};
    int total_revenue = 0, total_items = 0;
    int customers, i, j, n, item_no, quantity, bill;
    char name[50];

    printf("========== Café Order Management System ==========\n");
    printf("Enter total number of customers: ");
    scanf("%d", &customers);

    for (i = 1; i <= customers; i++) {
        printf("\n--- Customer %d ---\n", i);
        printf("Enter customer name: ");
        scanf("%s", name);
        printf("Enter number of items: ");
        scanf("%d", &n);
        bill = 0;

        for (j = 0; j < n; j++) {
            printf("Enter item number and quantity: ");
            scanf("%d %d", &item_no, &quantity);
            bill += prices[item_no - 1] * quantity;
            qty[item_no - 1] += quantity;
            total_revenue += prices[item_no - 1] * quantity;
            total_items += quantity;
        }

        printf("Total Bill for Customer %d (%s): ₹%d\n", i, name, bill);
    }

    int most = qty[0], least = qty[0], most_index = 0, least_index = 0;
    for (i = 1; i < 5; i++) {
        if (qty[i] > most) {
            most = qty[i];
            most_index = i;
        }
        if (qty[i] < least) {
            least = qty[i];
            least_index = i;
        }
    }

    printf("\n========== Café Summary ==========\n");
    printf("Total Revenue: ₹%d\n", total_revenue);
    printf("Total Items Sold: %d\n", total_items);
    printf("Most Ordered Item: ");
    if (most_index == 0) printf("Coffee\n");
    else if (most_index == 1) printf("Tea\n");
    else if (most_index == 2) printf("Sandwich\n");
    else if (most_index == 3) printf("Burger\n");
    else printf("Pastry\n");

    printf("Least Ordered Item: ");
    if (least_index == 0) printf("Coffee\n");
    else if (least_index == 1) printf("Tea\n");
    else if (least_index == 2) printf("Sandwich\n");
    else if (least_index == 3) printf("Burger\n");
    else printf("Pastry\n");

    return 0;
}
