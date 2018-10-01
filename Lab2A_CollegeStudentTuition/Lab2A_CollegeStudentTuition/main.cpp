/////////////////////////////////////////////////////////////////////////////////////
//                                                                     
// Filename: main.cpp
// Date: Sep 11, 2018
// Programmer: Shengkai Xu
//
// Description:
//    This program using table data to help calculates the college tuition fee.
// 
/////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////
//
// Class: main function
//                                                                   
// Description:
//    Function read and check the input of tuition type.
//    Calculate the tuition fee acorrding to the input.
// 
/////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include "pch.h"
#include "header.h"

int main()
{
	cout << "Welcome to Studetns tuition calculator. Hit \"Enter\" to continue." << endl;

	ofstream outData("tuition_report.txt");

	if (!outData.is_open())
	{
		cout << "ERROR, output file could not be opened! \n";
		return 1;
	}

	while (true)
	{
		cin.clear();
		cin.ignore(100, '\n');

		string student_name;

		cout << "Your name is: ";
		getline(cin, student_name);

		int tuition_type = 0;

		cout << "(1) In State Tuition \n"
			<< "(2) Out State Tuition \n"
			<< "Please enter tuition type by using (1/2) \n";

		while (true) //giving options for tuition type
		{
			cin >> tuition_type; //read input

			if (tuition_type == 1 || tuition_type == 2)// checking input
			{
				break;
			}

			else
			{
				cout << "ERROR, Please type either 1 or 2 for selection! \n"; //error option
				cin.clear();
				cin.ignore(100, '\n');
				continue;
			}
		}

		double crdt_hrs = 0;
		double total_fee = 0;

		switch (tuition_type)
		{
		case 1:
			total_fee = instate_cal();
			break;

		case 2:
			total_fee = outstate_cal();
			break;
		}

		//choosing health plane
		cout << "(N) I dont want a health plan for now \n"
			<< "(E) Plan E: $40 \n"
			<< "(S) Plan S: $160 \n"
			<< "(C) Plan C: $120 \n"
			<< "(F) Plane F: $200 \n"
			<< "Please choose optional health plan as above: " << endl;

		char health_plan;

		cin >> health_plan; //read input
		health_plan = toupper(health_plan);

		while (true)
		{
			if (health_plan == 'E' || health_plan == 'S' || health_plan == 'C' || health_plan == 'F' || health_plan == 'N')
			{
				switch (health_plan)
				{
				case 'E': cout << "\nYou choosed Health Plan N with additon $40 on your tuition. \n";
					break;

				case 'S': cout << "\nYou choosed Health Plan S with additon $40 on your tuition. \n";
					break;

				case 'C': cout << "\nYou choosed Health Plan C with additon $40 on your tuition. \n";
					break;

				case 'F': cout << "\nYou choosed Health Plan F with additon $40 on your tuition. \n";
					break;

				case 'N': cout << "\nYou don't want health plan for now? There will be no additon fee to your tuition. \n";
					break;
				}
				break;
			}
			else //error option
			{
				cout << "ERROR, Please type letter above for selection! \n";
				cin.clear();
				cin.ignore(100, '\n');
				continue;
			}
		}

		double updated_fee = 0.0;

		if (health_plan == 'E')
		{
			updated_fee = total_fee + 40;
		}
		else if (health_plan == 'S')
		{
			updated_fee = total_fee + 160;
		}
		else if (health_plan == 'C')
		{
			updated_fee = total_fee + 120;
		}
		else if (health_plan == 'F')
		{
			updated_fee = total_fee + 200;
		}
		else
		{
			updated_fee = total_fee + 0;
		}

		cout << "\nYour updated total tuition fee with health plan is: $" << updated_fee << endl;
		// output data to .txt

		string tuition_status = (tuition_type == 1) ? "In State Tuition" : "Out State Tuition";

		outData
			<< "Name: " << student_name << "\n"
			<< "Tuition Status: " << tuition_status << "\n"
			<< "Health Plan Type: " << health_plan << "\n"
			<< "Total Tuition Fee: $" << updated_fee << "\n\n" << endl;

		cout << "\nExporting the data to \"tuition_report.txt\""; //wait
		for (int i = 0; i < 10; i++) //for loop dots loading
		{
			Sleep(100);
			cout << ".";
		}

		cout << "Done.\nDo you want to continue enter next student information? (Y/N)" << endl;
		char multi_students;
		cin >> multi_students;

		if (multi_students == 'Y' || multi_students == 'y')
		{
			continue;
		}
		else
		{
			outData.close();
			break;
		}
	}
	system("pause");
	return 0;
}

