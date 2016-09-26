# trainSVM

Code to train a off-line head detector with OpenCV HOG+SVM method.

## Usage

- `cd trainSVM`

- generate training sample lists  

`./listGen.sh /data/gengshan/train/pos/ /data/gengshan/train/neg/ /data/gengshan/val/pos/ /data/gengshan/val/neg/`

- make

- ./trainSVM data/listPosTrain.txt data/listNegTrain.txt data/listPosVal.txt data/listNegVal.txt
