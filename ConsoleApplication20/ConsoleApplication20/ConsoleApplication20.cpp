#include <iostream>
#include <fstream>
#include <windows.h>
#include <locale.h>
using namespace std; void controller();
void firstEx();
void firstExV2();
void secondEx();

void secondExV2();
void thirdEx();
void additionThirdEx();
void additionThirdEx2();
void additionThirdEx3();
void fourEx();
void additionfourEx();
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    additionfourEx();

    return 0;
}



void controller() {
    int choice;
    std::cout << "Enter the exercice\n";
    std::cin >> choice;
    std::cin.ignore();
    switch (choice) {
    case 1: {
        firstEx();
        break;
    }
    case 2: {
        secondEx();
        break; }
    default:
        break;
    }
}

void firstEx() {
    int length;
    char* buffer;
    char separators[]{ '.','!',';' };
    int separatorsLenght = 3;
    std::ifstream is("text.txt");
    if (!is.is_open()) {
        std::cout << "Opens error\n";
        return;
    }
    is.seekg(0, std::ios::end);
    length = is.tellg();
    is.seekg(0, std::ios::beg);
    buffer = new char[length];
    is.read(buffer, length);
    is.close();

    for (int index = 0, start = 0, end; buffer[index] != 0; ++index) {
        if (buffer[index] == '?') {
            end = index + 1;
            while (start != end) {

                std::cout << buffer[start];
                start++;
            }
            start++;
            std::cout << '\n';
        }
        for (int separatorIndex = 0; separatorIndex < separatorsLenght; ++separatorIndex) {
            if (separators[separatorIndex] == buffer[index]) {
                start = index + 1;
            }
        }

    }
    delete[] buffer;
}
void additionFirstEx() {
    int length;
    char* buffer;
    char separators[]{ '.','?',';' };
    int separatorsLenght = 3;
    std::ifstream is("text.txt");
    std::ofstream os("text2.txt");

    if (!is.is_open() || !os.is_open()) {
        std::cout << "Opens error\n";
        return;
    }
    is.seekg(0, std::ios::end);
    length = is.tellg();
    is.seekg(0, std::ios::beg);
    buffer = new char[length];
    is.read(buffer, length);
    is.close();

    for (int index = 0, start = 0, end; buffer[index] != 0; ++index) {
        if (buffer[index] == '!') {
            end = index + 1;
            while (start != end) {

                os << buffer[start];
                start++;
            }
            start++;
            std::cout << '\n';
        }
        for (int separatorIndex = 0; separatorIndex < separatorsLenght; ++separatorIndex) {
            if (separators[separatorIndex] == buffer[index]) {
                start = index + 1;
            }
        }

    }
    delete[] buffer;
}
void secondEx() {
    {
        std::ofstream os("z3.dat", ios::binary);
        if (!os.is_open()) {
            std::cout << "Opens error\n";
            return;
        }
        const int intsArrSize = 10, charsArrSize = 5;
        double doubleNum1 = 36.14, doubleNum2 = 0.3543;
        int intsArr[intsArrSize];
        char charsArr[charsArrSize];
        for (int index = 0; index < intsArrSize; ++index)
            intsArr[index] = index;
        for (int index = 0; index < charsArrSize; ++index) {
            charsArr[index] = 70 + index;
        }
        os.write((char*)&doubleNum1, sizeof(doubleNum1));
        os.write((char*)&doubleNum2, sizeof(doubleNum2));

        for (int index = 0; index < intsArrSize; ++index)
            os.write((char*)&intsArr[index], sizeof(intsArr[index]));

        for (int index = 0; index < charsArrSize; ++index)
            os.write((char*)&charsArr[index], sizeof(charsArr[index]));

        os.close();
    }
    {
        std::ifstream is("z3.dat", ios::binary);
        if (!is.is_open()) {
            std::cout << "Opens error\n";
        }
        is.seekg(0, ios::end);
        int lenght = is.tellg();
        std::cout << lenght << '\n';
        is.close();

        std::ofstream os("z3.dat", ios::binary | ios::app);
        if (!os.is_open()) {
            std::cout << "Opens error\n";
        }
        os.write((char*)&lenght, sizeof(lenght));
        os.close();
    }
}
void additionSecondEx() {

}
void thirdEx() {
    const int arrSize = 10;
    int arr[arrSize];
    for (int index = 0; index < arrSize; ++index) {
        arr[index] = index;
    }
    ofstream ofs("z3_3.txt", ios::binary);
    if (!ofs.is_open()) {
        cout << "An error has occurred\n";
        return;
    }
    ofs.write((char*)arr, sizeof(arr));

    ofs.close();

    int newNum;
    int numIndex;
    cout << "Enter the number and its index\n";
    cin >> newNum >> numIndex;

    fstream fst("z3_3.txt", ios::binary | ios::in | ios::out);
    if (!fst.is_open()) {
        cout << "An error has occurred\n";
        return;
    }
    fst.seekg(0, ios::end);
    int lenght = fst.tellg();
    cout << "The file size is: " << lenght << "bytes\n";
    int possition = numIndex * sizeof(int);

    cout << "Position of the edited element: " << possition << '\n';
    fst.seekp(possition, ios::beg);
    fst.write((char*)&newNum, sizeof(int));
    fst.seekg(0);
    fst.read((char*)&arr, sizeof(arr));
    for (int index = 0; index < arrSize; ++index)
    {
        cout << arr[index] << " ";
    }

}
void additionThirdEx() {
    int arrSize;
    cout << "Enter the size of array\n";
    cin >> arrSize;
    int* arr = new int[arrSize];
    for (int index = 0; index < arrSize; ++index) {
        arr[index] = index;
    }
    ofstream ofs("z3_3.txt", ios::binary);
    if (!ofs.is_open()) {
        cout << "An error has occurred\n";
        return;
    }
    ofs.write((char*)arr, sizeof(arr) * arrSize);

    ofs.close();

    int newNum;
    int numIndex;
    cout << "Enter the number and its index\n";
    cin >> newNum >> numIndex;

    fstream fst("z3_3.txt", ios::binary | ios::in | ios::out);
    if (!fst.is_open()) {
        cout << "An error has occurred\n";
        return;
    }
    fst.seekg(0, ios::end);
    int lenght = fst.tellg();
    cout << "The file size is: " << lenght << "bytes\n";
    int possition = numIndex * sizeof(int);

    cout << "Position of the edited element: " << possition << '\n';
    fst.seekp(possition, ios::beg);
    fst.write((char*)&newNum, sizeof(int));
    fst.seekp(0);


    fst.read((char*)arr, sizeof(arr) * arrSize);
    for (int index = 0; index < arrSize; ++index)
    {
        cout << arr[index] << " ";
    }

}

