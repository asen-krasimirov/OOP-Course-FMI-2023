#pragma once

#include "constants.h"
#include "DateTime.h"

class File {
private:
    char _name[NAME_MAX_SIZE];
    char _content[CONTENT_MAX_SIZE] = "";
    char _accessRights[ACCESS_RIGHTS_SIZE] = "---------";

    DateTime _createdTime;
    DateTime _modifiedTime;

    unsigned _contentSize = 0;

public:
    File();
    File(const char *name,
         unsigned hours, unsigned mins, unsigned secs,
         unsigned day, unsigned month, unsigned year,
         const char *accessRights);

    void setName(const char *name);
    void setContent(const char *content);
    void setContentSize(unsigned size);
    void setAccessRights(const char *accessRights);
    void setCreatedTime(unsigned hours, unsigned mins, unsigned secs, unsigned day, unsigned month, unsigned year);
    void setModifiedTime(unsigned hours, unsigned mins, unsigned secs, unsigned day, unsigned month, unsigned year);

    const char *getName() const;
    const char *getContent() const;
    const unsigned getContentSize() const;
    const DateTime &getCreatedTime() const;
    const DateTime &getModifiedTime() const;

    bool canRoleUseFile(Role role, Mode mode) const;

    void changeRoleRights(Role role, Mode mode);

    void printMetaInfo() const;

private:
    bool canUseFile(Mode mode, const char* accessRights) const;
};