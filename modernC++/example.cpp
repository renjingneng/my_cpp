#include <iostream>
#include <vector>
#include <functional>
#include <chrono>
#include <thread>

template<class... Args>
void print(Args&&... args)
{
	(std::cout << ... << args) << std::endl;
}

#define LOG_HELPER(...) \
	print(__VA_ARGS__);

#define LOG_DEBUG(...) LOG_HELPER("LOG_DEBUG",__FUNCTION__,__VA_ARGS__);

#define Sleep(_ms) std::this_thread::sleep_for(std::chrono::milliseconds(_ms));

template <typename T>
using func_template = T(T);//function signature
template <typename T>
using dyn_arr_data_template = std::vector<T>;
template <typename T>
using dyn_arr_func_template = std::vector<std::function<func_template<T>>>;


//must "unsigned long long int" for int
//https://docs.microsoft.com/en-us/cpp/cpp/user-defined-literals-cpp?view=msvc-170
constexpr unsigned long long int   operator"" _KB(unsigned long long int no)
{
	return no ;
}
constexpr unsigned long long int operator"" _MB(unsigned long long int no)
{
	return no * (1024_KB);
}


class MyResource
{
public:
	int num;
	MyResource(int num) :num(num) {
		std::cout << "MyResource-" << this->num << std::endl;
	}
	~MyResource() {
		std::cout << "~MyResource-" << this->num << std::endl;
	}
};


class MyClassResource
{
public:
	MyResource* resource;
	MyClassResource(int num)  {
		std::cout << "MyClassResource(int num) in-" << num << std::endl;
		resource = new MyResource(num);
		std::cout << "MyClassResource(int num) out-" << num << std::endl;
	}
	MyClassResource() {
		std::cout << "MyClassResource()"<< std::endl;
	}
	~MyClassResource() {
		std::cout << "~MyClassResource() in" << std::endl;
		if (resource) {
			int num = resource->num;
			std::cout << "delete resource in-" << num << std::endl;
			delete resource;
			resource = nullptr;
			std::cout << "delete resource out-" << num << std::endl;
		}
		std::cout << "~MyClassResource() out"<< std::endl;
	}
	void init_resource(int num) {
		std::cout << "init_resource(int num) in-" << num << std::endl;
		resource = new MyResource(num);
		std::cout << "init_resource(int num) out-" << num << std::endl;
	}
	void show_resource() {
		std::cout << "show_resource-" << resource->num << std::endl;
	}
};


class B {};
class D : public B {};
class X {};


struct demo
{
	 operator bool() { return true; } //define how Type Casting works for:   demo -> bool
};


int main()
{
	std::cout << "/****!!START!!****/" << std::endl;


	std::cout << "/****Digit separators****/" << std::endl;
	{
		int no = 1'000'000;
		long addr = 0x1000'EFFF;
		int binary = 0b0001'0010;
		std::cout << no << std::endl;
		std::cout << addr << std::endl;
		std::cout << binary << std::endl;
	}


	std::cout << "/****Type aliases****/" << std::endl;
	{
		std::cout << "dyn_arr_data_template" << std::endl;
		dyn_arr_data_template<int> nums;
		nums.push_back(1);
		nums.push_back(3);
		for (auto& i : nums)
		{
			std::cout << i << std::endl;
		}
		std::cout << "dyn_arr_func_template" << std::endl;
		dyn_arr_func_template<int> funcs;
		using namespace std::placeholders;
		auto func_temp = [](int x, int y)-> int {
			return x * 2 + y;
		};
		funcs.push_back(std::bind(func_temp, 2, _1));
		funcs.push_back(std::bind(func_temp, _1, 3));
		for (auto& func : funcs)
		{
			std::cout << func(5) << std::endl;
		}
	}
	

	std::cout << "/****Smart pointer****/" << std::endl;
	//resource acquisition is initialization (RAII) - custom
	{
		MyClassResource temp{ 1 };
		temp.show_resource();
	}
	//resource acquisition is initialization (RAII) - unique_ptr
	{
		std::unique_ptr<MyClassResource> temp = std::make_unique<MyClassResource>(2);
		temp->show_resource();
	}


	std::cout << "/****User-defined literals****/" << std::endl;
	{

		std::cout << 1_KB << std::endl;
		std::cout << 5_MB << std::endl;
	}

	std::cout << "/****Type Casting****/" << std::endl;

	{
		demo dd;
		if (dd) {  // implicit conversion
			std::cout << "dd" << std::endl;
		}
		bool b_d1 = dd;                       // implicit conversion
		bool b_d2 = static_cast<bool>(dd);    // explicit conversion


		//D->B X
		D* d = new D;
		B* b = static_cast<B*>(d); // this works
		//X* x = static_cast<X*>(d); // ERROR - Won't compile

		//dynamic_cast take advantage of RTTI(Run Time Type Identification) mechanism
		//http://www.vishalchovatiya.com/cpp-type-casting-with-example-for-c-developers/
	}

	std::cout << "/****others****/" << std::endl;
	Sleep(1000);
	LOG_DEBUG( "test2");
	std::cout << "/****!!END!!****/" << std::endl;
	return 0;
}