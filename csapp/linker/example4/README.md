## 创建目标文件，创建归档文件，静态链接编异程序
gcc -c addvec.c multvec.c
ar rcs libvector.a addvec.o multvec.o
gcc -c main.c
gcc -static -o prog main.o ./libvector.a

## 创建动态链接库
gcc -shared -fpic -o libvector.so addvec.c multvec.c
gcc -o prog-dynamic main.c ./libvector.so

#编译动态链接程序
gcc -rdynamic -o prog-ddl dynamic-dl.c -ldl