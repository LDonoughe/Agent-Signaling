#!/bin/bash

DIR=$1
DIRTWO=$2
if [ -d $DIRTWO ]; then
	echo directory exists
else
	mkdir $DIRTWO
	echo directory created
fi
echo generating new model
ruby generate_0th_iteration.rb > $DIR/0.xml
echo running simulation - takes approximately 2 minutes
$DIR/main 10000 $DIR/0.xml > $DIRTWO/log.txt
echo copying data
# Separating out files to avoid errors
cp $DIR/0* $DIRTWO
cp $DIR/1[,0-4]* $DIRTWO
cp $DIR/1[5-9]* $DIRTWO
cp $DIR/2[,0-4]* $DIRTWO
cp $DIR/2[5-9]* $DIRTWO
cp $DIR/3[,0-4]* $DIRTWO
cp $DIR/3[5-9]* $DIRTWO
cp $DIR/4[,0-4]* $DIRTWO
cp $DIR/4[5-9]* $DIRTWO
cp $DIR/[5-9]* $DIRTWO
cp $DIR/[a-k,m-z]* $DIRTWO
cp $DIR/l[a-h,j-z]* $DIRTWO
echo Extracting data, making graphs
ruby parse_xml_extract_strategies.rb $DIR/ | Rscript createGraph.R > xmldata.csv
echo moving graphs to correct location
mv Rplots.pdf $DIRTWO
mv xmldata.csv $DIRTWO
