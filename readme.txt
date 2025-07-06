macOS

brew install gcc
gcc hello-world.c; ./a.out
gcc single\ core\ -\ count\ to\ 4.3\ billion.c; time ./a.out
gcc single\ core\ -\ count\ to\ 10\ billion.c; time ./a.out
gcc multi\ core\ -\ count\ to\ 100\ billion.c; time ./a.out

Hello World!

real	0m4.159s
user	0m4.120s
sys	0m0.025s

real	0m9.615s
user	0m9.561s
sys	0m0.053s
Final count: 100000000000

real	0m20.328s
user	2m29.586s
sys	0m0.559s