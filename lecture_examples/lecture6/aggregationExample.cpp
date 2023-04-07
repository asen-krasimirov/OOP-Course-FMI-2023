#include <iostream>

struct Config {
    int setting1 = 0;
};

struct App {
    Config &config;

    void run() const {
        std::cout << config.setting1 << std::endl;
    }
};

int main() {
    Config config1{1};
    App app1{config1};
    {
        Config config2{2};
        app1.config = config2;
    }

    app1.run();

    return 0;
}
