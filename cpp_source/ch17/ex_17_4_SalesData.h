#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <iostream>


class Sales_data
{
    // friends
    friend Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs);

    friend std::ostream&
    operator << (std::ostream& os, const Sales_data& s);

    friend std::istream&
    operator >> (std::istream& is, Sales_data& s);

    friend Sales_data add(const Sales_data&, const Sales_data&);
    friend std::ostream &print(std::ostream&, const Sales_data&);
    friend std::istream &read(std::istream&, Sales_data&);

public:
	// constructors
	Sales_data() = default;
	Sales_data(const std::string &s): bookNo(s) { }
	Sales_data(const std::string &s, unsigned n, double p):
	           bookNo(s), units_sold(n), revenue(p*n) { }
    Sales_data(const Sales_data &s ):
        bookNo(s.bookNo), units_sold(s.units_sold), revenue(s.revenue)
    { }

    Sales_data(Sales_data&& s):
        bookNo(s.bookNo), units_sold(s.units_sold), revenue(s.revenue)
    { }

    ~Sales_data(){ }
	Sales_data(std::istream &);

	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data&);

    // assignments
    Sales_data& operator  =(const Sales_data& rhs);
    Sales_data& operator  =(const std::string&  rhs);
    Sales_data& operator +=(const Sales_data& rhs);

    // conversion
    explicit operator std::string () const { return bookNo; }
    explicit operator double      () const { return revenue; }

	double avg_price() const;
private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};


// overloaded operators added 10.Jan.2014 for ex14.2
inline Sales_data
operator+(const Sales_data& lhs, const Sales_data& rhs)
{
    Sales_data sum = lhs;
    sum += rhs;

    return sum;
}

std::ostream&
operator << (std::ostream& os, const Sales_data& item);

std::istream&
operator >> (std::istream& is, Sales_data& s);

// nonmember Sales_data interface functions
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);

// used in future chapters
inline 
bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() < rhs.isbn();
}
#endif