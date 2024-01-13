```bash
gcc -c addvec.c multvec.c
ar rcs libvector.a addvec.o multvec.o
gcc -c main.c
gcc -static -o prog main.o -L. -lvector
# gcc -static -o prog main.o libvector.a  # same as above
# gcc -static -o prog libvector.a main.o  # error
./prog
```