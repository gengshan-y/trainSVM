####
 # Filename:        listGen.sh
 # Date:            Sep 20 2016
 # Last Edited by:  Gengshan Yang
 # Description:     Usage: ./listGen.sh path-to positive-images
 #                  path-to-negative-images 
 ####

currPath=$PWD 

cd $1
ls -d -1 $PWD/*.* > ${currPath}/listPos.txt

cd $2
ls -d -1 $PWD/*.* > ${currPath}/listNeg.txt

cd $currPath
