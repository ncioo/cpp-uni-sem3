#include "firma.h"

Firma::Firma(string _fio, int _tabNumber, double _hoursWorked, double _hourlyRate)
    : fio(_fio), tabNumber(_tabNumber), hoursWorked(_hoursWorked), hourlyRate(_hourlyRate){};

Firma::~Firma(){};

void Firma::displayInfo()
{
    int salary = hoursWorked * hourlyRate;

    if (hoursWorked > 144)
    {
        salary = 144 * hourlyRate + (hoursWorked - 144) * 2 * hourlyRate;
    }

    cout << "ФИО: " << fio
         << "\nТабельный номер: " << tabNumber
         << "\nОтработанные часы: " << hoursWorked
         << "\nПочасовой тариф: " << hourlyRate
         << "\nЗаработная плата: " << salary << endl;
};