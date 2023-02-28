#include "utilities.hpp"

void quicksort(Point arr[], int n){
    Point pivot = arr[0];
    //cout << "Begin Quicksort " << endl << endl;
    //pivot.printPoint();
    if(n == 1){

    }
    else if(n == 2){
        if(arr[0].getX() > arr[1].getX()){
            arr[0] = arr[1];
            arr[1] = pivot;
        }

    }else{
        int p = 1;
        int q = n - 1;
        bool flagBigger = false;
        bool flagSmaller = false;
        int count1 = 0;
        int count2 = 0;

        //Run positioning for spliting
        while(p < q){
            for(; p < n; p++){
                if(arr[p].getX() > pivot.getX()){
                    //arr[p].printPoint();
                    //cout << "Is bigger than pivot" << endl;
                    flagBigger = true;
                    count1++;
                    break;
                }else{
                    //arr[p].printPoint();
                    //cout << "Is not bigger than pivot" << endl;
                }
            }

            // Case if pivot is the biggest
            if(!flagBigger){
                p = 0;
            }

            for(; q >= 1; q--){
                if(arr[q].getX() <= pivot.getX()){
                    //arr[q].printPoint();
                    //cout << "Is smaller than pivot" << endl;
                    flagSmaller = true;
                    count2++;
                    break;
                }
            }

            // Break out loop if q and p already cross
            if(q <= p){
                break;
            }

            // Case if pivot is the smallest
            if(!flagSmaller){
                q = 0;
            }

            //Swap q and p (smaller and bigger)
            if(flagBigger && flagSmaller){
                swap(arr[p], arr[q]);

                p++;
                q--;
            }else{ //if pivot is the biggest or smallest
                break;
            }
            

            
            
        }

        //Swap the pivot if it's not the smallest
        if(flagSmaller){
            arr[0] = arr[q];
            arr[q] = pivot;
        }
        

        Point firstHalf[MAX_ARR];
        Point secondHalf[MAX_ARR];

        //Create the first half of points (if pivot is not smallest)
        int i = 0;
        if(flagSmaller){
            //cout << "FIRST HALF" << endl;
            for(i = 0; i < q; i++){
                firstHalf[i] = arr[i];
                // firstHalf[i].printPoint();
            }
            
        }
        
        i++;

        //Create the second half of points (if pivot is not biggest)
        if(flagBigger){
            //cout << "SECOND HALF" << endl;
            for(int j = 0; i < n; j++){
                secondHalf[j] = arr[i];
                // secondHalf[j].printPoint();
                i++;
            }
        }
        
        //Recursive for bot halves
        if(flagSmaller){
            quicksort(firstHalf, q);
        }
        if(flagBigger){
            quicksort(secondHalf, n - (q + 1));
        }
        
        //Merging all the ordered halves
        Point result[MAX_ARR];
        int j = 0;
        if(flagSmaller){
            //cout << "First merge\n";
            for(j = 0; j < q; j++){
                arr[j] = firstHalf[j];
                //arr[j].printPoint();
            }
        }

        arr[j] = pivot;
        j++;

        if(flagBigger){
            //cout << "second merge\n";
            for(int k = 0; j < n; k++){
                arr[j] = secondHalf[k];
                //arr[j].printPoint();
                j++;
            }
        }
    }
}

void BruteForce(Point arr[], int n){
    //Brute Force Way
    double MIN = arr[0].getDistance(arr[1]);
    Point T1 = arr[0];
    Point T2 = arr[1];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i != j && arr[i].getDistance(arr[j]) < MIN){
                MIN = arr[i].getDistance(arr[j]);
                T1 = arr[i];
                T2 = arr[j];
            }
        }
    }
    cout << "BRUTE FORCE: " << MIN << endl;
    cout << "Titik 1: (" << T1.getX() << ", " << T1.getY() << ", " << T1.getZ() << ")" << endl;
    cout << "Titik 2: (" << T2.getX() << ", " << T2.getY() << ", " << T2.getZ() << ")" << endl;
    
}

void DivideAndConquer(Point arr[], int n){
    Point leftSide[MAX_ARR / 2];
    Point rightSide[MAX_ARR / 2];
    Point T1 = arr[0];
    Point T2 = arr[1];
    int leftMax = round(n / 2) -1;
    int count = 0;

    //Split array of points
    split(arr, leftSide, rightSide, n);
    double strip = (rightSide[0].getX() - leftSide[leftMax].getX()) + leftSide[leftMax].getX();

    //Shortest Distance on Left
    double LeftMin = -1;
    Point LeftT1 = Point();
    Point LeftT2 = Point();
    if(round(n / 1) > 1){
        LeftT1 = leftSide[0];
        LeftT2 = leftSide[1];
        LeftMin = leftSide[0].getDistance(leftSide[1]);
        for(int i = 0; i < round(n / 2); i++){
            for(int j = 0; j < round(n / 2); j++){
                if(i < j && leftSide[i].getDistance(leftSide[j]) < LeftMin){
                    LeftMin = leftSide[i].getDistance(leftSide[j]);
                    LeftT1 = leftSide[i];
                    LeftT2 = leftSide[j];
                }
            }        
        }
    }

    //Shortest Distance on Right
    double RightMin = rightSide[0].getDistance(rightSide[1]);
    Point RightT1 = rightSide[0];
    Point RightT2 = rightSide[1];
    for(int i = 0; i < n - round(n / 2); i++){
        for(int j = 0; j < n - round(n / 2); j++){
            if(i < j && rightSide[i].getDistance(rightSide[j]) < RightMin){
                RightMin = rightSide[i].getDistance(rightSide[j]);
                RightT1 = rightSide[i];
                RightT2 = rightSide[j];
            }
        }        
    }

    //Shortest distance between left and right
    double universalMin;
    if(LeftMin == -1 || RightMin <= LeftMin){
        universalMin = RightMin;
        T1 = RightT1;
        T2 = RightT2;
    }else{
        universalMin = LeftMin;
        T1 = LeftT1;
        T2 = LeftT2;
    }
    //Shortes distance near strip
    count = 0;
    for(int i = 0; i < round(n / 2); i++){
        if(leftSide[i].getX() >= strip - universalMin && leftSide[i].getX() <= strip + universalMin){
            for(int j = 0; j < n - round(n / 2); j++){
                if(rightSide[i].getX() >= strip - universalMin && rightSide[i].getX() <= strip + universalMin && leftSide[i].getDistance(rightSide[j]) < universalMin){
                    universalMin = leftSide[i].getDistance(rightSide[j]);
                    T1 = leftSide[i];
                    T2 = rightSide[j];
                }
            }
        }
    }

    cout << "DIVIDE & CONQUER: " << universalMin << endl;
    cout << "Titik 1: (" << T1.getX() << ", " << T1.getY() << ", " << T1.getZ() << ")" << endl;
    cout << "Titik 2: (" << T2.getX() << ", " << T2.getY() << ", " << T2.getZ() << ")" << endl;
}


void split(Point parent[], Point child1[], Point child2[], int n){
    int count = 0;
    // Left Points
    for(int i = 0; i < round(n/2); i++){
        child1[i] = parent[count];
        //leftSide[i].printPoint();
        count++;
    }
    //Right points
    for(int i = 0; i < n - round(n / 2); i++){
        child2[i] = parent[count];
        //rightSide[i].printPoint();
        count++;
    }
}