#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H
#include "disc_quote.h"

class Bulk_quote : public Disc_quote
{

public:
    Bulk_quote() { std::cout << "default constructing Bulk_quote\n"; }
    Bulk_quote(const std::string& b, double p, std::size_t q, double disc) :
        Disc_quote(b, p, q, disc) { std::cout << "Bulk_quote : constructor taking 4 parameters\n"; }

    // copy constructor
    Bulk_quote(const Bulk_quote& bq) : Disc_quote(bq)
    { std::cout << "Bulk_quote : copy constructor\n"; }

    // move constructor
    //page 535, " In a constructor, noexcept appears between the parameter list and the : that begins the constructor initializer list"
    Bulk_quote(Bulk_quote&& bq) noexcept : Disc_quote(std::move(bq))
    {
        std::cout << "Bulk_quote : move constructor\n";
    }

    // copy =()
    Bulk_quote& operator =(const Bulk_quote& rhs)
    {
        Disc_quote::operator =(rhs);
        std::cout << "Bulk_quote : copy =()\n";

        return *this;
    }


    // move =()
    Bulk_quote& operator =(Bulk_quote&& rhs) noexcept
    {
        Disc_quote::operator =(std::move(rhs));
        std::cout << "Bulk_quote : move =()\n";

        return *this;
    }

    double net_price(std::size_t n) const override;
    void  debug() const override;

    ~Bulk_quote() override
    {
        std::cout << "destructing Bulk_quote\n";
    }
};



#endif // BULK_QUOTE_H