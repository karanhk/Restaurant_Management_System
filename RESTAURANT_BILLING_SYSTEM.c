#include<stdio.h>
#include<stdlib.h>



int total_amount = 0;           //total amount to be paid
int total_quant = 0;            //total ordered quantities
float gst, cgst, sgst;          //different taxes on food item



int bf_rate[8][2] = {  {0,0},{1,30},{2,35},{3,40},{4,20},{5,15},{6,20},{7,30} };
                            //rate of break fast items

int lunch_rate[8][2] = { {0,0},{1,80},{2,120},{3,20},{4,120},{5,150},{6,160},{7,30} };
                            //rate of lunch itmes

int dinner_rate[8][2] = { {0,0},{1,65},{2,50},{3,70},{4,80},{5,65},{6,110},{7,50} };
                            //rate of dinner items

int purchased[] = { 0 };        //shows purchased items


int quantities[] = { 0 };       //quantities of each purchased items


float _gst[] = { 0 };           //gst amount on each purchased items


float _cgst[] = { 0 };          //cgst amount on each purchased items


float _sgst[] = { 0 };          //sgst amount on each purchased items



void bflundin ( char bfmenu[8][15], char lunchmenu[8][15], char dinnermenu[8][15] );
                        //shows items in selected one of three menus


void display ( void );
                        //displays name of restaurant and design


void bfast ( char bfmenu[8][15] );
                        //for break fast items order


void display_bfmenu ( void );
                        //shows items in break fast menu


void repeatbf ( char bfmenu[8][15] );
                        //repeats break fast menu until customer doesn't finish order


void display_bf_bill ( char bfmenu[8][15] );
                        //when customer finish order it shows bill


void lunch ( char lunchmenu[8][15] );
                        //for lunch items order


void display_lunchmenu ( void );
                        //shows items in lunch menu


void repeatlunch ( char lunchmenu[8][15] );
                        //repeats lunch menu until customer doesn't finish order


void display_lunch_bill ( char lunchmenu[8][15] );
                        //when customer finish order it shows bill


void dinner ( char dinnermenu[8][15] );
                        //for dinner items order


void display_dinnermenu ( void );
                        //shows items in dinner menu


void repeatdinner ( char dinnermenu[8][15] );
                        //repeats lunch menu until customer doesn't finish order


void display_dinner_bill ( char dinnermenu[8][15] );
                        //when customer finish order it shows bill



int main()                      //main function starts

{
    
    char bfmenu[8][15] = {"","Toast","Parantha","Dosa","Upma","Milk","Tea","Coffee"};
                            //break fast menu
    
    
    char lunchmenu[8][15] = {"","Veg Biryani","Special meal","Roti","Dal",
                            "Paneer Tikka","Veg mix","Icecream"};
                            //lunch menu
    
    
    char dinnermenu[8][15] = {"","Fried rice","Spaghetti","Burger","Pasta",
                            "Noodles","Parantha","Fruit Salad"};
                            //dinner menu
    
    
    bflundin ( bfmenu, lunchmenu, dinnermenu );         //bflundin function call
    
    
    exit(0);
    
    
    return 0;
    
}                                                       //program ends



void display()                             //function called by bflundin starts

{
    
    printf("                   Welcome to APNA Restaurant.          \n ");
    printf("        +###########################################+          \n\n");
    printf("    Please select the meal that you would like to purchase.\n\n");
    printf("\t\t      [A] Breakfast\n");
    printf("\t\t      [B] Lunch\n");
    printf("\t\t      [C] Dinner\n");
    
}                                             //function ends



void bflundin ( char bfmenu[8][15], char lunchmenu[8][15], char dinnermenu[8][15] )
                    //function called by main starts

