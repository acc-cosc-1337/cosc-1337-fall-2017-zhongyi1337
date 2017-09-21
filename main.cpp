#include "Payroll.h"
#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

int main()
{
	const int SIZE = 36;
	const double ot_rate = 1.5;
	double salary1, pay1, pay_rate, hours, pay2, otpay_rate, otpay1, ot1, ssn, med, charges, gpay, netpay;
	string category, name;
	string results[SIZE];
	for (int i = 0; i < 3; i++)
	{
		
		cout << "Please enter your name: ";
		getline(cin, name);
		bool c_flag = true;
		while (c_flag) 
		{
			cout << "Please enter employee category(salary or hourly): ";
			cin >> category;
			if (category == "salary")
			{
				bool s_flag = true;
				while (s_flag)
				{
					cout << "Please enter your  yearly salary: ";
					cin >> salary1;
					if (salary1 >= 20000 && salary1 <= 100000)
					{
						pay1 = grosspay(salary1);
						ssn = getFICASSN(pay1);
						med = getFICAMED(pay1);
						charges = getFIT(pay1);
						netpay = getNetpay(pay1, ssn, med, charges);
						results[0 + i * 12] = name;
						results[1 + i * 12] = "";
						results[2 + i * 12] = "";
						results[3 + i * 12] = "";
						results[4 + i * 12] = "";
						results[5 + i * 12] = contoStr(pay1);
						results[6 + i * 12] = "";
						results[7 + i * 12] = contoStr(pay1);
						results[8 + i * 12] = contoStr(ssn);
						results[9 + i * 12] = contoStr(med);
						results[10 + i * 12] = contoStr(charges);
						results[11 + i * 12] = contoStr(netpay);
						s_flag = false;
					}
					else
					{
						cout << "A valid range of salary is from $20000 to $100000" << endl;

					}
				}
				c_flag = false;
			}
			else if (category =="hourly")
			{
				bool pay_rate_flag = true;
				while (pay_rate_flag)
				{
					cout << "Please enter your pay rate: ";
					cin >> pay_rate;
					if (pay_rate < 0 || pay_rate >= 50)
						cout << "A valid range of pay rate is from $0 to $50" << endl;
					else
						pay_rate_flag = false;

				}
				bool hour_flag = true;
				while (hour_flag)
				{
					cout << "Please enter your worked hours: ";
					cin >> hours;
					if (hours < 0 || hours > 60)
						cout << "A valid range of worked hours is from 0 to 60" << endl;
					else
					{
						double reg_hour;
						ot1 = ot(hours);
						reg_hour = hours - ot1;
						pay2 = regularpay(reg_hour, pay_rate);
						otpay_rate = ot_rate *pay_rate;
						otpay1 = otpay(pay_rate, ot1);
						gpay = grosspay(pay2, otpay1);
						ssn = getFICASSN(gpay);
						med = getFICAMED(gpay);
						charges = getFIT(gpay);
						netpay = getNetpay(gpay, ssn, med, charges);
						results[0 + i * 12] = name;
						results[1 + i * 12] = contoStr(hours);
						results[2 + i * 12] = contoStr(ot1);
						results[3 + i * 12] = contoStr(pay_rate);
						results[4 + i * 12] = contoStr(otpay_rate);
						results[5 + i * 12] = contoStr(pay2);
						results[6 + i * 12] = contoStr(otpay1);
						results[7 + i * 12] = contoStr(gpay);
						results[8 + i * 12] = contoStr(ssn);
						results[9 + i * 12] = contoStr(med);
						results[10 + i * 12] = contoStr(charges);
						results[11 + i * 12] = contoStr(netpay);
						hour_flag = false;
							
					}
				}
				c_flag = false;
			}
			else 
			{
				cout << "Category must be salary or hourly" << endl;
			}
			cin.ignore();

		}
		
	}
	cout << fixed << showpoint << setprecision(2);
	printout(results);
	cin.ignore();
	cin.get();
	return 0;
}
