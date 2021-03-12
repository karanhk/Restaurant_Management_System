# Restaurant_Management_System  
 <h2>IT Group Members:  </h2>
<ul>
<li>Hrishubh Bhandari (202011026)</li>  <br />  
<li>Gurupal Singh (202011022)</li>    <br />
<li>Hari Gopal (202011024)</li>  <br />
<li>Inderjeet Singh (202011027)</li>  <br />
<li>Karan Hadiyal (202011023)</li>  <br />

<h2>CODE EXPLANATION</h2>

<h3>6 Global Variables</h3>
    total, total_quant, gst, cgst, sgst, total_gst

<h3>8 Arrays</h3>
    bf_rate[8][2], lunch_rate[8][2], dinner_rate[8][2], purchased[], quantities[], _gst[], _cgst[], _sgst[]

<h3>7 Display Functions</h3>
      void display();<br />
      void display_bfmenu();<br />
      void display_bf_bill(char bfmenu[][100]);<br />
      void display_lunchmenu();<br />
      void display_lunch_bill(char lunchmenu[][100]);<br />
      void display_dinnermenu();<br />
      void display_dinner_bill(char dinnermenu[][100]);<br />

<h3>6 Foodie Functions</h3>
      void bfast(char bfmenu[][100]);<br />
      void lunch( char lunchmenu[][100]);<br />
      void dinner(char dinnermenu[][100]);<br />
      void repeatbf(char bfmenu[][100]);<br />
      void repeatlunch(char lunchmenu[][100]);<br />
      void repeatdinner(char dinnermenu[][100]);<br />

<h3>Local Main Scope Variables</h3>
      char bfmenu[][100]={"","Toast","Parantha","Dosa","Upma","Milk","Tea","Coffee"};<br />
	  char lunchmenu[][100]={"","Veg Biryani","Special meal","Roti","Dal","Paneer Tikka","Veg mix","Icecream"};<br />
      char dinnermenu[][100]={"","Fried rice","Spaghetti","Burger","Pasta","Noodles","Parantha","Fruit Salad"};<br />

<h3>How CODE executes ??</h3><!>
	
	First we display banner using <display()> function
	
	We have a choice variable <char choice>
	Depeneding on whether user wants to eat breakfast, lunch or dinner
	We take that input as <a/A> or <b/B> or <c/c> in <choice> variable
	We use a do while loop to execute the users request 
	
	In that do while loop we are taking this <choice> variable as input
	We use a switch control statement as switch(choice)
	If the case is <a/A> : then breakfast functions will execute
	If the case is <b/B> : then lunch functions will execute
	If the case is <c/C> : then dinner functions will execute

	NOTE: The following explaination is based on the case <b/B> for lunch. Other cases also work in a similar way

	The following things happen in the lunch function:
	It will display a banner for lunchmenu using <display_lunchmenu()> function
	In that lunch menu banner we have 9 number choices ranging from 1 to 9	
	We are using here a variable <c> to take the choice
	If choice is 0 then we will call main() function (it's like we press back button, then it will display initial banner again)
	If the code is not 0 or between 1 to 9 then it will call <lunch(lunchmenu)> function once again
	If the code is between 1 and 9 then further processing is done as follow. 

		A variable named <quantity> will store the quantity of the item indexed between 1 to 9 that the user chooses
		Now it will multiply that <quantity> * <lunch_rate[c][1]> to get the cost and store it in <purchased[c]>
		NOTE: That is why lunch_rate and purchased arrays are global because we want them to use in whatever function that we want
		Now, in the global int variable <total_quant> we will add quantity --> total_quant += quantity
		Similarly we will increase <total> and add purchased[c] to it as --> total += purchased[c]
		We will calculate gst of that item as <gst> = <purchased[c]> * 0.12
		Then we give <total_gst> += gst
		Similarly, we will take that <gst> and store it in _gst[] array at index c as --> _gst[c]=gst
		Similarly <_cgst[]> and <_sgst[]> arrays are filled as --> _cgst[c]=gst/2 and _sgst[c]=gst/2 respectively

	After this when everything is calculated we ask the user if he/she wants to order anything else or not
	To do that, we implement a repeat function as --> <repeatlunch(lunchmenu)>
	Now what will happen in that repeatlunch(lunchmenu) function ??

		It will ask whether you want to add something else or not
		Where choices are like this [1] for Yes and [2] for No
		We store these choices in a int variable called <again>
		Now suppose again is not equals to 1 or 2, then
		it will say invalid code entered and it will call repeatlunch(lunchmenu) function once again

		If again is equal to 1, then it will print lunch(lunchmenu) once again because user wants to add some other item again
		If again is equal to 2, then this means that the customer has placed his order 
		Here we call another function inside this again == 2 condition as --> display_lunch_bill(lunchmenu)

		Now this display_lunch_bill(lunchmenu) function displays the bill using all the information gathered throughout the code.
		It shows bill with respective costs of added items, there gst, csgst, sgst.
