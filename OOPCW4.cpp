
#include <iostream>

using namespace std;
#define random(a,b) a + rand() % (b - a + 1)
//создать класс машина(цвет,гос номер(уникальный),марка)

//создать класс парковка реализовать метод добавления машин и удаления по госномеру


const string carMark[] = { "Toyota", "Honda", "Ford", "Chevrolet", "Nissan", "BMW", "Mercedes-Benz", "Audi", "Volkswagen", "Hyundai" };
const string carColors[] = { "Red", "Blue", "Green", "Yellow", "Black" };
const char carAlpha[] = { 'А', 'В', 'Е', 'К', 'М', 'Н', 'О', 'Р', 'С', 'Т', 'У', 'Х' };

class Car {
    static string numberC;
    static int counterCar;
    string info;
    string mark;
    string colour;
    string number;
    //AA000A
public:
    Car() {

    }
    void upAlpha() {
        if (numberC[5] != 'Х') {
            for (int i = 0; i < 11; i++) {
                if (numberC[5] == carAlpha[i]) {
                    numberC[5] = carAlpha[i + 1];
                    break;
                }
            }
        }
        else if (numberC[1] != 'Х') {
            for (int i = 0; i < 11; i++) {
                if (numberC[1] == carAlpha[i]) {
                    numberC[1] = carAlpha[i + 1];
                    break;
                }
            }
        }
        else if (numberC[0] != 'Х') {
            for (int i = 0; i < 11; i++) {
                if (numberC[0] == carAlpha[i]) {
                    numberC[0] = carAlpha[i + 1];
                    break;
                }
            }
        }
        else cout << "MAX number" << endl;

    }

    void upCarNumbers() {
        if (numberC[4] == '9' && numberC[3] == '9' && numberC[2] == '9') {
            upAlpha();
            numberC[4] = '0';
            numberC[3] = '0';
            numberC[2] = '0';
        }
        else if (numberC[4] != '9') {
            numberC[4] ++;
        }
        else if(numberC[3]!='9') {
            numberC[4] = '0';
            numberC[3] ++;
        }
        else if (numberC[2] != '9') {
            numberC[3] = '0';
            numberC[2] ++;
        }


        


    }

    
    Car(string mark, string colour) {
        this->mark = mark;
        this->colour = colour;
        this->number = numberC;
        upCarNumbers();
        counterCar++;
    }
    string getNumber() {
        return number;
    }
    void operator=(Car& oldCar) {
        this->mark = oldCar.mark;
        this->colour = oldCar.colour;
        //this->number = oldCar.number;
        this->info = oldCar.info;
        this->number = numberC;
        //upCarNumbers();
        counterCar++;
    }
    void show() {
        cout << mark + " | " + colour + " | " + number + " | " + info << endl;
    }
};
string Car::numberC = "АА000А";
int Car::counterCar = 0;

class Park {
    Car* cars = nullptr;
    int counterCar = 0;
public:
    void addCar(Car& newCar) {
        Car* buf = new Car[counterCar + 1];
        for (int i = 0; i < counterCar; i++) {
            buf[i] = cars[i];
        }
        buf[counterCar] = newCar;
        counterCar++;
        delete[]cars;
        cars = buf;

    }
    int searchCar(string number) {
        for (int i = 0; i < counterCar; i++) {
            if (number == cars[i].getNumber()) {
                return i;
            }
        }
    }
    void deleteCar(string number) {
        int index = searchCar(number);
        if (index != -1) {
            Car* buf = new Car[counterCar - 1];
            for (int i = 0; i < index; i++) {
                buf[i] = cars[i];
            }
            for (int i = index + 1; i < counterCar; i++) {
                buf[i - 1] = cars[i];
            }
            counterCar--;
            delete[] cars;
            cars = buf;
        }
    }

    ~Park() {
        delete[]cars;
    }
    void showAll() {
        for (int i = 0; i < counterCar; i++) {
            cars[i].show();
            cout << "| index: " << i << endl;
        }
    }

    void dublicateCar(int index) {
        Car newCar = cars[index];
        addCar(newCar);
    }


};

void carGenerator(Park& park,int count) {
    for (int i = 0; i < count; i++) {
        string mark= carMark[random(0, 9)];
        string colour=carColors[random(0, 4)];
        Car bufCar(mark, colour);
        park.addCar(bufCar);
    }



}
int main() {
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    Park park1;
    carGenerator(park1,5);
    park1.showAll();

    park1.dublicateCar(2);
    cout << endl << endl;
    park1.showAll();

}