{
    
    char choice;            //choice for break fast, lunch and dinner one at a time
    
    do                      //do while loop starts
    {
        
        display ();         //calls display function
        
        printf("\nEnter your choice (Enter '!' to exit) : ");
        fflush(stdin);
        scanf("%c", &choice);
        
        
        switch (choice)     //switch case starts
        {
                
            case 'A':
            case 'a':   {   bfast(bfmenu);      //calls bfmenu function
                            break;  }
                
                
            case 'B':
            case 'b':   {   lunch(lunchmenu);   //calls lunchmenu function
                            break;  }
                
                
            case 'C':
            case 'c':   {   dinner(dinnermenu);
                            break;  }           //calls dinnermenu function
                
                
            case '!':   {   printf("Exiting Code");
                            break;  }       //whole code exits
                
                
            default:
                printf("\nWrong choice entered Please enter the valid choice!!\n\n");
                
        }           //switch case ends
        
        
    }   while( choice != '!' );             //loop ends when choice is equal to '!'
    
}           //function ends



void bfast ( char bfmenu[8][15] )                 //function called by bflundin starts
{
    
    int quantity = -1;                           //for quantity of selected itsm
    int c;                                       //no. of item for order
    
    display_bfmenu();                           //calls bf menu function
    
    fflush(stdin);
    scanf("%d", &c);                            //takes food item number
    
    
    
    if ( c >= 1 && c <= 7 )                     //if contro structure starts
    {
        
        printf( "\nEnter the quantity: " );
        scanf( "%d" , &quantity );
        
        
        purchased[c]   =  quantity * bf_rate[c][1];      //stores price of that item
        quantities[c]  =  quantity;                      //stores quantities of tht item
        total_quant   +=  quantity;                      //stores total quantities
        total_amount  +=  purchased[c];                  //stores total amount
        
        
        printf("\n The Total Cost is %d\n\n" , total_amount );
        
        
        gst = purchased[c] * 0.12;                      //gst price on item
        _gst[c] = gst;                                  //stores gst price
        _cgst[c] = gst / 2;
        _sgst[c] = gst / 2;                             //cgst and sgst prices
        
    }               //if ends
    
    
    else if ( c == 0 )
    {
        
        printf("\n");
        main();                 //calls main function, program starts again
        
    }
    
    
    else
    {
       
        printf("\nInvalid code entered, Please enter the code again!!!!\n\n");
        bfast ( bfmenu );              //to go back to the bfast
        
    }
    
    
    repeatbf(bfmenu);               //calls repeatbf function
    
    
}                       //bfast function ends



void display_bfmenu ()              //function called by bfast starts
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
    printf("\nPlease enter your choices or enter 0 to go back :\n\n");
    
}                                   //function ends



void repeatbf ( char bfmenu[8][15] )        //function called by bfast starts
{
    
    int again = 0;                          //to purchase again or not
    
    
    printf("\nWould you like to buy anything else?\n[1] Yes , [2] No : ");
    fflush(stdin);
    scanf("%d" , &again);
    
    
    if ( again == 1 )
    {
           
            printf("\n");
            bfast ( bfmenu );                  //calls bfast function
        
    }
    
    
    else if ( again == 2 )
        
    {
        
        printf("\n");
        display_bf_bill ( bfmenu );             //calls display_bf_bill function
        
        exit(0);
        
    }
    
    
    else
    {
        
        printf("\n\n\t\tSorry Invalid Choice Entered\n\n");
        repeatbf(bfmenu);           //calls bfmenu function
        
    }
    
    
}                   //repeatbf function ends



