#include <QtGui/QApplication>
#include "mainwindow.h"
#include "fibonacciSystem.h"
#include "numberSystem.h"
#include "multiBase.h"
#include "goldenRatioSystem.h"
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <securer.h>
#include <assert.h>
#include <Magick++.h>
#include <compressor.h>

void PrintVector(vector<float>*seq){
    for(size_t i = 0; i < seq->size(); i++){
        cout << seq->at(i) << " ";
    }
    cout<< "end of sequence" << endl;
}

void TestSequences(){
    Fibonacci f1(1, 1000, 0);
    Fibonacci f2(2, 1000, 0);
    vector<NumberSystem> systems;
    systems.push_back(f1);
    systems.push_back(f2);
    MultiBase b(0, &systems);
    b.sanitizeSequence();
    PrintVector(f1.getSequence());
    PrintVector(f2.getSequence());
    PrintVector(b.getSequence());
    vector<int> greedy;
    b.getGreedyRepresentation(999, &greedy);
    string s = b.getGreedyAsSum(&greedy);
    cout<< s;
}

int main(int argc, char *argv[])
{
    //TestSequences();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();


    //possible todo
   /* Fibonacci f(1, 10, 0);
    NumberSystem k;
    k = f;
    GoldenRatio g(100, 1.618);
    k = g;
    vector<NumberSystem> gf;
    gf.push_back(g);
    gf.push_back(f);
    MultiBase gff(0, &gf);*/
    return 0;

}

