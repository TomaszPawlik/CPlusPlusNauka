#include <iostream>

using namespace std;

//Static

// (1) Zmienna statyczna - raz zaimplementowana zostaje w pamiêci a¿ do koñca dzia³ania programu
// (2) Zmienna statyczna dla obiektu - jesli dzielona pomiêdzy wszystkie obiekty. Musi byæ zainicjowana poza cia³em klasy w natêpuj¹cy sposób: int MyClass::i = 1;
// (3) Statyczny obiekt - obiekt statyczny istnieje az do konca dzialania programu, niezaleznie od bloku w jakim byl zadeklarowany
// (4) Funkcja statyczna - mozna ja wywolac bez instancji danego obiektu. Meotdy statyczne maja dostep jedynie do innych metod i zmiennych statycznych

void demoStatic()
{
    static int count = 0;                                       // (1)
    cout << count << " ";
    count++;
}

class MyClass{

private:
    static int myClassCounter;                                  // (2)

    void incrementCounter(){myClassCounter++;}
    void nonStaticMethod(){cout << "Non static function";}

public:

    MyClass(){
        incrementCounter();
        cout << endl << "Constructor ..." << endl;
    }

    ~MyClass(){
        cout << endl << "Destructor ..." << endl;
    };

    static int getCounterValue() {                              // (4)
//        nonStaticMethod();                                    // (4) Nie mozna jej wywowlac. Meotdy statyczne maja dostep jedynie do innych metod i zmiennych statycznych
        return myClassCounter;
    }


};

int MyClass::myClassCounter=0;                                  // (2)

int main()
{
    for (int i=0; i<5; i++)
        demoStatic();                                               // (1)
    cout << endl << "++++++++++++++++++++++++++++++" << endl;

    MyClass mc1;
    {
        static MyClass mc2;                                     // (3) - gdyby obiekt nie by³ ustawiony jako static, destruktor bylby wywolany zaraz po zamknieciu bloku
    }
    //mc2.getCounterValue();                                    // Poomimo deklaracji static, obiekt nie jest widoczny
    std::cout << MyClass::getCounterValue();                    // (4)
}
