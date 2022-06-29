//  Coffee Order Strings Assignment
//  Created by Hamzah Jamal Eddin on 3/30/22.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void orderCoffee(char flavorPick[],char size[],float *pricePTR,int *creamChoice,int *sugarChoice);
void convertCase(char toConvert[]);
void displayOrder(char flavorPick[],char size[],float price,int *creamChoice,int *sugarChoice);

int main()
{
    char flavorPick[11], size[10] ,again[5]="Yes";
    float price;
    int creamChoice ,sugarChoice;
    
    while(strcmp(again,"Yes")==0)
    {
    orderCoffee(flavorPick,size,&price,&creamChoice,&sugarChoice);
    displayOrder(flavorPick,size,price,&creamChoice,&sugarChoice);
    printf("\nWould You Like to Place Another Order ? (Yes,No) ");
        fgets(again,5,stdin);
        again[strlen(again)-1]='\0';
        convertCase(again);
        while(strcmp(again,"Yes")!=0 && strcmp(again,"No")!=0)
        {
            printf("Invalid Input, Try Again");
            printf("\nWould You Like to Place Another Order ? (Yes,No) ");
                fgets(again,5,stdin);
                again[strlen(again)-1]='\0';
                convertCase(again);
        }
    }
    printf("\nEnjoy!");
    return 0;
}

void orderCoffee(char flavorPick[],char size[],float *pricePTR,int *creamChoice,int *sugarChoice)

{
    char *cupSize [3]={"Small","Medium","Large"};
    char *coffeeTypes[5]={"House","Iced","Vanilla","Hazelnut","Mocha"};
    int found;
    int foundCoffee;

    do
    {
        printf("\nWhat size coffee would you like (Small/Medium/Large)");
            fgets(size,10,stdin);
                size[strlen(size)-1]='\0';
                convertCase(size);
                found=0;
            

        if(strcmp(size,cupSize[0])==0)
            {
                found=1;
                *pricePTR=3;
            }
            
        else if( strcmp(size,cupSize[1])==0)
            {
                found=1;
                *pricePTR=4.5;
            }
            
        else if (strcmp(size,cupSize[2])==0 )
            {
                found=1;
                *pricePTR=6;
            }
        else if (found==0)
                
            {
            printf("Invalid Input, Try Again");
            }
            

    }while(found==0);
        
    do
    {
        printf("\nWhat Flavor of Coffee Would you like to order? %s, %s, %s, %s,or %s",coffeeTypes[0],coffeeTypes[1],coffeeTypes[2],coffeeTypes[3],coffeeTypes[4]);
            fgets(flavorPick,11,stdin);
                flavorPick[strlen(flavorPick)-1]='\0';
                convertCase(flavorPick);
                foundCoffee=0;

        for(int x=0;x<5;x++)
            if(strcmp(flavorPick,coffeeTypes[x])==0)
                {
                    foundCoffee=1;
                    break;
                }
                 if (foundCoffee==0)
                {
                    printf("Invalid Input, Try Again");
                }
    }while(foundCoffee==0);
        
    do
    {
        char cream[5];
        *creamChoice=3;
        printf("\nWould You Like Cream? (Yes,No) ");
            fgets(cream,5,stdin);
            cream[strlen(cream)-1]='\0';
            convertCase(cream);

        if(strcmp(cream, "Yes")==0)
                {
                    *creamChoice=1;
                }
        if(strcmp(cream, "No")==0)
                {
                    *creamChoice=0;
                }
        if (*creamChoice==3)
                {
                    printf("Invalid Input, Try Again");
                }
            
    }while(*creamChoice==3);
        
    do
    {
        char sugar[5];
        *sugarChoice=3;
        printf("\nWould You Like Sugar? (Yes,No) ");
            fgets(sugar,5,stdin);
            sugar[strlen(sugar)-1]='\0';
            convertCase(sugar);

        if(strcmp(sugar, "Yes")==0)
                {
                    *sugarChoice=1;
                }
        if(strcmp(sugar, "No")==0)
                        {
                    *sugarChoice=0;
                        }
        if (*sugarChoice==3)
                {
                    printf("Invalid Input, Try Again");
                }
    }while(*sugarChoice==3);
    
}




void convertCase(char toConvert[])
{
    int x=1;
    if(toConvert[0]>=97)
    toConvert[0]-=32;
    while(toConvert[x]!='\0')
        {
             if(toConvert[x]<=96)
            {
              toConvert[x]+=32;
            }
       x++;
        }

}

void displayOrder(char flavorPick[],char size[],float price,int *creamChoice,int *sugarChoice)
{
    
    if(*creamChoice==1 && *sugarChoice==1)
    {
    printf("\nYour coffee order: ");
    printf("\n%s %s coffee with cream and sugar ",size,flavorPick);
    printf("\nTotal due:  $ %.2f\n",price);
    }
    
    else if(*creamChoice==0 && *sugarChoice==1)
    {
    printf("\nYour coffee order: ");
    printf("\n%s %s coffee with sugar ",size,flavorPick);
    printf("\nTotal due:  $ %.2f\n",price);

    }
    
    else if(*creamChoice==1 && *sugarChoice==0)
    {
    printf("\nYour coffee order: ");
    printf("\n%s %s coffee with cream ",size,flavorPick);
    printf("\nTotal due:  $ %.2f\n",price);

    }
    
    
    else if(*creamChoice==0 && *sugarChoice==0)
    {
    printf("\nYour coffee order: ");
    printf("\n%s %s coffee ",size,flavorPick);
    printf("\nTotal due:  $ %.2f\n",price);

    }
    
    
}
