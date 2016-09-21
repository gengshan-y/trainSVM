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
  cout << res.rows << endl;
  cout << res << endl;

  testImgSVM.SVMPredict(valNeg, res);
  cout << res.rows << endl;
  cout << res << endl; 

  return 0;
}
