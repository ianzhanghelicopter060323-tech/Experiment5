#include <iostream>
using namespace std;


class Appliance
{
private:
    int brand;
protected:
    int power;
public:
    int test = 0;
    Appliance(): brand(0), power(0) {}
    Appliance(int brand_in, int power_in): brand(brand_in), power(power_in) {}
    Appliance(const Appliance &apn): brand(apn.brand), power(apn.power) {}
    ~Appliance() {}

    void setBrand(int brand_to_set)
    {
        if (brand_to_set < 0)
        {
            cout << "ERROR" << endl;
            return ;
        }

        brand = brand_to_set;
    }

    void setPower(int power_to_set)
    {
        if (power_to_set < 0)
        {
            cout << "ERROR" << endl;
            return ;
        }

        power = power_to_set;
    }

    int getBrand() const {  return brand;   }
    int getPower() const {  return power;   }
};


class Fan : private Appliance
{
private:
    int speed;
public:
    Fan():Appliance(),  speed(0) {};
    Fan(int speed_in, int brand_in, int power_in): Appliance(brand_in, power_in), speed(speed_in) {}
    Fan(const Fan &f): Appliance(f), speed(f.speed) {}
    ~Fan() {};

    // show members
    // show members 
    void show() const 
    {
        cout << "[newly Added] speed: "
             << speed << endl;
        /*
        cout << "[In Base] power:"   // FAIL: private + private = no
             << power << endl;
        */
       cout << "[In Base] power: "
             << power << endl;      // SUCCEED: proted + private = private
        cout << "[In Base] brand: "
            << getBrand() << endl;  // SUCCEED: public + private = private
        cout << "[In Base] power: "
             << getPower() << endl; 
        cout << "[In Base] test:"
             << test << endl;       // SUCEED: in Applaince is publice
    } 
};


class AirConditioner : protected Appliance
{
private:
    int temperature;
public:
    AirConditioner(): Appliance(), temperature(0) {};
    AirConditioner(int temp_in, int brand_in, int power_in): Appliance(brand_in, power_in), temperature(temp_in) {}
    AirConditioner(const AirConditioner &ac): Appliance(ac), temperature(ac.temperature) {}
    ~AirConditioner() {};

    // show members 
    void show() const 
    {
        cout << "[newly Added] temperature: "
             << temperature << endl;
        /*
        cout << "[In Base] power:"   // FAIL: private + private = no
             << power << endl;
        */
       cout << "[In Base] power: "
             << power << endl;      // SUCCEED: proted + private = private
        cout << "[In Base] brand: "
            << getBrand() << endl;  // SUCCEED: public + private = private
        cout << "[In Base] power: "
             << getPower() << endl; 
        cout << "[In Base] test:"
             << test << endl;       // SUCEED: in Applaince is publice
    } 
};


int main()
    {
        Fan f(1001, 100, 150); // brand, kW, r/min
        AirConditioner ac(2001, 500, 25); // rand, kW, C

        // show() test
        f.show();
        ac.show();

        // getBrand() and getPower()
        /*cout << "Fan getBrand test: " << f.getBrand() << endl;*/  // FAIL: getBrand() public + private = private
        /*cout << "Fan getPower test: " << f.getPower() << endl;*/  // FAIL: getPower() public + private = private
        /*cout << "AirConditioner getBrand test: " << ac.getBrand() << endl;*/ // FAIL: getBrand() public + private = private
        /*cout << "AirConditioner getpower test: " << ac.getPower() << endl;*/ // FAIL: getPower() public + private = private

        return 0;
    }

