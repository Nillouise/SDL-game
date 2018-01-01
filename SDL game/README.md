配置环境的要点：
1 配置好include和lib的路径，可以用$(ProjectDir)这个环境变量
2 把linker 的System中的SubSystem 从console改成window，这样可以让console窗口不弹出来。
3 把dll文件放到跟exe文件同一个目录。
4 注意configuration是64还是x86