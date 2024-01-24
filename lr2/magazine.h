class Magazine
{
protected:
    int ID;
    string title;
    int publishYear;
    int number;
    int numberOfPages;

public:
    Magazine(string _title);

    ~Magazine();

    void setInfo(int totalMagazines);

    virtual void print();
};

class Type : public Magazine
{
    friend void displayByYear(Type *magazines, int totalMagazines, int publishYear);

private:
    string category;
    string type;

public:
    Type(string _title, string _type, string _category);

    ~Type();

    void print() override;

    int getNumberOfPages()
    {
        return numberOfPages;
    }

    int getPublishYear()
    {
        return publishYear;
    }
};
