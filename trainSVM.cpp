#include <iostream>
#include "imgSVM.hpp"

using namespace std;
using namespace cv;

int main(int argc, char* argv[]) {
  if (argc != 5) {
    cout << "Usage: ./trainSVM path-to-train-positive path-to-train-negative" 
         << " path-to-val-positive path-to-val-negative" << endl;
    exit(-1);
  }

  // Creating SVM
  imgSVM testImgSVM;

  // Read images
  Mat trainPos = testImgSVM.path2feat(argv[1]);
  Mat trainNeg = testImgSVM.path2feat(argv[2]);
  Mat valPos = testImgSVM.path2feat(argv[3]);
  Mat valNeg = testImgSVM.path2feat(argv[4]);
  
  // Parse data to classfier
  testImgSVM.fillData(trainPos, trainNeg);

  // Configure parameters
  testImgSVM.SVMConfig();

  // Train SVM
  testImgSVM.SVMTrain();

  // Test SVM
  Mat res;
  testImgSVM.SVMPredict(valPos, res);
  unsigned int accum = 0;
  for (int it = 0; it < res.rows; it++) {
    if (res.at<float>(it, 0) > 0) {
      accum++;
    }
  }
  cout << "pos accuracy:\t" << float(accum)/res.rows << endl;

  accum = 0;
  testImgSVM.SVMPredict(valNeg, res);
  for (int it = 0; it < res.rows; it++) {
    if (res.at<float>(it, 0) < 0) {
      accum++;
    }
  }
  cout << "neg accuracy:\t" << float(accum)/res.rows << endl;

  return 0;
}
