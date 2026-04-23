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
                cout << "wheel number should be positive" << endl;
                return ;
            }

            wheels = wheels_to_set;
        }
        // set weight
        void weightSet(double weight_to_set)
        {
            if (weight_to_set < 0.0)
            {
                cout << "weight should be positive" << endl;
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
        Car(): Vehicle(0, 0.0), displacement(0.0) {}
        // with pram
        Car(double displacement_in, int wheels_in, double weight_in): Vehicle(wheels_in, weight_in), displacement(displacement_in) {}

        // weight output
        double weightGet() const {  return Vehicle::weightGet();  }
        // wheels output
        int wheelsGet() const { return Vehicle::wheelsGet();  }
        // displacement output
        double displacementGet() const {  return displacement;    }

        // set wheels
        void wheelsSet(int wheels_to_set)
        {
            if (wheels_to_set < 0)
            {
                cout << "wheel number should be positive" << endl;
                return ;
            }

            Vehicle::wheelsSet(wheels_to_set);
        }
        // weight set
        void weightSet(double weight_to_set)
        {
            if (weight_to_set < 0.0)
            {
                cout << "weight should be positive" << endl;
                return ;
            }

            Vehicle::weightSet(weight_to_set);
        }


        // displacement set
        void displacementSet(double displacement_to_set)
        {
            if (displacement_to_set < 0)
            {
                cout << "displacement should be positive" << endl;
                return ;
            }

            displacement = displacement_to_set;
        }

        // Vehicle call test inside the class
        void accessTestInDerived() const
        {
            // int x = wheels;      // FAIL: wheels is private in Vehicle
            double y = weight;      // OK: weight is protected in Vehicle
            int z = Vehicle::wheelsGet(); // OK: public member callable inside derived
            
            cout << "x FAIL TO GET VALUE" << endl;
            cout << "y = " << y << endl;
            cout << "z = " << z << endl;
        }

    private:
        double displacement;
};


class Truck : protected Vehicle
{
    public:
        //without param
        Truck(): Vehicle(0, 0.0), payload(0.0) {}
        // with param
        Truck(double payload_in, int wheels_in, double weight_in): Vehicle(wheels_in, weight_in), payload(payload_in) {}

        // get weight
        double weightGet() const {  return Vehicle::weightGet(); }
        // get wheels
        int wheelsGet() const { return Vehicle::wheelsGet(); }
        // get payload
        double payloadGet() const { return payload; }

        // set wheels
        void wheelsSet(int wheels_to_set)
        {
            if (wheels_to_set < 0)
            {
                cout << "wheel number should be positive" << endl;
                return ;
            }

            Vehicle::wheelsSet(wheels_to_set);
        }
        // weight set
        void weightSet(double weight_to_set)
        {
            if (weight_to_set < 0.0)
            {
                cout << "weight should be positive" << endl;
                return ;
            }

            Vehicle::weightSet(weight_to_set);
        }
        // payload set
        void payloadSet(double payload_to_set)
        {
            if (payload_to_set < 0)
            {
                cout << "payload should be positive" << endl;
                return ;
            }

            payload = payload_to_set;
        }

        // Vehicle call test inside the class
        void accessTestInDerived() const
        {
            // int x = wheels;      // FAIL: wheels is private in Vehicle
            double y = weight;      // OK: weight is protected in Vehicle
            int z = Vehicle::wheelsGet(); // OK: public member callable inside derived
            
            cout << "x FAIL TO GET VALUE" << endl;
            cout << "y = " << y << endl;
            cout << "z = " << z << endl;
        }

    private:
        double payload;

};


class Van : public Vehicle
{
    public:
        // without param
        Van(): Vehicle(0, 0.0), passenger_load(0) {}
        // with param
        Van(int passenger_load_in, int wheels_in, double weight_in): Vehicle(wheels_in, weight_in), passenger_load(passenger_load_in) {}

        // =============== public herited, not needed ================
        // get weight
        // double weightGet() const {  return Vehicle::weightGet(); }
        // get wheels
        // int wheelsGet() const { return Vehicle::wheelsGet(); }
        // passenger_load get
        // =============== public herited, not needed ================
        int passenger_loadGet() const { return passenger_load;  }

        // =============== public herited, not needed ================
        // set wheels
        /*void wheelsSet(int wheels_to_set)
        {
            if (wheels_to_set < 0)
            {
                cout << "wheel number should be positive" << endl;
                return ;
            }

            Vehicle::wheelsSet(wheels_to_set);
        }*/
        // weight set
        /*void weightSet(double weight_to_set)
        {
            if (weight_to_set < 0.0)
            {
                cout << "weight number shouble be positive" << endl;
                return ;
            }

            Vehicle::weightSet(weight_to_set);
        }*/
        // ================== public herited, not needed ================
        // passenger_load set
        void passenger_loadSet(int passenger_load_to_set)
        {
            if (passenger_load_to_set < 0)
            {
                cout << "passenger_load should be positive" << endl;
                return ;
            }

            passenger_load = passenger_load_to_set;
        }

        // Vehicle call test inside the class
        void accessTestInDerived() const
        {
            // int x = wheels;      // FAIL: wheels is private in Vehicle
            double y = weight;      // OK: weight is protected in Vehicle
            int z = Vehicle::wheelsGet(); // OK: public member callable inside derived
            
            cout << "x FAIL TO GET VALUE" << endl;
            cout << "y = " << y << endl;
            cout << "z = " << z << endl;
        }

    private:
        int passenger_load;
};


int main()
{
    // without param test
    Car c1;
    Truck t1;
    Van v1;
    // output test
    cout << "Car weight: "
         << c1.weightGet() << endl;
    cout << "Car wheels: "
         << c1.wheelsGet() << endl;
    cout << "Car displacement: "
         << c1.displacementGet() << endl;

    cout << "Truck weight: "
         << t1.weightGet() << endl;
    cout << "Truck wheels: "
         << t1.wheelsGet() << endl;
    cout << "Truck payload: "
         << t1.payloadGet() << endl;
    
    cout << "Van weight: "
         << v1.weightGet() << endl;
    cout << "Van wheels: "
         << v1.wheelsGet() << endl;
    cout << "Van passenger_load: "
         << v1.passenger_loadGet() << '\n' << endl;

    // construct with param test
    Car c2(1.14, 3, 5.14);
    Truck t2(19.19, 4, 8.10);
    Van v2(330, 2, 0.32);
    // output test
    cout << "Car weight: "
         << c2.weightGet() << endl;
    cout << "Car wheels: "
         << c2.wheelsGet() << endl;
    cout << "Car displacement: "
         << c2.displacementGet() << endl;

    cout << "Truck weight: "
         << t2.weightGet() << endl;
    cout << "Truck wheels: "
         << t2.wheelsGet() << endl;
    cout << "Truck payload: "
         << t2.payloadGet() << endl;
    
    cout << "Van weight: "
         << v2.weightGet() << endl;
    cout << "Van wheels: "
         << v2.wheelsGet() << endl;
    cout << "Van passenger_load: "
         << v2.passenger_loadGet() << '\n' << endl;
    
    // function setting test
    Car c3;
    Truck t3;
    Van v3;

    c3.displacementSet(111.1);
    c3.weightSet(222.3);
    c3.wheelsSet(44);

    t3.payloadSet(55.555);
    t3.weightSet(66.6);
    t3.wheelsSet(7);

    v3.passenger_loadSet(888);
    v3.weightSet(99.999);
    v3.wheelsSet(1000000000);
    // output test
    cout << "Car weight: "
         << c3.weightGet() << endl;
    cout << "Car wheels: "
         << c3.wheelsGet() << endl;
    cout << "Car displacement: "
         << c3.displacementGet() << endl;

    cout << "Truck weight: "
         << t3.weightGet() << endl;
    cout << "Truck wheels: "
         << t3.wheelsGet() << endl;
    cout << "Truck payload: "
         << t3.payloadGet() << endl;
    
    cout << "Van weight: "
         << v3.weightGet() << endl;
    cout << "Van wheels: "
         << v3.wheelsGet() << endl;
    cout << "Van passenger_load: "
         << v3.passenger_loadGet() << '\n' << endl;

    // accessing base class memebers inside class
    c1.accessTestInDerived();
    t1.accessTestInDerived();
    v1.accessTestInDerived();

    // accessing base class members through an object
    // int failCallPrivate_wheels = c1.wheels;   // FAIL: private 
    // double failCallPrivate_weight = c1.weight;   // FAIL: private 

    // int failCallProtected_wheels = t1.wheels; // FAIL: protected 
    // double failCallProtected_weight = t1.weight; // FAIL: protected 

    int successCallPublic_wheels = v1.wheelsGet();
    double successCallPublic_weight = v1.weightGet();
    // output
    cout << "Call wheels suceeded: " << successCallPublic_wheels << endl;
    cout << "Call weight suceeded: " << successCallPublic_weight << endl;

    return 0;
} 