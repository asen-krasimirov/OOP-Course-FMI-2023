#pragma once

const unsigned NAME_MAX_SIZE = 65;
const unsigned CONTENT_MAX_SIZE = 513;
const unsigned ACCESS_RIGHTS_SIZE = 10;

enum class Role {
    user,
    group,
    other
};

enum class Mode {
    read,
    write,
    execute
};

enum class SortOptions {
    name,
    createdTime,
    modifiedTime,
    size
};
