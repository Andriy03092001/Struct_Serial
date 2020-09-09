#include<iostream>
#include<string>
using namespace std;

//struct Time {
//	int hours;
//	int minutes;
//	int seconds;
//};

struct Date {
	int day;
	string month;
	int year;
};

struct Serial {
	string name;
	string genre;
	string director;
	Date startPresent;
	string country;
};

int countSerials = 0;
Serial* ListSerials = new Serial[countSerials];

void addSerialToSystem(Serial newSerial) {

	Serial* temp = new Serial[countSerials + 1];
	for (int i = 0; i < countSerials; i++)
	{
		temp[i] = ListSerials[i];
	}

	temp[countSerials] = newSerial;

	countSerials++;

	ListSerials = new Serial[countSerials];

	for (int i = 0; i < countSerials; i++)
	{
		ListSerials[i] = temp[i];
	}
	delete[]temp;
}

void showAllSerials() {

	for (int i = 0; i < countSerials; i++)
	{
		cout << endl;
		cout << ListSerials[i].name << endl;
		cout << " (" << ListSerials[i].startPresent.day << " " << ListSerials[i].startPresent.month << " " << ListSerials[i].startPresent.year << ")" << endl;
		cout << "Genre: " << ListSerials[i].genre << endl;
		cout << "Director: " << ListSerials[i].director << endl;
		cout << "Country: " << ListSerials[i].country << endl;
	}
}


void searchSerial(string dataSearch) {

	for (int i = 0; i < countSerials; i++)
	{
		if (ListSerials[i].name.find(dataSearch) != string::npos || 
			ListSerials[i].country.find(dataSearch) != string::npos ||
			ListSerials[i].director.find(dataSearch) != string::npos ||
			ListSerials[i].genre.find(dataSearch)  != string::npos)
		{
			cout << endl;
			cout << ListSerials[i].name << endl;
			cout << " (" << ListSerials[i].startPresent.day << " " << ListSerials[i].startPresent.month << " " << ListSerials[i].startPresent.year << ")" << endl;
			cout << "Genre: " << ListSerials[i].genre << endl;
			cout << "Director: " << ListSerials[i].director << endl;
			cout << "Country: " << ListSerials[i].country << endl;
		}
	}

}

int main() {

	//Date day1;
	//day1.day = 13;
	//day1.month = "November";
	//day1.year = 2011;
	//day1.time.hours = 23;
	//day1.time.minutes = 13;
	//day1.time.seconds = 0;
	//cout << day1.day << " " << day1.month << " " << day1.year << endl;

	int action = 0;
	do
	{

		cout << "1. Show all serials" << endl;
		cout << "2. Add new serial" << endl;
		cout << "3. Search serials" << endl;
		cout << "4. Exit" << endl;
		cout << endl;
		cout << "Select action from menu ->_" << endl;
		cin >> action;

		switch (action)
		{
			case 1: {
				showAllSerials();
			}break;

			case 2: {
				Serial newSerial;
				cout << "Enter name for serial: ";
				cin >> newSerial.name;

				cout << "Enter genre for serial: ";
				cin >> newSerial.genre;

				cout << "Enter country for serial: ";
				cin >> newSerial.country;

				cout << "Enter director for serial: ";
				cin >> newSerial.director;

				cout << "Enter start day for serial: ";
				cin >> newSerial.startPresent.day;

				cout << "Enter start mounth for serial: ";
				cin >> newSerial.startPresent.month;

				cout << "Enter start year for serial: ";
				cin >> newSerial.startPresent.year;

				addSerialToSystem(newSerial);
			}break;

			case 3: {
				string dataSearch = "";
				cout << "Search: ";
				cin >> dataSearch;
				searchSerial(dataSearch);
			}break;

			case 4: {
				cout << "Goodbye!" << endl;
			}break;

			default: {
				cout << "Error: Please, select actiom from menu!" << endl;
			}break;
		}

	} while (action != 4);


	return 0;
}