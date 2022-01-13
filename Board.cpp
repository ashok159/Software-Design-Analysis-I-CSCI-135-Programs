/*
Author: Ashok Surujdeo
Course: CSCI-135
Instructor: Tong Yi
Assignment: Board

Define constructors, destructor, and method print for Board.cpp. 
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <cstdlib>
#include "Board.hpp"
using namespace std;

/*
Board::Board()
{
    numRows = 3;
    numCols = 3;
    max = 0;
    target = 32;

    panel = new int*[numRows];

    for(int i = 0; i < numRows; i++) {
        panel[i] = new int[numCols];
    }

    for(int i = 0; i < numRows; i++) {
        for(int j = 0; j < numCols; j++) {
            panel[i][j] = max;
        }
    }
}

Board::Board(int m)
{
    max = 0;
    target = 32;

    panel = new int*[numRows];

    if(m >= 1) {
        numRows = m;
        numCols = m;
    } 
    else {
        numRows = 3;
        numCols = 3;
    }
    for(int i = 0; i < numRows; i++) {
        panel[i] = new int[numCols];
    }

    for(int i = 0; i < numRows; i++) {
        for(int j = 0; j < numCols; j++) {
            panel[i][j] = max;
        }
    }

}

Board::Board(int m, int n)
{
    max = 0;
    target = 32;

    panel = new int*[numRows];

    if(m >= 1) {
        numRows = m;
        numCols = n;
    } 
    else {
        numRows = 3;
        numCols = 3;
    }
    for(int i = 0; i < numRows; i++) {
        panel[i] = new int[numCols];
    }

    for(int i = 0; i < numRows; i++) {
        for(int j = 0; j < numCols; j++) {
            panel[i][j] = max;
        }
    }
}
*/

/*
Board::~Board()
{
    delete[] panel;
    panel = nullptr;
}
*/

/*
void Board::selectRandomCell(int& row, int&col)
{
    int zeroes = 0;
    vector<int> cells;
    for (int i = 0; i < numRows; ++i)
        for (int j = 0; j < numCols; ++j){
            if(!panel[i][j]){
                cells.push_back(i * numCols + j);
                zeroes++;
            }
        }
    if(!zeroes and this->noAdjacentSameValue()){
        cout << "Game over. Try again.\n";
    }else{
        if(zeroes){
            srand(1);
            int n = cells[rand() % cells.size()];
            row = n / numCols;
            col = n % numCols;
            panel[row][col] = 1;
            this->print();
            if(!--zeroes and this->noAdjacentSameValue())
                cout << "Game over. Try again.\n";
        }
    }
}

bool Board::noAdjacentSameValue() const
{
    int numZeros = 0;
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            if (panel[i][j] == 0)
                numZeros++;
        }
    }

    if (numZeros > 0)
        return false;

    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols-1; j++)
        {
            if (panel[i][j] == panel[i][j+1])
                return false;
        }
    }

    for (int j = 0; j < numCols; j++)
    {
        for (int i = 0; i < numRows-1; i++)
        {
            if (panel[i][j] == panel[i+1][j])
                return false;
        }
    }

    return true;
}
*/


void Board::pressUp(){
    vector<int> col;
    vector<int> col2;
    int r,r1;
    for(int j = 0; j < numCols; j++){
        r = 0;
        r1 = 0;
        int diff = j * numRows;
        for (int i = 0; i < numRows; ++i)
            if (panel[i][j]){
                col.push_back(panel[i][j]);
                r++;
            }
        for (int i = r; i < numRows; ++i)
            col.push_back(0);
        for (int i = 0; i < numRows - 1; ++i)
            if(col[diff + i] == col[diff+i+1]){
                col[diff + i] *= 2;
                col[diff+i+1] = 0;
            }
        for (int i = 0; i < numRows; ++i)
            if(col[diff+i]){
                r1++;
                col2.push_back(col[diff+i]);
            }
        for (int i = r1; i < numRows; ++i)
            col2.push_back(0);
        for (int i = 0; i < numRows; ++i)
                panel[i][j] = col2[diff+i];
    }
    this->selectRandomCell(r,r1);
}

