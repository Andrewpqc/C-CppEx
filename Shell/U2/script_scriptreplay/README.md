# 启动录制
``` bash
$ script -t 2>timing.log -a output.session
```
开始输入你的命令，这些命令的时序，输出信息将会被分别保存
在timing.log和output.session中

# 结束录制
``` bash
$ exit
```

# 回放
``` bash
$ scriptreplay timing.log output.session
```
或者
``` bash
$ bash replay.sh
```
只要你将这个timing.log,output.session文件拷给别人，别人在机子上运行即可回放你录制的命令