#include<stdio.h>
#include<stdlib.h>

int total=0;
float gst,cgst,sgst;

int bf_rate[8][2]={  {0,0},{1,30},{2,35},{3,40},{4,20},{5,15},{6,20},{7,30}     };

int lunch_rate[8][2]={   {0,0},{1,80},{2,120},{3,20},{4,120},{5,150},{6,160},{7,30}   };

int dinner_rate[8][2]={   {0,0},{1,65},{2,50},{3,70},{4,80},{5,65},{6,110},{7,50}    };

int purchased[][2]={  {0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}   };

int temp[][2]={  {0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}  };

void display();
void bfast(char bfmenu[][100]);
void display_bfmenu();
void repeatbf(char bfmenu[][100]);
void display_bf_bill(char bfmenu[][100]);
void lunch( char lunchmenu[][100]);
void display_lunchmenu();
void repeatlunch(char lunchmenu[][100]);
void display_lunch_bill(char lunchmenu[][100]);
void dinner(char dinnermenu[][100]);
void display_dinnermenu();
void repeatdinner(char dinnermenu[][100]);
void display_dinner_bill(char dinnermenu[][100]);

void main()
{
    char bfmenu[][100]={"","Toast","Parantha","Dosa","Upma","Milk","Tea","Coffee"};
    char lunchmenu[][100]={"","Veg Biryani","Special meal","Roti","Dal","Paneer Tikka","Veg mix","Icecream"};
    char dinnermenu[][100]={"","Fried rice","Spaghetti","Burger","Pasta","Noodles","Parantha","Fruit Salad"};
    char choice;
    do
    {
        display();
        printf("\nEnter your choice here (Enter '!' to exit) : ");
        scanf("%c", &choice);
        
        switch(choice)
        {
            case 'A':
            case 'a':bfast(bfmenu);
                    break;
            case 'B':
            case 'b':lunch(lunchmenu);
                    break;
            case 'C':
            case 'c':dinner(dinnermenu);
                    break;
            case '!':printf("Exiting Code");
                    break;
            default:printf("\nWrong choice entered Please enter the valid choice!!\n\n");            
        }
    }while(choice!='!');
}
void display()
{
    printf("                   Welcome to APNA Restaurant.          \n ");
    printf("        +###########################################+          \n\n");
    printf("    Please select the meal that you would like to purchase.\n\n");
    printf("\t\t      [A] Breakfast\n");
    printf("\t\t      [B] Lunch\n");
    printf("\t\t      [C] Dinner\n");
}
void bfast(char bfmenu[][100]) //Breakfast Menu Screen
{
    //local variables
    int quantity = -1;
    int c;
    display_bfmenu();
    printf("\nEnter the code:: ");
    scanf("%d", &c);
    if(c>=1&&c<=7)
    {
        printf("\nEnter the quantity::");
        scanf("%d",&quantity);
        purchased[c][1]= quantity*bf_rate[c][1]; 
        total+=purchased[c][ 1];
        printf("\nTotal Cost is %d\n\n",total);
        gst=total*0.12;
        cgst=gst/2;
        sgst=cgst;
    }
    else
    {
        printf("\nInvalid code entered, Please enter the code again!!!!\n\n");
        bfast(bfmenu);
    }
    repeatbf(bfmenu);
}
void display_bfmenu()
{
    printf("                    Welcome to APNA Restaurant.          \n ");
    printf("         +###########################################+          \n\n");
    printf("                      $  Breakfast Menu  $ \n\n");
    printf("     Please select the food that you would like to purchase.  \n\n");
    printf("\t\t   [1] Toast     -   Rs 30.00\n");
    printf("\t\t   [2] Parantha  -   Rs 35.00\n");
    printf("\t\t   [3] Dosa      -   Rs 40.00\n");
    printf("\t\t   [4] Upma      -   Rs 20.00\n");
    printf("\t\t   [5] Milk      -   Rs 15.00\n");
    printf("\t\t   [6] Tea       -   Rs 20.00\n");
    printf("\t\t   [7] Coffee    -   Rs 30.00\n");
}
void repeatbf(char bfmenu[][100])
{   
    int again = 0;
    printf("\nWould you like to buy anything else?\n[1] Yes , [2] No : "); // Allows user to choose whether to check-out or buy anything else.
    scanf("%d",&again);
    if (again == 1)
            bfast(bfmenu);
    else if (again == 2 )
    {
        display_bf_bill(bfmenu);
        exit(0);
    }
    else
    {
        printf("\n\n\t\tSorry Invalid Choice Entered\n");
        repeatbf(bfmenu);
    }
}
void display_bf_bill(char bfmenu[][100]) // Breakfast Bill
{
    int i;
    printf("  +**********************************************************+          \n\n");
    printf("                      APNA RESTAURANT                   \n");
    printf("                    BILLING INFORMATION                \n");
    printf("\t\t ITEMS\t\tPrice(in Rs.)\n");
    for(i=1;i<=7;i++)
    {
        if(purchased[i][1]!=0)
        {
            printf("\t\t%s\t\t",bfmenu[i]);
            printf("%d\n",purchased[i][1]); /*purchased[i][1]);*/
        }
    }
    printf("\t\tGST=Rs.%0.2f\n",gst);
    printf("\t\tC-GST=Rs.%0.2f\n",cgst);
    printf("\t\tS-GST=Rs.%0.2f\n",sgst);
    printf("\t\tTotal=Rs.%d\n",total);
    
    printf("\n\n  +**********************************************************+          \n\n");

}
void lunch(char lunchmenu[][100]) // Lunch Screen Menu
{
    //local variables
    int quantity = -1;
    int c;
    display_lunchmenu();
    printf("\nEnter the code:: ");
    scanf("%d", &c);
    if(c>=1&&c<=7)
    {
        printf("\nEnter the quantity::");
        scanf("%d",&quantity);
        purchased[c][1]= quantity*lunch_rate[c][1];
        total+=purchased[c][ 1];
        printf("\nTotal Cost is %d\n\n",total);
        gst=total*0.12;
        cgst=gst/2;
        sgst=cgst;
    }
    else
    {
        printf("\nInvalid code entered, Please enter the code again!!!!\n\n");
        lunch(lunchmenu);
    }
    repeatlunch(lunchmenu);
}
void display_lunchmenu()
{
    printf("                     Welcome to APNA Restaurant.          \n ");
    printf("           +##########################################+          \n\n");
    printf("                          $  Lunch Menu  $ \n\n");
    printf("       Please select the food that you would like to purchase.  \n\n");
    printf("\t\t   [1] Veg Biryani   -   Rs 80.00\n");
    printf("\t\t   [2] Special Meal  -   Rs 120.00\n");
    printf("\t\t   [3] Roti          -   Rs 20.00\n");
    printf("\t\t   [4] Dal tadka     -   Rs 120.00\n");
    printf("\t\t   [5] Paneer Tikka  -   Rs 150.00\n");
    printf("\t\t   [6] Veg Mix       -   Rs 160.00\n");
    printf("\t\t   [7] Ice cream     -   Rs 30.00\n");
    printf("Enter your choice here : ");
}
void repeatlunch(char lunchmenu[][100])
{   
    int again=0;
    printf("\nWould you like to buy anything else?\n[1] Yes , [2] No : "); // Allows user to choose whether to check-out or buy anything else.
    scanf("%d",&again);
    if (again == 1)
            lunch(lunchmenu);
    else if (again == 2 )
    {
        display_lunch_bill(lunchmenu);
        exit(0);
    }
    else
    {
        printf("\n\n\t\tSorry Invalid Choice Entered\n");
        repeatlunch(lunchmenu);
    }
}
void display_lunch_bill(char lunchmenu[][100]) // Lunch Bill 
{
    int i;
    printf("  +**********************************************************+          \n\n");
    printf("                      APNA RESTAURANT                   \n");
    printf("                    BILLING INFORMATION                \n");
    printf("\t\t ITEMS\t\t\tPrice(in Rs.)\n");
    for(i=1;i<=7;i++)
    {
        if(purchased[i][1]!=0)
        {
            printf("\t\t %s \t\t",lunchmenu[i]);
            printf("%d\n",purchased[i][1]);
        }
    }
    printf("\t\tGST=Rs.%0.2f\n",gst);
    printf("\t\tC-GST=Rs.%0.2f\n",cgst);
    printf("\t\tS-GST=Rs.%0.2f\n",sgst);
    printf("\t\tTotal=Rs.%d\n",total);
    
    printf("\n\n  +**********************************************************+          \n\n");
}
void dinner(char dinnermenu[][100]) // Dinner Menu Screen
{
    //local variables
    int quantity = 0;
    int c;
    display_dinnermenu();

    printf("\nEnter the code:: ");
    scanf("%d", &c);
    if(c>=1 && c<=7)
    {
        printf("\nEnter the quantity::");
        scanf("%d",&quantity);
        purchased[c][1]= quantity*dinner_rate[c][1];
        total+=purchased[c][1];
        printf("\nTotal Cost is %d\n\n",total);
        gst=total*0.12;
        cgst=gst/2;
        sgst=cgst;
    }
    else
    {
        printf("\nInvalid code entered, Please enter the code again!!!!\n\n");
        dinner(dinnermenu);
    }
    repeatdinner(dinnermenu);
}
void display_dinnermenu()
{
    printf("                    Welcome to APNA Restaurant.          \n ");
    printf("         +###########################################+          \n\n");
    printf("                        $  Dinner Menu  $ \n\n");
    printf("      Please select the food that you would like to purchase.  \n\n");
    printf("\t\t   [1] Fried Rice   -   Rs 65.00\n");
    printf("\t\t   [2] Spaghetti     -   Rs 50.00\n");
    printf("\t\t   [3] Burger       -   Rs 70.00\n");
    printf("\t\t   [4] Pasta        -   Rs 80.00\n");
    printf("\t\t   [5] Noodles      -   Rs 65.00\n");
    printf("\t\t   [6] Parantha     -   Rs 110.00\n");
    printf("\t\t   [7] Fruit Salad  -   Rs 50.00\n");
        printf("Enter your choice here : ");
}
void repeatdinner(char dinnermenu[][100])
{
    int again=0;
    printf("\nWould you like to buy anything else?\n[1] Yes , [2] No : "); // Allows user to choose whether to check-out or buy anything else.
    scanf("%d",&again);
    if (again == 1)
    {
        dinner(dinnermenu);
    }
    else if (again == 2 )
    {
        display_dinner_bill(dinnermenu);
        exit(0);
    }
    else
    {
        printf("\n\n\t\tSorry Invalid Choice Entered\n");
        repeatdinner(dinnermenu);
    }
}
void display_dinner_bill(char dinnermenu[][100]) //Dinner Bill
{
    int i;
    printf("  +**********************************************************+          \n\n");
    printf("                      APNA RESTAURANT                   \n");
    printf("                    BILLING INFORMATION                \n");
    printf("\t\t ITEMS\t\t\tPrice(in Rs.)\n");
    for(i=1;i<=7;i++)
    {
        if(purchased[i][1]!=0)
        {
            printf("\t\t %s \t\t",dinnermenu[i]);
            printf("%d\n",purchased[i][1]);
        }

    }
    printf("\t\tGST=Rs.%0.2f\n",gst);
    printf("\t\tC-GST=Rs.%0.2f\n",cgst);
    printf("\t\tS-GST=Rs.%0.2f\n",sgst);
    printf("\t\tTotal=Rs.%d\n\n",total);
    
    printf("\n\n  +**********************************************************+          \n\n");
}
