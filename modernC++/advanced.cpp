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
	return 0;
}