// This is made by Daniel Clark
// no ai was used for this program
//the purpose of this program is to show how much pizza is needed for the party and the number of guests attending
// and the total cost of the party, and how much it costs per guest to come.


#include <iostream>
#include <iomanip> // fixed
#include <cmath> // ceil()
using namespace std;

const double NUM_SLICES = 8.0; // per pizza
const double GST = 0.05;


// PROTOTYPES
void printBanner();
int calcSlicesNeeded(int guests, int slicesPerGuest);
int calcPizzasNeeded(int slicesNeeded);
double calcSubtotal(int pizzas, double pricePerPizza);
double calcGst(double subtotal);
double calcCostPerGuest(double total, int guests);



// MAIN CODE
int main ()
{
 string partyName;
 int guests;
 int slicesPerGuest;
 double pricePerPizza;
int slicesNeeded;
 int totalPizza = 0.0;
 double subtotal = 0.0;
 double total = 0.0;
 double guestTotal = 0.0;
 double gst = 0.0;

 cout << fixed << setprecision (2);

 cout << "What is the name for the party?";
 getline(cin, partyName);
 cout << "How many people are going to attend?";
 cin >> guests;
 cout << "How many slices of pizza per guest?";
 cin >> slicesPerGuest;
 cout << "Whats the price of one pizza? $";
 cin >> pricePerPizza;


 slicesNeeded = calcSlicesNeeded(guests,slicesPerGuest);

 totalPizza = calcPizzasNeeded(slicesNeeded);

 subtotal = calcSubtotal(totalPizza, pricePerPizza);

 gst = calcGst(subtotal);

 total = subtotal + gst;

 guestTotal = calcCostPerGuest(total, guests);

printBanner();


 cout << "Party:           " << partyName << endl;
 cout << "Guests:          " << guests << endl;
 cout << "Slices needed:   " << slicesNeeded << endl;
 cout << "Pizzas to order: " << totalPizza << endl;
 cout << "---------------------------------" <<  endl;
 cout << "Subtotal:       $" << subtotal << endl;
 cout << "GST (5%):       $" << gst << endl;
 cout << "Total:          $" << total << endl;
 cout << "Per guest:      $" << guestTotal << endl;
 cout << "=================================";


 return 0;
}


// FUNCTION DEFINITION

//PURPOSE: prints a banner for the pizza order
//INPUTS none
//OUTPUTS Prints the three-line banner at the top of the receipt
void printBanner()
{
 cout << "=================================" << endl;
 cout << "     PIZZA PARTY PLANNER" << endl;
 cout << "=================================" << endl;
}

//PURPOSE: calculates the slices of pizza needed
//INPUTS   guests - the number of guests
//         slicesPerGuest - the number of slices per guest
//OUTPUTS: returns the total number of slices needed for the party
int calcSlicesNeeded(int guests, int slicesPerGuest)
{
return guests * slicesPerGuest;
}

//PURPOSE - calculates the pizzas needed
//INPUTS - slicesNeeded - the number of total slices needed
//OUTPUTS - returns the whole pizzas to order, rounded up
int calcPizzasNeeded(int slicesNeeded)
{

 return ceil(slicesNeeded/NUM_SLICES);
}

//PURPOSE - calculates the subtotal
//INPUTS - pizzas - the number of pizzas for the order
//        pricePerPizza - the price per pizza for the order
//OUTPUTS - returns the cost before tax
double calcSubtotal(int totalPizza, double pricePerPizza)
{
return totalPizza * pricePerPizza;
}

//PURPOSE - find the cost of gst of the order
//INPUTS - subtotal - the subtotal of the order withput gst
//OUTPUTS - returns the GST (5%) on a subtotal
double calcGst(double subtotal)
{
return subtotal * GST;
}

//PURPOSE calculates the cost per guest
//INPUTS total - the total price of the order
//       guests - the number of guests attending
//OUTPUTS - returns each guest’s share of the total
double calcCostPerGuest(double total, int guests)
{
return total / guests;
}



