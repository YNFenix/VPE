#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>

class IVehicle
{
protected:
    double miliage = 0.0;

public:
    virtual bool drive(int kilometres) = 0;
    virtual void refuel() = 0;
    virtual void printStatus() = 0;
};

struct RoutePoint
{
    int xKm;
    int yKm;
    std::string nameCar;

    RoutePoint(int x, int y, std::string name) : xKm(x), yKm(y), nameCar(name) {}
};

class Route
{
private:
    std::vector<RoutePoint> points;

public:
    void addPoint(const RoutePoint& point)
    {
        points.push_back(point);
    };

    void run(IVehicle* vehicle)
    {

        if (points.size() < 2)
        {
            std::cout << "Ошибка! Маршрут должен иметь минимум 2 точки.";
            return;
        }

        for (int i = 0; i < points.size() - 1; i++)
        {
            double distanceBetweenPoints = sqrt(pow(points[i + 1].xKm - points[i].xKm, 2) + pow(points[i + 1].yKm - points[i].yKm, 2));

            if (!vehicle->drive(distanceBetweenPoints))
            {
                vehicle->refuel();
                vehicle->drive(distanceBetweenPoints);
            }

        }
    }
};

class AbstractCar : public IVehicle
{
protected:
    double fuelTankCapacity; // Объём бака
    double fuelConsumption; // Расход топлива на 100 км
    double fuelLevel; // Уровень топлива
    double miliage; // Пробег

public:
    AbstractCar(double tankCapacity, double consumption) : fuelTankCapacity(tankCapacity), fuelConsumption(consumption), fuelLevel(fuelTankCapacity), miliage(0.0) {}

    bool drive(int kilometres) override
    {
        double requiredFuel = (static_cast<double>(kilometres) / 100) * fuelConsumption;

        if (requiredFuel <= fuelLevel)
        {
            miliage += kilometres;
            fuelLevel -= requiredFuel;
            std::cout << "Проехали: " << kilometres << " км. Осталось топлива: " << fuelLevel << " л." << std::endl;
        }
        else
        {
            std::cout << "Недостаточно топлива для поездки на " << kilometres << " км." << std::endl;
            return false;
        }
    }

    void refuel() override
    {
        fuelLevel = fuelTankCapacity;
        std::cout << "Бак заправлен до полного, теперь у вас " << fuelLevel << " литров топлива." << std::endl;
    }

    void printStatus() override
    {
        std::cout << "Общий пробег автомобиля: " << miliage << " км." << std::endl;
        std::cout << "Оставшееся в баке топливо: " << fuelLevel << " л." << std::endl;
    }
};

class Sedan : public AbstractCar
{
public:
    Sedan() : AbstractCar(68.0, 15.2) {}
};

class Suv : public AbstractCar
{
public:
    Suv() : AbstractCar(96.0, 16.7) {}
};

class Bus : public AbstractCar
{
public:
    Bus() : AbstractCar(300.0, 33.6) {}
};

class Bicycle : public IVehicle
{
    bool drive(int kilometres) override
    {
        miliage += kilometres;
        std::cout << "Проехали: " << kilometres << std::endl;
        return true;
    }

    void printStatus() override
    {
        std::cout << "Общий пробег велосипедиста: " << miliage << std::endl;
    }

    void refuel() override {}
};


#include <iostream>

int main(int argc, char* argv[])
{
    setlocale(0, "");

    if (argc < 2)
    {
        std::cerr << "Ошибка! Был передан всего один аргумент!" << std::endl;
        return 1;
    }

    const char* fileName = argv[1];

    std::ifstream inputFile(fileName);

    if (!inputFile.is_open())
    {
        std::cout << "Ошибка! Не удалось открыть нужный файл!" << std::endl;
        return 1;
    }


    const int countRoutes = 1;
    Route routes[countRoutes];

    for (int i = 0; i < countRoutes; i++)
    {
        int x;
        int y;
        std::string namepoint;

        while (inputFile >> x >> y >> namepoint)
        {
            routes[i].addPoint(RoutePoint(x, y, namepoint));
        }

    }


    IVehicle* vehicles[] = { new Sedan, new Suv, new Bus, new Bicycle };

    for (int i = 0; i < 1; i++)
    {
        std::cout << i + 1 << "-ый маршрут.\n\n";

        for (int j = 0; j < 4; j++)
        {
            IVehicle* vehicle = vehicles[j];

            vehicle->refuel();
            routes[i].run(vehicle);

            if (i >= 2)
            {
                delete vehicle;
            }

            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}