void display_bf_bill ( char bfmenu[8][15] )    //function called by repeatbf starts
{
    
    int i;
    
    printf("+#######################################################");
    printf("###############################+\n\n");
    
    printf("                                  ## APNA RESTAURANT ##");
    printf("\n\n");
    
    printf("                                 --BILLING INFORMATION--                \n\n");
    printf("  |ITEMS            |PRICE(Rs.)   |QUANTITY       |GST            |CGST |SGST\n");
    
    printf("  --------------------------------------------------");
    printf("-----------------------------------\n");
    
    
    for ( i = 1 ; i <= 7 ; i++ )
    {
        
        if ( purchased[i] != 0 )
        {
            
            printf("  |%-15s  ",bfmenu[i]);
            printf("|%-5d\t  ",purchased[i]);
            printf("|%-5d\t  ", quantities[i]);
            printf("|%-5.2f\t  ", _gst[i]);
            printf("|%-5.2f\t  ", _cgst[i]);
            printf("|%-5.2f\n", _sgst[i]);
            
        }           //if control structure ends

    }               //for loop ends
    
    
    printf("  ---------------------------------------------");
    printf("----------------------------------------");
    
    printf("\n\n+################################################");
    printf("######################################+\n\n");
    
    
    exit(0);
    
}                   //display_bf_bill ends



void lunch ( char lunchmenu[8][15] )               // function called by bflundin starts

{
    
    int quantity = -1;                       //for quantities of selected item
    int c;                                   //to select item
    
    
    display_lunchmenu();                    //calls display_lunchmenu function
    
    
    printf("\nEnter the code:: ");
    fflush(stdin);
    scanf("%d", &c);
    
    
    if ( c >= 1 && c <= 7 )
    {
        
        printf("\nEnter the quantity (Enter 0 to go back)::");
        scanf("%d" , &quantity);
        
        purchased[c]   =  quantity * lunch_rate[c][1];  //price of selected item
        quantities[c]  =  quantity;     //stores quantities
        total_quant    +=  quantity;    //stores total quantities
        total_amount   +=  purchased[c];    //stores total amount
        
        printf("\nThe Total Cost is %d\n\n", total_amount );
        
        gst=purchased[c]*0.12;          //gst price on item
        _gst[c]=gst;                    //stores gst price
        _cgst[c]=gst/2;
        _sgst[c]=gst/2;                 //cgst and sgst prices
        
        
    }                   //if control structure ends
    
    
    else if ( c == 0 )
    {

        printf("\n");
        main();         //calls main function program starts again

    }


    else
    {

        printf("\nInvalid code entered, Please enter the code again!!!!\n\n");
        lunch(lunchmenu);           //calls lunch function

    }


    repeatlunch(lunchmenu);         //calls repeat lunch function


}                   //function ends


void display_lunchmenu()            //function called by lunch starts
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
    printf("\nPlease enter your choices below:\n\n");
    
}


void repeatlunch ( char lunchmenu[8][15] )          //function called by lunch starts

{
    int again = 0;

    printf("\nWould you like to buy anything else?\n[1] Yes , [2] No : ");
    fflush(stdin);
    scanf("%d",&again);


    if ( again == 1 )
    {

            printf("\n");
            lunch(lunchmenu);           //lunch function is called

    }


    else if ( again == 2 )
    {

        printf("\n");
        display_lunch_bill(lunchmenu);          //display_lunch_bill starts
        exit(0);

    }


    else
    {

        printf("\n\n\t\tSorry Invalid Choice Entered\n");
        repeatlunch(lunchmenu);         //repeatlunch function is called

    }


}


void display_lunch_bill(char lunchmenu[8][15]) //function called by repeatlunch starts

{

    int i;

    printf("+#################################################");
    printf("#####################################+\n\n");

    printf("                                  ## APNA RESTAURANT ##                  \n\n");

    printf("                                 --BILLING INFORMATION--                \n\n");

    printf("  |ITEMS            |PRICE(Rs.)   |QUANTITY       |GST            |CGST          |SGST\n");

    printf("  ------------------------------------------------");
    printf("-------------------------------------\n");


    for( i = 1; i <= 7; i++ )       //loop starts
    {

        if ( purchased[i] != 0 )
        {

            printf("  |%-15s  ",lunchmenu[i]);
            printf("|%-5d\t  ",purchased[i]);
            printf("|%-5d\t  ", quantities[i]);
            printf("|%-5.2f\t  ", _gst[i]);
            printf("|%-5.2f\t  ", _cgst[i]);
            printf("|%-5.2f\n", _sgst[i]);

        }       //if control structure ends

    }       //for loop ends


    printf(" -------------------------------------------------");
    printf("------------------------------------");

    printf("\n\n+#############################################");
    printf("#########################################+\n\n");

    exit(0);


}           //function ends


