配置环境的要点：
1 配置好include和lib的路径，可以用$(ProjectDir)这个环境变量
2 把linker 的System中的SubSystem 从console改成window。
3 把dll文件放到跟exe文件同一个目录。