//Greenhouse Temperature Monitoring System
#include<stdio.h>
int main(){
    int temperature[3][3][3];
    float total=0.0,average=0.0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                printf("Please enter the temperature at %d,%d,%d: ",i,j,k);
                scanf("%d",&temperature[i][j][k]);
            }
        }
    }
    int hottestLayer,highest=0,cordi,cordj,cordk;
    float hottestTemp=0;
    for(int i=0;i<3;i++){
        total =0.0;
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                total+=temperature[i][j][k];
                if (temperature[i][j][k]>highest){ highest=temperature[i][j][k];
                cordi=i;cordj=j;cordk=k;
                }
                
            }
        }
        average = total/9;
        if (average>hottestTemp){ hottestTemp=average;
        hottestLayer = i;
        }
        printf("Average for layer %d: %0.2f\n",i,average);
    }
    printf("Hottest Average temp: %0.2f at layer %d\n",hottestTemp,hottestLayer);
    printf("Highest temperature: %d at %d,%d,%d\n",highest,cordi,cordj,cordk);

}