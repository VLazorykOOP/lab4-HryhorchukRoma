#pragma once
#include <map>
#include <string>
using namespace std;

class CountyList {
private:
    map<string, string> countries;
    string error_message;

public:
    CountyList() {}
    string operator[](string name) {
        if (countries.find(name) != countries.end()) {
            return countries[name];
        }
        else {
            error_message = "Country not found";
            return "index error";
        }
    }

    void operator()(string name, string capital) {
        countries[name] = capital;
    }

    void print() {
        cout << "Countries:\n";
        for (const auto& country : countries) {
            cout << country.first << ": " << country.second << endl;
        }
    }

    friend istream& operator>>(istream& in, CountyList& cl) {
        string name, capital;
        cout << "Enter country: ";
        in >> name;
        cout << "Enter capital: ";
        in >> capital;
        cl(name, capital);
        return in;
    };
    friend ostream& operator<<(ostream& out, CountyList& cl) {
        out << "Contacts:\n";
        for (const auto& country : cl.countries) {
            out << country.first << ": " << country.second << endl;
        }
        return out;
    }
};
