#include <iostream>
#include <string>

class Creature
{
public:
    Creature() { std::cout << "Call Constructor" << std::endl; }

    /*====================*/
    /* [Copy Constructor] */
    /*====================*/
    // 복사 생성자가 정의되어있지 않으면 기본 복사 생성자를 디폴트로 사용한다
    // 일반 매개변수에 객체를 넘기면 Call by Value형태로 객체를 전달하게 된다
    // 매개변수인 creature 객체가 생성되면서 복사 하는 같은 타입의 대상이 있기에
    // 기본 복사 생성자가 호출된다 creature는 복사 없이 Creature 그 자체를 참조 한다(Call by Ref)
    //-> 즉 객체가 생성될때 같은 타입의 객체의 멤버를 복사하여 멤버를 초기화한다

    //[복사 생성자가 호출되는 순간]
    // 먼저 생성한 객체를 나중에 생성한 객체의 생성자 인자로 전달할 때
    // 함수의 인자로 객체를 Call by Value 형태로 전달할때
    // 객체를 Call by Value 형태로 리턴할때
    Creature(const Creature &creature)
    {
        this->_name = creature._name;
        std::cout << "Call Copy Constructor" << std::endl;
    }
    ~Creature() {}

    void Setter(std::string name) { this->_name = name; };
    //[Const OverLoading]
    std::string Getter() { return this->_name; };
    const std::string Getter() const { return this->_name; }; // const가 앞 뒤 붙이는 것도 가능
    const std::string CGetter() { return this->_name; }       // const가 앞에 붙는 것: 리턴을 변경 할 수 없는 상수로 하겠다
    std::string CGetter() const { return this->_name; }       // const가 뒤에 붙는 것: 멤버 값을 변경하지 않겠다

private:
    std::string _name;
};

void Print(Creature creature)
{
    std::cout << &creature << std::endl;         // 주소값 출력
    std::cout << creature.Getter() << std::endl; // 멤버변수 출력
}

int main()
{
    /*====================*/
    /* [객체 생성과 const] */
    /*====================*/
    const Creature creature;

    //[1]. Creature 클래스의 객체 creature의 멤버 변수의 값을 바꿀 수 없다
    //-> Setter 접근 함수의 사용이 불가능해짐
    creature.Setter("Rayelle"); // Compile Error

    //-> Getter 접근조차도 사용이 불가능해짐
    creature.Getter(); // Compile Error

    //->> 멤버를 바꾸지 않는 것을 확실히 하는 const 멤버 함수만 사용 가능하기 때문
    //->> 컴파일러는 멤버 값을 바꿨는가 아닌가로 판단하는 것이 아닌 멤버 함수가 const인가 아닌가로 판단함
    creature.CGetter(); // Not Compile Error

    // const가 붙은 객체는 const가 붙은 멤버 함수만 사용 가능하다
    // 당연히 일반 객체도 const 멤버 함수를 사용 할 수 있다
}