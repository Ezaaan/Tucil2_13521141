#include <iostream>
#include <time.h>
#include <ctime>
#include <chrono>
#include "utilities.cpp"

using namespace std;
using chrono::duration_cast;
using chrono::duration;
using chrono::milliseconds;

typedef chrono::high_resolution_clock Clock;

int main(){
    //Point p[MAX_ARR];
    int n;
    Point points[MAX_ARR];
    Point* pointsPtr = points;
    Point pointsByX[MAX_ARR];
    int Rx, Ry, Rz;
    srand(time(NULL));

    //Opening
    cout << "Selamat datang!\n" << endl;
    cout << "Keterangan:" << endl;
    cout << "1) Range Koordinat: (-500) - 500\n2) Maximum titik: 1000\n" << endl;
    cout << "Masukan jumlah titik: ";
    cin >> n;
    cout << endl;

    //Generate random points
    for(int i = 0; i < n; i++){
        Rx = rand() % (MAX__COOR - MIN_COOR + 1) + MIN_COOR;
        Ry = rand() % (MAX__COOR - MIN_COOR + 1) + MIN_COOR;
        Rz = rand() % (MAX__COOR - MIN_COOR + 1) + MIN_COOR;

        points[i] = Point(Rx, Ry, Rz);
        //points[i].printPoint();

    }

    //Sort the array
    quicksort(points, n);
    // cout<<"RESULTS\n";
    // for(int i = 0; i < n; i++){
    //     pointsByX[i].printPoint();
    // }

    //Brute Force Way
    auto start_s = Clock::now();
    BruteForce(points, n);
    auto stop_s = Clock::now();
    duration<double, milli> exec = stop_s - start_s;
    cout << "Execution time: " << exec.count() << " ms" << endl << endl;
    
    //Divide and Conquer Way
    start_s = Clock::now();
    DivideAndConquer(points, n);
    stop_s = Clock::now();
    exec = stop_s - start_s;
    cout << "Execution time: " << exec.count() << " ms" << endl << endl;
 
    return 0;
}



