## 编译时打桩
```bash
gcc -DCOMPILETIME -c mymalloc.c
gcc -I. -o prog1 int.c mymalloc.o
./prog1
```

## 链接时打桩
```bash
gcc -DLINKTIME -c mymalloc1.c
gcc -c int.c
gcc -Wl,--wrap,malloc -Wl,--wrap,free -o prog2 int.o mymalloc1.o
./prog2
```

## 运行时打桩
```bash
gcc -DRUNTIME -shared -fpic -o mymalloc2.so mymalloc2.c -ldl
gcc -o prog3 int.c
LD_PRELOAD=./mymalloc2.so ./prog3
```

## NOTE
1. 在wsl中进行测试，链接时打桩和运行时打桩都会出现“Segmentation fault”的错误