#include "ProgramController.h"

ProgramController::ProgramController() {
    std::cout << "Enter beginning of set:" << std::endl;
    std::cin >> _start;
    std::cout << "Enter end of set:" << std::endl;
    std::cin >> _end;
    if (_start > _end) {
        std::cout << "End should be longer then start!" << std::endl;
        throw std::invalid_argument("End should be longer then start!");
    }

}

int32_t ProgramController::getNextNumber() const {

}
