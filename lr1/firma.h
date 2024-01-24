class Firma
{
private:
    string fio;
    int tabNumber;
    double hoursWorked;
    double hourlyRate;

public:
    Firma(string _fio, int _tabNumber, double _hoursWorked, double _hourlyRate);

    ~Firma();

    void displayInfo();
};
