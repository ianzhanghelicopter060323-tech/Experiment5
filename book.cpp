#include <iostream>
using namespace std;


class Book
{
private:
    int pages;
protected:
    double price;
public:
    Book();
    Book(int pages_in, double price_in);
    Book(const Book &b);
    ~Book();

    double getPrice() const;
    int getPages() const; 

    void show() const;
};

Book::Book(): pages(0), price(0.0) {}
Book::Book(int pages_in, double price_in): pages(pages_in), price(price_in) {}
Book::Book(const Book &b):pages(b.pages), price(b.price) {}
Book::~Book() {}

double Book::getPrice() const 
{
    return price;
}
int Book::getPages() const
{
    return pages;
}

void Book::show() const
{
    cout << "price: " << price << endl;
    cout << "pages: " << pages << endl;
}


class TextBook : private Book
{
private:
    int subject;
public:
    TextBook();
    TextBook(int subject_in, int pages_in, double price_in);
    TextBook(const TextBook &txbk);
    ~TextBook();

    // redefine TextBook::show()
    void show() const;

    // redefine TextBook::getPrice()
    double getPrice() const;
};

TextBook::TextBook():Book(), subject(0) {}
TextBook::TextBook(int subject_in, int pages_in, double price_in): Book(pages_in, price_in), subject(subject_in) {}
TextBook::TextBook(const TextBook &txbk): Book(txbk), subject(txbk.subject) {}
TextBook::~TextBook() {}

// redefine TextBook::show()
void TextBook::show() const
{
    cout << "subject: " << subject << endl;
    // call Book::show()
    Book::show();
}
// redefine TextBook::getPrice()
double TextBook::getPrice() const
{
    return Book::getPrice();
}


int main()
{
    TextBook txbk(1001, 500, 250);
    
    cout << "price of the text book is: " << txbk.getPrice() << endl;
    txbk.show();

    return 0;
}