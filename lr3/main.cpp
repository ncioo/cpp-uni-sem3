#include <iostream>
#include <string>
#include "vector"

using namespace std;

#include "firma.cpp"

void Error(string message)
{
    cout << "[!] - " << message << endl;
};

int main()
{
    cout << "Лабораторная #3 | Вариант 19" << endl;

    const int MAX_EMPLOYEES = 20;
    vector<Firma *> employees;

    int totalEmployees = 0, action;

    while (true)
    {
        cout << endl;
        cout << "[?] - Выберите действие:"
             << "\n  1. Просмотр текущего списка"
             << "\n  2. Создание объектов"
             << "\n  3. Удаление объекта"
             << "\n  4. Выход"
             << endl;
        cout << ">> ";
        cin >> action;

        system("cls");
        switch (action)
        {
        case 1:
            if (totalEmployees == 0)
            {
                Error("Список пустой");
                break;
            }

            for (int i = 0; i <= totalEmployees - 1; i++)
            {
                cout << i + 1 << ". -====-" << endl;
                employees[i]->displayInfo();
            }

            break;
        case 2:
            int numOfObjects;

            cout << "[?] - Введите количество создаваемых объектов"
                 << " (доступно: " << MAX_EMPLOYEES - totalEmployees << "/" << MAX_EMPLOYEES << ")" << endl;
            cout << ">> ";
            cin >> numOfObjects;

            if (totalEmployees + numOfObjects > MAX_EMPLOYEES)
            {
                Error("Достигнут лимит количества сотрудников");
                break;
            }

            for (int i = 1; i <= numOfObjects; i++)
            {
                string fio;
                int tabNumber;
                double hoursWorked;
                double hourlyRate;

                cout << "[?] - Введите ФИО: " << endl;
                cout << ">> ";
                cin.ignore();
                getline(cin, fio);

                cout << "[?] - Введите табельный номер: " << endl;
                cout << ">> ";
                cin >> tabNumber;
                cout << "[?] - Введите отработанные часы: " << endl;
                cout << ">> ";
                cin >> hoursWorked;
                cout << "[?] - Введите почасовой тариф: " << endl;
                cout << ">> ";
                cin >> hourlyRate;

                employees.push_back(new Firma(fio, tabNumber, hoursWorked, hourlyRate));
                totalEmployees++;
            }

            break;
        case 3:
            int objectIndex;

            cout << "[?] - Порядковый номер: " << endl;
            cout << ">> ";
            cin >> objectIndex;

            if (objectIndex < 0 || objectIndex > employees.size())
            {
                Error("Введен неверный номер");
                break;
            }

            cout << "[!] - Удаленный объект: " << endl;
            employees[objectIndex - 1]->displayInfo();

            delete employees[objectIndex - 1];
            employees.erase(employees.begin() + (objectIndex - 1));
            totalEmployees--;

            break;
        default:
            if (totalEmployees > 0)
                for (int i = 0; i <= totalEmployees - 1; i++)
                {
                    delete employees[i];
                }

            return 0;
        }
    }
}
