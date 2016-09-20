#ifndef IMG_SVM
#define IMG_SVM

#include <opencv2/opencv.hpp>
#include <fstream>
#include "global.hpp"

using namespace cv;


/** The class for pasing images to SVM classifier
***/
class imgSVM {
 public:
  /* Constructor */
  imgSVM() : featSize(1764), trainingPos(0, 1764, CV_32FC1){
  }
  
  /* Show basic information of SVM classifier */
  void showInfo();

  /* Read images in the list and compute features */
  void path2feat(char* imgListPath);

  /* Parse Mat into training sample */
  void Mat2samp();

  /* Configure parameters */
  void SVMConfig();

  /* Training SVM */
  void SVMTrain();

  /* Predicing label */
  float SVMPredict(Mat sampleMat);

 private:
  CvSVM SVM;
  CvSVMParams params;
  Mat trainingDataMat;
  Mat labelsMat;
  Mat trainingPos;
  Mat trainingNeg;
  unsigned int featSize;
};

#endif  // IMG_SVM
