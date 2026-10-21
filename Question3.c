//Store Sales Management System
#include <stdio.h>
int main(){
    int sales[4][5];
    for(int i=0;i<4;i++){
        for(int j=0;j<5;j++){
            printf("Enter sales, for product %d, by salesman %d: ",j+1,i+1);
            scanf("%d",&sales[i][j]);
        }
    }
    printf("\nSummary: \n");
    float totalSales[4]={0};
    for(int i=0;i<4;i++){
        for(int j=0;j<5;j++){
            totalSales[i]+=sales[i][j];
        }printf("Total sales for salesman %d: %0.0f\n",i+1,totalSales[i]);
    }
    printf("\n\n");
    int productSales[5]={0};
    for(int i=0;i<5;i++){
        for(int j=0;j<4;j++){
            productSales[i]+=sales[j][i];
        }printf("Total sales for product %d: %d\n",i+1,productSales[i]);
    }
    printf("\n\n");
    int expensive=0,product=0;
    for(int i=0;i<5;i++){
        if(productSales[i]>expensive) {expensive = productSales[i];
            product=i;}
    }printf("Most expensive product: %d\n",product+1);
    printf("\n\n");
    for(int i=0;i<4;i++){
        if(totalSales[i]>10000){ totalSales[i]=totalSales[i]*1.1;
            printf("Final sales for salesman %d after bonus: %0.2f\n",i+1,totalSales[i]);
        }else printf("Final total sales for salesman %d: %0.0f\n",i+1,totalSales[i]);
    }
    

}