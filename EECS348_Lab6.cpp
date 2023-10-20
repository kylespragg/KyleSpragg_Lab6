#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
const int maxMatrix = 100;
void readMatrixFromFile(int matrix1[maxMatrix][maxMatrix], int matrix2[maxMatrix][maxMatrix], int &size, const string &filename);
void printMatrixFunction(const int matrix[maxMatrix][maxMatrix], int size);
void addMatrixFunction(const int matrix1[maxMatrix][maxMatrix], const int matrix2[maxMatrix][maxMatrix], int size, int result[maxMatrix][maxMatrix]);
void subtractMatrixFunction(const int matrix1[maxMatrix][maxMatrix], const int matrix2[maxMatrix][maxMatrix], int size, int result[maxMatrix][maxMatrix]);
void multiplyMatrixFunction(const int matrix1[maxMatrix][maxMatrix], const int matrix2[maxMatrix][maxMatrix], int size, int result[maxMatrix][maxMatrix]);
int main(){

    int matrix1[maxMatrix][maxMatrix];

    int matrix2[maxMatrix][maxMatrix];

    int result[maxMatrix][maxMatrix];

    int size;

    readMatrixFromFile(matrix1, matrix2, size, "sample.txt");
    
    cout << "Kyle Spragg" << endl;
    cout << "Lab 6: Matrix manipulation\n" << endl;

    cout<< "Matrix A" << endl;
    printMatrixFunction(matrix1, size);

    cout << "\nMatrix B" << endl;
    printMatrixFunction(matrix2, size);

    cout << "\nMatrix Sum (A+B):" << endl;
    addMatrixFunction(matrix1, matrix2, size, result);
    printMatrixFunction(result, size);

    cout << "\nMatrix Product (A*B):" << endl;

    multiplyMatrixFunction(matrix1, matrix2, size, result);
    printMatrixFunction(result, size);

    cout << "\nMatrix Difference (A-B):" << endl;
    subtractMatrixFunction(matrix1, matrix2, size, result);
    printMatrixFunction(result, size);

    vector<int> integers;
}

void readMatrixFromFile(int matrix1[maxMatrix][maxMatrix], int matrix2[maxMatrix][maxMatrix],int &size,const string &filename){

    fstream inFile(filename);
    string firstline;

    if (!inFile.is_open()){

        cerr << "Failed to open file." << endl;

        return;

    }

    if (getline(inFile, firstline)){

        size = stoi(firstline);

    } else{

        cerr << "Failed to read a line from the file." << endl;

        inFile.close();
        return;

    }

    for (int i = 0; i < size;i++){
        for (int j = 0; j < size; j++){

            if (!(inFile >> matrix1[i][j])){

                cerr << "Failed to read matrix." << filename << endl;
                inFile.close();

                return;
            }
        }

        cout << endl;
    }


    for (int i = 0; i < size; i++){

        for (int j = 0; j < size; j++){
            
            if (!(inFile >> matrix2[i][j])){

                cerr << "Failed to read matrix." << filename <<endl;
                inFile.close();

                return;
            }
        
        }
    }
    inFile.close();


}

void addMatrixFunction(const int matrix1[maxMatrix][maxMatrix], const int matrix2[maxMatrix][maxMatrix], int size, int result[maxMatrix][maxMatrix]) {

    for (int i = 0; i < size; i++ ){

        for (int j = 0; j < size; j++){

            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void multiplyMatrixFunction(const int matrix1[maxMatrix][maxMatrix], const int matrix2[maxMatrix][maxMatrix], int size, int result[maxMatrix][maxMatrix]){
    for (int i = 0; i < size; i++){

        for (int j = 0; j < size; j++){

            result[i][j] = 0;

            for (int k = 0; k < size; k++){

                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

}

void subtractMatrixFunction(const int matrix1[maxMatrix][maxMatrix], const int matrix2[maxMatrix][maxMatrix], int size, int result[maxMatrix][maxMatrix]){

    for (int i = 0; i < size; i++ ){

        for (int j = 0; j < size; j++){

            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}


void printMatrixFunction(const int matrix[maxMatrix][maxMatrix], int size){

    for (int i = 0; i <size; i++){

        for (int j = 0; j < size; j++){

            cout << matrix[i][j] << ' ';

        }

        cout << endl;
    }
}