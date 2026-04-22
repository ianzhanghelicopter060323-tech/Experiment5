#include <iostream>
using namespace std;


class Vehicle
{
    public:
        // without param
        Vehicle(): wheels(0), weight(0.0) {}
        // with param
        Vehicle(int wheels_in, double weight_in): wheels(wheels_in), weight(weight_in) {}

        // output wheels
        int wheelsGet() const { return wheels;  }
        // output weight
         double weightGet() const { return weight;  }

        // set wheels
        void wheelsSet(int wheels_to_set)
        {
            if (wheels_to_set < 0)
            {
                cout << "wheel number shouble be positive" << endl;
                return ;
            }

            wheels = wheels_to_set;
        }
        // set weight
        void weightSet(double weight_to_set)
        {
            if (weight_to_set < 0.0)
            {
                cout << "wheel number shouble be positive" << endl;
                return ;
            }

            weight = weight_to_set;
        }
    
    private:
        int wheels;
    protected:
        double weight;
};


class Car: private Vehicle
{
    public:
        // without param
        Car(): displacement(0.0) 
        {
            wheelsSet(0);
            weightSet(0.0);
        }
        // with pram
        Car(double displacement_in, int wheels_in, double weight_in): displacement(displacement_in) 
        {
            wheelsSet(wheels_in);
            weightSet(weight_in);
        }

    private:
        double displacement;
};


class Truck : protected Vehicle
{
    public:
        //without param
        Truck(): payload(0.0)
        {
            wheelsSet(0);
            weightSet(0.0);
        }
        // with param
        Truck(double payload_in, int wheels_in, double weight_in): payload(payload_in)
        {
            wheelsSet(wheels_in);
            weightSet(weight_in);
        }

    private:
        double payload;

};


class Van : public Vehicle
{
    public:
        // without param
        Van(): passenger_load(0)
        {
            wheelsSet(0);
            weightSet(0.0);
        }
        // with param
        Van(int passenger_load_in, int wheels_in, double weight_in): passenger_load(passenger_load_in)
        {
            wheelsSet(wheels_in);
            weightSet(weight_in);
        }
    private:
        int passenger_load;
};