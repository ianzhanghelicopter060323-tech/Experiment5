# Car.cpp要求
1. 编写一个汽车类```Vehicle```，有无参数构造函数，类中的数据成员：车轮个数```wheels```为私有成员，车重```weight```为保护成员，获取和设置轮胎个数和车重的函数为公有成员；
2. ```Car```类**私有继承**```Vehicle```，增加数据成员排量```displacement```；
3.  ```Truck```类**保护继承**```Vehicle```，增加数据成员载重量```payload```；
4. ```Van```类**公有继承**```Vehicle```，增加数据成员载人数```passenger_load```。每个类都有相关数据的输入输出方法。
5. 编写主函数测试，并尝试在各派生类中访问基类各访问权限的成员，尝试通过派生类对象访问基类各访问权限的成员

# basic.cpp 要求
1. 定义一个Object类，有数据成员weight，无参和有参构造函数、析构函数和拷贝构造函数。由此派生出Box类，增加数据成员height和width，构造函数、析构函数和拷贝构造函数
2. 声明一个Box对象，观察构造函数与析构函数的调用顺序。
3. 尝试通过子类BOX分别调用Object类的无参与有参构造函数
4. 如果Box类有如下构造函数
```cpp
    Box()
    {
        cout<<"box born with nothing"<<endl;
    }
```
删除Object类的无参构造函数，观察结果
5. 删除Box类的拷贝构造函数，观察构造函数调用情况变化

# geo.cpp
1. 定义一个基类```Shape```，在此基础上派生出```Rectangle```和```Circle```，二者都有```getArea()```函数计算对象的面积并输出。
2. 尝试```getArea```为普通成员函数（上机5基础）
3. 尝试```getArea```为虚函数（上机5附加，上机6基础）
4. 尝试```getArea```为纯虚函数（上机5附加，上机6基础）
5. 编程一下```main```函数测试：
```cpp
    int main()
    {
        Shape * p;
        Shape s;
        Rectangle r(4,5);
        Circle c(2);
        
        p = &s;
        p->getArea();
        p = &r;
        p->getArea();
        p = &c;
        p->getArea();
    }
```
# access.cpp 要求

编写程序 `access.cpp`：

## 要求

1. 定义一个基类 `Appliance`，有数据成员：
   - `brand`（私有，整型，表示品牌编号）
   - `power`（保护，整型，表示功率）

2. 为基类 `Appliance` 定义下列成员函数：
   - `setBrand(int)`
   - `getBrand()`
   - `setPower(int)`
   - `getPower()`

3. 由 `Appliance` 派生出两个类：
   - `Fan`，采用 **private 继承**
   - `AirConditioner`，采用 **protected 继承**

4. 在两个派生类中分别增加自己的数据成员：
   - `Fan` 增加 `speed`
   - `AirConditioner` 增加 `temperature`

5. 在两个派生类中分别定义构造函数，对继承来的成员和新增成员进行初始化。

6. 在两个派生类中分别编写一个 `show()` 成员函数，要求在函数中：
   - 输出本类新增数据成员的值
   - 直接访问并输出基类中的 `power`
   - 通过基类成员函数访问并输出 `brand`
   - 尝试说明为什么不能直接访问基类中的 `brand`

7. 在 `main()` 函数中定义 `Fan` 和 `AirConditioner` 对象并调用 `show()` 函数进行测试。

8. 尝试在 `main()` 函数中直接通过对象调用继承来的 `getBrand()`，观察并说明结果。

## 目的

通过本题掌握：

- `private` 继承和 `protected` 继承的写法
- 基类 `public / protected / private` 成员在派生类中的访问情况
- 为什么派生类内部可以调用某些基类成员函数，而类外却不能直接通过对象调用