// FileWithGit.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Jacket {
    string brand;
    string material;
    string color;
    string size;
    float price = 0;
};

struct Jacket* inputJacketDetails(struct Jacket* j) {
    int i;

    for (i = 0; i < 5; i++) {
        cout << "Enter jacket brand : ";
        getline(cin, j->brand);
        cout << "Enter jacket material : ";
        getline(cin, j->material);
        cout << "Enter jacket size : ";
        getline(cin, j->size);
        cout << "Enter jacket color : ";
        cin >> j->color;
        cout << "Enter jacket price : ";
        cin >> j->price;
        cout << "\n";
        cin.ignore();
        j++;
    }

    return (j);
}

int main()
{
    struct Jacket jckt[5];
    struct Jacket* j = jckt;
    int i;

    inputJacketDetails(j);

    //writing to the file
    fstream jacketFile;

    //open the file
    jacketFile.open("jacket.txt", ios::out);

    //writing input data into file
    for (i = 0; i < 5; i++) {
        jacketFile << j->brand << "\t";
        jacketFile << j->material << "\t";
        jacketFile << j->size << "\t";
        jacketFile << j->color << "\t";
        jacketFile << j->price << endl;
        j++;
    }
    cout << "\nStored details into the file" << endl;
    jacketFile.close();
}
