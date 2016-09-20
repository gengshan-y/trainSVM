#include <iostream>
#include "imgSVM.hpp"

using namespace std;
using namespace cv;

int main(int argc, char* argv[]) {
  if (argc != 3) {
    cout << "Usage: ./trainSVM path-to-positive path-to-negative" << endl;
    exit(-1);
  }

  // Creating SVM
  imgSVM testImgSVM;

  // Read images
  testImgSVM.path2feat(argv[1]); 

  // Parse data to classfier
  testImgSVM.Mat2samp();

  // Configure parameters
  testImgSVM.SVMConfig();

  // Train SVM
  testImgSVM.SVMTrain();

  // Test SVM
  for (int i = 0; i < 5; ++i)
    for (int j = 0; j < 5; ++j)
    {
      Mat sampleMat = (Mat_<float>(1,2) << i,j);
      float response = testImgSVM.SVMPredict(sampleMat);
    }

  return 0;
}
