#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to check if a year is leap (2011 is not, but general function)
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Get the doomsday date for a given month in 2011
int getDoomsdayDate(int month, bool leap) {
    switch (month) {
        case 1: return leap ? 11 : 10;
        case 2: return leap ? 22 : 21;
        case 3: return 7;  // We can use any multiple, but 3/7 is a Monday
        case 4: return 4;
        case 5: return 9;
        case 6: return 6;
        case 7: return 11;
        case 8: return 8;
        case 9: return 5;
        case 10: return 10;
        case 11: return 7;
        case 12: return 12;
        default: return -1;
    }
}

int main() {
    vector<string> daysOfWeek = {
        "Monday", "Tuesday", "Wednesday", "Thursday",
        "Friday", "Saturday", "Sunday"
    };

    int T;
    cin >> T;

    int year = 2011;
    bool leap = isLeapYear(year);

    // Doomsday in 2011 is Monday (index 0)
    while (T--) {
        int M, D;
        cin >> M >> D;

        // Get the doomsday date for month M
        int doomDay = getDoomsdayDate(M, leap);
        // Doomsday of month M is a Monday (index 0 in daysOfWeek)

        // Calculate difference in days
        int diff = D - doomDay;
        // Find day of week: Monday + diff days
        int dayIndex = (diff % 7 + 7) % 7; // Ensure positive modulo
        dayIndex = (0 + dayIndex) % 7;     // Start from Monday

        cout << daysOfWeek[dayIndex] << endl;
    }

    return 0;
}