#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "magazine.cpp"

void Error(string message)
{
    cout << "[!] - " << message << endl;
};

int main()
{
    cout << "Лабораторная #2 | Вариант 19" << endl;

    const int MAX_MAGAZINES = 20;
    Type *library[MAX_MAGAZINES];

    int totalMagazines = 0, action;

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
            if (totalMagazines == 0)
            {
                Error("Список пустой");
                break;
            }

            int subAction;

            cout << "[?] - Выберите вид просмотра:"
                 << "\n  1. Просмотр всех журналов"
                 << "\n  2. Просмотр журналов за указанный период"
                 << endl;
            cout << ">> ";
            cin >> subAction;

            switch (subAction)
            {
            case 1:
                for (int i = 0; i <= totalMagazines - 1; i++)
                {
                    cout << i + 1 << ". -====-" << endl;
                    library[i]->print();
                }
                break;
            case 2:
                int targetYear;

                cout << "[?] - Введите интересующий год: " << endl;
                cout << ">> ";
                cin >> targetYear;

                displayByYear(library, totalMagazines, targetYear);
                break;
            default:
                break;
            }

            break;
        case 2:
            int numOfObjects;

            cout << "[?] - Введите количество создаваемых объектов (доступно: " << MAX_MAGAZINES - totalMagazines << "/" << MAX_MAGAZINES << ")"
                 << endl;
            cout << ">> ";
            cin >> numOfObjects;

            if (totalMagazines + numOfObjects > MAX_MAGAZINES)
            {
                Error("Достигнут лимит количества журналов");
                break;
            }

            for (int i = 1; i <= numOfObjects; i++)
            {
                string title;
                int typeIndex, categoryIndex;

                cout << "[?] - Введите название: " << endl;
                cout << ">> ";
                cin.ignore();
                getline(cin, title);

                cout << "[?] - Выберите тип из доступных: " << endl;
                for (int i = 0; i < availableTypes.size(); i++)
                {
                    cout << i + 1 << ". " << availableTypes[i] << endl;
                }
                cout << ">> ";
                cin >> typeIndex;
                typeIndex -= 1; //  Первый элемент массива под индексом 0, а пользователь видит его под индексом 1

                if (typeIndex < 0 || typeIndex > availableTypes.size())
                {
                    Error("Выбран неверный тип");
                    break;
                }

                cout << "[?] - Выберите категорию из доступных: " << endl;
                for (int i = 0; i < availableCategories.size(); i++)
                {
                    cout << i + 1 << ". " << availableCategories[i] << endl;
                }
                cout << ">> ";
                cin >> categoryIndex;
                categoryIndex -= 1; //  Первый элемент массива под индексом 0, а пользователь видит его под индексом 1

                if (categoryIndex < 0 || categoryIndex > availableCategories.size())
                {
                    Error("Выбрана неверная категория");
                    break;
                }

                Type *newMagazine = new Type(title, availableTypes[typeIndex], availableCategories[categoryIndex]);

                newMagazine->setInfo(totalMagazines);

                library[totalMagazines++] = newMagazine;
            }

            break;
        default:
            if (totalMagazines > 0)
                for (int i = 0; i <= totalMagazines - 1; i++)
                {
                    delete library[i];
                }

            return 0;
        }
    }
};
