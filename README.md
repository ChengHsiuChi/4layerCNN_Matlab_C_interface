## Dataset
Mnist
## Original performance
863 seconds in 10 epochs \
Where tensorflow took 483 seconds originally
## With caccum.cpp to replace accumarray in vTP
626 seconds in 10 epochs
## With outersum.cpp to replace outer sum in vTP
605 seconds in 10 epochs
## With makepoolP.m to replace P(max_id) in maxpooling
595 seconds in 10 epochs