void Board::pressDown()
{
    int* temp = new int[numRows]; 
    int toWrite;
    for (int j = 0; j < numCols; j++)
    {
        //initialize each element of temp to be 0
        for (int k = 0; k < numRows; k++)
            temp[k] = 0;

        //copy the non-zeros from the jth column
        //of panel to temp
        toWrite = numRows -1; //next position to write in temp
        for (int i = numRows-1; i >= 0; i--)
            if (panel[i][j] > 0)
            {
               temp[toWrite] = panel[i][j];
               toWrite--;
            }

        for (int k = numRows-1; k > 0; k--) //? k >= 0 is not correct, it would result in out of index exception in expression temp[k-1].
            if (temp[k] == temp[k-1])
            {
               temp[k] *= 2;

               //MISS
               if (max < temp[k])
                  max = temp[k];

               temp[k-1] = 0;
               k--; //k-- to skip adjacent pair
               //temp[k-1] and temp[k-2]
               //since temp[k-1] is merged with
               //temp[k] already.
               //This line can be omitted after
               //setting temp[k-1] = 0;
               //since if temp[k-2] is not zero,
               //no way to merge since
               //temp[k-1] != temp[k-2],
               //if temp[k-2] is zero,
               //then 0 merged with 0 does not
               //result in any actual difference.
            }

        int i = numRows -1;  //to write in jth column of panel, starting from the last row since we press down key, whose row index is numRows-1. 
        int k = numRows -1; //can use for loop for k
        while (k >= 0) 
        {
            if (temp[k] > 0)
            {
               panel[i][j] = temp[k];
               i--;
            }
            k--;
        }

        //For the remaining elements in the jth column, pad with 0.
        while (i >= 0)
        {
            panel[i][j] = 0;
            i--;
        }
    }

    delete[] temp;
    temp = nullptr;

    //MISS
    int row = -1, col = -1;
    selectRandomCell(row, col);
}

void Board::pressLeft(){
    vector<int> row;
    vector<int> row2;
    int c,c1;
    for (int i = 0; i < numRows; ++i) {
        c = 0;
        c1 = 0;
        int diff = i * numCols;
        for (int j = 0; j < numCols; ++j) {
            if(panel[i][j]){
                row.push_back(panel[i][j]);
                c++;
            }
        }
        for (int j = c; j < numCols; ++j) {
            row.push_back(0);
        }
        for (int j = 0; j < numCols - 1; ++j) {
            if(row[diff + j] == row[diff +j+1]){
                row[diff + j] *= 2;
                row[diff+j+1] = 0;
            }
        }
        for (int j = 0; j < numCols; ++j) {
            if(row[diff+j]){
                c1++;
                row2.push_back(row[diff+j]);
            }
        }
        for (int j = c1; j < numCols; ++j) {
            row2.push_back(0);
        }
        for (int j = 0; j < numCols; ++j) {
            panel[i][j] = row2[diff+j];
        }
    }
    this->selectRandomCell(c,c1);
}

void Board::pressRight(){
    vector<int> row;
    vector<int> row2;
    int c,c1;
    for (int i = 0; i < numRows; ++i) {
        c = 0;
        c1 = 0;
        int diff = i * numCols;
        for (int j = numCols - 1; j >= 0; --j) {
            if(panel[i][j]){
                row.push_back(panel[i][j]);
                c++;
            }
        }
        for (int j = c; j < numCols; ++j) {
            row.push_back(0);
        }
        for (int j = 0; j < numCols - 1; ++j) {
            if(row[diff + j] == row[diff +j+1]){
                row[diff + j] *= 2;
                row[diff+j+1] = 0;
            }
        }
        for (int j = 0; j < numCols; ++j) {
            if(row[diff+j]){
                c1++;
                row2.push_back(row[diff+j]);
            }
        }
        for (int j = c1; j < numCols; ++j) {
            row2.push_back(0);
        }
        for (int j = 0; j < numCols; ++j) {
            panel[i][j] = row2[diff+numCols - 1-j];
        }
    }
    this->selectRandomCell(c,c1);
}

/*
void Board::print() const
{
    for(int i = 0; i < 2 * numRows + 1; i++){
        if(i % 2){
            for(int j = 0; j < numCols; j++){
                int n = panel[i/2][j];
                if(n > 0){
                    int digits = floor(log(n) / log(10)) + 1;
                    switch (digits) {
                        case 1:
                            cout << "|   " << n;
                            break;
                        case 2:
                            cout << "|  " << n;
                            break;
                        case 3:
                            cout << "| " << n;
                            break;
                        case 4:
                            cout << "|" << n;
                            break;
                    }
                }else {
                    cout << "|    ";
                }
            }
            cout << "|\n";
        }else{
            for(int j = 0; j < numCols; j++)
                cout << "+----";
            cout << "+\n";
        }
    }
}
*/

void printSeparateLine(int numCols)
{
    cout << "+";
    for (int j = 0; j < numCols; j++)
        cout << "----+";

    cout << endl;
}

void Board::print() const
{
    printSeparateLine(numCols);
    for (int i = 0; i < numRows; i++)
    {
        cout << "|";
        for (int j = 0; j < numCols; j++)
            if (panel[i][j] > 0)
               cout << setw(4) << panel[i][j] << "|";
            else cout << setw(4) << " " << "|";

        cout << endl;
        printSeparateLine(numCols);
    }
}



