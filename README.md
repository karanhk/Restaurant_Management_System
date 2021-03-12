# Restaurant_Management_System  
 <h2>IT Group Members:  </h2>
<ul>
<li>Hrishubh Bhandari</li>  <br />  
<li>Gurupal Singh</li>    <br />
<li>Hari Gopal</li>  <br />
<li>Inderjeet Singh</li>  <br />
<li>Karan Hadiyal</li>  <br />

<h2>CODE EXPLANATION</h2>

<h3>6 Global Variables</h3>
    total, total_quant, gst, cgst, sgst, total_gst

<h3>8 Arrays</h3>
    bf_rate[8][2], lunch_rate[8][2], dinner_rate[8][2], purchased[], quantities[], _gst[], _cgst[], _sgst[]

<h3>7 Display Functions</h3>
    &emsp void display();<br />
    &emsp void display_bfmenu();<br />
    &emsp void display_bf_bill(char bfmenu[][100]);<br />
    &emsp void display_lunchmenu();<br />
    &emsp void display_lunch_bill(char lunchmenu[][100]);<br />
    &emsp void display_dinnermenu();<br />
    &emsp void display_dinner_bill(char dinnermenu[][100]);<br />

<h3>6 Foodie Functions</h3>
    &emsp void bfast(char bfmenu[][100]);<br />
    &emsp void lunch( char lunchmenu[][100]);<br />
    &emsp void dinner(char dinnermenu[][100]);<br />
    &emsp void repeatbf(char bfmenu[][100]);<br />
    &emsp void repeatlunch(char lunchmenu[][100]);<br />
    &emsp void repeatdinner(char dinnermenu[][100]);<br />

<h3>Local Main Scope Variables</h3>
    &emsp char bfmenu[][100]={"","Toast","Parantha","Dosa","Upma","Milk","Tea","Coffee"};<br />
    &emsp char lunchmenu[][100]={"","Veg Biryani","Special meal","Roti","Dal","Paneer Tikka","Veg mix","Icecream"};<br />
    &emsp char dinnermenu[][100]={"","Fried rice","Spaghetti","Burger","Pasta","Noodles","Parantha","Fruit Salad"};<br />

<h3>How CODE executes ??</h3><!>
	We have a choice variable //char choice//
	We display banner using <display()> function
	Then depeneding on whether user wants to eat breakfast, lunch or dinner
	We take that input as <a/A> or <b/B> or <c/c> in <choice> variable
	We use a do while loop to display the banner till user doesn't enter 
	
	In that do while loop we are taking this <choice> variable input actually
	The we use a switch control statement as switch(choice)
	If the case is <a/A> : then breakfast functions will execute
	If the case is <b/B> : then lunch functions will execute
	If the case is <c/C> : then dinner functions will execute

	Note: User can only choose breakfast, lunch or dinner at one time. He can't choose items from all three menus simultaneously.
	Note: It's not a bug but it's a feature of APNA restaurant.

	NOTE: Now onwards so many function calls will execute.
	Now suppose user chose b/B or lunch. So how the lunch functions continues now
	Now <lunch(lunchmenu)> function will execute where lunchmenu is an argument for this lunch function
	And <lunchmenu> is nothing but array of all the items that are present in lunch.

	How lunch(lunchmenu) will execute now??
	It will display a banner for lunchmenu using <display_lunchmenu()> function
	In that lunch menu banner we have 7 number choices ranging from 1 to 7	
	We are using here a variable <c> to take the choice
	If choice is 0 then we will call main() function and it's like we press back button, then it will display initial banner again
	If the code is not 0 or between 1 to 7 then it will call <lunch(lunchmenu)> function once again
	If the code is between 1 and 7 then calculation things will happen 

		A variable named <quantity> will store the quantity of the item indexed btwn 1 to 7 that user chose
		Now it will multiply that <quantity> * <lunch_rate[c][1]> to get the cost and store it in <purchased[c]>
		That is why lunch_rate and purchased arrays are global because we want them to use in whatever function that we want
		We have a normal global int variable as <total_quant> we will add quantity to it --> total_quant += quantity
		Similarly we will increase <total> and add purchased[c] to it as --> total += purchased[c]
		Then print <total> using printf statement
		We will calculate gst of that item as <gst> = <purchased[c]> * 0.12
		Then we give <total_gst> += gst
		Then we will take that <gst> and store it in _gst[] array at index c as --> _gst[c]=gst
		Similarly <_cgst[]> and <_sgst[]> arrays are filled as --> _cgst[c]=gst/2 and _sgst[c]=gst/2 

	After this when everything is calculated user have only chosen one item within a particular quantity
	User won't eat roti with air he needs some dal or sabzi also that means we need to repeat this lunch menu once again
	Here we implement a repeat function as --> <repeatlunch(lunchmenu)>
	Now what will happen in that repeatlunch(lunchmenu) function ??

		How repeatlunch(lunchmenu) function will executes ??
		It will ask whether you want to add something else or not
		Where choices are like this [1] for Yes and [2] for No
		We store these choices in a int variable called <again>
		Now suppose again is not equals to 1 or 2, then
		it will say invalid code entered and it will call repeatlunch(lunchmenu) function once again

		If again is equal to 1, then it will print lunch(lunchmenu) once again because user wants to add some other item again
		If again is equal to 2, then user wants to conclude things and he wants to see the bill, then 
		Here we call another function inside this again == 2 condition as --> display_lunch_bill(lunchmenu)

		Now this display_lunch_bill(lunchmenu) function shows bill.
		It shows bill with respective costs of added items, there gst, csgst, sgst.

//NOTE
	In the similar way dinner and breakfast functions executes with the exact same fashion.