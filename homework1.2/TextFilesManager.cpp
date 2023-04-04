#include <cstring>

#include "utils.h"
#include "TextFilesManager.h"

namespace {
    void swap(File &file1, File &file2) {
        File temp = file1;
        file1 = file2;
        file2 = temp;
    }

    int compareNames(File &file1, File &file2) {
        return std::strcmp(file1.getName(), file2.getName());
    }

    int compareCreatedTimes(File &file1, File &file2) {
        return file1.getCreatedTime().compare(file2.getCreatedTime());
    }

    int compareModifiedTimes(File &file1, File &file2) {
        return file1.getModifiedTime().compare(file2.getModifiedTime());
    }

    int compareSizes(File &file1, File &file2) {
        if (file1.getContentSize() > file2.getContentSize()){
            return 1;
        }
        else if (file1.getContentSize() < file2.getContentSize()) {
            return -1;
        }
        else {
            return 0;
        }
    }
}

void TextFilesManager::copyFiles(const File *newFiles, unsigned int newMaxFileCount) {
    _files = new File[newMaxFileCount];
    for (int i = 0; i < newMaxFileCount; ++i) {
        _files[i] = newFiles[i];
    }

    _maxFileCount = newMaxFileCount;
}

void TextFilesManager::copyFrom(const TextFilesManager &other) {
    copyFiles(other._files, other._maxFileCount);
    _fileCount = other._fileCount;
}

void TextFilesManager::free() {
    delete[] _files;
    _files = nullptr;
    _fileCount = 0;
}

TextFilesManager::TextFilesManager(const File *files, unsigned maxFileCount) {
    setMaxFileCount(maxFileCount);
    setFiles(files, maxFileCount);
}

TextFilesManager::TextFilesManager(unsigned maxFileCount) : TextFilesManager(new File[maxFileCount], maxFileCount) {}

TextFilesManager::TextFilesManager() : TextFilesManager(1) {}

TextFilesManager::TextFilesManager(const TextFilesManager &other) {
    copyFrom(other);
}

TextFilesManager &TextFilesManager::operator=(const TextFilesManager &other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }

    return *this;
}

TextFilesManager::~TextFilesManager() {
    free();
}

void TextFilesManager::setFiles(const File *files, unsigned maxFileCount) {
    if (!maxFileCount) {
        throw "MaxFileCount value is not valid!";
    }

    delete[] _files;
    copyFiles(files, maxFileCount);
}

void TextFilesManager::setMaxFileCount(unsigned int maxFileCount) {
    _maxFileCount = maxFileCount;
}

File &TextFilesManager::findFileByName(const char *name) {
    for (int i = 0; i < _fileCount; ++i) {
        if (std::strcmp(_files[i].getName(), name) == 0) {
            return _files[i];
        }
    }

    throw "File was not found!";
}

void TextFilesManager::addFile(const char *name,
                               unsigned int hours, unsigned int mins, unsigned int secs,
                               unsigned int day, unsigned int month, unsigned int year,
                               const char *accessRights) {
    if (_fileCount + 1 == _maxFileCount) {
        throw "Max amount of files was reached!";
    }

    File newFile(name, hours, mins, secs, day, month, year, accessRights);
    _files[_fileCount++] = newFile;
}

void TextFilesManager::setNewContentToFile(File &file, const char *newContent,
                                           unsigned int hours, unsigned int mins, unsigned int secs,
                                           unsigned int day, unsigned int month, unsigned int year) {

    file.setContent(newContent);
    file.setModifiedTime(hours, mins, secs, day, month, year);
}

void TextFilesManager::editFile(const char *name, const char *content,
                                unsigned int hours, unsigned int mins, unsigned int secs,
                                unsigned int day, unsigned int month, unsigned int year,
                                Role role) {
    File& file = findFileByName(name);

    if (!file.canRoleUseFile(role, Mode::write)) {
        throw "Error! You do not have the rights to edit!";
    }

    setNewContentToFile(file, content, hours, mins, secs, day, month, year);
}

void TextFilesManager::addInFile(const char *name, char *content, unsigned int hours, unsigned int mins,
                                 unsigned int secs, unsigned int day, unsigned int month, unsigned int year,
                                 Role role) {
    File& file = findFileByName(name);

    if (!file.canRoleUseFile(role, Mode::write)) {
        throw "Error! You do not have the rights to add to this file!";
    }

    mergeArrays(content, getArrLen(content),  file.getContent());

    setNewContentToFile(file, content, hours, mins, secs, day, month, year);
}

void TextFilesManager::deleteFile(const char *name) {
    File& file = findFileByName(name);
    file = _files[_fileCount - 1];
    _fileCount--;
}

void TextFilesManager::changeRights(const char *name, Role role, Mode mode) {
    File& file = findFileByName(name);
    file.changeRoleRights(role, mode);
}

void TextFilesManager::printFileInfo(const char *name) {
    File& file = findFileByName(name);
    file.printMetaInfo();
}

void TextFilesManager::printFile(const char *name, Role role) {
    File& file = findFileByName(name);

    if (!file.canRoleUseFile(role, Mode::read)) {
        throw "Error! You do not have the rights to read!";
    }

    std::cout << file.getContent();
}

void TextFilesManager::print() {
    for (int i = 0; i < _fileCount; ++i) {
        std::cout << _files[i].getName() << std::endl;
    }
}

void TextFilesManager::sortByOption(int (*sortFunc)(File&, File&)) {
    for (unsigned i = 0; i < _fileCount - 1; i++) {
        unsigned minIndex = i;

        for (unsigned j = i + 1; j < _fileCount; j++) {
            if (sortFunc(_files[minIndex], _files[j]) > 0) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            swap(_files[i], _files[minIndex]);
        }
    }
}

void TextFilesManager::sort(SortOptions option) {
    switch(option) {
        case SortOptions::name:
            sortByOption(compareNames);
            break;
        case SortOptions::createdTime:
            sortByOption(compareCreatedTimes);
            break;
        case SortOptions::modifiedTime:
            sortByOption(compareModifiedTimes);
            break;
        case SortOptions::size:
            sortByOption(compareSizes);
            break;
        default:
            throw "Option is not available!";
    }
}
