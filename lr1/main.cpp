#include <iostream>
#include <string>

using namespace std;

#include "firma.cpp"

void Error(string message)
{
    cout << "[!] - " << message << endl;
};

int main()
{
    cout << "Лабораторная #1 | Вариант 19" << endl;

    const int MAX_EMPLOYEES = 20;
    Firma *employees[MAX_EMPLOYEES];

    int totalEmployees = 0, action;

    while (true)
    {
        cout << endl;
        cout << "[?] - Выберите действие:"
             << "\n  1. Просмотр текущего списка"
             << "\n  2. Создание объектов"
             << "\n  3. Выход"
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

                employees[totalEmployees++] = new Firma(fio, tabNumber, hoursWorked, hourlyRate);
            }

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
};
