```bash
gcc -shared -fpic -o libvector.so addvec.c multvec.c  # 在link_0中
gcc -rdynamic -o prog dll.c -ldl
./prog  # 如果删除了libvector.so，那么./prog会报错
```