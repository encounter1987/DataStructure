PROBLEM=$1

make INPUT=Input SRC=$PROBLEM
make clean

# delete swp files
rm -rf  .*.swp   *~      ../DsUtils/.*.swp    ../DsUtils/*~
