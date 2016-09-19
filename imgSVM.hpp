#ifndef IMG_SVM
#define IMG_SVM

#include <opencv2/opencv.hpp>
using namespace cv;


/** The class for pasing images to SVM classifier
***/
class imgSVM {
 public:
  /* Constructor */
  imgSVM() {
  }
  
  /* Show basic information of SVM classifier */
  void showInfo();

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
};

#endif  // IMG_SVM
