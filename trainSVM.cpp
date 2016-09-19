#include <iostream>
#include "imgSVM.hpp"

using namespace std;
using namespace cv;

int main(int argc, char* argv[]) {
  if (argc != 2) {
    cout << "Usage: ./trainSVM another-argument" << endl;
  }

  // Creating SVM
  imgSVM testImgSVM;

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
