#include "aaaa.h"

int main() {

    setlocale(0, "");

    IVehicle* vehicles[4] = { new Sedan(), new Suv(), new Bus(), new Bicycle() };

    for (int i = 0; i < 4; ++i)
    {
        IVehicle* vehicle = vehicles[i];
        vehicle->refuel();
        vehicle->printStatus();
        vehicle->drive(120);
        vehicle->printStatus();
        vehicle->drive(420);
        vehicle->printStatus();
        vehicle->drive(300);
        vehicle->printStatus();
        vehicle->refuel();
        vehicle->drive(300);
        vehicle->printStatus();
        delete vehicle;
        cout << endl;
    }

    return 0;
}