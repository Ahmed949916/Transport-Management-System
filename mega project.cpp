
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<time.h>
#include<stdlib.h>
#include<fstream>
#include<stdio.h>
#include <mutex>
using namespace std;

static int bh;
static int d_sh = 0;
static int v_sh;
void red()
{

	printf("\033[0;31m");

}
void boldRed()
{

	printf("\033[1;31m");

} //for adding colours
void yellow()
{

	printf("\033[0;33m");

}
void boldYellow()
{

	printf("\033[1;33m");

}
void green()
{

	printf("\033[0;32m");

}
void boldGreen()
{

	printf("\033[1;32m");

}
void blue()
{

	printf("\033[0;34m");

}
void boldBlue()
{

	printf("\033[1;34m");

}
void magenta()
{

	printf("\033[0;35m");

}
void boldMagenta()
{

	printf("\033[1;35m");

}
void cyan()
{

	printf("\033[0;36m");

}
void boldCyan()
{

	printf("\033[1;36m");

}
void reset()
{
   printf("\033[0m");
}
void flagg(string a)
{
	once_flag onceFlag;
	red();
	cout << a << endl;
	reset();
}



	class Name
	{
	private:
		char* fname;
		char* lname;
	public:
		Name();
		Name(char*, char*);
		void setfname(char*);
		void setlname(char*);
		char* getfname();
		char* getlname();
		Name(const Name&);
		friend ostream& operator<<(ostream&, const Name&);
		~Name()
		{
			delete fname;
			delete lname;
		}
	};
	void Name::setfname(char* f)
	{
		if (fname != nullptr)
		{
			delete[]fname;
		}
		fname = new char[strlen(f)+1];
		strcpy(fname, f);
	}
	void Name::setlname(char* l)
	{
		if (lname != nullptr)
		{
			delete[]lname;
		}
		lname = new char[strlen(l)+1];
		strcpy(lname,l);
	}
	char* Name::getfname()
	{
		return fname;
	}
	char* Name::getlname()
	{
		return lname;
	}
	Name::Name()
	{
		fname = nullptr;
		lname = nullptr;
	}
	Name::Name(char* fN, char* lN)
	{
		fname = new char[strlen(fN)];
		lname = new char[strlen(lN)];
		fname = fN;
		lname = lN;
	}
	ostream& operator<<(ostream & output, const Name & n)
	{
		output << n.fname << " " << n.lname << endl;
		return output;
	}
	Name:: Name(const Name& n)
	{
		fname = new char[strlen(n.fname)];
		lname = new char[strlen(n.lname)];
		fname = n.fname;
		lname = n.lname;
	}

	class Date
	{
	private:
		int day;
		int month;
		int year;
		public:
			Date();
			
			Date(int, int, int);
			void setDate(int);
			void setMonth(int);
			void setYear(int);
			int getDate();
			int getMonth();
			int getYear();
			friend istream& operator>>(istream&, Date&);
			friend ostream& operator<<(ostream&, const Date&);
	};
	istream& operator>>(istream& inp, Date& d)
	{
		bool check = true;
		while (check)
		{
			cout << "\nDate:";
			 inp >> d.day;
			cout << "Month:";
			inp >> d.month;
			cout << "Year:";
			inp >> d.year;
			if (d.day >= 1 && d.day <= 31 && d.month >= 1 && d.month <= 12 && d.year > 1900 && d.year <= 2023)
				check = false;
			if (check)
			{
				cout << "Invalid Date\n";
			}
		}
		return inp;

	}
	ostream& operator<<(ostream& output, const Date& d)
	{
		output << d.day << "/" << d.month << "/" << d.year<<endl;
		return output;
	}
	int Date::getDate()
	{
		return day;
	}
	int Date::getMonth()
	{
		return month;
	}
	int Date::getYear()
	{
		return year;
	}
	void Date::setYear(int y)
	{
		year = y;
	}
	void Date::setMonth(int m)
	{
		month = m;
	}
	void Date::setDate(int d)
	{
		day = d;
	}
	Date::Date(int d, int m, int y)
	{
		day = d;
		month = m;
		year = y;
	}
	Date::Date()
	{
		day = 0;
		month = 0;
		year = 0;
	}


	class Mtime
	{
	public:
		Mtime();
		
		Mtime(int, int, int);
		void setHour(int);
		void setMin(int);
		void setSec(int);
		int getHour();
		int getMin();
		int getSec();
		friend ostream& operator<<(ostream&, const Mtime&);
	private:
		int hour;
		int min;
		int sec;
	};
	Mtime::Mtime()
	{
		hour = 0, min = 0, sec = 0;
	}
	Mtime::Mtime(int h, int m, int s)
	{
		hour = h;
		min = m;
		sec = s;
	}
	int Mtime::getHour()
	{
		return hour;
	}
	int Mtime::getMin() {
		return min;
	}
	int Mtime::getSec()
	{
		return sec;
	}
	void Mtime::setHour(int h)
	{
		hour = h;
	}
	void Mtime::setMin(int m)
	{
		min = m;
	}
	void Mtime::setSec(int s)
	{
		sec = s;
	}
	ostream& operator<<(ostream& output, const Mtime& t)
	{
		output << t.hour << ":" << t.min << ":" << t.sec<<endl;
		return output;
	}


	class Service
	{
	private:
		char* source;
		char* destination;
		float distance;  // distance in km
		Date bookingDate;
		Mtime bookingTime;
		bool status;
		float fuelrate;
		int cId;    //Customer ID
		int dId;    //Driver ID
		int vId;    // Vehicle ID
		int cost_of_service;
	public:
		int getcost()
		{
			return cost_of_service;
		}
		virtual void setcost(int c)
		{
			cost_of_service = c;
		}
		Service();
		
		  Service(char*, char*, float, int, int, int, int, int, int, bool, float, int, int, int);
		void setSource(char*);
		void SetDestination(char*);
		void setDistance(float);
		void setStatus(bool);
		void setFuelrate(float);
		void setCID(int);
		void setDID(int);
		void setVID(int);
		virtual void setbookingtime(int, int, int);
		virtual void setbookingdate(int, int, int);
	};
	
	void Service::setbookingtime(int s, int m, int h)
	{
		bookingTime.setSec(s);
		bookingTime.setMin(m);
		bookingTime.setHour(h);
	}
	void Service::setbookingdate(int d, int m, int y)
	{
		bookingDate.setDate(d);
		bookingDate.setMonth(m);
		bookingDate.setYear(y);
	}
	void Service::setSource(char* s)
	{
		if (source != nullptr)
			delete[]source;
		int l = strlen(s);
		source = new char[l];
		strcpy(source,s);
	}
	void Service::SetDestination(char* d)
	{
		if (destination == nullptr)
			delete[]destination;
		int l = strlen(d);
		destination = new char[l];
		for (int i = 0; i < l; i++)
		{
			destination[i] = d[i];
		}
	}
	Service::Service()
	{
		source = nullptr;
		destination = nullptr;
		distance = 0.0;
		status = 0;
		fuelrate = 0.0;
		cId = 0;
		dId = 0;
		vId = 0;
	}
	Service::Service(char* a, char* b, float c, int d, int e, int f, int g, int h, int i, bool s, float fuel, int cid, int did, int vid) :bookingDate(d, e, f), bookingTime(g, h, i)
	{
		int la= strlen(a);//length of a
		source = new char[la+1];
		strcpy(source, a);
		int lb = strlen(a);//length of b
		destination = new char[lb+1];
		strcpy(destination, b);
		distance = c;
		status = s;
		fuelrate = fuel;
		cId = cid;
		dId = did;
		vId = vid;
	}
	void Service::setCID(int cid)
	{
		cId = cid;
	}
	void Service::setVID(int vid)
	{
		vId = vid;
	}
	void Service::setDID(int did)
	{
		dId = did;
	}
	void Service::setFuelrate(float fuel)
	{
		fuelrate = fuel;
	}
	void Service::setStatus(bool s)
	{
		status = s;
	}
	void Service::setDistance(float d)
	{
		distance = d;
	}

	class Ride : public Service
	{
	public:
		Ride();
		~Ride();
		Ride(int, char*, float, float,bool);
		void setNOP(int);//setter for no of passengers
		void setridetype(string);
		void setDriverR(float);
		void setVehicleR(float);
		int getNOP();//getter for no of passengers
		float getDriverR();
		float getVehicleR();
		char* getRideType();
	
	private:
		int no_of_passengers;
		char* rideType;
		float DriverRanking;
		float VehicleRanking;
		bool status;
		
	};
	Ride::~Ride()
	{
		delete[] rideType;
	}
	Ride::Ride()
	{
		no_of_passengers = 0;
		rideType = nullptr;
		DriverRanking = 0.0;
		VehicleRanking = 0.0;
		status = false;
	}
	Ride::Ride(int p, char* t, float d, float v,bool stat)
	{
		no_of_passengers = p;
		int l = strlen(t);
		rideType = new char[l];
		for (int i = 0; i < l; i++)
		{
			rideType[i] = t[i];
		}
		DriverRanking = d;
		VehicleRanking = v;
		status = stat;
	}
	void Ride::setNOP(int no_of_passengers)
	{
		this->no_of_passengers = no_of_passengers;
	}
	void Ride::setridetype(string t)
	{
		
		if (rideType != nullptr)
			delete[]rideType;
		rideType = new char[10];
		strcpy(rideType,(t.c_str()));
		
	}
	void Ride::setDriverR(float r)
	{
		DriverRanking = r;
	}
	void Ride::setVehicleR(float v)
	{
		VehicleRanking = v;
	}
	float Ride::getDriverR()
	{
		return DriverRanking;
	}
	float Ride::getVehicleR()
	{
		return VehicleRanking;
	}
	int Ride::getNOP()
	{
		return no_of_passengers;
	}
	char* Ride:: getRideType()
	{
		return rideType;
	}
	class Delivery :public Service
	{
	public:
		Delivery();
		Delivery(float, char*);
		void setweight(float);
		void setGoodType(char*);
		float getgoodweight();
		char* getgoodtype();
	private:
		float goodsweight;
		char* goodsType;
	};
	Delivery::Delivery()
	{
		goodsweight = 0;
		goodsType = nullptr;
	}
	Delivery::Delivery(float a, char* b)
	{
		goodsweight = a;
		goodsType = new char[strlen(b)+1];
		strcpy(goodsType, b);
	}
	void Delivery::setweight(float w)
	{
		goodsweight = w;
	}
	void Delivery::setGoodType(char*)
	{
		if (goodsType != nullptr)
			delete[]goodsType;
	}
	float Delivery::getgoodweight()
	{
		return goodsweight;
	}
	char* Delivery::getgoodtype()
	{
		return goodsType;
	}

	class Person
	{
	protected:
		Name pName;
		Date DOB;
		int Age; 
		long long int Nid;
	public:
		friend ostream& operator<<(ostream&, const Person&);
		
		void setAge(int);
		void setNID(int);
		int getAge();
		int getNID();
		Person();
		Person(int, int);
		Person(const Person&);
		/*~Person(){};*/
		void SetPerson(char* a, char* b, int c, int d, int e, int f, int g);
		
	};
	Person::Person(const Person& p)
	{
		pName = p.pName;
		DOB = p.DOB;
		Age = p.Age;
		Nid = p.Nid;
	}
	void Person::setAge(int a)
	{
		Age = a;
	}
	void Person::setNID(int nID)
	{
		this->Nid = nID;
	}
	int Person::getAge()
	{
		return Age;
	}
	int Person::getNID()
	{
		return Nid;
	}
    Person::Person(int Age, int Nid)
	{
		this->Age = Age;
		this->Nid = Nid;
	}
	Person::Person()
	{
		Age = 0;
		Nid = 0;

	}
	ostream& operator<<(ostream& out, const Person& p)
	{
		out <<"Name:" << p.pName << "Date of Birth:" << p.DOB;
		out << "Age:" << p.Age << "\nNational ID:" << p.Nid<<endl;
		return out;
	}
	void Person::SetPerson(char* a, char* b, int c, int d, int e, int f, int g)
	{
		pName.setfname(a);
		pName.setlname(b);
		DOB.setDate(c);
		DOB.setMonth(d);
		DOB.setYear(e);
		Age = f; Nid = g;
	}


	class Customer :public Person
	{
	public:
		int getcid();
		Customer();
		 static int bh;
		void setcustomer(int,char* p, char* q, int r, int s, int t, int u, int v);
		void setCust(int a, char* b, char* c, float d, int e, int f, int g, int h, int i, int j, bool k, float l, int m, int n, int o, char* p, char* q, int r, int s, int t, int u, int v);
		Customer(int a, char* b, char* c, float d, int e, int f, int g, int h, int i, int j, bool k, float l, int m, int n, int o, char* p, char* q, int r, int s, int t, int u, int v);
		virtual void setbookinghistory(char* , char* , float , int , int , int , int , int , int , bool , float , int ,int,int);
		~Customer()
		{
			delete[]bookingHistory;
		}

	private:

		int cId;
		Service** bookingHistory;
		
	};
	int Customer::bh = 0;
	 void Customer::setbookinghistory(char* a, char* b, float c, int d, int e, int f, int g, int h, int i, bool s, float fuel, int cid, int did, int vid)
	{
		 if(bookingHistory[bh]==nullptr)
		bookingHistory[bh] = new Service(a, b, c, d, e, f, g, h, i, s, fuel, cid, did, vid);
		bh++;
	}
	
	int Customer::getcid()
	{
		return cId;
	}
	Customer::Customer():Person()
	{
		cId = 0;
		bookingHistory = new Service*[15];
	}
	Customer::Customer(int a, char* b, char* c, float d, int e, int f, int g, int h, int i, int j, bool k, float l, int m, int n, int o, char* p, char* q, int r, int s, int t, int u, int v)
	{
		cId = a;
		bookingHistory = new Service * [10];
		bookingHistory[0] = new Service(b, c, d, e, f, g, h, i, j, k, l, m, n, o);
		this->SetPerson(p, q, r, s, t, u, v);
	}
	void Customer::setCust(int a, char* b, char* c, float d, int e, int f, int g, int h, int i, int j, bool k, float l, int m, int n, int o, char* p, char* q, int r, int s, int t, int u, int v)
		{
			cId = a;
			bookingHistory = new Service * [10];
			bookingHistory[0] = new Service(b, c, d, e, f, g, h, i, j, k, l, m, n, o);
			this->SetPerson(p, q, r, s, t, u, v);
		}
	void Customer::setcustomer(int a,char* p, char* q, int r, int s, int t, int u, int v)
	{
		cId = a;
		bookingHistory = new Service*;
		bookingHistory[0] = new Service;
		this->SetPerson(p, q, r, s, t, u, v);
	}
	

	class Driver :public Person
	{
	private:
		int dId;
		char** LicencesList;
		int no_of_Licences;
		float overallRanking;
		float salary;
		int experience;
		int status;
		Service** serviceHistory;
	public:
		Driver()
		{
			dId = 0;
			LicencesList = nullptr;
			no_of_Licences = 0;
			overallRanking = 0;
			salary = 0;
			experience = 0;
			status = 0;
			serviceHistory = new Service*[20];
		};
		~Driver()
		{
			for (int i = 0; i < no_of_Licences; i++)
			{
				delete[] LicencesList[i];
			}
			delete LicencesList;
			delete[] serviceHistory;
		}
		static int service_h;
		void setstat(int);
		void setdid(int a)
		{
			dId = a;
		}
		void plusdriver();
		void setdata(int did, char* f, char* l, int d, int m, int y, int age1, int nic);
		void setdata2(int, char**&, float, float, int, int);
		int getid();
		void print();
		int getlicense()
		{
			return no_of_Licences;
		}
		float getrank();
		int getstatus();
		void print_for_services();
		void update_To_file(int);
		void addservice(char* a, char* b, float c, int d, int e, int f, int g, int h, int i, bool s, float fuel, int cid, int did, int vid)
		{
			serviceHistory[service_h] = new Service(a, b, c, d, e, f, g, h, i, s, fuel, cid, did, vid);
			service_h++;
		}
	};
	int Driver::service_h = 0;
	void  Driver::update_To_file(int count)
	{
		
		ofstream ofs;
		if(count==0)
		ofs.open("temp.txt", ofstream::out);
		else
			ofs.open("temp.txt", ofstream::app);
		
		//ofs<<
		ofs << dId << "/" << pName.getfname() << "/" << pName.getlname() << "/" << DOB.getDate() << "/" << DOB.getMonth() << "/" << DOB.getYear() <<"/" <<Age<< "/" << Nid << "/" << no_of_Licences << "/";
		for (int i = 0; i < no_of_Licences; i++)
		{
			if(i==no_of_Licences-1)
				ofs << LicencesList[i] << "/";
			else
			ofs << LicencesList[i]<<",";
		}
		ofs << overallRanking << "/" << salary<<"/"<<experience << "/" << status << endl;
		ofs.close();


      
	}
	void Driver::setstat(int a)
	{
		status = a;
	}
	void Driver::print_for_services()
	{
		cout << "Overall Ranking:" << overallRanking;
		cout << "\nExperience:" << experience<<" Years\n";
		for (int i = 0; i < no_of_Licences; i++)
		{
			cout << "License " << i + 1 << ":" << LicencesList[i] << endl;
		}
	}
	int Driver::getstatus()
	{
		return status;
	}
	float Driver::getrank()
	{
		return overallRanking;
	}
	void Driver::print()
	{
		for (int i = 0; i < no_of_Licences; i++)
		{
			cout << "License "<<i+1<<":" << LicencesList[i] << endl;
		}
		cout << "Overall Ranking:" << overallRanking;
		cout << "\nSalary:" << salary;
		cout << "\nExperience:" << experience;
		cout << "\nStatus:";
		if (status == 1)
			cout << "free\n";
		else if (status == 2)
			cout << "booked\n";
		else if (status == 3)
			cout << "Canceled\n";
		
		
	}
	int Driver::getid()
	{
		return dId;
	}
	void Driver::plusdriver()
	{

		int r, s, t;
		int age = 0;
		int nic = 0;
		char* fn = new char[30];
		char* ln = new char[30];
		cout << "Enter First Name:";
		cin.ignore();
		cin.getline(fn, 30);
		cout << "Enter second Name:";
		cin.getline(ln, 30);
		cout << "Enter Age:";
		cin >> age;
		cout << "Enter NIC:";
		cin >> nic;
		cout << "Enter Date of Birth\nDate:";
		cin >> r;
		cout << "Month:";
		cin >> s;
		cout << "Year:";
		cin >> t;
		SetPerson(fn, ln, r, s, t, age, nic);

		cout << "Enter no of license:";
		cin >> no_of_Licences;
		LicencesList = new char* [no_of_Licences];
		for (int i = 0; i < no_of_Licences; i++)
		{
			LicencesList[i] = new char[10];
			cout << "Enter name for license " << i + 1 << endl;
			if (i == 0)
				cin.ignore();
			cin.getline(LicencesList[i], 20);
		}
		cout << "Enter overall Ranking:";
		cin >> overallRanking;
		cout << "Enter Salary:";
		cin >> salary;
		cout << "Enter Experience:";
		cin >> experience;
		cout << "Enter Status \n1 for free\n2 if booked\n3 if canceled\n";
		cin >> status;
		fstream my_fil;
		my_fil.open("driver.txt", ios::app);
		if (!my_fil) {
			cout << "File not created!";
		}
		else
		{
			cout << "Driver Added";
			my_fil << dId << "/" << fn << "/" << ln << "/" << r << "/" << s << "/" << t << "/" << age << "/" << nic << "/" << no_of_Licences << "/";
			for (int i = 0; i < no_of_Licences; i++)
			{
				if (i == no_of_Licences - 1)
					my_fil << LicencesList[i] << "/";
				else
					my_fil << LicencesList[i] << ",";

			}
			my_fil << overallRanking << "/" << salary << "/" << experience << "/" << status << endl;

		}
		my_fil.close();
	}
	void Driver::setdata2(int no_l, char**& license, float rank, float sal, int exp, int stat)
	{
		no_of_Licences = no_l;
		LicencesList = new char* [no_of_Licences];
		for (int i = 0; i < no_of_Licences; i++)
		{
			LicencesList[i] = new char[strlen(license[i]) + 1];
			strcpy(LicencesList[i], license[i]);
		}
		overallRanking = rank;
		salary = sal;
		experience = exp;
		status = stat;
	}
	void Driver::setdata(int dId, char* f, char* l, int d, int m, int y, int age1, int nic)
	{
		this->dId = dId;
		SetPerson(f, l, d, m, y, age1, nic);
	}



	class Feature
	{
	private:
		int fId;
		char* description;
		float cost;
	public:
		float getcost();
		Feature();
		Feature(int id, char* d, float c);
		friend istream& operator>>(istream& , Feature&);
		friend ostream& operator<<(ostream&, Feature&);
		char* getdescrip();
		int getfid()
		{
			return fId;
		}
		~Feature()
		{
			//delete[] description;
		}
	};
	char* Feature::getdescrip()
	{
		return description;
	}
	float Feature::getcost()
	{
		return cost;
	}
	ostream& operator<<(ostream& out, Feature& f)
	{
		out <<"FID:" << f.fId << "\nDescription:";
	    out<< f.description << "\nCost:" << f.cost;
		return out;
	}
	istream& operator>>(istream& inp,  Feature& f)
	{
		f.description = new char[40];
		cout << "Enter FID:";
		inp >> f.fId;
		cout << "Enter Description(less than 35 characters):";
		cin.ignore();
		cin.getline(f.description, 35);
		cout << "Enter cost of Vehicle:";
		cin >> f.cost;
	
		return inp;
	}
	Feature::Feature()
	{
		fId = 0; description = nullptr; cost = 0.0;
	}
	Feature::Feature(int id, char* d, float c)
	{
		fId = id;
		description = new char[(strlen(d)+1)];
		strcpy(description, d);
		cost = c;
	}

	class Vehicle
	{
	private:
		int vId;
		int registrationNo;
		float avgMileage;
		char* LicenceType;
		bool status;
		char* fuelType;
		float overallRanking;
		Date manufacturingDate;
		Feature* list;
		Service** serviceHistory;
	public:
		static int service_count;
		char* gettype();
		static int count;
		void setterVehicle1(int ,char*,float,int ,int,int);
		void setvid(int);
		void setterVehicle(int,float,char*,bool,char*,float);
		void adderVehicle();
		int getVID();
		Vehicle();
		void print();
		bool getstat();
		virtual void setstat(int stat);
		void setdatatofile(int);
		~Vehicle()
		{
			delete LicenceType;
			delete fuelType;
			delete[] list;
			/*for (int i = 0; i < 20; i++)
			{
				delete[] serviceHistory[i];
			}*/
			delete [] serviceHistory;
		}
		void setService(char* a, char* b, float c, int d, int e, int f, int g, int h, int i, bool s, float fuel, int cid, int did, int vid)
		{
			serviceHistory[service_count] = new Service( a,  b,  c,  d,  e,  f,  g, h, i, s,  fuel, cid, did, vid);
			service_count++;
		}

	}; 
	int Vehicle::service_count = 0;
	void Vehicle::setdatatofile(int count)
	{
		
		ofstream ofs_V;
		if (count == 0)
		{
			ofs_V.open("vehicle.txt", ofstream::out);
		}
		else
		ofs_V.open("vehicle.txt", ofstream::app);
	
		ofs_V << vId << "/" << registrationNo << "/" << avgMileage << "/" << LicenceType << "/";
		if (status)
			ofs_V << 1;
		else
			ofs_V << 0;
		ofs_V<< "/" << fuelType << "/" << overallRanking;
		ofs_V << "/" << list[0].getfid() << "/" << list[0].getdescrip() << "/" << list[0].getcost() <<"/" << manufacturingDate.getDate();
		ofs_V<< "/" << manufacturingDate.getMonth() << "/" << manufacturingDate.getYear() << endl;
		
		
		ofs_V.close();

	}
	void Vehicle::setstat(int stat)
	{
		status = stat;
	}
	bool Vehicle::getstat()
	{
		return status;
	}
	void Vehicle::print()
	{
		cout << "Vehicle ID:" << vId;
		cout << "\nRegistration No:" << registrationNo;
		cout << "\nAverage Mileage:" << avgMileage;
		if (status)
			cout << "\nStatus->booked";
		else if (!status)
			cout << "\nStatus->free";
		cout <<"\nFuel Type:" << fuelType;
		cout << "\nOverall Ranking:" << overallRanking;
		cout << "\nManufacturing Date:" << manufacturingDate;
		cout << list[0];
	}
	char* Vehicle::gettype()
	{
		return LicenceType;
	}
	int Vehicle::getVID()
	{
		return vId;
	}
	void Vehicle::setvid(int a)
	{
		vId = a;
	}
    int Vehicle::count = 55;
	void Vehicle::adderVehicle()
	{
		srand(time(NULL));
		vId = rand()%1000;
		count++;
		char* fuelType = new char[13];
		cout << "Enter Registration Number:";
		cin >> registrationNo;
		cout << "Enter Mileage:";
		cin >> avgMileage;
		LicenceType = new char[25];
		cout << "Enter License Type:";
		cin.ignore();
		cin.getline(LicenceType, 25);

		cout << "Enter Status (0 for free/1 for booked):";
		cin >> status;

		cout << "Enter Fuel Type:";
		cin.ignore();
		cin.getline(fuelType, 13);
		
		cout << "Enter overall ranking(float):";
		cin >> overallRanking;
        
		serviceHistory = nullptr;

		list = new Feature;
		cin >> list[0];
		cout << "Enter Manufacturing Date";
		cin >> manufacturingDate;

		/*fuelType = new char[strlen(fuel) + 1];
		strcpy(fuelType, fuel);
		overallRanking = overall;*/

		fstream my_file;
		my_file.open("vehicle.txt", ios::app);
		if (!my_file) {
			cout << "File not created!";
		}
		else
		{
			cout << "Vehicle Added";
			my_file << vId << "/" << registrationNo << "/" << avgMileage << "/" << LicenceType << "/" << status << "/" << fuelType << "/" << overallRanking << "/" << list[0] <<"/" << manufacturingDate;
			my_file.close();
		}
	}
	void Vehicle::setterVehicle(int reg,float mil,char* l_type,bool s,char* fuel,float overall)
	{
		registrationNo = reg;
		avgMileage = mil;
		LicenceType = new char[strlen(l_type) + 1];
		strcpy(LicenceType,l_type);
		status = s;
		fuelType = new char[strlen(fuel) + 1];
		strcpy(fuelType, fuel);
		overallRanking = overall;
	}
	void Vehicle::setterVehicle1(int fid, char* descrip, float c, int d, int m, int y)
	{
		serviceHistory = nullptr;
		list = new Feature(fid, descrip, c);
		manufacturingDate.setDate(d);
		manufacturingDate.setMonth(m);
		manufacturingDate.setYear(y);

	}
	Vehicle::Vehicle()
	{
		vId = 0;
		registrationNo = 0;
		avgMileage = 0;
		LicenceType = nullptr;
		status = 0;
		fuelType = nullptr;
		overallRanking = 0;
		list = nullptr;
		serviceHistory = new Service*[20];
	}



	class TMS
	{

		Customer* C;
		Driver* d;
		Vehicle* v;
		Service* S;
		Ride* r;
		Delivery* deliver;
	public:
		void servicecustomer(int);
		void upload_data_customer();
		void upload_vehicle();
		TMS();
		void add_a_new_customer();
		void addOrRemoveDriver();
		void addOrRemoveVehicle();
		void printCustomerDetials();
		void printDriverDetails();
		void printListOfTheVehicles();
		void printHistoryOfCustomer();
		void upload_driver();
		void print_no_of_license();
		void print_driver4_5();
		static int count_driver;
		static int count_vehicle;
		static int count_service;
		static int count_customer;
		static int a;
		void upload_data();
		void rideordelivery();
		static int count_ride;
		static int count_delivery;
		void cancelservice();
		void complete();
		~TMS();
		void function_7();
		void function_8();
		void function_9();
		void function_12();
		void function_16();
		void function_17();
		void function_18();
		void function_19();
	};

	void TMS::complete()
	{
		int option,v_r,d_r;
		cout << "Enter 1 for ride and 2 for service";
		cin >> option;
		int service_id;
		cout << "Enter Service ID";
		cin >> service_id;
		
		cout << "Enter Vehicle rating";
		cin >> v_r;
		cout << "Enter Driver rating";
		cin >> d_r;
		if (option == 1)
		{

			ifstream read("ride.txt");
			ofstream ofs;
			char* Fname = new char[15];
			char* Lname = new char[15];
			string aa;
			string bb;
			string cc;
			string trash;
			string ee;
			string ff;
			string gg;
			string dis; string Date;
			string month; string Year; string Serv; string Minu; string Hour_1;
			string c_id;
			string v_id;
			string d_id;
			int dat;
			int mont;
			int yea;
			int secon;
			int minut;
			int hou;
			int sid;
			int vid;
			int cid;
			int did;
			float Distance;
			//bool status;
			float fuel = 0;
			int line_no = 0;
			int index = 0;

			while (read.peek() != EOF)
			{
				if (read.eof())
					break;
				getline(read, aa, '/');//service id
				if (aa == "\n")
					return;
				getline(read, ee, '/');//fuel
				getline(read,  trash, ',');//trash
				getline(read, cc, '/');//f name
				getline(read,bb, '/');//s name
				getline(read, dis, '/');//distance
				getline(read, Date, '/');//day
				getline(read, month, '/');//month
				getline(read, Year, '/');//year
				getline(read, Serv, '/');//sec
				getline(read, Minu, '/');//min
				getline(read, Hour_1, '|');//hour
				getline(read, c_id, '/');//cid
				getline(read, d_id, '/');//did
				getline(read, v_id, '\n');//vid
			
				fuel = stof(ee);
				sid = stoi(aa);
				Distance = stof(dis);
				strcpy(Lname, bb.c_str());
				strcpy(Fname, cc.c_str());
				dat = stoi(Date);
				mont = stoi(month); 
				yea = stoi(Year);
				secon = stoi(Serv);
				minut = stoi(Minu);
				hou = stoi(Hour_1);
				did = stoi(d_id);
				cid = stoi(c_id);
				vid = stoi(v_id);
				line_no++;
				if (sid == service_id)
				{
					index = line_no;
					for (int i = 0; i < count_vehicle; i++)
					{
						if (vid == v[i].getVID())
						{
							v[i].setstat(0);

							v[i].setService(Fname, Lname, Distance, dat, mont, yea, secon, minut, hou, 0, fuel, cid, did, vid);
						}
					}

					for (int j = 0; j < count_driver; j++)
					{
						if(did==d[j].getid())
						d[j].setstat(3);
						d[j].addservice(Fname, Lname, Distance, dat, mont, yea, secon, minut, hou, 0, fuel, cid, did, vid);
					}
					break;
				}

			}

			read.close();

			ifstream is("ride.txt");
			ofs.open("temp_ride.txt", ofstream::out);
			char charac;
			line_no = 1;

			bool con = true;
			while (is.get(charac))
			{

				if (charac == '\n')
					line_no++;
				if (line_no == index)
				{
					if (con)
					{
						getline(read, aa, '/');//service id
						if (aa == "\n")
							return;
						
						ofs << endl << aa << "/";
						ofs << ee << '/';
						ofs << '0' << "/" << trash << ","<<"/" << cc << "/" << bb << "/" << dis << "/" << Date << "/" << month << "/" << Year << "/" << Serv << "/" << Minu << "/" << Hour_1 << "|" << c_id << "/" << d_id << "/" << v_id;
						
						con = false;
					}

				}
				else
					ofs << charac;

			}

			ofs.close();
			is.close();
			remove("ride.txt");
			rename("temp_ride.txt", "ride.txt");
			if (!con)
				cout << "Service Completed\n";
			else
				cout << "Invalid Input\n";
		}
		else if (option == 2)
		{
		ifstream read("delivery.txt");
		ofstream ofs;
		char* Fname = new char[15];
		char* Lname = new char[15];
		string aa;
		string bb;
		string cc;
		string trash;
		string ee;
		string ff;
		string gg;
		string dis; string Date;
		string month; string Year; string Serv; string Minu; string Hour_1;
		string c_id;
		string v_id;
		string d_id;
		int dat;
		int mont;
		int yea;
		int secon;
		int minut;
		int hou;
		int sid;
		int vid;
		int cid;
		int did;
		float Distance;
		//bool status;
		float fuel = 0;
		int line_no = 0;
		int index = 0;

		while (read.peek() != EOF)
		{
			if (read.eof())
				break;
			getline(read, aa, '/');//service id
			if (aa == "\n")
				return;
			getline(read, ee, '/');//fuel
			getline(read, trash, ',');//trash
			getline(read, cc, '/');//f name
			getline(read, bb, '/');//s name
			getline(read, dis, '/');//distance
			getline(read, Date, '/');//day
			getline(read, month, '/');//month
			getline(read, Year, '/');//year
			getline(read, Serv, '/');//sec
			getline(read, Minu, '/');//min
			getline(read, Hour_1, '|');//hour
			getline(read, c_id, '/');//cid
			getline(read, d_id, '/');//did
			getline(read, v_id, '\n');//vid
		
			fuel = stof(ee);
			sid = stoi(aa);
			Distance = stof(dis);
			strcpy(Lname, bb.c_str());
			strcpy(Fname, cc.c_str());
			dat = stoi(Date);
			mont = stoi(month);
			yea = stoi(Year);
			secon = stoi(Serv);
			minut = stoi(Minu);
			hou = stoi(Hour_1);
			did = stoi(d_id);
			cid = stoi(c_id);
			vid = stoi(v_id);

			line_no++;
			if (sid == service_id)
			{
				index = line_no;
				for (int i = 0; i < count_vehicle; i++)
				{
					if (vid == v[i].getVID())
					{
						v[i].setstat(0);
						v[i].setService(Fname, Lname, Distance, dat, mont, yea, secon, minut, hou, 0, fuel, cid, did, vid);
					}
				}

				for (int j = 0; j < count_driver; j++)
				{
					if (did == d[j].getid())
						d[j].setstat(3);
					d[j].addservice(Fname, Lname, Distance, dat, mont, yea, secon, minut, hou, 0, fuel, cid, did, vid);
				}
				break;
			}

		}

		read.close();

		ifstream is("delivery.txt");
		ofs.open("temp_delivery.txt", ofstream::out);
		char charac;
		line_no = 1;

		bool con = true;
		while (is.get(charac))
		{

			if (charac == '\n')
				line_no++;
			if (line_no == index)
			{
				if (con)
				{
					getline(read, aa, '/');//service id
					if (aa == "\n")
						return;

					ofs << endl << aa << "/";
					ofs << ee << '/';
					ofs << '0' << "/" << trash << "," << "/" << cc << "/" << bb << "/" << dis << "/" << Date << "/" << month << "/" << Year << "/" << Serv << "/" << Minu << "/" << Hour_1 << "|" << c_id << "/" << d_id << "/" << v_id;

					con = false;
				}

			}
			else
				ofs << charac;

		}

		ofs.close();
		is.close();
		remove("vehicle.txt");
		rename("temp_vehicle.txt", "vehicle.txt");
		if (!con)
			cout << "Service Completed\n";
		else
			cout << "Invalid Input\n";
		}
		else
			cout << "Invalid Input";

	}
	TMS::TMS()
	{
		
		srand(time(NULL));
		a = rand() % 1000 + 1;
		C = new Customer[15];
		d = new Driver[10];
		v = new Vehicle[15];
		r = new Ride[50];
		deliver = new Delivery[50];
		S = new Service; 
		upload_data();
	}
	TMS::~TMS()
	{
		for (int i = 0; i < count_vehicle; i++)
		{
			v[i].setdatatofile(i);
		}
		for (int i = 0; i < count_driver; i++)
		{
			d[i].update_To_file(i);
		}
		remove("driver.txt");
		rename("temp.txt", "driver.txt");

		delete[]S;
		delete[]C;
		delete[]d;
		delete[]v;
		delete[]deliver;
		delete[]r;
	}
	void TMS::servicecustomer(int a)
	{	
		
		ifstream read("ride.txt");
		
		string f;
		string l; string trash; string cost;
		string status;  string dis; string nid; string d; string m; string y;
		float distance; string second; string min; string Hour; string ci, vi, di;
		char* source = new char[20]; 
		char* destination = new char[20]; 
		int day, month = 0, year = 0, sec, minute, hour, cid, vid, did, stat;
		float fuel;
		while (read.peek() != EOF)
		{
			if (read.eof())
				break;
				
			getline(read, status, '/');
			if(status == "\n")           
				return;
			getline(read, cost, '/');
			getline(read, trash, ',');
			getline(read, f, '/');
			getline(read, l, '/');
			getline(read, dis, '/');
			getline(read, d, '/');
			getline(read, m, '/');
			getline(read, y, '/');
			getline(read, second, '/');
			getline(read, min, '/');
			getline(read, Hour, '/');
			getline(read, ci, '/');
			getline(read, di, '/');
			getline(read, vi, '\n');
			
			strcpy(source, f.c_str());
			strcpy(destination, l.c_str());
			distance = stof(dis);
			day = stoi(d);
			month = stoi(m);
			year = stoi(y);
		    sec = stoi(second);
			minute = stoi(min);
			hour = stoi(Hour);
			cid = stoi(ci);
			vid = stoi(vi);
			did = stoi(di);
		    fuel = stof(cost);
			stat = stoi(status);
			

			if (cid==a)
		     C[count_customer].setbookinghistory(source,destination,distance,day,month,year,sec,minute,hour,stat,fuel,cid,did,vid);
		

		}
		read.close();
		ifstream read1("delivery.txt");
		
		while (read1.peek() != EOF)
		{
			if (read1.eof())
				break;

			getline(read1, status, '/');
			if (status == "\n")
				return;
			getline(read1, cost, '/');
			getline(read1, trash, ',');

			getline(read1, f, '/');
			getline(read1, l, '/');
			getline(read1, dis, '/');
			getline(read1, d, '/');
			getline(read1, m, '/');
			getline(read1, y, '/');
			getline(read1, second, '/');
			getline(read1, min, '/');
			getline(read1, Hour, '/');
			getline(read1, ci, '/');
			getline(read1, di, '/');
			getline(read1, vi, '\n');

			strcpy(source, f.c_str());
			strcpy(destination, l.c_str());
			distance = stof(dis);
			day = stoi(d);
			month = stoi(m);
			year = stoi(y);
			sec = stoi(second);
			minute = stoi(min);
			hour = stoi(Hour);
			cid = stoi(ci);
			vid = stoi(vi);
			did = stoi(di);
			fuel = stof(cost);
			stat = stoi(status);

			
			if (cid == a)		
			C[count_customer].setbookinghistory(source, destination, distance, day, month, year, sec, minute, hour, stat, fuel, cid, did, vid);
			

		}
		read1.close();
	}
	void TMS::print_no_of_license()
	{

		for (int i = 0; i < count_driver; i++)
		{
			if (d[i].getlicense()>1)
			{
				cout << d[i]<<"No of licenses:"<<d[i].getlicense()<<endl;
				d[i].print();
			}
			cout << endl<<endl;
		}
	}
	int TMS::count_driver = 0;
	int TMS::count_vehicle = 0;
	int TMS::count_service = 0;
	int TMS::count_customer = 0;
	int TMS::a = 0;
	int TMS::count_ride = 0;
	int TMS::count_delivery = 0;
	
	void TMS::print_driver4_5()
	{
		int j = 1;
		for (int i = 0; i < count_driver; i++)
		{
			if (d[i].getrank() > 4.5)
			{
				red();
				cout << "\nDRIVER NO->" << j;
				reset();
				cout << "\nDriver ID : " << d[i].getid() << endl;
				cout << d[i] ;
				cout << "No of License:" << d[i].getlicense() << endl;
				d[i].print();
				j++;		
			}

		}
	}
	void TMS::cancelservice()
	{
		int option;
		int service_id;
		int customer_id;
		cout << "Enter 1 to cancel ride and 2 to cancel delivery:";
		cin >> option;
		cout << "Enter Service ID:";
		cin >> service_id;
		cout << "Enter Customer ID:";
		cin >> customer_id;
		if (option == 1)
		{
			ifstream read("ride.txt");
			ofstream ofs;
			
			string a;
			string b;
			string c;
			string trash;
			string e;
			string f;
			string g;
			int sid;
			int vid;
			int cid;
			int did;	
			bool status;
			float fuel = 0;
			int line_no = 0;
			int index = 0;
			
			while (read.peek() != EOF)
			{
				if (read.eof())
					break;
				getline(read, a, '/');//service id
				if (a == "\n")
					return;
				getline(read, b, '/');//fuel rate
				getline(read, c, '/');//status

				getline(read, trash, '|');//trash
				getline(read, e, '/');//cid
				getline(read, f, '/');//did
				getline(read, g, '\n');//vid
                status = stoi(c);
				fuel = stof(b);
				sid = stoi(a);

				cid = stoi(e);
				vid = stoi(g);
				did = stoi(f);
				
				//cout<<endl << status << endl << sid << endl << cid << endl << did << endl << vid;
				line_no++;
				if (sid == service_id && cid == customer_id&&status==0 )
				{
					index = line_no;
					for (int i = 0; i < count_vehicle; i++)
					{
						if (vid == v[i].getVID())
						{
							cout << "Cancelation Fees:" << ((fuel / 100) * 50) << endl;
							
							v[i].setstat(0);
						}
					}
					
					for (int j = 0; j < count_driver; j++)
					{
						if(did==d[j].getid())
						d[j].setstat(3);
					}
					break;
				}

			}

			read.close();

			ifstream is("ride.txt");
			ofs.open("temp_ride.txt", ofstream::out);
			char charac;
			line_no = 1;
		
			bool con = true;
			    while (is.get(charac))
			    {
			         
			        if (charac == '\n')
			            line_no++;
					if (line_no == index)
					{
						if (con)
						{
							ofs<<endl << a << "/";
							ofs << b;
							ofs << '/';
							ofs << '1' << "/" << trash << "|";
							ofs << e << "/" << f << "/" << g ;
							con = false;
						}
							
					}
					else
						ofs << charac;
					
			    }
				
				ofs.close();
				is.close();
				remove("ride.txt");
				rename("temp_ride.txt", "ride.txt");
				if (!con)
					cout << "Service Canceled\n";
				else
					cout << "Invalid Input\n";
		}
		else if (option == 2)
		{
		ifstream read("delivery.txt");
		ofstream ofs;

		string a;
		string b;
		string c;
		string trash;
		string e;
		string f;
		string g;
		int sid;
		int vid;
		int cid;
		int did;
		bool status;
		float fuel = 0;
		int line_no = 0;
		int index = 0;

		while (read.peek() != EOF)
		{
			if (read.eof())
				break;
			getline(read, a, '/');//service id
			if (a == "\n")
				return;
			getline(read, b, '/');//fuel rate
			getline(read, c, '/');//status

			getline(read, trash, '|');//trash
			getline(read, e, '/');//cid
			getline(read, f, '/');//did
			getline(read, g, '\n');//vid
			status = stoi(c);
			fuel = stof(b);
			sid = stoi(a);

			cid = stoi(e);
			vid = stoi(g);
			did = stoi(f);

			//cout<<endl << status << endl << sid << endl << cid << endl << did << endl << vid;//for testing
			
			line_no++;
			if (sid == service_id && cid == customer_id && status == 0)
			{
				index = line_no;
				for (int i = 0; i < count_vehicle; i++)
				{
					if (vid == v[i].getVID())
					{
						v[i].setstat(0);
					}
				}
				for (int j = 0; j < count_driver; j++)
				{
					d[j].setstat(3);
				}
				break;
			}

		}

		read.close();

		ifstream is("delivery.txt");
		ofs.open("temp_delivery.txt", ofstream::out);
		char charac;
		line_no = 1;

		bool con = true;
		while (is.get(charac))
		{

			if (charac == '\n')
				line_no++;
			if (line_no == index)
			{
				if (con)
				{
					ofs << endl << a << "/";
					ofs << b;
					ofs << '/';
					ofs << '1' << "/" << trash << "|";
					ofs << e << "/" << f << "/" << g;
					con = false;
				}

			}
			else
				ofs << charac;

		}

		ofs.close();
		is.close();
		remove("delivery.txt");
		rename("temp_delivery.txt", "delivery.txt");
		if (!con)
			cout << "Service Canceled\n";
		else
			cout << "Invalid Input\n";
		}
		else
			cout << "Invalid Input";
	}
	void TMS::rideordelivery()
	{
		//counting free drivers
		flagg("->Free Drivers\n");
		int count = 0;
		for (int i = 0; i < count_driver; i++)
		{
			if (d[i].getstatus() == 1)
				count++;
		}


		int* index = new int[count];
		float* arr = new float[count];
		//storing values in arrays
		for (int i = 0, j = 0; i < count_driver; i++)
		{
			if (d[i].getstatus() == 1)
			{
				index[j] = i;
				arr[j] = d[i].getrank();
				j++;
			}

		}
		//sorting
		float key = 0;
		int key1;
		int n = 0, m = 0;
		for (n = 1; n < count; n++)
		{
			key = arr[n];
			key1 = index[n];
			m = n - 1;
			while (m >= 0 && arr[m] < key)
			{
				index[m + 1] = index[m];
				arr[m + 1] = arr[m];
				m = m - 1;
			}
			index[m + 1] = key1;
			arr[m + 1] = key;
		}
		//printing
		for (int i = 0; i < count; i++)
		{
			cyan();
			cout << "Driver NO:" << i + 1 << endl;
			reset();
			cout << d[index[i]];
			d[index[i]].print_for_services();
			cout << endl << endl;
		}
		int index_vehicle[15]={};
		for (int i = 0,j=0; i < count_vehicle; i++)
		{
			if (v[i].getstat()==0)
			{
				cyan();
				cout << "Vehicle no:" << j + 1<<endl;
				reset();
				index_vehicle[j] = i;
				v[i].print();
				j++;
				cout << endl << endl;
			}
		}

            int did=0,cid=0,vid=0, option=0, c_index=0;
			cout << "Enter customer ID:";
			cin >> cid;
			int i;
			//searching for the customer
			for ( i = 0; i < count_customer; i++)
			{
				if (cid == C[i].getcid())
				{
					c_index = i;
					break;
				}
				
			}

			if (i == count_customer)
			{
				cout << "Customer not found\nFirst add a customer\n";
				return;
			}

			int option_v;
			cout << "Enter Driver No from the list:";
			cin >> option;
            did = d[index[option - 1]].getid();
			r[count_ride].setDriverR(did);
			d[index[option - 1]].setstat(2);
			cout << "Enter Vehicle No from the list:";
			cin >> option_v;
			vid = v[index_vehicle[option_v - 1]].getVID();
			v[index_vehicle[option_v - 1]].setstat(1);
			char* source = new char[40];
			char* destination = new char[40];
			float dis = 0, fuel = 0;
			bool check = true;
			int b_day = 0, b_month = 0, b_year = 0,b_sec,b_min,b_hour;

		int opt;
		cout << "\nEnter 1 for Ride and 2 for Delivery:";
		cin >> opt;
		if (opt == 1)
		{
			int inter;
    		int nop;
			cout << "Enter No of Passengers:";
			cin >> nop;
			r[count_ride].setNOP(nop);
			cout << "Enter 1 for intercity or 2 for intracity:";
			cin >> inter;
			if (inter == 1)
				r[count_ride].setridetype("intercity");
			else if (inter == 2)
				r[count_ride].setridetype("intracity");
			else
				cout << "Invalid Input";
			cin.ignore();
			cout << "Enter Source:";
			cin.getline(source, 40);
			r[count_ride].setSource(source);
			cout << "Enter Destination:";
			cin.getline(destination, 40);
			r[count_ride].SetDestination(destination);
			cout << "Enter distance:";
			cin >> dis;
			r[count_ride].setDistance(dis);
			cout << "Enter Fuel rate:";
			cin >> fuel;
			r[count_ride].setFuelrate(fuel);
			cout << "Enter Booking date\nDay:";
			cin >> b_day;
			cout << "Month:";
			cin >> b_month;
			cout << "Year:";
			cin >> b_year;
			r[count_ride].setbookingdate(b_day, b_month, b_year);
			cout << "Enter booking time\nSecond:";
			cin >> b_sec;
			cout << "Minutes:";
			cin >> b_min;
			cout << "Hour:";
			cin >> b_hour;
			r[count_ride].setbookingtime(b_sec, b_min, b_hour);
			r[count_ride].setCID(a);
			C[c_index].setbookinghistory(source,destination,dis,b_day,b_month,b_year,b_sec,b_min,b_hour,0,fuel,cid,did,vid);
			srand(time(NULL));
			int serviceid = rand() % 100 + rand() % 100;
			cout<<"Service ID :" << serviceid<<endl;
			fstream my_file;
			my_file.open("ride.txt", ios::app);
			if (!my_file) {
				cout << "File not created!";
			}
			else
			{
				int costt;
				cout << "\nCost:";
				costt= d[index[option - 1]].getrank() * (fuel / 100) * (dis / 100);
				r[count_ride].setcost(costt);
				cout << costt;
				cout << "\nService Added";
				my_file<< serviceid <<"/" << fuel << "/" <<0<< "/" << nop << "/";
				if (inter == 1)
					my_file << "intercity";
				else if (inter == 2)
					my_file <<"intracity";
					
				my_file<< "," << source << "/" << destination << "/" << dis << "/" << b_day << "/" << b_month<<"/"<<b_year<< "/" <<b_sec<< "/" <<b_min<< "/"<<b_hour<<"|"<<cid<<"/"<< did<<"/"<<vid << endl;
				my_file.close();
			}
			count_ride++;
		}
		else if (opt == 2)
		{
			
			float weight;
			char* good = new char[20];
			cout << "Enter Good's Weigth:";
			cin >> weight;
			deliver[count_vehicle].setweight(weight);
			cout << "Enter Good's Type:";
			cin.ignore();
			cin.getline(good,20);
	
			cout << "Enter Source:";
			
			cin.getline(source, 40);
			deliver[count_vehicle].setSource(source);
			cout << "Enter Destination:";
			cin.getline(destination, 40);
			deliver[count_vehicle].SetDestination(destination);
			cout << "Enter distance:";
			cin >> dis;
			deliver[count_vehicle].setDistance(dis);
			cout << "Enter Fuel rate:";
			cin >> fuel;
			deliver[count_vehicle].setFuelrate(fuel);
			cout << "Enter Booking date\nDay:";
			cin >> b_day;
			cout << "Month:";
			cin >> b_month;
			cout << "Year:";
			cin >> b_year;
			deliver[count_vehicle].setbookingdate(b_day, b_month, b_year);
			cout << "Enter booking time\nSecond:";
			cin >> b_sec;
			cout << "Minutes:";
			cin >> b_min;
			cout << "Hour:";
			cin >> b_hour;
			deliver[count_vehicle].setbookingtime(b_sec, b_min, b_hour);
			deliver[count_vehicle].setCID(a);
			C[c_index].setbookinghistory(source, destination, dis, b_day, b_month, b_year, b_sec, b_min, b_hour, 0, fuel, cid, did, vid);
			count_vehicle++;

			srand(time(NULL));
			int serviceid = rand() % 100 + rand() % 100;
			cout <<"Service ID:" << serviceid << endl;

			fstream my_file;
			my_file.open("delivery.txt", ios::app);
			if (!my_file)
					cout << "File not created!";
			else
			{
				int costt;
				cout << "\nCost:";
				costt = d[index[option - 1]].getrank() * (fuel / 10) * (did / 10.0);
				r[count_ride].setcost(costt);
				cout << costt;
				cout << "\nService Added";
				my_file << serviceid<<"/" << fuel << "/" <<  0<< "/" << weight << "/" << good << "," << source << "/" << destination << "/" << dis << "/" << b_day << "/" << b_month << "/" << b_year << "/" << b_sec << "/" << b_min << "/" << b_hour << "|" << cid << "/" << did << "/" << vid << endl;
				my_file.close();
			}

		}
		else
			cout << "Invalid Input\n";
    }
	void TMS::printDriverDetails()
	{

		for (int i = 0; i < count_driver; i++)
		{
			boldCyan();
			cout << "->" << "Driver No:"<< i + 1;
			reset();
			cout << "\nDriver ID : " << d[i].getid() << endl;
			cout << "No of License:" << d[i].getlicense() << endl;
			d[i].print();
			cout << d[i]<<endl;
		}
	}
	void TMS::upload_driver()//uploading from file
	{
		ifstream read("driver.txt");
		string f;
		string l;
		string id;
		string age;
		string nid;
		string da;
		string m;
		string y;
		float rank;
		float salary;
		int did;
		char** licenses;
		char* temp;
		char* first = new char[20];
		char* last = new char[20];
		int day; int month;
		int year;
		int age1;
		int nic;
		while (read.peek() != EOF)
		{

			if (read.eof())
				break;
			getline(read, id, '/');
			if (id == "\n")
				return;
			getline(read, f, '/');
			getline(read, l, '/');
			getline(read, da, '/');
			getline(read, m, '/');
			getline(read, y, '/');
			getline(read, age, '/');
			getline(read, nid, '/');
			strcpy(first, f.c_str());
			strcpy(last, l.c_str());
			did = stoi(id);
			day = stoi(da);
			month = stoi(m);
			year = stoi(y);
			age1 = stoi(age);
			nic = stoi(nid);
			if (count_driver > 9)
			{
				cout << "Customer limit reached\n";
				return;
			}
			d[count_driver].setdata(did, first, last, day, month, year, age1, nic);
			//cout<<"Count:"<<count_driver << endl << endl << did << endl << first << endl << last << endl << day << endl << month << endl << year << endl << age1 << endl << nic << endl;

			getline(read, f, '/');
			nic = stoi(f);                     //reusing variables
			licenses = new char* [nic];
			for (int i = 0; i < nic; i++)
			{
				temp = new char[15];
				licenses[i] = new char[15];
				if (i == nic - 1)
					read.getline(temp, 15, '/');
				else
					read.getline(temp, 15, ',');
				licenses[i] = new char[strlen(temp) + 1];
				strcpy(licenses[i], temp);
				temp = nullptr;
			}
			getline(read, da, '/');
			getline(read, m, '/');
			getline(read, y, '/');
			getline(read, age, '\n');
			day = 0;
			month = 0;
			rank = 0;
			salary = 0;

			rank = stof(da);
			salary = stof(m);
			day = stoi(y);
			month = stoi(age);
			d[count_driver].setdata2(nic, licenses, rank, salary, day, month);
			/*cout << nic << endl << rank << endl << salary << endl << day << endl << month << endl ;
			for (int i = 0; i < nic; i++)
			{
				cout << licenses[i]<<endl;
			}
			cout<< endl;*/
			count_driver++;
			licenses = nullptr;
		}
		read.close();

	}
	void TMS::upload_vehicle()
	{


		ifstream read("vehicle.txt");
		string a;
		string b;
		string c;
		string d;
		string e;
		string f;

		int vid;
		int reg_no;
		float avg;
		char* license_type=new char[14];
		bool status;
		char* f_type=new char[14];
		float o_rank;
		char* descrip = new char[50];
		int day;
		int month;
		int year;
		
		
		while (read.peek() != EOF)
		{
            if (count_vehicle > 19)
			{
				cout << "Vehicle limit reached\n";
				return;
			}
			if (read.eof())
				break;
			getline(read, a, '/');
			if (a == "\n")
				return;
			vid = stoi(a);
			v[count_vehicle].setvid(vid);
			getline(read,a, '/');
			getline(read, b, '/');
			getline(read, c, '/');
			getline(read, d, '/');
			getline(read, e, '/');
			getline(read, f, '/');
           
			reg_no= stoi(a);
			avg = stof(b);
			strcpy(license_type, c.c_str());
		    status = stoi(d);
			strcpy(f_type, e.c_str());
			o_rank = stof(f);
			v[count_vehicle].setterVehicle(reg_no, avg, license_type, status, f_type, o_rank);

			//cout<<vid<<endl << reg_no << endl << avg << endl << license_type << endl << status << endl << f_type << endl << o_rank << endl;//testing

			getline(read, a, '/');
			getline(read, b, '/');
			getline(read, c, '/');
			getline(read, d, '/');
			getline(read, e, '/');
			getline(read, f, '\n');
			
			reg_no = stoi(a);//fid
			strcpy(descrip, b.c_str());
			o_rank = stof(c);//cost
			day = stoi(d);
			month = stoi(e);
			year = stoi(f);
			//cout << reg_no << endl << descrip << endl << o_rank << endl << day << endl << month << endl << year << endl << endl;//testing
			v[count_vehicle].setterVehicle1(reg_no, descrip, o_rank, day, month, year);
			count_vehicle++;

		}
		read.close();

   }
	void TMS::upload_data_customer()
	{
		ifstream read("project.txt");
		string f ;
		string l ;
		string id ;  string age; string nid ; string d ; string m ; string y ;
		int cid;
		char* first=new char[20]; char* last=new char[20]; int day; int month; int year; int age1; int nic;
		while (read.peek() != EOF)
		{
			if (read.eof())
				break;
			getline(read,id,'/');
			if (id == "\n")
				return;
			getline(read, f, '/');
			getline(read, l, '/');
			getline(read, d, '/');
			getline(read, m, '/');
			getline(read, y, '/');
			getline(read, age, '/');
			getline(read, nid, '\n');
	 		strcpy(first,f.c_str());
			strcpy(last, l.c_str());
			cid = stoi(id);
			day = stoi(d);
			month = stoi(m);
			year = stoi(y);
			age1 = stoi(age);
			nic = stoi(nid);
			servicecustomer(cid);
			//cout << cid << endl << first << endl << last<<endl << day << endl << month << endl << year << endl << age1 << endl << nic << endl<<endl;//testing purpose
			if (count_customer > 14)
			{
				cout << "Customer limit reached\n";
				return;
			}

		
			C[count_customer].setcustomer(cid,first,last,day,month,year,age1,nic);
			count_customer++;

		}
		read.close();
	}
	void TMS::add_a_new_customer()
	{
		
		if (count_customer > 14)
		{
			cout << "Customer limit reached\n";
			return;
		}
		
		char* b;
		char* c;
		char* source;
		char* destination;
		int r=0, s=0, t=0, u=0, v=0;
		int option = 0;
		float dis = 0;
		b = new char[30];
		c = new char[30];
		source = new char[40];
		int fuel = 0;
		int b_day = 0;
		a+=4;
		bool check = true;
		int b_month=0;
		int b_year = 0;
		int b_sec = 0;
		int b_min = 0;
		destination = new char[40];
		
		cin.ignore();
			cout << "Enter first name:";	
            cin.getline(b, 30);
			
		
			cout << "Enter last name:";
			cin.getline(c, 30);
			while (check)
			{
				cout << "Enter Date of Birth\nDate:";
				cin >> r;
				cout << "Month:";
				cin >> s;
				cout << "Year:";
				cin >> t;
				if (r >= 1 && r <= 31 && s >= 1 && s <= 12 && t > 1900 && t < 2022)
					check = false;
				if (check)
				{
					cout << "Invalid date\n";
				}
			}
			cout << "Enter Age:";
			cin >> u;
			cout << "National ID:";
			cin >> v;
			
			C[count_customer].setcustomer(a,b, c, r,s,t,u,v);
			fstream my_file;
			my_file.open("project.txt", ios::app);
			if (!my_file) {
				cout << "File not created!";
			}
			else
			{
				cout << "Customer Added";
                my_file << a << "/" << b << "/" << c << "/" << r << "/" << s << "/" << t << "/" << u << "/"<<v << endl;
				my_file.close();
			}
			
	}
	void TMS::addOrRemoveDriver()
	{
		int opt = 0;
		cout << "Enter 1 for addition of driver\nEnter 2 for Removal of driver ";
		cin >> opt;
		if (opt == 1)
		{
			srand(time(NULL));
			d[count_driver].setdid(a + rand()%1000);
			d[count_driver].plusdriver();
			count_driver++;
		}
		else if (opt == 2)
		{
			int driver_id;
			opt = -1;//using opt 1 more time
			cout << "Enter Driver's Id:";
			cin >> driver_id;
			for (int j = 0; j < count_driver; j++)
			{
				if (driver_id == d[j].getid())
				opt = j + 1;
			}
			if (opt != -1)
			{
				ifstream inp("driver.txt");
				ofstream ofs;
				ofs.open("temp.txt", ofstream::out);
				char c;
				int line_no = 1;
				if (opt == 1)
				{
					while (inp.get(c))         //loop for getting single char
					{
						if (c == '\n')
							line_no++;
						if (line_no != 1 )
						{
							if (c == '\n'&&line_no==2) //so that space does not appear when deleting first line
								continue;
							ofs << c;
						}
					}
					ofs.close();
					inp.close();
					remove("driver.txt");
					rename("temp.txt", "driver.txt");
					upload_driver();
					cout << "\nDriver removed\n";
				}
				else 
				{
					while (inp.get(c))         //loop for getting single char
					{
						if (c == '\n')
							line_no++;
						if (line_no != opt)
							ofs << c;
					}
					ofs.close();
					inp.close();
					remove("driver.txt");
					rename("temp.txt", "driver.txt");
					upload_driver();
					cout << "\nDriver removed\n";
				}
			}
			else if (opt == -1)
			{
				cout << "\nDriver Not Found\n";
			}
		}
		else
			cout << "Invalid Input";
	}
	void TMS::addOrRemoveVehicle()
	{
		int opt = 0;
		cout << "Enter 1 for addition of vehicle\nEnter 2 for Removal of vehicle :";
		cin >> opt;
		 if (opt == 1)
		 {
			
			v[count_vehicle].adderVehicle();
			count_vehicle++;
		 }
		else if (opt == 2)
		{
			opt = -1;
			int id = 0;
			cout << "Enter Vehicle Id:";
			cin >> id;
			 for (int i = 0; i < count_vehicle; i++)
			 {
				if (id == v[i].getVID())	
				opt = i+1;
				
			 }


			 if (id == -1)
			 {
				cout << "Vehicle Not Found";
			 }
			 else
			 {
				if (opt != -1)
				{
					ifstream inp("vehicle.txt");
					ofstream ofs;
					ofs.open("temp.txt", ofstream::out);
					char c;
					int line_no = 1;
					if (opt == 1)
					{
						while (inp.get(c))         //loop for getting single char
						{
							if (c == '\n')
								line_no++;
							if (line_no != 1)
							{
								if (c == '\n' && line_no == 2) //so that space does not appear when deleting first line
									continue;

								ofs << c;
							}
						}
						ofs.close();
						inp.close();
						remove("vehicle.txt");
						rename("temp.txt", "vehicle.txt");
						upload_driver();
						cout << "\nVehicle removed\n";
					}

					else
					{
						while (inp.get(c))         //loop for getting single char
						{
							if (c == '\n')
								line_no++;
							if (line_no != opt)
								ofs << c;
						}
						ofs.close();
						inp.close();
						remove("vehicle.txt");
						rename("temp.txt", "vehicle.txt");
						upload_driver();
						cout << "\nVehicle removed\n";
					}
			    }
			 }
		}
		
	}
	void TMS::printCustomerDetials()
	{
		for (int i = 0; i < count_customer; i++)
		{
		 boldCyan();
			cout << "->";
           
			cout << "Customer NO:";
			
			cout<< i + 1;
			reset();
			cout<< "\nCustomer ID : " << C[i].getcid() << endl;
			cout << C[i];

		}
		
	}
	void TMS::upload_data()
	{
		upload_data_customer();
        upload_driver();
		upload_vehicle();
	}
	void TMS::printListOfTheVehicles()
	{
		once_flag onceFlag;
		once_flag onceFlag1;
			once_flag onceFlag2;
			once_flag onceFlag3;
			once_flag onceFlag4;
			once_flag onceFlag5;
			once_flag onceFlag6;
		for (int i = 0; i < count_vehicle; i++)
		{
			
			char* type = new char[(strlen(v[i].gettype()) + 1)];
			strcpy(type, v[i].gettype());

			if (!strncmp(type,"LTV", sizeof(type)) || !strncmp(type, "ltv", sizeof(type)))
			{
				call_once(onceFlag, [] {flagg("->LTV"); });//so LTV prints once
				v[i].print();
			}
			else if (!strncmp(type, "rickshaw", sizeof(type)) || !strncmp(type, "motorbike", sizeof(type)))
			{
            	call_once(onceFlag1, [] {flagg("->Motorbike/rickshaw"); });
				v[i].print();
			}
			else if (!strncmp(type, "HTV", sizeof(type)) || !strncmp(type, "htv", sizeof(type)))
			{
				call_once(onceFlag2, [] {flagg("->HTV"); });
				v[i].print();
			}
			else if (!strncmp(type, "jeep", sizeof(type)) || !strncmp(type, "motorcar", sizeof(type)))
			{	
				call_once(onceFlag3, [] {flagg("->Jeep/Motorcar"); });
				v[i].print();
			}
			else if (!strncmp(type, "TRACTOR", sizeof(type)) || !strncmp(type, "tractor", sizeof(type)))
			{
				call_once(onceFlag4, [] {flagg("->Tractor"); });
				v[i].print();
			}
			else if (!strncmp(type, "psv", sizeof(type)) || !strncmp(type, "PSV", sizeof(type)))
			{
				
				call_once(onceFlag5, [] {flagg("->PSV"); });
				v[i].print();
			}
			else if (!strncmp(type, "International driver's permit", sizeof(type)) || !strncmp(type, "TDP", sizeof(type)))
			{
				
				call_once(onceFlag6, [] {flagg("->International driver's permit(IDP)"); });
				v[i].print();
			}
			cout << endl << endl;
		}
		
	}
	void TMS::function_7()
	{
		int vehicle_id = 0;
		cout << "Enter Vehicle ID:";
		cin >> vehicle_id;
		for (int i = 0; i < count_vehicle; i++)
		{
			if (vehicle_id == v[i].getVID())
			{
				v[i].print();
			}
			
		}
		cout << endl<<endl;
		ifstream read("ride.txt");
		ifstream read1("delivery.txt");
		char* Fname = new char[15];
		char* Lname = new char[15];
		string aa;
		string bb;
		string cc;
		string trash;
		string ee;
		string ff;
		string gg;
		string dis; string Date;
		string month; string Year; string Serv; string Minu; string Hour_1;
		string c_id;
		string v_id;
		string d_id;
		int dat;
		int mont;
		int yea;
		int secon;
		int minut;
		int hou;
		int sid;
		int vid;
		int cid;
		int did;
		float Distance;
		//bool status;
		float fuel = 0;
		int line_no = 0;
		int index = 0;

		while (read.peek() != EOF)
		{
			if (read.eof())
				break;
			getline(read, aa, '/');//service id
			if (aa == "\n")
				return;
			getline(read, ee, '/');//fuel
			getline(read, trash, ',');//trash
			getline(read, cc, '/');//f name
			getline(read, bb, '/');//s name
			getline(read, dis, '/');//distance
			getline(read, Date, '/');//day
			getline(read, month, '/');//month
			getline(read, Year, '/');//year
			getline(read, Serv, '/');//sec
			getline(read, Minu, '/');//min
			getline(read, Hour_1, '|');//hour
			getline(read, c_id, '/');//cid
			getline(read, d_id, '/');//did
			getline(read, v_id, '\n');//vid

			fuel = stof(ee);
			sid = stoi(aa);
			Distance = stof(dis);
			strcpy(Lname, bb.c_str());
			strcpy(Fname, cc.c_str());
			dat = stoi(Date);
			mont = stoi(month);
			yea = stoi(Year);
			secon = stoi(Serv);
			minut = stoi(Minu);
			hou = stoi(Hour_1);
			did = stoi(d_id);
			cid = stoi(c_id);
			vid = stoi(v_id);
			
			if (vehicle_id == vid)
			{
				cout << "Service ID:" << aa << endl << "Fuel:" << ee << "\nSource:" << cc << "\nDestination:" << bb << "\nDistance:" << dis << endl;
				cout << "Date:" << dat << "/" << mont << "/" << yea << "\nDriver ID:" << did << endl << endl;
			}
			
			
		}
		read.close();
		while (read1.peek() != EOF)
		{
			if (read1.eof())
				break;
			getline(read1, aa, '/');//service id
			if (aa == "\n")
				return;
			getline(read1, ee, '/');//fuel
			getline(read1, trash, ',');//trash
			getline(read1, cc, '/');//f name
			getline(read1, bb, '/');//s name
			getline(read1, dis, '/');//distance
			getline(read1, Date, '/');//day
			getline(read1, month, '/');//month
			getline(read1, Year, '/');//year
			getline(read1, Serv, '/');//sec
			getline(read1, Minu, '/');//min
			getline(read1, Hour_1, '|');//hour
			getline(read1, c_id, '/');//cid
			getline(read1, d_id, '/');//did
			getline(read1, v_id, '\n');//vid

			fuel = stof(ee);
			sid = stoi(aa);
			Distance = stof(dis);
			strcpy(Lname, bb.c_str());
			strcpy(Fname, cc.c_str());
			dat = stoi(Date);
			mont = stoi(month);
			yea = stoi(Year);
			secon = stoi(Serv);
			minut = stoi(Minu);
			hou = stoi(Hour_1);
			did = stoi(d_id);
			cid = stoi(c_id);
			vid = stoi(v_id);

			if (vehicle_id == vid)
			{
				cout << "Service ID:" << aa << endl << "Fuel:" << ee << "\nSource:" << cc << "\nDestination:" << bb << "\nDistance:" << dis << endl;
				cout << "Date:" << dat << "/" << mont << "/" << yea << "\nDriver ID:" << did << endl << endl;
			}


		}
		read1.close();
	}
	void TMS::function_8()
	{
		int vehicle_id = 0;
		cout << "Enter Customer ID:";
		cin >> vehicle_id;
		for (int i = 0; i < count_customer; i++)
		{
			if (vehicle_id == C[i].getcid())
			{
				cout << C[i];
			}

		}
		cout << endl << endl;
		ifstream read("ride.txt");
		ifstream read1("delivery.txt");
		char* Fname = new char[15];
		char* Lname = new char[15];
		string aa;
		string bb;
		string cc;
		string trash;
		string ee;
		string ff;
		string gg;
		string dis; string Date;
		string month; string Year; string Serv; string Minu; string Hour_1;
		string c_id;
		string v_id;
		string d_id;
		int dat;
		int mont;
		int yea;
		int secon;
		int minut;
		int hou;
		int sid;
		int vid;
		int cid;
		int did;
		float Distance;
		//bool status;
		float fuel = 0;
		int line_no = 0;
		int index = 0;

		while (read.peek() != EOF)
		{
			if (read.eof())
				break;
			getline(read, aa, '/');//service id
			if (aa == "\n")
				return;
			getline(read, ee, '/');//fuel
			getline(read, trash, ',');//trash
			getline(read, cc, '/');//f name
			getline(read, bb, '/');//s name
			getline(read, dis, '/');//distance
			getline(read, Date, '/');//day
			getline(read, month, '/');//month
			getline(read, Year, '/');//year
			getline(read, Serv, '/');//sec
			getline(read, Minu, '/');//min
			getline(read, Hour_1, '|');//hour
			getline(read, c_id, '/');//cid
			getline(read, d_id, '/');//did
			getline(read, v_id, '\n');//vid

			fuel = stof(ee);
			sid = stoi(aa);
			Distance = stof(dis);
			strcpy(Lname, bb.c_str());
			strcpy(Fname, cc.c_str());
			dat = stoi(Date);
			mont = stoi(month);
			yea = stoi(Year);
			secon = stoi(Serv);
			minut = stoi(Minu);
			hou = stoi(Hour_1);
			did = stoi(d_id);
			cid = stoi(c_id);
			vid = stoi(v_id);

			if (vehicle_id == cid)
			{
				cout << "Service ID:" << aa << endl << "Fuel:" << ee << "\nSource:" << cc << "\nDestination:" << bb << "\nDistance:" << dis << endl;
				cout << "Date:" << dat << "/" << mont << "/" << yea << "\nDriver ID:" << did << endl << endl;
			}


		}
		read.close();
		while (read1.peek() != EOF)
		{
			if (read1.eof())
				break;
			getline(read1, aa, '/');//service id
			if (aa == "\n")
				return;
			getline(read1, ee, '/');//fuel
			getline(read1, trash, ',');//trash
			getline(read1, cc, '/');//f name
			getline(read1, bb, '/');//s name
			getline(read1, dis, '/');//distance
			getline(read1, Date, '/');//day
			getline(read1, month, '/');//month
			getline(read1, Year, '/');//year
			getline(read1, Serv, '/');//sec
			getline(read1, Minu, '/');//min
			getline(read1, Hour_1, '|');//hour
			getline(read1, c_id, '/');//cid
			getline(read1, d_id, '/');//did
			getline(read1, v_id, '\n');//vid

			fuel = stof(ee);
			sid = stoi(aa);
			Distance = stof(dis);
			strcpy(Lname, bb.c_str());
			strcpy(Fname, cc.c_str());
			dat = stoi(Date);
			mont = stoi(month);
			yea = stoi(Year);
			secon = stoi(Serv);
			minut = stoi(Minu);
			hou = stoi(Hour_1);
			did = stoi(d_id);
			cid = stoi(c_id);
			vid = stoi(v_id);

			if (vehicle_id == cid)
			{
				cout << "Service ID:" << aa << endl << "Fuel:" << ee << "\nSource:" << cc << "\nDestination:" << bb << "\nDistance:" << dis << endl;
				cout << "Date:" << dat << "/" << mont << "/" << yea << "\nDriver ID:" << did << endl << endl;
			}


		}
		read1.close();
	}
	void TMS::function_9()
	{
		int vehicle_id = 0;
		cout << "Enter Driver ID:";
		cin >> vehicle_id;
		for (int i = 0; i < count_driver; i++)
		{
			if (vehicle_id == C[i].getcid())
			{
				cout << d[i];
			}

		}
		cout << endl << endl;
		ifstream read("ride.txt");
		ifstream read1("delivery.txt");
		char* Fname = new char[15];
		char* Lname = new char[15];
		string aa;
		string bb;
		string cc;
		string trash;
		string ee;
		string ff;
		string gg;
		string dis; string Date;
		string month; string Year; string Serv; string Minu; string Hour_1;
		string c_id;
		string v_id;
		string d_id;
		int dat;
		int mont;
		int yea;
		int secon;
		int minut;
		int hou;
		int sid;
		int vid;
		int cid;
		int did;
		float Distance;
		
		float fuel = 0;
		int line_no = 0;
		int index = 0;

		while (read.peek() != EOF)
		{
			if (read.eof())
				break;
			getline(read, aa, '/');//service id
			if (aa == "\n")
				return;
			getline(read, ee, '/');//fuel
			getline(read, trash, ',');//trash
			getline(read, cc, '/');//f name
			getline(read, bb, '/');//s name
			getline(read, dis, '/');//distance
			getline(read, Date, '/');//day
			getline(read, month, '/');//month
			getline(read, Year, '/');//year
			getline(read, Serv, '/');//sec
			getline(read, Minu, '/');//min
			getline(read, Hour_1, '|');//hour
			getline(read, c_id, '/');//cid
			getline(read, d_id, '/');//did
			getline(read, v_id, '\n');//vid

			fuel = stof(ee);
			sid = stoi(aa);
			Distance = stof(dis);
			strcpy(Lname, bb.c_str());
			strcpy(Fname, cc.c_str());
			dat = stoi(Date);
			mont = stoi(month);
			yea = stoi(Year);
			secon = stoi(Serv);
			minut = stoi(Minu);
			hou = stoi(Hour_1);
			did = stoi(d_id);
			cid = stoi(c_id);
			vid = stoi(v_id);

			if (vehicle_id == did)
			{
				cout << "Service ID:" << aa << endl << "Fuel:" << ee << "\nSource:" << cc << "\nDestination:" << bb << "\nDistance:" << dis << endl;
				cout << "Date:" << dat << "/" << mont << "/" << yea << "\nDriver ID:" << did << endl << endl;
			}


		}
		read.close();
		while (read1.peek() != EOF)
		{
			if (read1.eof())
				break;
			getline(read1, aa, '/');//service id
			if (aa == "\n")
				return;
			getline(read1, ee, '/');//fuel
			getline(read1, trash, ',');//trash
			getline(read1, cc, '/');//f name
			getline(read1, bb, '/');//s name
			getline(read1, dis, '/');//distance
			getline(read1, Date, '/');//day
			getline(read1, month, '/');//month
			getline(read1, Year, '/');//year
			getline(read1, Serv, '/');//sec
			getline(read1, Minu, '/');//min
			getline(read1, Hour_1, '|');//hour
			getline(read1, c_id, '/');//cid
			getline(read1, d_id, '/');//did
			getline(read1, v_id, '\n');//vid

			fuel = stof(ee);
			sid = stoi(aa);
			Distance = stof(dis);
			strcpy(Lname, bb.c_str());
			strcpy(Fname, cc.c_str());
			dat = stoi(Date);
			mont = stoi(month);
			yea = stoi(Year);
			secon = stoi(Serv);
			minut = stoi(Minu);
			hou = stoi(Hour_1);
			did = stoi(d_id);
			cid = stoi(c_id);
			vid = stoi(v_id);

			if (vehicle_id == did)
			{
				cout << "Service ID:" << aa << endl << "Fuel:" << ee << "\nSource:" << cc << "\nDestination:" << bb << "\nDistance:" << dis << endl;
				cout << "Date:" << dat << "/" << mont << "/" << yea << "\nDriver ID:" << did << endl << endl;
			}


		}
		read1.close();
	}
	void TMS::function_12()
	{
		//ifstream read("ride.txt");
		//ofstream ofs;
		//char* Fname = new char[15];
		//char* Lname = new char[15];
		//string aa;
		//string bb;
		//string cc;
		//string trash;
		//string ee;
		//string ff;
		//string gg;
		//string dis; string Date;
		//string month; string Year; string Serv; string Minu; string Hour_1;
		//string c_id;
		//string v_id;
		//string d_id;
		//int dat;
		//int mont;
		//int yea;
		//int secon;
		//int minut;
		//int hou;
		//int sid;
		//int vid;
		//int cid;
		//int did;
		//float Distance;
		//bool status;
		//float fuel = 0;
		//int line_no = 0;
		//int index = 0;

		//while (read.peek() != EOF)
		//{
		//	if (read.eof())
		//		break;
		//	getline(read, aa, '/');//service id
		//	if (aa == "\n")
		//		return;
		//	getline(read, ee, '/');//fuel
		//	getline(read, trash, ',');//trash
		//	getline(read, cc, '/');//f name
		//	getline(read, bb, '/');//s name
		//	getline(read, dis, '/');//distance
		//	getline(read, Date, '/');//day
		//	getline(read, month, '/');//month
		//	getline(read, Year, '/');//year
		//	getline(read, Serv, '/');//sec
		//	getline(read, Minu, '/');//min
		//	getline(read, Hour_1, '|');//hour
		//	getline(read, c_id, '/');//cid
		//	getline(read, d_id, '/');//did
		//	getline(read, v_id, '\n');//vid
		//	status = stoi(cc);
		//	fuel = stof(ee);
		//	sid = stoi(aa);
		//	Distance = stof(dis);
		//	strcpy(Lname, bb.c_str());
		//	strcpy(Fname, cc.c_str());
		//	dat = stoi(Date);
		//	mont = stoi(month);
		//	yea = stoi(Year);
		//	secon = stoi(Serv);
		//	minut = stoi(Minu);
		//	hou = stoi(Hour_1);
		//	did = stoi(d_id);
		//	cid = stoi(c_id);
		//	vid = stoi(v_id);
	}
	void TMS::function_16()
	{

		int vehicle_id = 0;
		cout << "Enter Vehicle ID:";
		cin >> vehicle_id;
		
		cout << endl << endl;
		ifstream read("ride.txt");
		ifstream read1("delivery.txt");
		char* Fname = new char[15];
		char* Lname = new char[15];
		string aa;
		string bb;
		string cc;
		string trash;
		string ee;
		string ff;
		string gg;
		string dis; string Date;
		string month; string Year; string Serv; string Minu; string Hour_1;
		string c_id;
		string v_id;
		string d_id;
		int dat;
		int mont;
		int yea;
		int secon;
		int minut;
		int hou;
		int sid;
		int vid;
		int cid;
		int did;
		float Distance;

		float fuel = 0;
		int line_no = 0;
		int index = 0;
		cout << endl;
		while (read.peek() != EOF)
		{
			if (read.eof())
				break;
			getline(read, aa, '/');//service id
			if (aa == "\n")
				return;
			getline(read, ee, '/');//fuel
			getline(read, trash, ',');//trash
			getline(read, cc, '/');//f name
			getline(read, bb, '/');//s name
			getline(read, dis, '/');//distance
			getline(read, Date, '/');//day
			getline(read, month, '/');//month
			getline(read, Year, '/');//year
			getline(read, Serv, '/');//sec
			getline(read, Minu, '/');//min
			getline(read, Hour_1, '|');//hour
			getline(read, c_id, '/');//cid
			getline(read, d_id, '/');//did
			getline(read, v_id, '\n');//vid

			fuel = stof(ee);
			sid = stoi(aa);
			Distance = stof(dis);
			strcpy(Lname, bb.c_str());
			strcpy(Fname, cc.c_str());
			dat = stoi(Date);
			mont = stoi(month);
			yea = stoi(Year);
			secon = stoi(Serv);
			minut = stoi(Minu);
			hou = stoi(Hour_1);
			did = stoi(d_id);
			cid = stoi(c_id);
			vid = stoi(v_id);

			if (vehicle_id == vid)
			{
				for (int i = 0; i < count_customer; i++)
				{
					if (cid == C[i].getcid())
						cout << C[i]<<endl;
				}
			}


		}
		read.close();


	}
	
	void TMS::function_17()
	{
		int day_i = 0, month_i = 0, year_i = 0;
		cout << "Enter Date\nday:";
		cin >> day_i;
		cout << "Month:";
		cin >> month_i;
		cout << "Year:";
		cin >> year_i;
		
		cout << endl << endl;
		ifstream read1("delivery.txt");
		char* Fname = new char[15];
		char* Lname = new char[15];
		string aa;
		string bb;
		string cc;
		string trash;
		string ee;
		string ff;
		string gg;
		string dis; string Date;
		string month; string Year; string Serv; string Minu; string Hour_1;
		string c_id,status;
		string v_id;
		string d_id;
		int dat;
		int mont;
		int yea;
		int secon;
		int minut;
		int hou;
		int sid;
		int vid;
		int cid;
		int did;
		float Distance;
		bool stat;
		float fuel = 0;
		int line_no = 0;
		int index = 0;

	
		
		while (read1.peek() != EOF)
		{
			if (read1.eof())
				break;
			getline(read1, aa, '/');//service id
			if (aa == "\n")
				return;
			getline(read1, ee, '/');//fuel
			getline(read1, status, '/');//fuel
			getline(read1, trash, ',');//trash
			getline(read1, cc, '/');//f name
			getline(read1, bb, '/');//s name
			getline(read1, dis, '/');//distance
			getline(read1, Date, '/');//day
			getline(read1, month, '/');//month
			getline(read1, Year, '/');//year
			getline(read1, Serv, '/');//sec
			getline(read1, Minu, '/');//min
			getline(read1, Hour_1, '|');//hour
			getline(read1, c_id, '/');//cid
			getline(read1, d_id, '/');//did
			getline(read1, v_id, '\n');//vid
			stat = stoi(status);
			fuel = stof(ee);
			sid = stoi(aa);
			Distance = stof(dis);
			strcpy(Lname, bb.c_str());
			strcpy(Fname, cc.c_str());
			dat = stoi(Date);
			mont = stoi(month);
			yea = stoi(Year);
			secon = stoi(Serv);
			minut = stoi(Minu);
			hou = stoi(Hour_1);
			did = stoi(d_id);
			cid = stoi(c_id);
			vid = stoi(v_id);

			if (dat == day_i && mont == month_i && yea == year_i && stat == 1)
			{
				for (int i = 0; i < count_vehicle; i++)
				{
					if (vid == d[i].getid())
						cout << d[i]<<endl;
				}
			}


		}
		read1.close();
	}
	void TMS::function_18()
	{

		int day_i = 0,month_i=0,year_i=0;
		cout << "Enter Date\nday:";
		cin >> day_i;
		cout << "Month:";
		cin >> month_i;
		cout << "Year:";
		cin>> year_i;
		int counterr = 0;
		
		ifstream read("ride.txt");
		ifstream read1("delivery.txt");
		char* Fname = new char[15];
		char* Lname = new char[15];
		string status;
		string aa;
		string bb;
		string cc;
		string trash;
		string ee;
		string ff;
		string gg;
		string dis; string Date;
		string month; string Year; string Serv; string Minu; string Hour_1;
		string c_id;
		string v_id;
		string d_id;
		int dat;
		int mont;
		int yea;
		int secon;
		int minut;
		int hou;
		int sid;
		int vid;
		int cid;
		int did;
		float Distance;
		bool stat;
		float fuel = 0;
		int line_no = 0;
		int index = 0;

		while (read.peek() != EOF)
		{
			if (read.eof())
				break;
			getline(read, aa, '/');//service id
			if (aa == "\n")
				return;
			getline(read, ee, '/');//fuel
			getline(read, status, '/');//status
			getline(read, trash, ',');//trash
			getline(read, cc, '/');//f name
			getline(read, bb, '/');//s name
			getline(read, dis, '/');//distance
			getline(read, Date, '/');//day
			getline(read, month, '/');//month
			getline(read, Year, '/');//year
			getline(read, Serv, '/');//sec
			getline(read, Minu, '/');//min
			getline(read, Hour_1, '|');//hour
			getline(read, c_id, '/');//cid
			getline(read, d_id, '/');//did
			getline(read, v_id, '\n');//vid
			stat = stoi(status);
			fuel = stof(ee);
			sid = stoi(aa);
			Distance = stof(dis);
			strcpy(Lname, bb.c_str());
			strcpy(Fname, cc.c_str());
			dat = stoi(Date);
			mont = stoi(month);
			yea = stoi(Year);
			secon = stoi(Serv);
			minut = stoi(Minu);
			hou = stoi(Hour_1);
			did = stoi(d_id);
			cid = stoi(c_id);
			vid = stoi(v_id);
			

			if (stat==0&&day_i==dat&&month_i==mont&&yea==year_i)
			{
				counterr++;
				cout << "Service ID:" << aa << endl << "Fuel:" << ee << "\nSource:" << cc << "\nDestination:" << bb << "\nDistance:" << dis << endl;
				cout << "Date:" << dat << "/" << mont << "/" << yea << "\nDriver ID:" << did << endl << endl<<endl;
			}

		}
		read.close();
		while (read1.peek() != EOF)
		{
			if (read1.eof())
			{
				break;
			}
				
			getline(read1, aa, '/');//service id
			if (aa == "\n")
				return;
			getline(read1, ee, '/');//fuel
			getline(read1, status, '/');//status
			getline(read1, trash, ',');//trash
			getline(read1, cc, '/');//f name
			getline(read1, bb, '/');//s name
			getline(read1, dis, '/');//distance
			getline(read1, Date, '/');//day
			getline(read1, month, '/');//month
			getline(read1, Year, '/');//year
			getline(read1, Serv, '/');//sec
			getline(read1, Minu, '/');//min
			getline(read1, Hour_1, '|');//hour
			getline(read1, c_id, '/');//cid
			getline(read1, d_id, '/');//did
			getline(read1, v_id, '\n');//vid

			fuel = stof(ee);
			sid = stoi(aa);
			Distance = stof(dis);
			strcpy(Lname, bb.c_str());
			strcpy(Fname, cc.c_str());
			dat = stoi(Date);
			mont = stoi(month);
			yea = stoi(Year);
			secon = stoi(Serv);
			minut = stoi(Minu);
			hou = stoi(Hour_1);
 			did = stoi(d_id);
			cid = stoi(c_id);
			vid = stoi(v_id);
			stat = stoi(status);
			if (stat == 0 && day_i == dat && month_i == mont && yea == year_i)
			{
				counterr++;
				cout << "Service ID:" << aa << endl << "Fuel:" << ee << "\nSource:" << cc << "\nDestination:" << bb << "\nDistance:" << dis << endl;
				cout << "Date:" << dat << "/" << mont << "/" << yea << "\nDriver ID:" << did << endl << endl;
			}
			

		}

		read1.close();
            if (counterr == 0)
			{
				cout << "NONE\n";
			}
	}
	void TMS::function_19()
	{

		int driver_id = 0;
		cout << "Enter Driver ID:";
		cin >> driver_id;
		cout << endl ;
		int count = 0;
		flagg ("Pending Services\n");
		ifstream read("ride.txt");
		ifstream read1("delivery.txt");
		char* Fname = new char[15];
		char* Lname = new char[15];
		string aa;
		string bb;
		string cc;
		string trash;
		string ee;
		string ff;
		string gg;
		string dis; string Date;
		string month; string Year; string Serv; string Minu; string Hour_1;
		string c_id;
		string v_id;
		string d_id;string status;
		int dat;
		int mont;
		int yea;
		int secon;
		int minut;
		int hou;
		int sid;
		int vid;
		int cid;
		int did;
		float Distance;
		bool stat;
		float fuel = 0;
		int line_no = 0;
		int index = 0;
		
		while (read.peek() != EOF)
		{
			if (read.eof())
				break;
			getline(read, aa, '/');//service id
			if (aa == "\n")
				return;
			getline(read, ee, '/');//fuel
			getline(read, status, '/');//status
			getline(read, trash, ',');//trash
			getline(read, cc, '/');//f name
			getline(read, bb, '/');//s name
			getline(read, dis, '/');//distance
			getline(read, Date, '/');//day
			getline(read, month, '/');//month
			getline(read, Year, '/');//year
			getline(read, Serv, '/');//sec
			getline(read, Minu, '/');//min
			getline(read, Hour_1, '|');//hour
			getline(read, c_id, '/');//cid
			getline(read, d_id, '/');//did
			getline(read, v_id, '\n');//vid

			fuel = stof(ee);
			sid = stoi(aa);
			Distance = stof(dis);
			strcpy(Lname, bb.c_str());
			strcpy(Fname, cc.c_str());
			dat = stoi(Date);
			mont = stoi(month);
			yea = stoi(Year);
			secon = stoi(Serv);
			minut = stoi(Minu);
			hou = stoi(Hour_1);
			did = stoi(d_id);
			cid = stoi(c_id);
			vid = stoi(v_id);
			stat = stoi(status);
			if (driver_id == did && stat==0)
			{
				count++;
				cout << "Service ID:" << aa << endl << "Fuel:" << ee << "\nSource:" << cc << "\nDestination:" << bb << "\nDistance:" << dis << endl;
				cout << "Date:" << dat << "/" << mont << "/" << yea << "\nDriver ID:" << did << endl << endl;
			}

		}
		read.close();
		while (read1.peek() != EOF)
		{
			if (read1.eof())
				break;
			getline(read1, aa, '/');//service id
			if (aa == "\n")
				return;
			getline(read1, ee, '/');//fuel
			getline(read1, status, '/');//status
			getline(read1, trash, ',');//trash
			getline(read1, cc, '/');//f name
			getline(read1, bb, '/');//s name
			getline(read1, dis, '/');//distance
			getline(read1, Date, '/');//day
			getline(read1, month, '/');//month
			getline(read1, Year, '/');//year
			getline(read1, Serv, '/');//sec
			getline(read1, Minu, '/');//min
			getline(read1, Hour_1, '|');//hour
			getline(read1, c_id, '/');//cid
			getline(read1, d_id, '/');//did
			getline(read1, v_id, '\n');//vid

			fuel = stof(ee);
			sid = stoi(aa);
			Distance = stof(dis);
			strcpy(Lname, bb.c_str());
			strcpy(Fname, cc.c_str());
			dat = stoi(Date);
			mont = stoi(month);
			yea = stoi(Year);
			secon = stoi(Serv);
			minut = stoi(Minu);
			hou = stoi(Hour_1);
			did = stoi(d_id);
			cid = stoi(c_id);
			vid = stoi(v_id);

			if (driver_id == did&&stat==0)
			{
				count++;
				cout << "Service ID:" << aa << endl << "Fuel:" << ee << "\nSource:" << cc << "\nDestination:" << bb << "\nDistance:" << dis << endl;
				cout << "Date:" << dat << "/" << mont << "/" << yea << "\nDriver ID:" << did << endl << endl;
			}


		}
		read1.close();
		if (count == 0)
		{
			cout << "NONE\n";
		}
	}

	int main()
	{

		TMS a;
		bool condition = true;
		reset();
		boldCyan();
		cout << "->MAIN MENU\n";
		reset();
		cout << "Enter 1 to add a New Customer\nEnter 2 to Add or Remove a Driver\nEnter 3 to ADD or Remove a Vehicle\nEnter 4 to Print All customer Details\n";
		cout << "Enter 5 to Print List of All drivers\nEnter 6 to Print complete list of vehicles with details by their category\n";
		cout<<"Enter 7 to Print complete details and service history of a particular vehicle\n";
		cout << "Enter 8 to Print complete history of a particular customer\nEnter 9 to Print complete history of a driver including services\n";
		cout<<"Enter 10 to Print list of all drivers who have ranking above 4.5\nEnter 11 to Print list of all drivers who have multiple licenses and their license information"; 
		cout<<"\nEnter 12 to Print updated salary of all drivers based on their updated ranking\nEnter 13 to Add a Service request\n";
		cout << "Enter 14 to update after customer cancels a booking\n";
		cout << "Enter 15 to Complete a service\n";
		cout << "Enter 16 to Print details of all Customers, who used the same vehicle\n";
		cout << "Enter 17 to Print the List of all Drivers who completed delivery services on same days\n";
		cout << "Enter 18 to Print details of all pending services on a particular date.\n";
		cout << "Enter 19 to Print details of all pending services of a particular driver\n";
		cout << "Enter 20 to Print details of all canceled services by a customer\n";
		red();
		cout << "ENTER -1 to exit\n";
		reset();
		int opt;
		while (condition)
		{
			boldBlue();
			cout << "\n\nEnter Option->";
			reset();
			cin >> opt;
			cout << endl;
			
			switch (opt)
			{
			case 1:
				a.add_a_new_customer();
				break;
			case 2:
				a.addOrRemoveDriver();
				break;
			case 3:
				a.addOrRemoveVehicle();
				break;
			case 4:
				a.printCustomerDetials();
				break;
			case 5:
				a.printDriverDetails();
				break;
			case 6:
				a.printListOfTheVehicles();
				break;
			case 7:
				a.function_7();
				break; 
			case 8:
				a.function_8();
				break;
			case 9:
				a.function_9();
				break;
			case 10:
				a.print_driver4_5();
				break;
			case 11:
				a.print_no_of_license();
				break;
			case 12:
				a.function_12();
				break;
			case 13:
				a.rideordelivery();
				break; 
			case 14:
				a.cancelservice();
				break;
			case 15:
				a.complete();
				break;

			case 16:
				a.function_16();
				break;
			case 17:
			a.function_17();
				break;
			case 18:
				a.function_18();
				break;
			case 19:
				a.function_19();
				break;
			case 20:

				break;
			case -1:
			{
				condition = false;
				
				break;
			}
			default:
				cout << "\nINVALID INPUT\n";
				break;
			}
		}
		system("pause");
		return 0;
    }
	