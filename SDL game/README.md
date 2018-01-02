注意：貌似git没有把lib和dll文件上传到github，这个需要自己再手动下一遍吧。

配置环境的要点：
1 配置好include和lib的路径，可以用$(ProjectDir)这个环境变量
2 把linker 的System中的SubSystem 从console改成window，这样可以让console窗口不弹出来。
3 把dll文件放到跟exe文件同一个目录。
4 注意configuration是64还是x86
5 配置SDL image时，要把所有（4个以上）的dll文件都复制到执行目录里才行，不然加载png时既不报错，也无法显示图片

