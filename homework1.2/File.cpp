#include <cstring>

#include "utils.h"
#include "File.h"

void mergeArrays(char *arr1, unsigned size1, const char *arr2) {
    for (int i = 0; arr2[i] != '\0'; ++i) {
        arr1[size1 + i] = arr2[i];
    }
}


File::File(const char *name,
           unsigned hours, unsigned mins, unsigned secs,
           unsigned day, unsigned month, unsigned year,
           const char *accessRights) {
    setName(name);
    setCreatedTime(hours, mins, secs, day, month, year);
    setModifiedTime(hours, mins, secs, day, month, year);
    setAccessRights(accessRights);
}

File::File() : File("blank.txt", 0, 0, 0, 1, 1, 1, "---------") {}

void File::setName(const char *name) {
    if (name == nullptr) {
        throw "Name value is not valid!";
    }

    std::strcpy(_name, name);
}

void File::setContent(const char *content) {
    unsigned newContentSize = getArrLen(content);

    if (content == nullptr) {
        throw "Content value is not valid!";
    }
    if (newContentSize > CONTENT_MAX_SIZE) {
        throw "Content exceeds maximum allowed size!";
    }

    std::strcpy(_content, content);
    setContentSize(newContentSize);
}

void File::addContent(const char *content) {
    unsigned newContentSize = getArrLen(content) + _contentSize;

    if (content == nullptr) {
        throw "Content value is not valid!";
    }
    if (newContentSize > CONTENT_MAX_SIZE) {
        throw "Content exceeds maximum allowed size!";
    }

    mergeArrays(_content, _contentSize, content);
    setContentSize(newContentSize);
}

void File::setContentSize(unsigned size) {
    _contentSize = size;
}

void File::setAccessRights(const char *accessRights) {
    if (accessRights == nullptr) {
        throw "AccessRights value is not valid!";
    }

    std::strcpy(_accessRights, accessRights);
}

void File::setCreatedTime(unsigned hours, unsigned mins, unsigned secs,
                          unsigned int day, unsigned int month, unsigned int year) {

    _createdTime.changeTime(hours, mins, secs);
    _createdTime.changeDate(day, month, year);
};

void File::setModifiedTime(unsigned int hours, unsigned int mins, unsigned int secs,
                           unsigned int day, unsigned int month, unsigned int year) {
    _modifiedTime.changeTime(hours, mins, secs);
    _modifiedTime.changeDate(day, month, year);
}

const char *File::getName() const {
    return _name;
}

const char *File::getContent() const {
    return _content;
}

const unsigned File::getContentSize() const {
    return _contentSize;
}

const DateTime &File::getCreatedTime() const {
    return _createdTime;
}

const DateTime &File::getModifiedTime() const {
    return _modifiedTime;
}

bool File::canUseFile(Mode mode, const char* accessRights) const {
    switch (mode) {
        case Mode::read:
            return accessRights[0] != '-';
        case Mode::write:
            return accessRights[1] != '-';
        case Mode::execute:
            return accessRights[2] != '-';
        default:
            throw "Mode value is not valid!";
    }
}

bool File::canRoleUseFile(Role role, Mode mode) const {
    char accesRights[4];

    switch (role) {
        case Role::user:
            accesRights[0] = _accessRights[0];
            accesRights[1] = _accessRights[1];
            accesRights[2] = _accessRights[2];
            break;
        case Role::group:
            accesRights[0] = _accessRights[3];
            accesRights[1] = _accessRights[4];
            accesRights[2] = _accessRights[5];
            break;
        case Role::other:
            accesRights[0] = _accessRights[6];
            accesRights[1] = _accessRights[7];
            accesRights[2] = _accessRights[8];
            break;
        default:
            throw "Role value is not valid!";
    }

    return canUseFile(mode, accesRights);
}

void File::changeRoleRights(Role role, Mode mode) {
    bool hasAccess = canRoleUseFile(role, mode);

    switch (role) {
        case Role::user:
            if (mode == Mode::read) {
                _accessRights[0] = hasAccess ? '-' : 'r';
            }
            else if (mode == Mode::write) {
                _accessRights[1] = hasAccess ? '-' : 'w';
            }
            else if (mode == Mode::execute) {
                _accessRights[2] = hasAccess ? '-' : 'x';
            }
            break;
        case Role::group:
            if (mode == Mode::read) {
                _accessRights[3] = hasAccess ? '-' : 'r';
            }
            else if (mode == Mode::write) {
                _accessRights[4] = hasAccess ? '-' : 'w';
            }
            else if (mode == Mode::execute) {
                _accessRights[5] = hasAccess ? '-' : 'x';
            }
            break;
        case Role::other:
            if (mode == Mode::read) {
                _accessRights[6] = hasAccess ? '-' : 'r';
            }
            else if (mode == Mode::write) {
                _accessRights[7] = hasAccess ? '-' : 'w';
            }
            else if (mode == Mode::execute) {
                _accessRights[8] = hasAccess ? '-' : 'x';
            }
            break;
        default:
            throw "Role value is not valid!";
    }
}

void File::printMetaInfo() const {
    std::cout << "Name: " << _name << std::endl;
    std::cout << "Size: " << _contentSize << std::endl;

    std::cout << "Created on: ";
    _createdTime.printData();

    std::cout << "Last modified on: ";
    _modifiedTime.printData();

    std::cout << "Rights: " << _accessRights << std::endl;
}
