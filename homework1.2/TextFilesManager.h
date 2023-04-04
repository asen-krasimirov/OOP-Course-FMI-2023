#include "File.h"

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

    void addInFile(const char *name, char *content,
                   unsigned hours, unsigned mins, unsigned secs,
                   unsigned day, unsigned month, unsigned year,
                   Role rights);

    void deleteFile(const char *name);

    void changeRights(const char *name, Role role, Mode mode);

    void printFileInfo(const char *name);

    void printFile(const char *name, Role role);

    void print();

    void sort(SortOptions option);

private:
    File &findFileByName(const char *name);

    void setNewContentToFile(File &file, const char *newContent,
                             unsigned int hours, unsigned int mins, unsigned int secs,
                             unsigned int day, unsigned int month, unsigned int year);

    void sortByOption(int (*sortFunc)(File&, File&));
};
