#include<iostream>
using namespace std;

// Dziedziczenie, Polimorfizm

// 1 - konstruktor klasy nadrzędnej wykonywany jest jako pierwszy, a dopiero potem konstruktor klasy dziedziczacej
// 2 - destruktor - na odwrot. Najpierw klasy dziedziczacej a potem nadrzednej
// 3 - Urzywajac wskaznika klasy nadrzednej i majac 2 funkcje o takiej samej nazwie (ale nie virtual) wykonana zostanie metoda klasy podstawowej.
// 4 - Klasa dziedziczaca moze nadpisac metody virtual klasy podstawowej, ale nie musi
// 5 - Klasa dziedziczaca MUSI nadpisac metody czysto wirtualne (=0)
// 6 - w jezyku c++ mozna dziedziczyc po wielu klasach, dlatego nie ma odpowiednika "super" jak w Javie. Do metod klasy nadrzednej mozna sie dostac poprzez: derived.base::metoda();
// 7 - w przypadku poliformizmu nalezy ustawiac destruktor klasy nadrzednej jako wirtualny! W przeciwinym wypadku uzywacac wskaznika klasy nadrzednej (polimorfizm) uzyty zostanie jedynie destruktor klasy nadrzenej
// 8 - dla czytelności kodu można stosowac klauzule override
// 9 - mozna zabronic dziedziczenia po danej klasie, lub naspidania metody klauzula final

class base
{
public:
    base() {cout << "base-constructor " << this << endl;}
    virtual ~base() {cout << "base-destructor " << this << endl;}
    void fun_1() { cout << "base-1\n"; }
    virtual void fun_2() { cout << "base-2\n"; }
    virtual void fun_3() { cout << "base-3\n"; }
    virtual void fun_4() { cout << "base-4\n"; }
    virtual void fun_5()=0;                      // Utworzenie klasy abstrakcyjnej
    virtual void fun_6() final { cout << "base-6\n"; }
};

// class derived final : public base            // nextLevelDerived nie moglby dziediczyc po derived
class derived : public base
{
public:
    derived() {cout << "derived-constructor " << this << endl;}
    ~derived() {cout << "derived-destructor " << this << endl;}
    void fun_1() { cout << "derived-1\n"; }
    void fun_2() override { cout << "derived-2\n"; }
    void fun_4(int x) { cout << "derived-4\n"; }
    void fun_5() override { cout << "derived-5\n"; };                 // Metoda musi zostac nadpisana w klasie dziedziczacej
//    void fun_6() override { cout << "derived-6\n"; }                // Error - metoda w klasie based ustawiona jako final
};

class nextLevelDerived : public derived
{

};

int main()
{
    //base bo1;                                   //Przy klasie abstrakcyjnej wyswietlony bylby error;

    derived obj1;
    base *p = &obj1;

    //base *p = new derived();                      // Patrz: delete p;

    p->fun_1();                                    // Wywolana zostanie funkcja klasy base - wskaznik jest typu base a metoda nie jest wirtualna
    p->fun_2();                                     // Wywolana metoda klasy derived - nadpisana
    p->fun_3();                                     // Wywolana zostanie funkcja klasy base - klasa derived nie nadpisala metody fun_3()
    p->fun_4();                                     // JW. Klasa derived zrobila osobna metode
    p->fun_5();                                     // Wywolana metoda klasy derived - dla klasy based jest to metoda czysto wirtualna
    p->fun_6();

    //delete p;                                       //Dzieki ustawieniu destruktora klasy base jako virtual wykonywane sa oba destruktory a nie jedynie base!

    cout << "+++++++++++++++++++++++++++" << endl;

    obj1.fun_1();
    obj1.fun_2();
    obj1.fun_3();
    //obj1.fun_4();                                 // Funckja z klasy base nie dziala. Wyswietla sie error ze nalezy uzyc funkcji fun_4(int x);
    obj1.base::fun_4();                             // W ten sposob tez mozna wywolac metode z klasy po ktorej sie dziediczy.

    cout << "+++++++++++++++++++++++++++" << endl;

    nextLevelDerived obj2;
    obj2.base::fun_2();

}
