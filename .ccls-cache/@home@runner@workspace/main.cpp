
#include <iostream>
#include <cmath> 
#include <iomanip>

using namespace std;

//constants
const double GALLON_PER_SQFT = 1.0 / 110.0;
const double LABOR_HOURS_PER_SQFT = 8.0 / 110.0;
const double LABOR_CHARGE_PER_HOUR = 25.0;

//function prototypes
int getrooms();
double getSquareFeet(int roomNumber);
double getPaintPricePerGallon();
int calculateGallons(double squareFeet);
double calculateLaborHours(double squareFeet);
void displayEstimate(double totalGallons, double totalPaintCost, double totalLaborCost, double totalLaborHours);

int main() {
    int numberOfRooms = getrooms();
    double totalGallons = 0.0;
    double totalPaintCost = 0.0;
    double totalLaborCost = 0.0;
    double totalLaborHours = 0.0;

    //the loop for each room
    for (int i = 1; i <= numberOfRooms; i++) {
        cout << "\n----Room " << i << "----" << endl;
        double squareFeet = getSquareFeet(i);
        double paintPricePerGallon = getPaintPricePerGallon();
        int gallonsNeeded = calculateGallons(squareFeet);
        double paintCost = gallonsNeeded * paintPricePerGallon;
        double laborHours = calculateLaborHours(squareFeet);
        double laborCost = laborHours * LABOR_CHARGE_PER_HOUR;
        
        //calc totals
        totalGallons += gallonsNeeded;
        totalPaintCost += paintCost;
        totalLaborCost += laborCost;
        totalLaborHours += laborHours;
    }
    
    //display estimate
    displayEstimate(totalGallons, totalPaintCost, totalLaborCost, totalLaborHours);
    
    return 0;
}

//the function to get the number of rooms (this is input must be greater than zero)
int getrooms() {
    int rooms;
    do {
        cout << "Enter the number of rooms that require painting: ";
        cin >> rooms;
        if (rooms < 1) {
            cout << "Invalid input. Please enter a number greater than 0." << endl;
        }
    } while (rooms < 1);
    return rooms;
}

// Function to get square feet for each room (must be > 0)
double getSquareFeet(int roomNumber) {
    double sqft;
    do {
        cout << "Enter the square feet of wall space for room " << roomNumber << ": ";
        cin >> sqft;
        if (sqft <= 0) {
            cout << "Invalid input. Square feet must be positive.\n";
        }
    } while (sqft <= 0);
    return sqft;
}

// Function to get paint price per gallon (must be > $10)
double getPaintPricePerGallon() {
    double price;
    do {
        cout << "Enter the price of paint per gallon (minimum $10): ";
        cin >> price;
        if (price < 10) {
            cout << "Invalid input. Price must be at least $10.\n";
        }
    } while (price < 10);
    return price;
}

// Function to calculate gallons needed, rounded up
int calculateGallons(double squareFeet) {
    double gallons = squareFeet * GALLON_PER_SQFT;
    return static_cast<int>(ceil(gallons));
}

// Function to calculate labor hours needed
double calculateLaborHours(double squareFeet) {
    return squareFeet * LABOR_HOURS_PER_SQFT;
}

// Function to display estimate
void displayEstimate(double totalGallons, double totalPaintCost, double totalLaborCost, double totalLaborHours) {
    cout << fixed << setprecision(2);
    cout << "\nEstimate for painting job:\n";
    cout << "Total gallons of paint required: " << totalGallons << " gallons\n";
    cout << "Total cost of paint: $" << totalPaintCost << "\n";
    cout << "Total labor hours required: " << totalLaborHours << " hours\n";
    cout << "Total labor charges: $" << totalLaborCost << "\n";
    cout << "Total cost of the paint job: $" << (totalPaintCost + totalLaborCost) << "\n";
}
