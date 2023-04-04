
class Game {
private:
    bool isAvailable;
    char* title;
    double price;
public:
    Game();

    bool getIsAvailable() const;
    char* getTitle() const;
    double getPrice() const;

    void setIsAvailable(bool isAvailable);
    void setTitle(const char* title);
    void setPrice();

};