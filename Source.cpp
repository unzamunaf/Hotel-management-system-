#include <iostream>
#include <string>
using namespace std;
//Room information 
const string roomtype[3] = { "Single Bed", "Double Bed", "Deluxe Suite" };
const int roomprice[3] = { 10000, 20000, 30000 };
//Room status
const int maxfloors = 10;
const int maxrooms = 10;
bool roomavailability[maxfloors][maxrooms];
bool roombooked[maxfloors][maxrooms];
//Food information
const string foodtype[3] = { "Breakfast", "Lunch", "Dinner" };
const string foodoptions[3][3] =
{
    {"Eggs and Toast", "Bread and Jam", "Coffee and Croissant"},
    {"Salad and Grilled Chicken", "Burger and fries", "Pizza and Garlic Bread"},
    {"Steak and Mashed Potato", "Pasta and Breadsticks", "Dynamite Prawns and Garlic Rice"},
};
//Food prices
const int foodprices[3][3] =
{
    {120, 150, 200},
    {1000, 1500, 2000},
    {2500, 2000, 3500},
};
//Room services and room service prices
const string roomservice[3] = { "Laundry", "Cleaning", "Ironing" };
const int roomserviceprice[3] = { 700, 600, 800 };

// Transportation services and prices 
const string transportationtype[3] = { "car", "bike", "E-scooter" };
const int transportationprice[3] = { 3500, 1750, 1500 };

//Tourist guide 
const string touristguide[2] = { "Full day", "Half day" };
const int touristprice[2] = { 1000, 500 };

// Facilities Information
const string facilitytype[6] = { "Gym", "Spa", "Conference Room", "Swimming Pool", "Cinema Room", "Restaurant" };
const int facilityprice[6] = { 4000, 5000, 3000, 3500, 2800, 4500 };
bool facilityavailability[6] = { true, true, true, true, true, true };
// Cost
int totalcost[maxfloors][maxrooms] = { {0} };

///////////////////////////////////////////////////////////////////////////// Module 1 ////////////////////////////////////////////////////////////////////////////////

