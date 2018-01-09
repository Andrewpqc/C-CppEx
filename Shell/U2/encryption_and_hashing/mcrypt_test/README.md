首先下载mcrypt
``` bash
$ sudo apt install mcrypt
```
# 加密文件
``` bash
$ mcrypt file
```
接下来按照要求输入口令，加密完成后将生成file.nc，这个就是加密后得到的文件，我们可以将该文件发送给其他人，其他人可以通过下面的命令解密.
# 解密
``` bash
$ mcrypt -d file.nc
```
输入正确的口令(和加密时相同的口令)之后即可解密成功，得到file文件
