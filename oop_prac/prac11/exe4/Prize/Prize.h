
class Prize {
private:
    double _price = 0;
    unsigned _neededPoints = 0;

public:
    Prize() = default;
    Prize(double price, unsigned neededPoints) {
        _price = price;
        _neededPoints = neededPoints;
    }
    virtual ~Prize() = default;

    virtual void visualize() = 0;

};