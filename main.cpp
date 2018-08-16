#include "mainwindow.h"
#include "imagedir.h"
#include "sfm.h"

#include <QApplication>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <map>
#include <fstream>
#include <cassert>
#include <string>
#include <iomanip>
#include <dirent.h>

#include <opencv2/features2d.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

#include <gtsam/geometry/Point2.h>
#include <gtsam/inference/Symbol.h>
#include <gtsam/slam/PriorFactor.h>
#include <gtsam/slam/ProjectionFactor.h>
#include <gtsam/slam/GeneralSFMFactor.h>
#include <gtsam/nonlinear/NonlinearFactorGraph.h>
#include <gtsam/nonlinear/LevenbergMarquardtOptimizer.h>
#include <gtsam/nonlinear/DoglegOptimizer.h>
#include <gtsam/nonlinear/Values.h>


using namespace std;
using namespace cv;

int main(int argc, char *argv[])
{
    //QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    imageDir direktoriImage;
    direktoriImage.listImage("/home/achan/Documents/CODE_OF_NOTHING/Watch/IMAGE_DIR");
    direktoriImage.sortList();
    //direktoriImage.openFile();

    cout << direktoriImage.IMAGE_DIR << endl;

    image3DSFM imageSfm;
    imageSfm.imageMatching();


    return 0;//a.exec();
}