void bookroom(int floor, int room) {
    cout << "\t"; cout <<
        "Enter the type of room you want : " << "\n";
    for (int i = 0; i < 3; i++)
    {
        cout << "\t"; cout << i + 1 << ". " << roomtype[i] << " - Rs " << roomprice[i] << endl;   // 1. Single 
    }
    int choice;
    cout << "\t"; cout << "Enter your choice: ";
    cin >> choice;
    cout << endl;
    if (choice < 1 || choice > 3) {
        cout << "\t"; cout << "Invalid choice " << endl;
        return;
    }
    int days;
    cout << "\t"; cout << "Enter the number of days you want to stay : ";
    cin >> days;
    cout << endl;
    if (days < 1)
    {
        cout << "\t"; cout << " Invalid number of days." << endl;
        return;
    }

    if (roomavailability[floor - 1][room - 1])
    {
        roombooked[floor - 1][room - 1] = true;
        cout << "\t"; cout << "Room booked successfully!" << endl;
    }
    else
    {
        cout << "\t"; cout << "Room is not available!!" << endl;
    }

    cout << "\t"; cout << "Total cost for your stay: " << roomprice[choice - 1] * days << endl;
}
void updatebooking(int floor, int room)
{
    if (!roombooked[floor - 1][room - 1])
    {
        cout << "\t"; cout << " Currently no room booked for the desired room number and floor number!!" << endl;
    }
    else
    {
        char option;
        cout << "\t"; cout << " Do you wish to update your room booking? ";
        cin >> option;
        if (option == 'Y' || option == 'y')
        {
            cout << "\t"; cout << "Updating booking for room number " << room << " on floor number " << floor << endl;
            cout << "\t"; cout << "Enter new room type:" << endl;
            for (int i = 0; i < 3; i++)
            {
                cout << "\t"; cout << i + 1 << ". " << roomtype[i] << " - $" << roomprice[i] << endl;
            }
            int choice;
            cin >> choice;
            if (choice < 1 || choice > 3)
            {
                cout << "\t"; cout << "Invalid choice" << endl;
                return;
            }
            int duration;
            cout << "\t"; cout << "Enter the number of days that you will be staying:";
            cin >> duration;
            cout << endl;
            if (duration < 1)
            {
                cout << "\t"; cout << "Invalid duration." << endl;
                return;
            }
            cout << "\t"; cout << "Total cost would be: " << roomprice[choice - 1] * duration << endl;
            cout << "\t"; cout << "Room booked successfully!!" << endl;
        }
        else if (option == 'N' || option == 'n')
        {
            cout << "\t"; cout << "Booking not updated." << endl;
        }
        else
        {
            cout << "\t"; cout << "Invalid option." << endl;
        }
    }
}
void cancelbooking(int floor, int room) {
    if (!roombooked[floor - 1][room - 1])
    {
        cout << "\t"; cout << "There is no such booking available for the desired room number." << endl;
    }
    else
    {
        roombooked[floor - 1][room - 1] = false;
        roomavailability[floor - 1][room - 1] = true;
        cout << "\t"; cout << "The booking has been cancelled successffully!!" << endl;
    }
}
void checkin(int floor, int room) {
    cout << "\t"; cout << "Select room type: " << endl;
    for (int i = 0; i < 3; ++i)
    {
        cout << "\t"; cout << i + 1 << ". " << roomtype[i] << " - Rs " << roomprice[i] << endl;
    }
    int choice;
    cout << "\t"; cout << "Enter your choice: ";
    cin >> choice;
    if (choice < 1 || choice > 3) {
        cout << "\t"; cout << "Invalid choice.";
        return;
    }
    int duration;
    cout << "\t"; cout << "Enter duration of stay (days): ";
    cin >> duration;

    if (!roombooked[floor - 1][room - 1]) {
        roombooked[floor - 1][room - 1] = true;
        roomavailability[floor - 1][room - 1] = false;
        cout << "\t"; cout << "Check-in successful!" << endl;
    }
    else {
        cout << "\t"; cout << "Room is already booked." << endl;
    }

    totalcost[floor - 1][room - 1] = totalcost[floor - 1][room - 1] + roomprice[choice - 1] * duration;

}

void checkout(int floor, int room) {
    if (!roomavailability[floor - 1][room - 1]) {
        roomavailability[floor - 1][room - 1] = true;
        roombooked[floor - 1][room - 1] = false;
        cout << "\t"; cout << "Check-out successful!" << endl;
    }
    else {
        cout << "\t"; cout << "Room is occupied." << endl;
    }
}

///////////////////////////////////////////////////////////////////////////// Module 2 ////////////////////////////////////////////////////////////////////////////////////////

void roomservices(int floorNumber, int roomNumber)
{
    int choice;
    int quantity;
    for (int i = 0; i < 3; i++)
    {
        cout << "\t"; cout << i + 1 << ". " << roomservice[i] << " - Rs " << roomserviceprice[i] << endl;
    }
    cout << "\t"; cout << "Enter your choice: ";
    cin >> choice;
    if (choice < 1 || choice > 3)
    {
        cout << "\t"; cout << "Invalid choice." << endl;
        return;
    }
    cout << "\t"; cout << "How many times you want to avail this service? : ";
    cin >> quantity;
    if (quantity < 1)
    {
        cout << "\t"; cout << "Invalid quantity." << endl;
        return;
    }
    cout << "\t"; cout << "The total cost of the room services would be: Rs " << roomserviceprice[choice - 1] * quantity << endl;
    totalcost[floorNumber - 1][roomNumber - 1] = totalcost[floorNumber - 1][roomNumber - 1] + roomserviceprice[choice - 1] * quantity;
    cout << "\t"; cout << "Service added to the bill." << endl;
}

