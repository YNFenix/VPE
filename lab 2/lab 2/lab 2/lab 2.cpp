#include "lab 2.h"

int main() {

    setlocale(0, "");

    Vehicle* vehicles[4] = { new Sedan(), new Suv(), new Bus()};

    for (int i = 0; i < 4; ++i)
    {
        Vehicle* vehicle = vehicles[i];
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