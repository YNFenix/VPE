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
	int mileage; // пробег
	double fuel; // количество топлива в баке (в литрах)
	const double tankCapacity; // вместимость бака (в литрах)
	const double fuelConsumption; // расход топлива (литры на 100 км)
public:
	AbstractCar(double capacity, double consumption) : mileage(0), fuel(0), tankCapacity(capacity), fuelConsumption(consumption) {}
	void drive(int kilometers)
	{
		double fuelNeeded = (static_cast<double>(kilometers) / 100.0) * fuelConsumption;
		if (fuel >= fuelNeeded)
		{
			mileage += kilometers;
			fuel -= fuelNeeded;
			cout << "Проехали " << kilometers << " км. Осталось топлива: " << fuel << " литров." << endl;
		}
		else
		{
			cout << "Недостаточно топлива для поездки на " << kilometers << " км." << endl;
		}
	}
	void refuel()
	{
		fuel = tankCapacity;
		cout << "Бак заправлен до полного. Теперь у вас " << fuel << " литров топлива." << endl;
	}
	void printStatus()
	{
		cout << "Пробег: " << mileage << " км. Осталось топлива: " << fuel << " литров." << endl;
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
		cout << "Проехали: " << kilometers << endl;
	};

	void printStatus() override
	{
		cout << "Пробег: " << mileage << " км." << endl;
	};

	void refuel() override {};
};