void orderfood(int floorNumber, int roomNumber)
{
    int choice;
    int foodchoice;
    int quantity;
    cout << "\t"; cout << "Enter the meal number: " << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "\t"; cout << i + 1 << ". " << foodtype[i] << endl;
    }
    cout << "\t"; cout << "Enter your choice: ";
    cin >> choice;
    cout << endl;
    if (choice < 1 || choice > 3)
    {
        cout << "\t"; cout << "Invalid choice." << endl;
        return;
    }

    cout << "\t"; cout << "Enter the food number: " << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "\t"; cout << i + 1 << "." << foodoptions[choice - 1][i] << endl;
    }
    // cout <<"1. " << foodoptions[choice - 1][0] << endl;    
    //cout << "2. " << foodoptions[choice - 1][1] << endl;
    //cout << "3. " << foodoptions[choice - 1][2] << endl;
    cout << "\t"; cout << "Enter your choice: ";
    cin >> foodchoice;
    if (choice < 1 || choice > 3)
    {
        cout << "\t"; cout << "Invalid choice." << endl;
        return;
    }

    cout << "\t"; cout << "Enter the quantity: ";
    cin >> quantity;
    if (quantity < 1)
    {
        cout << "\t"; cout << "Invalid quantity." << endl;
        return;
    }
    cout << "\t"; cout << "The total price of the food would be: Rs  " << foodprices[choice - 1][foodchoice - 1] * quantity << endl;
    cout << "\t"; cout << "Should i confirm your order (yes/no) ?: ";
    char option;
    cin >> option;
    cout << endl;
    if (option == 'Y' || option == 'y')
    {
        cout << "\t"; cout << "Order is confirmed " << endl;
        totalcost[floorNumber - 1][roomNumber - 1] = totalcost[floorNumber - 1][roomNumber - 1] + foodprices[choice - 1][foodchoice - 1] * quantity;
        cout << "\t"; cout << "Food added to the bill." << endl;
    }
    else if (option == 'N' || option == 'n')
    {
        cout << "\t"; cout << "Order is not confirmed." << endl;
    }
    else
    {
        cout << "\t"; cout << "Invalid option." << endl;
        return;
    }
}

///////////////////////////////////////////////////////////////////////////// Module 3 ////////////////////////////////////////////////////////////////////////////////////////

void bookingfacilities(int floorNumber, int roomNumber)
{
    int choice;
    int hours;

    cout << "\t"; cout << "Available Facilities are:" << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << "\t"; cout << i + 1 << ". " << facilitytype[i] << " - Rs " << facilityprice[i] << " per hour" << endl;
    }

    cout << "\t"; cout << "Enter the facility you want to avail: ";
    cin >> choice;
    cout << endl;

    if (choice < 1 || choice > 6)
    {
        cout << "\t"; cout << "Invalid choice." << endl;
        return;
    }

    cout << "\t"; cout << "Enter the number of hours for which you want to book the " << facilitytype[choice - 1] << ": ";
    cin >> hours;
    cout << endl;
    if (hours < 1)
    {
        cout << "\t"; cout << "Invalid hours." << endl;
        return;
    }
    cout << "\t"; cout << "The total cost of the facility availed is: Rs " << facilityprice[choice - 1] * hours << endl;
    totalcost[floorNumber - 1][roomNumber - 1] = totalcost[floorNumber - 1][roomNumber - 1] + facilityprice[choice - 1] * hours;
    cout << "\t"; cout << "Facility booked for " << hours << " hours. Added to bill." << endl;
}

void totalcharges(int floorNumber, int roomNumber)
{
    cout << "\t"; cout << "Total charges: Rs " << totalcost[floorNumber - 1][roomNumber - 1] << endl;
}

///////////////////////////////////////////////////////////////////////////// Module 4 ////////////////////////////////////////////////////////////////////////////////////////

