#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct supplier {
	int id;
	string name;
	string sup_phone;
	char sup_product[100];
}s[50];
struct expire {
	int day;
	int month;
	int year;
};
struct medical_product {
	int id;
	string name;
	int stock;
	expire ex_date;
	string Sname;
	float price;


} m[50];
struct date {
	int day;
	int month;
	int year;
};
struct customer
{
	int id;
	string name;
	string phone;
	string the_purchased_products;
	float value;
	date lastbill;
	date firstbill;
	float total_price;
}c[50];
//================================================================
void add_supplier(supplier s)
{

	ofstream outfiles;
	outfiles.open("Suppliers.txt", ios::app);
	ifstream infiles;
	infiles.open("Suppliers.txt");
	while (!infiles.eof())
	{
		infiles >> s.id;
		infiles >> s.name;
		infiles >> s.sup_phone;
		infiles >> s.sup_product;
	}
	infiles.close();
	if (s.id <= 0)
	{
		s.id = 1;
	}
	else
	{
		s.id = s.id + 1;
	}
	cout << "enter name: \n ";
	cin >> s.name;
	cout << "enter sup_phone: \n";
	cin >> s.sup_phone;
	cout << "enter sup_product: \n";
	cin >> s.sup_product;
	outfiles << s.id << endl;
	outfiles << s.name << endl;
	outfiles << s.sup_phone << endl;
	outfiles << s.sup_product << endl;
	outfiles.close();

}
//================================================================
void add_medical_product(medical_product m, supplier s) {




	ofstream outfille;
	outfille.open("medical.txt", ios::app);

	ifstream infille;
	infille.open("medical.txt");

	while (!infille.eof())
	{
		infille >> m.id;
		infille >> m.name;
		infille >> m.stock;
		infille >> m.Sname;
		infille >> m.ex_date.day;
		infille >> m.ex_date.month;
		infille >> m.ex_date.year;
		infille >> m.price;


	}
	infille.close();

	if (m.id <= 0)
	{
		m.id = 1;
	}

	else
	{
		m.id = m.id + 1;
	}

	cout << "enter name \n";
	cin >> m.name;
	cout << "enter stock \n";
	cin >> m.stock;
	cout << "enter the date of epire date \n";
	cin >> m.ex_date.day >> m.ex_date.month >> m.ex_date.year;
	cout << "enter price \n";
	cin >> m.price;

	int tempp = 0;

	ofstream ofiles;
	ofiles.open("Suppliers.txt", ios::app);

	ofiles.close();

	ifstream ss;
	ss.open("Suppliers.txt");

	ss >> s.id;
	ss >> s.name;
	ss >> s.sup_phone;
	ss >> s.sup_product;

	while (!ss.eof())
	{
		if (s.sup_product == m.name)
		{
			m.Sname = s.name;
			tempp = 1;
		}


		ss >> s.id;
		ss >> s.name;
		ss >> s.sup_phone;
		ss >> s.sup_product;


	}

	ss.close();
	if (tempp == 0)
	{
		cout << "This supplier and medical is not found" << endl;
	}




	outfille << m.id << endl;
	outfille << m.name << endl;
	outfille << m.stock << endl;
	outfille << m.Sname << endl;
	outfille << m.ex_date.day << endl;
	outfille << m.ex_date.month << endl;
	outfille << m.ex_date.year << endl;
	outfille << m.price << endl;
	outfille.close();




}
//================================================================
float update_medical(medical_product m, string name)
{

	float value;

	ifstream mp;
	mp.open("medical.txt");
	ofstream ee;
	ee.open("new_m.txt");

	mp >> m.id;
	mp >> m.name;
	mp >> m.stock;
	mp >> m.Sname;
	mp >> m.ex_date.day;
	mp >> m.ex_date.month;
	mp >> m.ex_date.year;
	mp >> m.price;


	while (!mp.eof())
	{
		if (m.name != name)
		{

			ee << m.id << endl;
			ee << m.name << endl;
			ee << m.stock << endl;
			ee << m.Sname << endl;
			ee << m.ex_date.day << endl;
			ee << m.ex_date.month << endl;
			ee << m.ex_date.year << endl;
			ee << m.price << endl;


		}
		else
		{
			ee << m.id << endl;
			ee << m.name << endl;
			ee << m.stock - 1 << endl;
			ee << m.Sname << endl;
			ee << m.ex_date.day << endl;
			ee << m.ex_date.month << endl;
			ee << m.ex_date.year << endl;
			ee << m.price << endl;
			value = m.price;

		}


		mp >> m.id;
		mp >> m.name;
		mp >> m.stock;
		mp >> m.Sname;
		mp >> m.ex_date.day;
		mp >> m.ex_date.month;
		mp >> m.ex_date.year;
		mp >> m.price;

	}

	ee.close();
	mp.close();
	remove("medical.txt");
	rename("new_m.txt", "medical.txt");


	return value;


}
//================================================================
void add_customer(customer c, medical_product m)
{

	float val;

	ofstream outfile;
	outfile.open("Customers.txt", ios::app);

	ifstream infile;
	infile.open("Customers.txt");

	while (!infile.eof())
	{
		infile >> c.id;
		infile >> c.name;
		infile >> c.phone;
		infile >> c.the_purchased_products;
		infile >> c.firstbill.day;
		infile >> c.firstbill.month;
		infile >> c.firstbill.year;
		infile >> c.lastbill.day;
		infile >> c.lastbill.month;
		infile >> c.lastbill.year;
		infile >> c.value;
		infile >> c.total_price;

	}
	infile.close();

	if (c.id <= 0)
	{
		c.id = 1;
	}

	else
	{
		c.id = c.id + 1;
	}

	cout << "enter name \n";
	cin >> c.name;
	cout << "enter phone \n";
	cin >> c.phone;
	cout << "enter purchased_product \n";
	cin >> c.the_purchased_products;
	val = update_medical(m, c.the_purchased_products);
	cout << "enter the date of last bill \n";
	cin >> c.lastbill.day >> c.lastbill.month >> c.lastbill.year;
	c.value = val;



	c.total_price = c.value;
	c.firstbill.day = c.lastbill.day;
	c.firstbill.month = c.lastbill.month;
	c.firstbill.year = c.lastbill.year;

	outfile << c.id << endl;
	outfile << c.name << endl;
	outfile << c.phone << endl;
	outfile << c.the_purchased_products << endl;
	outfile << c.firstbill.day << endl;
	outfile << c.firstbill.month << endl;
	outfile << c.firstbill.year << endl;
	outfile << c.lastbill.day << endl;
	outfile << c.lastbill.month << endl;
	outfile << c.lastbill.year << endl;
	outfile << c.value << endl;
	outfile << c.total_price << endl;
	outfile.close();




}
//================================================================
int search_medical_product(medical_product m, string name)
{
	int temps = 0;

	ofstream outfille;
	outfille.open("medical.txt", ios::app);

	outfille.close();

	ifstream mp;
	mp.open("medical.txt");


	mp >> m.id;
	mp >> m.name;
	mp >> m.stock;
	mp >> m.Sname;
	mp >> m.ex_date.day;
	mp >> m.ex_date.month;
	mp >> m.ex_date.year;
	mp >> m.price;


	while (!mp.eof())
	{
		if (m.name == name)
		{

			cout << "ID      : " << "M" << m.id << endl;
			cout << "Name    : " << m.name << endl;
			cout << "stock   : " << m.stock << endl;
			cout << "Sname   : " << m.Sname << endl;
			cout << "expire  : " << m.ex_date.day << "/" << m.ex_date.month << "/" << m.ex_date.year << endl;
			cout << "price   : " << m.price << endl;
			temps = 1;
		}



		mp >> m.id;
		mp >> m.name;
		mp >> m.stock;
		mp >> m.Sname;
		mp >> m.ex_date.day;
		mp >> m.ex_date.month;
		mp >> m.ex_date.year;
		mp >> m.price;


	}

	mp.close();
	if (temps == 0)
	{
		cout << "This medical not found " << endl;
	}


	return temps;

}
//================================================================
int search_customer(customer c, string phone)
{
	int temp = 0;

	ofstream outfile;
	outfile.open("Customers.txt", ios::app);

	outfile.close();

	ifstream d;
	d.open("Customers.txt");


	d >> c.id;
	d >> c.name;
	d >> c.phone;
	d >> c.the_purchased_products;
	d >> c.firstbill.day;
	d >> c.firstbill.month;
	d >> c.firstbill.year;
	d >> c.lastbill.day;
	d >> c.lastbill.month;
	d >> c.lastbill.year;
	d >> c.value;
	d >> c.total_price;

	while (!d.eof())
	{
		if (c.phone == phone)
		{

			cout << "ID      : " << "U" << c.id << endl;
			cout << "Name    : " << c.name << endl;
			cout << "Phone   : " << c.phone << endl;
			cout << "Product : " << c.the_purchased_products << endl;
			cout << "Date    : " << c.lastbill.day << "/" << c.lastbill.month << "/" << c.lastbill.year << endl;
			cout << "value   : " << c.value << endl;
			cout << "TPrice  : " << c.total_price << endl;
			temp = 1;
		}



		d >> c.id;
		d >> c.name;
		d >> c.phone;
		d >> c.the_purchased_products;
		d >> c.firstbill.day;
		d >> c.firstbill.month;
		d >> c.firstbill.year;
		d >> c.lastbill.day;
		d >> c.lastbill.month;
		d >> c.lastbill.year;
		d >> c.value;
		d >> c.total_price;

	}

	d.close();
	if (temp == 0)
	{
		cout << "This customer not found " << endl;
	}


	return temp;

}
//================================================================
int search_supplier(supplier s, string Snamee)
{
	int tempp = 0;

	ofstream outfiles;
	outfiles.open("Suppliers.txt", ios::app);

	outfiles.close();

	ifstream ss;
	ss.open("Suppliers.txt");

	ss >> s.id;
	ss >> s.name;
	ss >> s.sup_phone;
	ss >> s.sup_product;

	while (!ss.eof())
	{
		if (s.name == Snamee)
		{
			cout << "ID        : " << "S" << s.id << endl;
			cout << "Name      : " << s.name << endl;
			cout << "Phone     : " << s.sup_phone << endl;
			cout << "Product   : " << s.sup_product << endl;
			tempp = 1;
		}


		ss >> s.id;
		ss >> s.name;
		ss >> s.sup_phone;
		ss >> s.sup_product;


	}

	ss.close();
	if (tempp == 0)
	{
		cout << "This supplier is not found" << endl;
	}


	return tempp;
}
//================================================================
void show_all_medical(medical_product m)
{
	ifstream infille;
	infille.open("medical_product.txt", ios::app);
	infille >> m.id;
	infille >> m.name;
	infille >> m.stock;
	infille >> m.ex_date.day;
	infille >> m.ex_date.month;
	infille >> m.ex_date.year;
	infille >> m.Sname;
	infille >> m.price;
	while (!infille.eof())
	{
		cout << "medical_product id : \n";
		cout << m.id << endl;
		cout << "name id : \n";
		cout << m.name << endl;
		cout << "stoke is : \n";
		cout << m.stock << endl;
		cout << "ex_date is : \n";
		cout << m.ex_date.day << m.ex_date.month << m.ex_date.year << endl;
		cout << " Sname is: \n";
		cout << m.Sname << endl;
		cout << "price is :\n";
		cout << m.price << endl;

		infille >> m.id;
		infille >> m.name;
		infille >> m.stock;
		infille >> m.ex_date.day;
		infille >> m.ex_date.month;
		infille >> m.ex_date.year;
		infille >> m.Sname;
		infille >> m.price;
	}
	infille.close();

}
//================================================================
void show_all_supplier(supplier s)
{
	ifstream infile;
	infile.open("supplier.txt");
	infile >> s.id;
	infile >> s.name;
	infile >> s.sup_phone;
	infile >> s.sup_product;
	while (!infile.eof())
	{
		cout << "supplier id:";
		cout << s.id << endl;
		cout << "name is :";
		cout << s.name << endl;
		cout << "sup_phone is:";
		cout << s.sup_phone << endl;
		cout << "sup_product is:";
		cout << s.sup_product << endl;
		infile >> s.id;
		infile >> s.name;
		infile >> s.sup_phone;
		infile >> s.sup_product;

	}
	infile.close();
}
//================================================================
void show_all_customer(customer c)
{
	ifstream infile;
	infile.open("Customers.txt");
	infile >> c.id;
	infile >> c.name;
	infile >> c.phone;
	infile >> c.the_purchased_products;
	infile >> c.firstbill.day;
	infile >> c.firstbill.month;
	infile >> c.firstbill.year;
	infile >> c.lastbill.day;
	infile >> c.lastbill.month;
	infile >> c.lastbill.year;
	infile >> c.value;
	infile >> c.total_price;

	while (!infile.eof())
	{

		cout << "Customer's id : ";
		cout << c.id << endl;
		cout << "name is  : ";
		cout << c.name << endl;
		cout << "phone is  : ";
		cout << c.phone << endl;
		cout << "purchased_product is  : ";
		cout << c.the_purchased_products << endl;
		cout << "date of lastbill is : ";
		cout << c.lastbill.day << "/" << c.lastbill.month << "/" << c.lastbill.year << endl;
		cout << "value is : ";
		cout << c.value << endl;
		cout << "=========================================" << endl;

		infile >> c.id;
		infile >> c.name;
		infile >> c.phone;
		infile >> c.the_purchased_products;
		infile >> c.firstbill.day;
		infile >> c.firstbill.month;
		infile >> c.firstbill.year;
		infile >> c.lastbill.day;
		infile >> c.lastbill.month;
		infile >> c.lastbill.year;
		infile >> c.value;
		infile >> c.total_price;
	}
	infile.close();



}
//================================================================
void delete_customer(customer c, string phone)
{


	ifstream d;
	d.open("Customers.txt");
	ofstream e;
	e.open("new_c.txt");

	d >> c.id;
	d >> c.name;
	d >> c.phone;
	d >> c.the_purchased_products;
	d >> c.firstbill.day;
	d >> c.firstbill.month;
	d >> c.firstbill.year;
	d >> c.lastbill.day;
	d >> c.lastbill.month;
	d >> c.lastbill.year;
	d >> c.value;
	d >> c.total_price;

	while (!d.eof())
	{
		if (c.phone != phone)
		{

			e << c.id << endl;
			e << c.name << endl;
			e << c.phone << endl;
			e << c.the_purchased_products << endl;
			e << c.firstbill.day << endl;
			e << c.firstbill.month << endl;
			e << c.firstbill.year << endl;
			e << c.lastbill.day << endl;
			e << c.lastbill.month << endl;
			e << c.lastbill.year << endl;
			e << c.value << endl;
			e << c.total_price << endl;

		}
		else
		{
			cout << "customer is deleted " << endl;
		}


		d >> c.id;
		d >> c.name;
		d >> c.phone;
		d >> c.the_purchased_products;
		d >> c.firstbill.day;
		d >> c.firstbill.month;
		d >> c.firstbill.year;
		d >> c.lastbill.day;
		d >> c.lastbill.month;
		d >> c.lastbill.year;
		d >> c.value;
		d >> c.total_price;
	}

	e.close();
	d.close();
	remove("Customers.txt");
	rename("new_c.txt", "Customers.txt");



}
//================================================================
void delete_medical_product(medical_product m, string name)
{


	ifstream mp;
	mp.open("medical.txt");
	ofstream ee;
	ee.open("new_m.txt");

	mp >> m.id;
	mp >> m.name;
	mp >> m.stock;
	mp >> m.Sname;
	mp >> m.ex_date.day;
	mp >> m.ex_date.month;
	mp >> m.ex_date.year;

	mp >> m.price;


	while (!mp.eof())
	{
		if (m.name != name)
		{

			ee << m.id << endl;
			ee << m.name << endl;
			ee << m.stock << endl;
			ee << m.Sname << endl;
			ee << m.ex_date.day << endl;
			ee << m.ex_date.month << endl;
			ee << m.ex_date.year << endl;
			ee << m.price << endl;


		}
		else
		{
			cout << "medical is deleted " << endl;
		}


		mp >> m.id;
		mp >> m.name;
		mp >> m.stock;
		mp >> m.Sname;
		mp >> m.ex_date.day;
		mp >> m.ex_date.month;
		mp >> m.ex_date.year;
		mp >> m.price;

	}

	ee.close();
	mp.close();
	remove("medical.txt");
	rename("new_m.txt", "medical.txt");



}
//================================================================
void delete_supplier(supplier s, string Snamee)
{
	ifstream ss;
	ss.open("Suppliers.txt");
	ofstream u;
	u.open("new_s.txt");
	ss >> s.id;
	ss >> s.name;
	ss >> s.sup_phone;
	ss >> s.sup_product;
	while (!ss.eof())
	{
		if (s.name != Snamee)
		{
			u << s.id << endl;
			u << s.name << endl;
			u << s.sup_phone << endl;
			u << s.sup_product << endl;
		}
		else
		{
			cout << "supplier is deleted " << endl;
		}

		ss >> s.id;
		ss >> s.name;
		ss >> s.sup_phone;
		ss >> s.sup_product;

	}

	u.close();
	ss.close();
	remove("Suppliers.txt");
	rename("new_s.txt", "Suppliers.txt");


}
//================================================================
void update_customer(customer c, string phone, medical_product m)
{

	int day[7]; // search in only one week
	int month[7]; // search in only one week
	int year[7]; // search in only one week
	int temp = 0;
	float val;
	int check;

	string name_m;
	ifstream d;
	d.open("Customers.txt");
	ofstream e;
	e.open("new_c.txt");

	d >> c.id;
	d >> c.name;
	d >> c.phone;
	d >> c.the_purchased_products;
	d >> c.firstbill.day;
	d >> c.firstbill.month;
	d >> c.firstbill.year;
	d >> c.lastbill.day;
	d >> c.lastbill.month;
	d >> c.lastbill.year;
	d >> c.value;
	d >> c.total_price;


	while (!d.eof())
	{
		if (c.phone != phone)
		{

			e << c.id << endl;
			e << c.name << endl;
			e << c.phone << endl;
			e << c.the_purchased_products << endl;
			e << c.firstbill.day << endl;
			e << c.firstbill.month << endl;
			e << c.firstbill.year << endl;
			e << c.lastbill.day << endl;
			e << c.lastbill.month << endl;
			e << c.lastbill.year << endl;
			e << c.value << endl;
			e << c.total_price << endl;

		}
		else
		{

			cout << "enter purchased_product \n";
			cin >> name_m;
			check = search_medical_product(m, name_m);
			if (check == 1)
			{
				c.the_purchased_products = name_m;
				val = update_medical(m, c.the_purchased_products);
				cout << "enter the date of lastbill \n";
				cin >> c.lastbill.day >> c.lastbill.month >> c.lastbill.year;
				c.value = val;

			}
			else
			{
				goto jump;
			}





			for (int i = 0; i <= 6; i++)
			{
				if (c.firstbill.day + i <= 30 && c.firstbill.month < 12)
				{
					day[i] = c.firstbill.day + i;
					month[i] = c.firstbill.month;
					year[i] = c.firstbill.year;

				}
				else if (c.firstbill.day + i > 30 && c.firstbill.month < 12)
				{
					day[i] = (c.firstbill.day + i) % 30;
					month[i] = c.firstbill.month + 1;
					year[i] = c.firstbill.year;
				}
				else if (c.firstbill.day + i > 30 && c.firstbill.month == 12)
				{
					day[i] = (c.firstbill.day + i) % 30;
					month[i] = 1;
					year[i] = c.firstbill.year + 1;
				}


			}

			for (int i = 0; i <= 6; i++)
			{

				if (c.lastbill.day == day[i] && c.lastbill.month == month[i] && c.lastbill.year == year[i])
				{
					c.total_price = c.total_price + c.value;
					temp = 1;
					break;

				}


			}

			if (temp == 0)
			{
				c.total_price = c.value;
				c.firstbill.day = c.lastbill.day;
				c.firstbill.month = c.lastbill.month;
				c.firstbill.year = c.lastbill.year;
			}

		jump:

			e << c.id << endl;
			e << c.name << endl;
			e << c.phone << endl;
			e << c.the_purchased_products << endl;
			e << c.firstbill.day << endl;
			e << c.firstbill.month << endl;
			e << c.firstbill.year << endl;
			e << c.lastbill.day << endl;
			e << c.lastbill.month << endl;
			e << c.lastbill.year << endl;
			e << c.value << endl;
			e << c.total_price << endl;

		}

		d >> c.id;
		d >> c.name;
		d >> c.phone;
		d >> c.the_purchased_products;
		d >> c.firstbill.day;
		d >> c.firstbill.month;
		d >> c.firstbill.year;
		d >> c.lastbill.day;
		d >> c.lastbill.month;
		d >> c.lastbill.year;
		d >> c.value;
		d >> c.total_price;

	}

	e.close();
	d.close();
	remove("Customers.txt");
	rename("new_c.txt", "Customers.txt");

}
//================================================================
int main()
{

	int choice;
	int option;
	string phone;
	string Snamee;
	string Mname;
	char x;
	int check;
	customer c;
	supplier s;
	medical_product m;
	while (true)
	{

		cout << "Please enter your option : ( 1/customer - 2/supplier - 3/medical_product  ) " << endl;
		cin >> option;
		switch (option)
		{
		case 1:
		{

			do
			{
				cout << "Please enter your phone  :" << endl;
				cin >> phone;
				check = search_customer(c, phone);
				if (check == 1)
				{
					cout << "Please enter your option : ( 1/Update - 2/delete - 3/Exit   ) " << endl;
					cin >> choice;
					switch (choice)
					{
					case 1:
					{
						update_customer(c, phone, m);
						break;
					}
					case 2:
					{
						delete_customer(c, phone);
						break;
					}

					default: break;



					}


				}
				else
				{
					add_customer(c, m);

				}


				cout << endl;
				cout << "Do you want to back to Customer again ? y/n" << endl;
				cin >> x;



			} while (x == 'y');

			break;
		}
		case 2:
		{
			do
			{
				cout << "Please enter your name    :" << endl;
				cin >> Snamee;
				check = search_supplier(s, Snamee);
				if (check == 1)
				{
					cout << "Please enter your option : ( 1/update - 2/delete -3/Exit )" << endl;
					cin >> choice;
					switch (choice)
					{
					case 1:
					{
						break;
					}
					case 2:
					{
						delete_supplier(s, Snamee);
						break;
					}
					default:
						break;



					}

				}
				else
				{
					add_supplier(s);
				}

				cout << endl;
				cout << "Do you want to back to Supplier again ? y/n" << endl;
				cin >> x;


			} while (x == 'y');

			break;
		}
		case 3:
		{

			do
			{
				cout << "Please enter medical name :" << endl;
				cin >> Mname;
				check = search_medical_product(m, Mname);
				if (check == 1)
				{
					cout << "Please enter your option : ( 1/Update - 2/delete - 3/Exit   ) " << endl;
					cin >> choice;
					switch (choice)
					{
					case 1:
					{
						//	update_medical_product(m, name);
						break;
					}
					case 2:
					{
						delete_medical_product(m, Mname);
						break;
					}

					default: break;



					}


				}
				else
				{
					add_medical_product(m, s);

				}


				cout << endl;
				cout << "Do you want to back to medical again ? y/n" << endl;
				cin >> x;



			} while (x == 'y');





			break;
		}





		}
	}

	return 0;
}
