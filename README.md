# trainSVM

- `cd trainSVM`

- generate training sample lists  

`./listGen.sh /data/gengshan/train/pos/ /data/gengshan/train/neg/ /data/gengshan/val/pos/ /data/gengshan/val/neg/`

- make

- ./trainSVM data/listPosTrain.txt data/listNegTrain.txt data/listPosVal.txt data/listNegVal.txt
