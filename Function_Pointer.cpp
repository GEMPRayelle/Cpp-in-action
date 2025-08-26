#include <iostream>
#include <array>
#include <functional>

void func(int x) { std::cout << x << std::endl; }

int IncFunc(int x) { return x; }

bool isEven(const int &number)
{
    if (number % 2 == 0)
        return true;
}
bool isOdd(const int &number)
{
    if (number % 2 == 1)
        return true;
}

// check_func의 디폴트 값을 isEven으로 두면 다른 함수를 대입하는게 아닌 이상짝수인 원소만 출력하도록 함
void PrintNumber(const std::array<int, 10> &_array, bool (*check_func)(const int &))
{
    for (int element : _array)
    {
        // 매개변수로 넘겨받은 함수 이름에 element를 대입
        // check_func 함수 포인터는 bool을 리턴하고, 매개변수는 const int&여야 한다
        if (check_func(element) == true)
            std::cout << element;
    }
    std::cout << std::endl;
}

int main()
{
    // func함수의 주소 출력
    std::cout << func << std::endl;

    // 배열의 이름이 배열의 주소를 가지듯이
    // 함수의 이름도 함수의 주소를 가진다
    void (*funcptr)(int) = func;

    /*==================*/
    /* [함수 포인터 정의] */
    /*==================*/

    // int: 함수의 리턴 타입
    //(*incptr): 함수 포인터의 이름
    //(int): 함수의 매개변수 타입, 없으면 ()
    // IncFunc: 초기화할 함수 주소
    int (*incfuncptr)(int) = IncFunc;

    // func함수의 주소와 동일한 주소값 출력
    std::cout << funcptr << std::endl;

    /*======================*/
    /* [함수 포인터 사용 방법] */
    /*======================*/
    // IncFunc함수의 주소를 가지고 있는 포인터 incptr로 IncFunc 함수를 사용할 수 있음
    std::cout << incfuncptr(5) << std::endl; // 5출력

    // 함수 포인터에 다른 함수를 대입하려면 리턴 타입, 매개변수 타입, 매개변수 개수가 모두 일치해야함

    /*==================*/
    /* [함수 포인터 활용] */
    /*==================*/
    std::array<int, 10> my_array{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    // 함수 자체를 매개변수로 넘김
    PrintNumber(my_array, isEven); // 짝수만 출력
    PrintNumber(my_array, isOdd);  // 홀수만 출력

    /*===================*/
    /* [최신 기능 C++ 11] */
    /*===================*/
    // #include <functional>
    // std::function <리턴 타입(매개변수)>
    std::function<bool(const int &)> boolptr = isEven;
    // boolptr = bool을 리턴하고 const int& 타입의 매개변수를 받는 함수의 주소를 담을 수 있는 포인터 변수

    // 사실 std::function은 함수 포인터뿐만 아니라 Callable 모두를 보관할 수 있는 객체임
    // Callable : https://modoocode.com/254
}