void dinner(char dinnermenu[8][15]) // function called by bflundin starts

{
    
    int quantity = 0;     //quantities of selected item
    int c;                //to select item

    display_dinnermenu();   //display_dinnermenu function is called

    printf("\nEnter the code:: ");
    fflush(stdin);
    scanf("%d" , &c);


    if ( c >= 1 && c <= 7 )         //if control structure starts
    {

        printf("\nEnter the quantity (Enter 0 to go back)::");
        scanf("%d" , &quantity);

        purchased[c]   =  quantity * dinner_rate[c][1];     //stores price of that item
        quantities[c]  =  quantity;     //stores quantities of that item
        total_quant    +=  quantity;        //stores total quantities
        total_amount   +=  purchased[c];    //stores total amount


        printf("\nThe Total Cost is %d\n\n",total_amount);


        gst        =  purchased[c] * 0.12;      //gst price on item
        _gst[c]    =  gst;                      //stores gst price
        _cgst[c]   =  gst/2;
        _sgst[c]   =  gst/2;                    //cgst and sgst prices

    }


    else if ( c == 0 )
    {

        printf("\n");
        main();         //calls main function program starts again

    }


    else
    {

        printf("\nInvalid code entered, Please enter the code again!!!!\n\n");
        dinner(dinnermenu);         //calls dinner function

    }


    repeatdinner(dinnermenu);       //calls repeatdinner funtion

}


void display_dinnermenu()           //function called by dinner starts
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
    printf("\nPlease enter your choices below:\n\n");
    
}                       //function ends


void repeatdinner ( char dinnermenu[8][15] )    //function called by dinner starts

{
    int again = 0;

    printf("\nWould you like to buy anything else?\n[1] Yes , [2] No : ");
    fflush(stdin);
    scanf("%d",&again);


    if ( again == 1 )
    {

        printf("\n");
        dinner(dinnermenu);     //dinner function is called


    }


    else if ( again == 2 )
    {

        printf("\n");
        display_dinner_bill(dinnermenu);    //display_dinner_bill function is called
        exit(0);

    }


    else
    {

        printf("\n\n\t\tSorry Invalid Choice Entered\n");
        repeatdinner(dinnermenu);           //repeatdinner function is callled

    }

}           //function ends


void display_dinner_bill ( char dinnermenu[8][15] )
                                //function called by repeatdinner starts

{

    int i;

    printf("+###########################################");
    printf("###########################################+\n\n");

    printf("                                  ## APNA RESTAURANT ##                  \n\n");

    printf("                                 --BILLING INFORMATION--                \n\n");

    printf("  |ITEMS            |PRICE(Rs.)   |QUANTITY       |GST            |CGST          |SGST\n");

    printf("  ---------------------------------------");
    printf("----------------------------------------------\n");


    for ( i = 1 ; i <= 7 ; i++ )            //loop starts
    {

        if ( purchased[i] != 0 )            //if control structure starts
        {

            printf("  |%-15s  ",dinnermenu[i]);
            printf("|%-5d\t  ",purchased[i]);
            printf("|%-5d\t  ", quantities[i]);
            printf("|%-5.2f\t  ", _gst[i]);
            printf("|%-5.2f\t  ", _cgst[i]);
            printf("|%-5.2f\n", _sgst[i]);

        }           //if control structure ends

    }           //loop ends


    printf("  ----------------------------------------");
    printf("---------------------------------------------");

    printf("\n\n+#########################################");
    printf("#############################################+\n\n");

    exit(0);

}           //function ends
