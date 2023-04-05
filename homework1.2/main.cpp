#include "constants.h"

#include "TextFilesManager.h"

int main() {

    Role u = Role::user;
    Role g = Role::group;
    Role o = Role::other;

    Mode r = Mode::read;
    Mode w = Mode::write;
    Mode x = Mode::execute;

    TextFilesManager fs(5);

    char inputName1[NAME_MAX_SIZE] = "test.txt";
    char inputAccessRights1[ACCESS_RIGHTS_SIZE] = "rwxr--r--";
    fs.addFile(inputName1, 14, 0, 0, 20, 3, 2023, inputAccessRights1);

    char inputContent1[CONTENT_MAX_SIZE] = "Hello, world!";
    fs.editFile(inputName1, inputContent1, 14, 10, 0, 20, 3, 2023, u);  // Hello world!
                                                                        // Last modified on: 14:10:00 20.03.2023

//    fs.editFile(inputName1, inputContent1, 14, 11, 0, 20, 3, 2023, o);  // Error! You do not have the rights to edit!

    const char inputContent2[CONTENT_MAX_SIZE] = "Hello, my friend!";
    fs.addInFile(inputName1, inputContent2, 14, 13, 0, 20, 3, 2023, u); // Hello world!
                                                                        // Hello, my friend!
                                                                        // Last modified on: 14:13:00 20.03.2023

    char inputContent3[CONTENT_MAX_SIZE] = "Hello";
    fs.editFile(inputName1, inputContent3, 14, 15, 0, 20, 3, 2023, u);  // Hello

    char inputName2[NAME_MAX_SIZE] = "attest.txt";
    fs.addFile(inputName2, 14, 30, 0, 20, 3, 2023, inputAccessRights1);
    fs.deleteFile(inputName2);

    fs.addFile("attest.txt", 14, 35, 0, 20, 3, 2023, inputAccessRights1);

    fs.changeRights(inputName2, u, w);  // r-xr--r--

    fs.changeRights(inputName2, u, w);  // rwxr--r--

    fs.changeRights(inputName2, u, r);  // -wxr--r--
//    fs.printFile(inputName2, u);        // Error! You do not have the rights to read!

    fs.printFile(inputName1, o);        // Hello


    fs.printFile(inputName2, o);        //

    fs.printFileInfo(inputName1);       // Name: test.txt
                                        // Size:  5
                                        // Created on: 14:00:00 20.03.2023
                                        // Last modified on: 14:15:00 20.03.2023
                                        // Rights: rwxr—r—

    fs.sort(SortOptions::name);
    fs.print();                         // attest.txt
                                        // test.txt


    fs.sort(SortOptions::modifiedTime);
    fs.print();                         // test.txt
                                        // attest.txt

    return 0;
}