//header files used
#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>

//function prototypes
void xBanner(void);
void mainmenu(void);
void front(void);
void hashBanner(void);
void menu();


//starting main
int main(void){

    //itemList
    char itemList[22][13] = { "Indian Salad", "Mineral Water", "Papad", "Lassi", "French Fries",
     "Onion Rings", "Choco Cake", "Choco Muffin", "Shahi Paneer", "Dal Makhni", "Alooo Dum", 
     "Mix Veg", "Plain Roti", "Butter Roti", "Aloo Nan", "Missi Roti", "Red Bull", "Monstar", 
     "Pepsi", "Maza", "Chocolate", "Butterscotch"};

    //Price of Each Item from itemList
    int priceOfItem[22] = { 30, 20, 15, 40, 60, 40, 60, 60, 150, 125, 150, 180, 25, 30, 35, 
        35, 50, 50, 35, 30, 50, 35};

    //1D arrays where updation will happen    
    char orderItem[22];
    int orderQuantity[22];
       
    //printing program's main menu
    mainmenu();


    //Choice for switch case
    int choice;
    printf("%s", "Enter your choice: ");
    scanf("%d", &choice);

    int itemCount;      //Used in case 2 for loop

    //Exit only if choice == 5
    while(choice != 6){
        switch(choice){
            case 1:     //SHOW MENU
                menu();//Show restaurant's menu
                hashBanner();
                break;    
            case 2:     //ADD ITEMS
                printf("%s", "How many items you want to add to the list: ");
                scanf("%d", &itemCount);

                //using a for loop to add items and there quantities in respective arrays
                for(size_t i = 0; i < itemCount; i++){
                    printf("Enter item %d name:\t", i+1);
                    fflush(stdin);
                    scanf("%c", &orderItem[i]);
                    printf("Enter item %d quantity: \t", i+1);
                    fflush(stdin);
                    scanf("%d", &orderQuantity[i]);
                    
                }

                break;
            case 3:     //UPDATE ITEMS
                
                break;
            case 4:     //Remove Items
                

                break;
            case 5:     //Print Bill
                
                break;
            case 6:     //Exit
                
                break;
            default:
                printf("Press 1-6 only...");
                break;                
        }
        if(choice !=6){
            mainmenu();
            printf("%s", "Enter your choice: ");
            scanf("%d", &choice);
        }
    }

    //ending code 
    system("pause");
    return 0;
}
//ending main




//function definition for mainmenu()
void mainmenu(void){
    hashBanner();
    printf("%s", "1. See Menu\n");
    printf("%s", "2. Add Items\n");
    printf("%s", "3. Update Items\n");
    printf("%s", "4. Remove Items\n");
    printf("%s", "5. Print Bill\n");
    printf("%s", "6. Exit\n");
    hashBanner();
}

//function definition for hashBanner()
void hashBanner(void){
    printf("***********************\n");
    printf("***********************\n");
}

//function definition for xBanner()
void xBanner(void){
        int row, column, numrows = 5, numcolumns = 17;
        
        for(row = 0; row < numrows; row++){
            for(column = 0; column < numcolumns; column++){
                if((row == column || row + column == 4) && (row < 5 && column < 5))
                    printf("%s", "#");    
                else
                    printf("%s", " ");


                if((column + row == 10) || (column - row == 6))
                    printf("%s", "#");
                else
                    printf("%s", " ");


                if((column + row == 16) || (column - row == 12))
                    printf("%s", "#");
                else
                    printf("%s", " ");
        }
        printf("%s", "\n");
    } 
}

//function definition for menu()
void menu(void){
    puts("");
    printf("%40s\n", "WELCOME TO OUR RESTAURANT");
    printf("%s", "\n\n");

    printf("%s\n", "1. STARTERS");
    printf("%s\n", "  a. Indian Salad   5.00  |  b. Papad         5.00");
    printf("%s\n", "  c. Mineral Water  6.00  |  d. Lassi         10.00");
    printf("%s", "\n");
   
    printf("%s\n", "2. SIDES");
    printf("%s\n", "  e. French Fries   20.00 |  f. Onion Rings   25.00");
    printf("%s\n", "  g. Choco Cake     35.00 |  h. Choco Muffin  40.00");
    printf("%s", "\n");

    printf("%s\n", "3. MAINS");
    printf("%s\n", "  i. Shahi Paneer   70.00 |  j. Dal Makahni   60.00");
    printf("%s\n", "  k. Aloo Dum       50.00 |  l. Mix Veg       70.00");
    printf("%s\n", "  m. Plain Roti     5.00  |  n. Butter Roti   7.00");
    printf("%s\n", "  o. Aloo Nan       10.00 |  p. Missi Roti    20.00");
    printf("%s", "\n");

    printf("%s\n", "4. DRINKS");
    printf("%s\n", "  q. Red Bull       110.00|  r. Monster       120.00");
    printf("%s\n", "  s. Pepsi          30.00 |  t. Mazaa         30.00");
    printf("%s\n", "  u. Chocolate      50.00 |  v. Butterscotch  50.00");
    printf("%s", "\n");
}