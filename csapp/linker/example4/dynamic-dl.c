#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int x[2]={1,2};
int y[2]={3,4};
int z[2];
int m[2];

int main (void){
    void *handle;
    void (*addvec)(int*,int*,int*,int);
    void (*multvec)(int*,int*,int*,int);
    handle=dlopen("./libvector.so",RTLD_GLOBAL|RTLD_LAZY);
    if(!handle){
        printf("open libvector.so error:%s",dlerror());
    }

    addvec=dlsym(handle,"addvec");
    multvec=dlsym(handle,"multvec");
    addvec(x,y,z,2);
    multvec(x,y,m,2);
    printf("add result:%d,%d\n",z[0],z[1]);
    printf("mult result:%d,%d\n",m[0],m[1]);

    if(dlclose(handle)){
        printf("close handle error:%s",dlerror());
    }
    return 0;
}