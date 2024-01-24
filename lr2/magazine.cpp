#include "magazine.h"

vector<string> availableTypes = {"Зарубежная литература", "На русском языке", "На белорусском языке"},
               availableCategories = {"Техника", "Наука", "Здоровье", "Кулинария", "Авто", "Детский", "Спорт", "Технологии"};

Magazine::Magazine(string _title) : title(_title){};

Magazine::~Magazine(){};

void Magazine::setInfo(int totalMagazines)
{
    int _publishYear, _number, _numberOfPages;

    cout << "[?] - Введите год издания: " << endl;
    cout << ">> ";
    cin >> _publishYear;

    cout << "[?] - Введите номер журнала: " << endl;
    cout << ">> ";
    cin >> _number;

    cout << "[?] - Введите количество страниц: " << endl;
    cout << ">> ";
    cin >> _numberOfPages;

    ID = totalMagazines + 1;
    publishYear = _publishYear;
    number = _number;
    numberOfPages = _numberOfPages;
}

void Magazine::print()
{
    cout << "ID: " << ID
         << "\nНазвание: " << title
         << "\nГод публикации: " << publishYear
         << "\nНомер: " << number
         << "\nКоличество страниц: " << numberOfPages << endl;
};

Type::Type(string _title, string _type, string _category)
    : Magazine(_title), type(_type), category(_category){};

Type::~Type(){};

void Type::print()
{
    cout << "ID: " << ID
         << "\nНазвание: " << title
         << "\nГод публикации: " << publishYear
         << "\nНомер: " << number
         << "\nКоличество страниц: " << numberOfPages << endl;
    cout << "Тематика: " << category
         << "\nТип: " << type << endl;
};

void displayByYear(Type *library[], int totalMagazines, int targetYear)
{
    int totalPages = 0;
    bool isExist = false;

    for (int i = 0; i < totalMagazines; i++)
    {
        Type *magazine = library[i];

        if (magazine->getPublishYear() == targetYear)
        {
            isExist = true;

            cout << i + 1 << ". -====-" << endl;
            magazine->print();

            totalPages += magazine->getNumberOfPages();
        }
    }

    if (!isExist)
    {
        cout << "[!] - За указаный период журналов не найдено" << endl;
    }
    else
    {
        cout << "Общее количество страниц: " << totalPages << endl;
    }
}