#include <iostream>
using namespace std;


class Object
{
    private:
        double weight;
    public:
        // without param construct
        /* =========== delted will report ERROR ============== */ 
        Object():weight(0.0) {   
            cout <<"object born with nothing"<<endl;    
        }
        /* ================================================== */                         
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
        Box(): Object(), height(0.0), width(0.0) {
            cout << "box born with nothing" << endl;
        }
        // with param construct
        Box(double height_in, double width_in, double weight_in):  Object(weight_in), height(height_in), width(width_in) {
            cout << "box born with param" << endl;
        } 
        // copy construct
        /* =========== delted will use automatically generated copying construct ============== */ 
        /*Box(const Box &bx): Object(bx), height(bx.height), width(bx.width) {
            cout << "box born with copying" <<endl;
        }*/
       /* ==================================================================================== */ 
        // deconstruct
        ~Box() {
            cout << "box destroyed" << endl;
        }
};


int main()
{
    Box bx1;
    Box bx2(1.14, 5.14, 1.19);
    Box bx3(bx1);
    return 0;
}