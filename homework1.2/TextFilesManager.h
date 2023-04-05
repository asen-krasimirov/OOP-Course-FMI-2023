#include "File.h"

namespace {
    void mergeArrays(char *arr1, unsigned size1, const char *arr2) {
        for (int i = 0; arr2[i] != '\0'; ++i) {
            arr1[size1 + i] = arr2[i];
        }
    }
}

class TextFilesManager {
private:
    File *_files = nullptr;
    unsigned _fileCount = 0;
    unsigned _maxFileCount;

    void copyFiles(const File *files, unsigned maxFileCount);

    void copyFrom(const TextFilesManager &other);
    void free();

public:
    TextFilesManager();

    explicit TextFilesManager(unsigned maxFileCount);

    explicit TextFilesManager(const File *files, unsigned maxFileCount);

    TextFilesManager(const TextFilesManager &other);

    TextFilesManager &operator=(const TextFilesManager &other);

    ~TextFilesManager();

    void setFiles(const File *files, unsigned fileCount);

    void setMaxFileCount(unsigned maxFileCount);

    void addFile(const char *name,
                 unsigned hours, unsigned mins, unsigned secs,
                 unsigned day, unsigned month, unsigned year,
                 const char *accessRights);

    void editFile(const char *name, const char *content,
                  unsigned hours, unsigned mins, unsigned secs,
                  unsigned day, unsigned month, unsigned year,
                  Role rights);

    void addInFile(const char *name, const char *content,
                   unsigned hours, unsigned mins, unsigned secs,
                   unsigned day, unsigned month, unsigned year,
                   Role rights);

    void deleteFile(const char *name);

    void changeRights(const char *name, Role role, Mode mode);

    void printFileInfo(const char *name) const;

    void printFile(const char *name, Role role) const;

    void print() const;

    void sort(SortOptions option);

private:
    File &findFileByName(const char *name);
    const File &findFileByName(const char *name) const;

    void setNewContentToFile(File &file, const char *newContent,
                             unsigned int hours, unsigned int mins, unsigned int secs,
                             unsigned int day, unsigned int month, unsigned int year);

    void sortByOption(int (*sortFunc)(File&, File&));
};
