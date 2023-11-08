#include <iostream>
#include <string>
using namespace std;

class IVehicle
{
public:
	virtual void drive(int kilometres) = 0;
	virtual void refuel() = 0;
	virtual void printStatus() = 0;
};



class AbstractCar : public IVehicle
{
protected:
	int mileage; // ������
	double fuel; // ���������� ������� � ���� (� ������)
	const double tankCapacity; // ����������� ���� (� ������)
	const double fuelConsumption; // ������ ������� (����� �� 100 ��)
public:
	AbstractCar(double capacity, double consumption) : mileage(0), fuel(0), tankCapacity(capacity), fuelConsumption(consumption) {}
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

class Sedan : public AbstractCar
{
public:
	Sedan() : AbstractCar(50.0, 6.5) {}
};

class Suv : public AbstractCar
{
public:
	Suv() : AbstractCar(70.0, 8.0) {}
};

class Bus : public AbstractCar
{
public:
	Bus() : AbstractCar(200.0, 15.0) {}
};

class Bicycle : public IVehicle
{
protected:
	int mileage;

public:
	void drive(int kilometers) override
	{
		mileage += kilometers;
		cout << "��������: " << kilometers << endl;
	};

	void printStatus() override
	{
		cout << "������: " << mileage << " ��." << endl;
	};

	void refuel() override {};
};