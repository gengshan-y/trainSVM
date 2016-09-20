#include "imgSVM.hpp"

using namespace std;
using namespace cv;

void imgSVM::showInfo() {
  cout << "feature size:\t" << featSize << endl;
  cout << "SVM params:" << endl;
  cout << "svm_type:\t" << params.svm_type << endl;
  cout << "kernel_type:\t" << params.kernel_type << endl;
  cout << "degree:\t" << params.degree << endl;
  cout << "gamma:\t" << params.gamma << endl;
  cout << "coef0:\t" << params.coef0 << endl;
  cout << "C:\t" << params.C << endl;
  cout << "nu:\t" << params.nu << endl;
  cout << "p:\t" << params.p << endl;
  cout << "class_weights:\t" << params.class_weights << endl;
  cout << "term_crit_type:\t" << params.term_crit.type << endl;
  cout << "term_crit_max_iter:\t" << params.term_crit.max_iter << endl;
  cout << "term_crit_epsilon:\t" << params.term_crit.epsilon << endl;
}

void imgSVM::Mat2samp() {
  float labels[4] = {1.0, -1.0, -1.0, -1.0};
  float trainingData[4][2] = {{501, 10}, {255, 10}, {501, 255}, {10, 501}};

  Mat(4, 2, CV_32FC1, trainingData).copyTo(trainingDataMat);  // avoid reference
  Mat(4, 1, CV_32FC1, labels).copyTo(labelsMat);
}

void imgSVM::SVMConfig() {
  params.svm_type    = CvSVM::C_SVC;
  params.kernel_type = CvSVM::LINEAR;
  params.term_crit   = cvTermCriteria(CV_TERMCRIT_ITER, 100, 1e-6);
  showInfo(); 
}

void imgSVM::SVMTrain() {
  SVM.train(trainingDataMat, labelsMat, Mat(), Mat(), params);
}

float imgSVM::SVMPredict(Mat sampleMat) {
  return SVM.predict(sampleMat);
}

void imgSVM::path2feat(char* imgListPath) {
  /* Open image list file */  
  ifstream imgListFile(imgListPath, ios::binary);
  if (!imgListFile.is_open()) {
    cout << "image list open failed." << endl;
    exit(-1);
  }
  imgListFile.seekg(0, ios_base::beg);

  /* Load image and perform transformation */
  string imgPath;
  while (getline(imgListFile, imgPath)) {
    Mat img = imread(imgPath, CV_LOAD_IMAGE_COLOR);
    // imshow("", img);
    // waitKey(0);

    /* Compute HOG feature */
    resize(img, img, Size(64, 64));
    HOGDescriptor HOG(winSize, blockSize, blockStride, cellSize, nbins);
    vector<float> feat;  // temp 1764 dim vector
    Mat featMat(1, featSize, CV_32FC1);  // temp mat

    HOG.compute(img, feat, winStride);
    for (unsigned int it = 0; it < feat.size(); it++) {
      featMat.at<float>(0, it) = feat[it];
    }
    trainingPos.push_back(featMat);
  }
   cout << trainingPos.size() << endl; 
  exit(-1);
}
