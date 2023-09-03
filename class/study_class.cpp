/*
 * 学习C++类
 * 钟焕
 * 2023年09月03日20:44:55
 */

#include <iostream>

class Student {
public:
    int getAge() {
        return age_;
    }

    void setAge(int age) {
        age_ = age;
        std::cout << "age = " << age << std::endl;
    }

    void printThisPointerAddress() {
        std::cout << "this指针里面存放的地址 = " << this << std::endl;
    }
    static void testStaticFuction() {
        std::cout << "static function属于类,而不是类实例的函数,直接通过类名调用" << std::endl;
    }

    virtual void funcVirtual() {
        std::cout << "类内有虚函数，会有一个虚函数指针指向虚函数表" << std::endl;
    }

private:
    int age_;
};

struct A {
    short a;
    char b;
    int c;
};

int main() {
    Student::testStaticFuction();
    std::cout << "sizeof(Student) = " << sizeof(Student) << std::endl; // this指针不占用class内存大小

    Student stu;
    std::cout << "sizeof(stu)  = " << sizeof(stu) << std::endl;
    stu.printThisPointerAddress(); // this指针是一个指向当前对象的指针
    std::cout << "student实例对象的地址 = " << &stu << std::endl;

    std::cout << sizeof(A) << std::endl;
    std::cout << sizeof(short) << std::endl;
    std::cout << sizeof(char) << std::endl;
    std::cout << sizeof(int) << std::endl;

    return 0;
}