void transportationbooking(int floorNumber, int roomNumber)
{
    int choice;
    int quantity;
    cout << "\t"; cout << "Enter the transportation type: " << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "\t"; cout << i + 1 << " " << transportationtype[i] << " - Rs " << transportationprice[i] << endl;
    }
    cout << "\t"; cout << "Enter your choice: ";
    cin >> choice;
    cout << endl;
    if (choice < 1 || choice > 3)
    {
        cout << "\t"; cout << "Invalid choice\n";
        return;
    }
    cout << "\t"; cout << "Enter the number of days for which you want to avail the transport service: ";
    cin >> quantity;
    cout << endl;
    if (quantity < 1)
    {
        cout << "\t"; cout << "Invalid quantity." << endl;
        return;
    }

    totalcost[floorNumber - 1][roomNumber - 1] = totalcost[floorNumber - 1][roomNumber - 1] + transportationprice[choice - 1] * quantity;
    cout << "\t"; cout << "Transportation added to the bill." << endl;
}

void touristguidebooking(int floorNumber, int roomNumber)
{
    int choice;
    int quantity;
    cout << "\t"; cout << "Enter the guide type: " << endl;
    cout << "\t"; cout << "1. Full day - Rs 1000" << endl;
    cout << "\t"; cout << "2. Half day - Rs 500" << endl;
    cout << "\t"; cout << "Enter your choice: ";
    cin >> choice;
    cout << endl;
    if (choice < 1 || choice > 2)
    {
        cout << "\t"; cout << "Invalid choice." << endl;
        return;
    }

    cout << "\t"; cout << "Enter the number of tourist guides you want: ";
    cin >> quantity;
    cout << endl;
    if (quantity < 1)
    {
        cout << "\t"; cout << "Invalid quantity." << endl;
        return;
    }

    totalcost[floorNumber - 1][roomNumber - 1] = totalcost[floorNumber - 1][roomNumber - 1] + touristprice[choice - 1] * quantity;
    cout << "\t"; cout << "Tourist guide added to the bill." << endl;
}
/////////////////////////////////////////////////////////////////////////////MAIN MENU////////////////////////////////////////////////////////////////////////////////////////
int menu()
{


    cout << "\t"; cout << "|-----------------------------------------------|" << endl;
    cout << "\t"; cout << "|    Welcome to RULE Management System Menu     |" << endl;
    cout << "\t"; cout << "|-----------------------------------------------|" << endl;
    cout << "\t"; cout << "| 1. Book a room                                |" << endl;
    cout << "\t"; cout << "| 2. Update a room                              |" << endl;
    cout << "\t"; cout << "| 3. Check-in                                   |" << endl;
    cout << "\t"; cout << "| 4. Check-out                                  |" << endl;
    cout << "\t"; cout << "| 5. Cancel Booking                             |" << endl;
    cout << "\t"; cout << "| 6. Room Services                              |" << endl;
    cout << "\t"; cout << "| 7. Order Food                                 |" << endl;
    cout << "\t"; cout << "| 8. Booking Facilities                         |" << endl;
    cout << "\t"; cout << "| 9. Transportation Booking                     |" << endl;
    cout << "\t"; cout << "| 10.Tourist Guide Booking                      |" << endl;
    cout << "\t"; cout << "| 11.Calculate Total                            |" << endl;
    cout << "\t"; cout << "| 12.Exit                                       |" << endl;
    cout << "\t"; cout << "|-----------------------------------------------|" << endl;

    int choice;
    cout << "\t"; cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}


