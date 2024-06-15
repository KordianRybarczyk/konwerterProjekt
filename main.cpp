#include <iostream>


class temperature {
public:

    virtual double convertToCelsius(double value) const = 0;
    virtual double convertFromCelsius(double value) const = 0;
    virtual ~temperature() = default;
};


class Celsius : public temperature {
public:
    double convertToCelsius(double value) const override {
        return value;
    }

    double convertFromCelsius(double value) const override {
        return value;
    }
};


class Fahrenheit : public temperature {
public:
    double convertToCelsius(double value) const override {
        return (value - 32) * 5.0 / 9.0;
    }

    double convertFromCelsius(double value) const override {
        return (value * 9.0 / 5.0) + 32;
    }
};


class Kelvin : public temperature {
public:
    double convertToCelsius(double value) const override {
        return value - 273.15;
    }

    double convertFromCelsius(double value) const override {
        return value + 273.15;
    }
};

int main() {
    temperature *converters[3];
    converters[0] = new Celsius();
    converters[1] = new Fahrenheit();
    converters[2] = new Kelvin();

    int in, out;
    double tempIn, tempCelsius, tempOut;

    std::cout << "Wybierz jednostke wejsciowa:\n";
    std::cout << "1 - Celsius\n";
    std::cout << "2 - Fahrenheit\n";
    std::cout << "3 - Kelvin\n";
    std::cin >> in;

    std::cout << "Wybierz jednostke wyjściowa:\n";
    std::cout << "1 - Celsius\n";
    std::cout << "2 - Fahrenheit\n";
    std::cout << "3 - Kelvin\n";
    std::cin >> out;

    std::cout << "Podaj wartosc temperatury: ";
    std::cin >> tempIn;

    tempCelsius = converters[in - 1]->convertToCelsius(tempIn);
    tempOut = converters[out - 1]->convertFromCelsius(tempCelsius);

    std::cout << "Skonwertowana temperatura: " << tempOut << std::endl;

    for (int i = 0; i < 3; ++i) {
        delete converters[i];
    }

    return 0;
}