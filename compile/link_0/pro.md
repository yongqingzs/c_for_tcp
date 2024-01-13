## 静态链接
```bash
gcc -c addvec.c multvec.c
ar rcs libvector.a addvec.o multvec.o
gcc -c main.c
gcc -static -o prog1 main.o -L. -lvector
# gcc -static -o prog main.o libvector.a  # same as above
# gcc -static -o prog libvector.a main.o  # error
./prog1
```
## 动态链接
```bash
gcc -shared -fpic -o libvector.so addvec.c multvec.c
gcc -rdynamic -o prog2 dll.c -ldl
./prog2  # 如果删除了libvector.so，那么./prog会报错
```