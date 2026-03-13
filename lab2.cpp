#include <iostream>
#include <cmath>
using namespace std;
class Numar_Complex {
    int real;
    double imaginar;
    public:
    Numar_Complex(int real, double imaginar) {
        this->real = real;
        this->imaginar = imaginar;
    }
    Numar_Complex(const Numar_Complex &num ) {
        this->real = num.real;
        this->imaginar = num.imaginar;
    }
    ~Numar_Complex() {
        this->real = 0;
        this->imaginar = 0;
    }
    void afisare() {
        if (real!=0) {
            if (imaginar!=0) {
                if (imaginar>0)
                cout<<real<<"+i"<<imaginar;
                else cout<<real<<"-i"<<imaginar;
            }
            else cout<<real;
        }
        else if (imaginar!=0) {
            if (imaginar>0)
                cout<<"i"<<imaginar;
            else cout<<"-i"<<imaginar;
        }
        else cout<<"0";
    }
    int modul() {
        int x;
        x=sqrt((real*real)+(imaginar*imaginar));
        return x;
    }
    Numar_Complex operator+(const Numar_Complex &aux){
        Numar_Complex f(1,1);
        f.real= aux.real + this->real;
        f.imaginar=aux.imaginar+this->imaginar;
    }
    Numar_Complex operator*(const Numar_Complex &aux) {
        Numar_Complex f(1,1);
        f.real=aux.real*this->real-this->imaginar*aux.imaginar;
        f.imaginar=aux.imaginar * this->real;
    }
    Numar_Complex operator/(const Numar_Complex &aux) {
        Numar_Complex f(1,1);
        f.real=(aux.real*this->real+this->imaginar*aux.imaginar)/(aux.real*aux.real+aux.imaginar*aux.imaginar);
        f.imaginar=(this->imaginar*aux.real-this->real*aux.imaginar)/(aux.real*aux.real+aux.imaginar*aux.imaginar);
    }
    int operator==(const Numar_Complex &aux) {
        Numar_Complex f(1,1);
        if (aux.real==this->real && aux.imaginar==this->imaginar)
            return 1;
        return 0;
    }
    int operator!=(const Numar_Complex &aux) {
        Numar_Complex f(1,1);
        if (aux.real!=this->real && aux.imaginar!=this->imaginar)
            return 1;
        return 0;
    }
    void conjugat() {
        this->imaginar=this->imaginar*(-1);
    }
    double operator[](int i)const {
        if (i==0) return this->real;
        if (i==1) return this->imaginar;
    }
    int rad() {
        int x = atan(this->imaginar/this->real);
        return x;
    }

};

int main() {
    Numar_Complex x(4,3), y(3,4);
    (x+y).afisare();

    return 0;
}