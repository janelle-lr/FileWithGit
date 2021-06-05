// FileWithGit.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct Jacket {
    string brand;
    string material;
    string color;
    string size;
    float price = 0;
};

struct Jacket* inputJacketDetails(struct Jacket* jacketPtr) {
    int i;

    for (i = 0; i < 5; i++) {
        cout << "Jacket " << i + 1 << " Input" << endl;
        cout << "Enter jacket brand : ";
        getline(cin, jacketPtr->brand);
        cout << "Enter jacket material : ";
        getline(cin, jacketPtr->material);
        cout << "Enter jacket size : ";
        getline(cin, jacketPtr->size);
        cout << "Enter jacket color : ";
        cin >> jacketPtr->color;
        cout << "Enter jacket price : ";
        cin >> jacketPtr->price;
        cout << "\n";
        cin.ignore();
        jacketPtr++;
    }

    return (jacketPtr);
}

struct Jacket* writingToTxtFile(struct Jacket* jacketPtr) {
    int i;

    //writing to the file
    fstream jacketFile;

    //open the file
    jacketFile.open("jacket.txt", ios::out);

    //writing input data into file
    for (i = 0; i < 5; i++) {
        jacketFile << jacketPtr->brand << "\t";
        jacketFile << jacketPtr->material << "\t";
        jacketFile << jacketPtr->size << "\t";
        jacketFile << jacketPtr->color << "\t";
        jacketFile << jacketPtr->price << endl;
        jacketPtr++;
    }
    cout << "\nInput data stored into txt file" << endl;

    //close the file
    jacketFile.close();

    return(jacketPtr);
}

void txtFileOutput() {
    string fileData;

    //open the file in read mode
    ifstream jcktFle;
    jcktFle.open("jacket.txt", ios::in);

    //display data written in file
    cout << "\nReading data from txt file" << endl;
    while (getline(jcktFle, fileData))
    {
        cout << fileData << endl;
    }

    jcktFle.close();
}

void sizeSearch() {
    string id, col2, col1, col3, fd;
    int jacketCount = 0;

    fstream jf;
    jf.open("jacket.txt", ios::in);

    cout << "\nPlease enter desired jacket size : ";
    cin >> id;

    //jacket size checker
    while (getline(jf, fd)) {
        istringstream ss(fd);
        ss >> col1 >> col2 >> col3;
        if (col3 == id) {
            jacketCount++;
        }
    }

    if (jacketCount >= 1) {
        cout << "\nThere were " << jacketCount << " jacket(s) found under that size" << endl;
    }
    else {
        cout << "\nThere were no jackets found under that size";
    }
    cout << "\n";

    //close the file
    jf.close();
}

int main()
{
    struct Jacket jckt[5];
    struct Jacket* j = jckt;//assigning pointer to jacket array of struct

    inputJacketDetails(j);

    writingToTxtFile(j);

    txtFileOutput();

    sizeSearch();

    return 0;
}
