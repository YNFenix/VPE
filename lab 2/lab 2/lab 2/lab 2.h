#include <iostream>
#include <string>
using namespace std;


class Vehicle 
{
protected:
	int mileage; // ������
	double fuel; // ���������� ������� � ���� (� ������)
	const double tankCapacity; // ����������� ���� (� ������)
	const double fuelConsumption; // ������ ������� (����� �� 100 ��)
public:
	Vehicle(double capacity, double consumption) : mileage(0), fuel(0), tankCapacity(capacity), fuelConsumption(consumption) {}
	void drive(int kilometers)
	{
		double fuelNeeded = (static_cast<double>(kilometers) / 100.0) * fuelConsumption;
		if (fuel >= fuelNeeded)
		{
			mileage += kilometers;
			fuel -= fuelNeeded;
			cout << "�������� " << kilometers << " ��. �������� �������: " << fuel << " ������." << endl;
		}
		else
		{
			cout << "������������ ������� ��� ������� �� " << kilometers << " ��." << endl;
		}
	}
	void refuel()
	{
		fuel = tankCapacity;
		cout << "��� ��������� �� �������. ������ � ��� " << fuel << " ������ �������." << endl;
	}
	void printStatus()
	{
		cout << "������: " << mileage << " ��. �������� �������: " << fuel << " ������." << endl;
	}
};

class Sedan : public Vehicle
{
public:
	Sedan() : Vehicle(50.0, 6.5) {}
};

class Suv : public Vehicle
{
public:
	Suv() : Vehicle(70.0, 8.0) {}
};

class Bus : public Vehicle
{
public:
	Bus() : Vehicle(200.0, 15.0) {}
};
