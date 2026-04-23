#include <iostream>
using namespace std;


class Object
{
    private:
        double weight;
    public:
        // without param construct
        Object():weight(0.0) {   
            cout <<"object born with nothing"<<endl;    
        }                        
        // with param construct 
        Object(double weight_in): weight(weight_in){   
            cout <<"object born with param"<<endl;   
        }  
        // copy construct
        Object(const Object &ob): weight(ob.weight) {   
            cout <<"object born with copying"<<endl;   
        }  
        // deconstruct
        ~Object() {   
            cout << "object destroyed" << endl; 
        }                                    
};

class Box : public Object
{
    private:
        double height;
        double width;
    public:
        // without param construct
        Box(): height(0.0), width(0.0),Object() {
            cout << "box born with nothing" << endl;
        }
        // with param construct
        Box(double height_in, double width_in, double weight_in): height(height_in), width(width_in), Object(weight_in) {
            cout << "box born with param" << endl;
        } 
        // copy construct
        Box(const Box &bx): height(bx.height), width(bx.width), Object(bx) {
            cout << "box born with copying" <<endl;
        }
        // deconstruct
        ~Box() {
            cout << "box destroyed" << endl;
        }
};


int main()
{
    
}