int main()
{
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            roomavailability[i][j] = true;
            roombooked[i][j] = false;
        }
    }

    int choice = menu();
    int floornumber;
    int roomnumber;

    while (true)
    {
        floornumber = 0;
        roomnumber = 0;
        switch (choice)
        {
        case 1:
            cout << "\t"; cout << "Enter floor number: ";
            cin >> floornumber;
            cout << "\t"; cout << "Enter room number: ";
            cin >> roomnumber;

            if (floornumber > 0 && floornumber <= maxfloors && roomnumber > 0 && roomnumber <= maxrooms)
            {
                if (roomavailability[floornumber - 1][roomnumber - 1])
                {
                    bookroom(floornumber, roomnumber);
                }
                else
                {
                    cout << "\t"; cout << "Room not available." << endl;
                }
            }
            else
            {
                cout << "\t"; cout << "Invalid floor and room number." << endl;
            }
            break;
        case 2:
            cout << "\t"; cout << "Enter floor number:";
            cin >> floornumber;
            cout << endl;
            cout << "\t"; cout << "Enter room number:";
            cin >> roomnumber;
            cout << endl;
            if (floornumber > 0 && floornumber <= maxfloors && roomnumber > 0 && roomnumber <= maxrooms)
            {
                updatebooking(floornumber, roomnumber);
            }
            else
            {
                cout << "\t"; cout << "\n Invalid room number!!";
            }
            break;
        case 3:
            cout << "\t"; cout << "Enter floor number: ";
            cin >> floornumber;
            //cout << endl;
            cout << "\t"; cout << "Enter room number: ";
            cin >> roomnumber;
            cout << endl;

            if (floornumber > 0 && floornumber <= maxfloors && roomnumber > 0 && roomnumber <= maxrooms)
            {
                if (roomavailability[floornumber - 1][roomnumber - 1])
                {
                    checkin(floornumber, roomnumber);
                }
                else
                {
                    cout << "\t"; cout << "Room not available." << endl;
                }
            }
            else
            {
                cout << "\t"; cout << "Invalid floor and room number." << endl;
            }
            break;
        case 4:
            cout << "\t"; cout << "Enter floor number: ";
            cin >> floornumber;
            //cout << endl;
            cout << "\t"; cout << "Enter room number: ";
            cin >> roomnumber;
            cout << endl;
            checkout(floornumber, roomnumber);

            if (floornumber > 0 && floornumber <= maxfloors && roomnumber > 0 && roomnumber <= maxrooms)
            {
                if (roomavailability[floornumber - 1][roomnumber - 1])
                {
                    totalcharges(floornumber, roomnumber);
                }
                else
                {
                    cout << "\t"; cout << "Invalid room number\n\tNo guest in room number " << roomnumber << ", floor number  " << floornumber << endl;
                }
            }
            else
            {
                cout << "\t"; cout << "Invalid floor and room number\n";
            }
            break;
        case 5:
            cout << "\t"; cout << "Enter floor number:";
            cin >> floornumber;
            //cout << endl;
            cout << "\t"; cout << "Enter room number:";
            cin >> roomnumber;
            cout << endl;
            if (floornumber > 0 && floornumber <= maxfloors && roomnumber > 0 && roomnumber <= maxrooms)
            {
                cancelbooking(floornumber, roomnumber);
            }
            else
            {
                cout << "\t"; cout << "\n Invalid room number!!";
            }
            break;
        case 6:
            cout << "\t"; cout << "Enter floor number: ";
            cin >> floornumber;
            //cout << endl;
            cout << "\t"; cout << "Enter room number: ";
            cin >> roomnumber;
            cout << endl;

            if (floornumber > 0 && floornumber <= maxfloors && roomnumber > 0 && roomnumber <= maxrooms)
            {
                if (!roomavailability[floornumber - 1][roomnumber - 1])
                {
                    roomservices(floornumber, roomnumber);
                }
                else
                {
                    cout << "\t"; cout << "Invalid room number\n\tNo guest in room number " << roomnumber << ", floor number " << floornumber << endl;
                }
            }
            else
            {
                cout << "\t"; cout << "Invalid floor and room number" << endl;
            }

            break;
        case 7:
            cout << "\t"; cout << "Enter floor number: ";
            cin >> floornumber;
            //cout << endl;
            cout << "\t"; cout << "Enter room number: ";
            cin >> roomnumber;
            cout << endl;

            if (floornumber > 0 && floornumber <= maxfloors && roomnumber > 0 && roomnumber <= maxrooms)
            {
                if (!roomavailability[floornumber - 1][roomnumber - 1])
                {
                    orderfood(floornumber, roomnumber);
                }
                else
                {
                    cout << "\t"; cout << "Invalid room number\n\tNo guest in room number " << roomnumber << ", floor number  " << floornumber << endl;
                }
            }
            else
            {
                cout << "\t"; cout << "Invalid floor and room number\n";
            }
            break;
        case 8:
            cout << "\t"; cout << "Enter floor number: ";
            cin >> floornumber;
            //cout << endl;
            cout << "\t"; cout << "Enter room number: ";
            cin >> roomnumber;
            cout << endl;

            if (floornumber > 0 && floornumber <= maxfloors && roomnumber > 0 && roomnumber <= maxrooms)
            {
                if (!roomavailability[floornumber - 1][roomnumber - 1])
                {
                    bookingfacilities(floornumber, roomnumber);
                }
                else
                {
                    cout << "\t"; cout << "Invalid room number\n\tNo guest in room number " << roomnumber << ", floor number  " << floornumber << endl;
                }
            }
            else
            {
                cout << "\t"; cout << "Invalid floor and room number\n";
            }

            break;
        case 9:
            cout << "\t"; cout << "Enter floor number: ";
            cin >> floornumber;
            //cout << endl;
            cout << "\t"; cout << "Enter room number: ";
            cin >> roomnumber;
            cout << endl;

            if (floornumber > 0 && floornumber <= maxfloors && roomnumber > 0 && roomnumber <= maxrooms)
            {
                if (!roomavailability[floornumber - 1][roomnumber - 1])
                {
                    transportationbooking(floornumber, roomnumber);
                }
                else
                {
                    cout << "\t"; cout << " Invalid room number\n\tNo guest in room number " << roomnumber << ", floor number  " << floornumber << endl;
                }
            }
            else
            {
                cout << "\t"; cout << "Invalid floor and room number" << endl;
            }
            break;
        case 10:
            cout << "\t"; cout << "Enter floor number: ";
            cin >> floornumber;
            //cout << endl;
            cout << "\t"; cout << "Enter room number: ";
            cin >> roomnumber;
            cout << endl;

            if (floornumber > 0 && floornumber <= maxfloors && roomnumber > 0 && roomnumber <= maxrooms)
            {
                if (!roomavailability[floornumber - 1][roomnumber - 1])
                {
                    touristguidebooking(floornumber, roomnumber);
                }
                else
                {
                    cout << "\t"; cout << "Invalid room number\n\tNo guest in room number " << roomnumber << ", floor number  " << floornumber << endl;
                }
            }

            else
            {
                cout << "\t"; cout << "Invalid floor and room number\n";
            }

            break;
        case 11:
            cout << "\t"; cout << "Enter floor number: ";
            cin >> floornumber;
            //cout << endl;
            cout << "\t"; cout << "Enter room number: ";
            cin >> roomnumber;
            cout << endl;

            if (floornumber > 0 && floornumber <= maxfloors && roomnumber > 0 && roomnumber <= maxrooms) {
                if (!roomavailability[floornumber - 1][roomnumber - 1])
                    totalcharges(floornumber, roomnumber);
                else
                {
                    cout << "\t"; cout << "Invalid room number\n\tNo guest in room number " << roomnumber << ", floor number  " << floornumber << endl;
                }
            }
            else
            {
                cout << "\t"; cout << "Invalid floor and room number\n";
            }

            break;
        case 12:
            cout << "\t"; cout << "Exiting program. Goodbye!" << endl;
            return 0;
        default:
            cout << "\t"; cout << "Invalid choice. Please enter a number between 1 and 9." << endl;
            break;
        }
        choice = menu();
    }
    return 0;
}
