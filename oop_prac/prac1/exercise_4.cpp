#include <iostream>

using namespace std;

struct Student {
    char name[30];
    unsigned facNum;
};

int getArrLen(const char arr[]) {

    int ctr = 0;
    for (int i = 0; arr[i] != '\0'; ++i) ctr++;

    return ctr;
}

void initStudent(Student& st) {
//    int nameLen = getArrLen(name);
//    if (nameLen < 0 || nameLen > 30) { }
//    char* name = new char[30];

    cout << "Name:\n";
    cin >> st.name;
    cout << "Faculty Number:\n";
    cin >> st.facNum;
}

int main() {
    /*
    Student st = { "Kolio", 10 };
    Student *pSt = &st;  // pointer (needs ->)
    const Student* pCSt = &st;
    Student* const cPSt = &st;
    const Student* const cpCSt = &st;
    Student& refSt = st;  // reference
    const Student& refCSt = st;
    */

//    (*pSt).name[0] = 'H';  // <=> pSt->name
//    refCSt.name[0] = 'H';  // <=> pSt->name
//    pCSt->name[0] = 'H';  // <=> pSt->name

//    cout << refSt.name << '\n';
//    cout << st.facNum << '\n';

    //char arr[] = "Kolio";
    //cout << getArrLen(arr);

    Student st{};
    initStudent(st);

    cout << st.name << '\n';
    cout << st.facNum << '\n';

    return 0;
}
