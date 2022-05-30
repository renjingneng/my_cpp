#include <iostream>
using namespace std;


template<class... Args>
void print(Args&&... args)
{
    (cout << ... << args) << endl;
}

// 接收左值的函数 f()
template<typename T>
void f(T&)
{
	cout << "f(T &)" << endl;
}

// 接收右值的函数f()
template<typename T>
void f(T&&)
{
	cout << "f(T &&)" << endl;
}

// 万能引用，转发接收到的参数 param
template<typename T>
void PrintType(T&& param)
{
	f(std::forward<T>(param));  // 将参数param转发给函数 void f()
}


class Human {

public:
    string name;
    int age;
    Human(string name, int age);
    bool operator < (const Human& b) const { return this->name < b.name ? true : false; }
};
Human::Human(string name, int age) : name(name), age(age) {}


//if constexpr
//https://stackoverflow.com/questions/59053142/c-template-function-cant-convert-stdstring-to-double-in-return
template <typename T>
string convert(T input) {
    if constexpr (is_same_v<T, const char*> ||
        is_same_v<T, std::string>) {
        return input;
    }
    else {
        return to_string(input);
    }
}

/****
A nested-type object contains only the members defined inside the nested type. 
Similarly, an object of the enclosing class has only those members that are defined by the enclosing class. 
Enclosing class does not contain the data members of any nested classes.
****/
//unordered_set for user-defined class
class Point
{
public:

    Point() { }
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    struct HashFunction
    {
        size_t operator()(const Point& point) const
        {
            std::hash<int> intHasher;
            size_t xHash = intHasher(point.x);
            size_t yHash = intHasher(point.y) << 1;
            return xHash ^ yHash;
        }
    };
    bool operator==(const Point& otherPoint) const
    {
        if (this->x == otherPoint.x && this->y == otherPoint.y) return true;
        else return false;
    }

    int x;
    int y;
};



int main()
{
	// variadic templates in C++11 and fold expressions in C++17
    print(1, ':', " Hello", ',', " ", "World!");

	//https://zhuanlan.zhihu.com/p/50816420
	int a = 0;
	PrintType(a);//传入左值
	PrintType(int(0));//传入右值


	Human p1("Child", 5);
    Human p2("Grandfather", 70);
    Human p3("Older son", 20);
    Human p4("Father", 40);
    Human p5("Younger son", 10);
    if (p1 < p2) {
        cout << "p1 < p2" << endl;
    }
    else {
        cout << "p1 > p2" << endl;
    }
    
	//comparison
    priority_queue<Human> Q;
    Q.push(p1);
    Q.push(p2);
    Q.push(p3);
    Q.push(p4);
    Q.push(p5);
    while (!Q.empty()) {
        cout << "Name: " << Q.top().name << ", age: " << Q.top().age << endl;
        Q.pop();
    }

    //if constexpr
    cout<<convert(2)<<endl;
    cout<<convert("222") << endl;
    cout << convert(string("2222")) << endl;

    //unordered_set
    std::unordered_set<Point, Point::HashFunction> points;
    points.insert(Point(1, 1));
    points.insert(Point(2, 2));
    points.insert(Point(1, 1));   // notice this is a duplicate with the 1st point so it won't change the set
    std::cout << "points: " << "\n";
    for (auto& point : points)
    {
        std::cout << "(" << point.x << ", " << point.y << ")" << "\n";
    }
	return 0;
}