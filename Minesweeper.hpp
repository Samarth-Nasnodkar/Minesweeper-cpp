#include<bits/stdc++.h>
#include"colors.hpp"
using namespace std;

class Cube{
    public:
        int value = -1;
        bool isBomb = false;
        int posn;
        Cube(){
        }
        Cube(int posn, bool isBomb = false, int value = -1){
            this->isBomb = isBomb;
            this->value = value;
            this->posn = posn;
        }
        Cube(Cube &cube){
            isBomb = cube.isBomb;
            value = cube.value;
            posn = cube.posn;
        }
};

bool isPresent(int arr[], int n, int item){
    for(int i = 0; i < n; i++){
        if(arr[i] == item)
            return true;
    }
    return false;
}

class Minesweeper{
    private:
        const int y = 25;
        const int x = 25;
        Cube cubes[625];
        int mines = 0.3 * x * y;
    public:
        Minesweeper &generate(){
            srand(time(0));
            int mineCoords[mines];
            int newCoord;
            int tempMines = 0;
            while(tempMines < mines){
                newCoord = rand() % (x * y);
                while(isPresent(mineCoords, mines, newCoord))
                    newCoord = rand() % (x * y);
                mineCoords[tempMines] = newCoord;
                tempMines++;
            }
            for(int i=0; i < x * y; i++){
                Cube cube(i, isPresent(mineCoords, mines, i));
                cubes[i] = cube;
            }
            for(int i=0; i < x * y; i++){
                int value = 0;
                int toBeChecked[] = {i - x - 1, i - 1, i + x - 1, i - x, i + x, i - x + 1, i + 1, i + x + 1};
                int start = (i % x == 0) ? 3 : 0;
                int end = (i % x == x - 1) ? 5 : 8;
                if(!cubes[i].isBomb){
                    for(int j = start; j < end; j++)
                        if((toBeChecked[j] < x * y) && (toBeChecked[j] >= 0))
                            if(cubes[toBeChecked[j]].isBomb)
                                value ++;
                    cubes[i].value = value;
                }
            }
            return *this;
        }
        void display(){
            for(int i = 0; i < x * y; i++){
                if(cubes[i].isBomb){
                    cout<<"|"<<RED_FLASH<<"*"<<NC;
                }
                else{
                    if(cubes[i].value)
                        cout<<"|"<<GREEN_NO_FLASH<<cubes[i].value<<NC;
                    else
                        cout<<"| ";
                }
                if(i % x == x - 1)
                    cout<<"|"<<endl;
            }
        }
};