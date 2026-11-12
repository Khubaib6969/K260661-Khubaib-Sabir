//Stationary Shop
#include<stdio.h>
int main(){
    double costPrice, sellPrice, quantity;
    double *ptrCost=&costPrice, *ptrSell=&sellPrice, *ptrQuantity=&quantity;

    printf("\nEnter cost price: ");
    scanf("%lf", ptrCost);
    printf("Enter sales price: ");
    scanf("%lf", ptrSell);
    printf("Enter quantity: ");
    scanf("%lf", ptrQuantity);

    double totalCost, totalSales, profit;
    double *ptrTotalCost = &totalCost, *ptrTotalSales = &totalSales, *ptrProfit = &profit;

    *ptrTotalCost = (*ptrCost) * (*ptrQuantity);
    *ptrTotalSales = (*ptrSell) * (*ptrQuantity);
    *ptrProfit = (*ptrTotalSales) - (*ptrTotalCost);

    if(*ptrProfit > 0) printf("PROFIT\n");
    else if (*ptrProfit < 0) printf("LOSS\n");
    else printf("No profit or loss\n");

    double profitPercentage;
    double *ptrProfitPercentage = &profitPercentage;

    *ptrProfitPercentage = (*ptrProfit)/(*ptrTotalCost);

    double *larger;

    if (*ptrCost > *ptrSell) {
        larger = ptrCost;
        printf("larger points to: costPrice\n");
    }else if (*ptrSell > *ptrCost) {
        larger = ptrSell;
        printf("larger points to: sellPrice\n");
    }else{
        larger = ptrCost;
        printf("costPrice and sellPrice are equal. larger points to costPrice\n");
    }
    printf("Value of the larger variable: %.2f\n", *larger);

    printf("\n---------------------------------------------------------------\n");
    printf("%-20s %-25s %-15s\n", "Entity Name", "Memory Address", "Stored Value");
    printf("---------------------------------------------------------------\n");


    printf("%-20s %-25p %-15.2lf\n", "costPrice", (void*)&costPrice, costPrice);
    printf("%-20s %-25p %-15.2lf\n", "sellPrice", (void*)&sellPrice, sellPrice);
    printf("%-20s %-25p %-15.2lf\n", "quantity", (void*)&quantity, quantity);
    printf("%-20s %-25p %-15.2lf\n", "totalCost", (void*)&totalCost, totalCost);
    printf("%-20s %-25p %-15.2lf\n", "totalSales", (void*)&totalSales, totalSales);
    printf("%-20s %-25p %-15.2lf\n", "profit", (void*)&profit, profit);
    printf("%-20s %-25p %-15.2lf\n", "profitPercentage", (void*)&profitPercentage, profitPercentage);


    printf("---------------------------------------------------------------\n");
    printf("%-20s %-25p %-15p\n", "ptrCost", (void*)&ptrCost, (void*)ptrCost);
    printf("%-20s %-25p %-15p\n", "ptrSell", (void*)&ptrSell, (void*)ptrSell);
    printf("%-20s %-25p %-15p\n", "ptrQuantity", (void*)&ptrQuantity, (void*)ptrQuantity);
    printf("%-20s %-25p %-15p\n", "larger", (void*)&larger, (void*)larger);
    printf("---------------------------------------------------------------\n");
}