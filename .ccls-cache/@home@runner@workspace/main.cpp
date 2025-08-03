#include <iostream>
#include <cmath> 
#include <iomanip>

using namespace std;

//constants
const double GallonPerSquareFt = 1.0 / 110.0;
const double LaborHoursPerSquareFt = 8.0 / 110.0;
const double LaborChargePerHour = 25.0;

//function types
int getrooms();
double GetSquareFt(int rooms);
double GetPaintPricePerGallon();
int calcgallons(double squarefeet);
double CalcLaborHours(double squarefeet);
void displayEstimate(double TotalPaintCost, double TotalLaborCost,double LaborHours);
int main()
int rooms = getrooms();
double totalgallons = 0.0;
double totalpaintcost = 0.0;
double totalLaborCost = 0.0;
double totalLaborHours = 0.0;

//get room #'s
numberofrooms = getrooms();

//the loop for each room
for (int i = 1; i <= numberofrooms; i++))
cout << 'n/----Room' << i << '----' << endl;'
  double squareFeet =
  getSquareFeet（i）；
  double paintPricePerGallon
  = getPaintPricePerGallon();
  int gallonsNeeded =
  calculateGallons(squareFeet);
  double paintCost =
  gallonsNeeded *
  paintPricePerGallon;
  double laborHours =
  calculateLaborHours(squareFeet);
  double laborCost =
  laborHours * LABOR_CHARGE_PER_HOUR;
//calc totals
totalgallons += gallonsNeeded;
totalpaintcost += paintCost;
totallaborcost += laborCost;
//display estimate
displayEstimate(totalgallons, totalpaintcost, totallaborcost, totallaborhours);

//the function to get the number of rooms (this is input must be greater than zero)
int getrooms()
int rooms;
do{
  cout<< "enter the number of rooms that require painting:";"
    cin>> rooms; if(rooms< 1) cout<< "invalid input. please enter a number greater than 1."
      while(rooms< 1);  return rooms;
  // Function to get square feet for each room (must be > 0)
   double getSquareFeet (int
  roomNumber) {
  double sqft;
  do {
  cout < "Enter the square
  feet of wall space for room " « roomNumber « ": ";
  cin > sqft; if (sqft <
  0) 1
  cout < "Invalid input.
  Square feet must be positive.\n";
  }
  } while (sqft <
  0);
  return sqft;

  // Function to get paint price per gallon (must be > $10)
  
  double getPaintPricePerGallon) {
  double price;
  do {
  cout < "Enter the price of
  paint per gallon (minimum $10): "
  cin » price;
  if (price < 10) {
  cout « "Invalid input.
  Price must be at least $10.\n";
  }
  } while (price ‹ 10); return price;
  }
  // Function to calculate gallonsneeded, rounded up
  
  int calculateGallons(double
  squareFeet) {
  double gallons = squareFeet *
  GALLON_PER_SQFT;
  return static_cast<int>(ceil(gallons));
  }
  // Function to calculate labor hours needed
  void displayestimate(double totalgallons, double totalpaintcost, double totallaborcost, double totallaborhours)
  cout<< fixed << setprecision(2);
  cout<<"\nEstimate for painting job:\n";"
    cout « "Total gallons of paint
    required: " « totalGallons « " gallons\n";
    cout « "Total cost of paint:
    $" « totalPaintCost « "\n"; cout < "Total labor hours required: " « totalLaborHours « " hours\n" ;
    cout < "Total labor charges:
    $"
    « totalLaborCost « "\n"; cout < "Total cost of the paint job: $" « (totalPaintCost + totalLaborCost
}
  