void additionThirdEx2() {
    int arrSize;
    cout << "Enter the size of array\n";
    cin >> arrSize;
    int** arr = new int* [arrSize];
    for (int index = 0; index < arrSize; ++index) {
        arr[index] = new int[arrSize];
    }
    for (int index = 0; index < arrSize; ++index) {
        for (int index2 = 0; index2 < arrSize; ++index2) {
            arr[index][index2] = index2 + index * arrSize;
            cout << arr[index][index2] << " ";
        }
        cout << "\n";
    }
    ofstream ofs("z3_3.txt", ios::binary);
    if (!ofs.is_open()) {
        cout << "An error has occurred\n";
        return;
    }
    //ofs.write((char*)arr, sizeof(arr));
    for (int index = 0; index < arrSize; ++index)
        ofs.write((char*)arr[index], sizeof(arr) * arrSize);

    ofs.close();

    int newNum;
    int numIndex;
    int numIndex2;
    cout << "Enter the number and its index1 && index2\n";
    cin >> newNum >> numIndex >> numIndex2;

    fstream fst("z3_3.txt", ios::binary | ios::in | ios::out);
    if (!fst.is_open()) {
        cout << "An error has occurred\n";
        return;
    }
    fst.seekg(0, ios::end);
    int lenght = fst.tellg();
    cout << "The file size is: " << lenght << "bytes\n";
    int possition = (numIndex * arrSize * sizeof(int)) + numIndex2 * sizeof(int);

    cout << "Position of the edited element: " << possition << '\n';
    fst.seekp(possition, ios::beg);
    fst.write((char*)&newNum, sizeof(int));
    fst.seekg(0);
    for (int index = 0; index < arrSize; ++index)
        fst.read((char*)arr[index], sizeof(arr) * arrSize);

    for (int index = 0; index < arrSize; ++index) {
        for (int index2 = 0; index2 < arrSize; ++index2) {
            cout << arr[index][index2] << " ";
        }
        cout << "\n";
    }

}
void additionThirdEx3() {
    const int arrSize = 10;
    int arr[arrSize];
    for (int index = 0; index < arrSize; ++index) {
        arr[index] = index;
    }
    for (int index = 0; index < arrSize; ++index) {
        cout << arr[index] << " ";

    }
    ofstream ofs("z3_3.txt", ios::binary);
    if (!ofs.is_open()) {
        cout << "An error has occurred\n";
        return;
    }
    //ofs.write((char*)arr, sizeof(arr));
    for (int index = 0; index < arrSize; ++index)
        ofs.write((char*)&arr[index], sizeof(int));

    ofs.close();

    int newNum;
    int numIndex;
    int numIndex2;
    cout << "Enter the index you want to delete\n";
    cin >> numIndex;

    fstream fst("z3_3.txt", ios::binary | ios::in | ios::out);
    if (!fst.is_open()) {
        cout << "An error has occurred\n";
        return;
    }
    fst.seekg(0, ios::end);
    int lenght = fst.tellg();
    cout << "The file size is: " << lenght << "bytes\n";
    int possition = (numIndex * sizeof(int));
    int tmp[arrSize - 1];

    fst.seekp(possition, ios::beg);
    for (int index = numIndex + 1; index < arrSize; ++index) {
        fst.write((char*)&arr[index], sizeof(int));
    }
    fst.seekg(0);
    fst.read((char*)arr, sizeof(arr));

    for (int index = 0; index < arrSize - 1; ++index) {
        cout << arr[index] << " ";
    }
    fst.close();
}
void fourEx() {
    ifstream firstFile;
    ifstream secondFile;

    firstFile.open("first.dat");
    secondFile.open("second.txt");

    if (!(firstFile.is_open() && secondFile.is_open())) {
        cout << "The error was occure\n";
        return;
    }
    char* firstBuf;
    char* secondBuf;
    int firstBufSize = 0;
    int secondBufSize = 0;

    firstFile.seekg(0, std::ios::end);
    firstBufSize = firstFile.tellg();
    firstFile.seekg(0);

    secondFile.seekg(0, std::ios::end);
    secondBufSize = secondFile.tellg();
    secondFile.seekg(0);

    if (firstBufSize != secondBufSize) {
        cout << "Files have different sizes\n";
        return;
    }
    firstBuf = new char[firstBufSize];
    secondBuf = new char[secondBufSize];

    firstFile.read((char*)firstBuf, sizeof(int) * firstBufSize);
    secondFile.read((char*)secondBuf, sizeof(int) * secondBufSize);

    for (int index = 0; index < firstBufSize && index < secondBufSize; ++index)
    {
        if (firstBuf[index] != secondBuf[index]) {
            cout << "Files have different content\n";
            return;
        }
    }
    cout << "Files are absolutely identical\n";
}
void additionfourEx() {
    ifstream firstFile;
    ifstream secondFile;

    firstFile.open("first.txt");
    secondFile.open("second.txt");

    if (!(firstFile.is_open() && secondFile.is_open())) {
        cout << "The error was occure\n";
        return;
    }
    char* firstBuf;
    char* secondBuf;
    int firstBufSize = 0;
    int secondBufSize = 0;
    bool isEquals = true;
    firstFile.seekg(0, std::ios::end);
    firstBufSize = firstFile.tellg();
    firstFile.seekg(0);

    secondFile.seekg(0, std::ios::end);
    secondBufSize = secondFile.tellg();
    secondFile.seekg(0);

    if (firstBufSize != secondBufSize) {
        cout << "Files have different sizes and content\n";
        isEquals = false;
    }
    firstBuf = new char[firstBufSize];
    secondBuf = new char[secondBufSize];

    firstFile.read((char*)firstBuf, sizeof(int) * firstBufSize);
    secondFile.read((char*)secondBuf, sizeof(int) * secondBufSize);
    if (isEquals) {
        for (int index = 0; index < firstBufSize && index < secondBufSize; ++index)
        {
            if (firstBuf[index] != secondBuf[index]) {
                cout << "Files have different content\n";
                isEquals = false;

            }
        }
        if (isEquals)
            cout << "Files are absolutely identical\n";
    }
    bool isContainFirst, isContainSecond;
    for (int index = 0; index < firstBufSize && index < secondBufSize; ++index) {
        isContainFirst = true, isContainSecond = true;
        for (int index2 = 0, index3 = index; index2 < firstBufSize && index2 < secondBufSize; ++index2, ++index3) {
            if (isContainFirst && firstBuf[index3] != secondBuf[index2]) {
                isContainFirst = false;
            }
            if (isContainSecond && secondBuf[index3] != firstBuf[index2]) {
                isContainSecond = false;
            }
            if (!isContainFirst && !isContainSecond) {
                break;
            }
        }
        if (isContainFirst || isContainSecond) {
            cout << "One file is part of another one\n";
            break;
        }
    }
}