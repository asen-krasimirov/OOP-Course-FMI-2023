#include <cstring>
#include "Game.h"

//Game::Game()

bool Game::getIsAvailable() const {
    return isAvailable;
}
char* Game::getTitle() const {
    return title;
}
double Game::getPrice() const {
    return price;
}

void Game::setIsAvailable(bool isAvailable) {
    this->isAvailable = isAvailable;
}

void myStrCpy(char*& dist, const char* source) {
    if (dist != nullptr) {
        delete[] dist;
    }


}

void Game::setTitle(const char* title) {
    // TODO: check if title or this->title is nullptr

    int len = strlen(title);
    this->title = new char[len + 1];
    strcpy(this->title, title);
    this->title[len] = '\0';
}
