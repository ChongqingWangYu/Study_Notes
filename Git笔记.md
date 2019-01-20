[TOC]

# Git笔记

## 下载和配置

### 下载

> 下载地址：https://git-scm.com/download

### 全局配置

> 使用git  config --global 参数进行全局配置，这个参数表示你这台机器上所有的git仓库都会使用这个配置，你也可以对某个仓库指定不同的用户名和邮箱

- 设置用户名<!--（在github上注册的用户名）-->

  ```
  git  config -- global  user.name '你再github上注册的用户名'
  ```

- 设置用户邮箱：<!--（注册时候的邮箱，该配置会在github主页上显示谁提交了该文件）-->


  ```
  git  config -- global  user.email  '注册时候的邮箱'
  ```

- 用如下命令来看看是否配置成功

  ```
  git config --list
  ```

### 局部配置

> 为不同的项目设置不同的用户名和邮箱

- 找到项目所在目录下（工作区）的 .git/文件夹，进入.git/文件夹，然后执行如下命令分别设置用户名和邮箱

  ```
  git config user.name "用户名"
  git config user.email "邮箱"
  ```

- 执行命令查看config文件

  ```
  cat config
  ```

------

## 基本操作命令（进入到工作区操作）

### 创建版本库和提交

- 初始化一个Git仓库，把一个文件夹变为Git可以管理的本地仓库

  ```
  git init
  ```

- 添加文件到Git仓库，分两步

  1. 提交到git暂存区<!--（工作区中有一个隐藏目录.git，这个是Git的版本库。Git的版本库中存了一个称为stage的暂存区）-->

     添加指定文件到暂存区：

     ```
     git add <file>
     ```

     添加所有修改的的文件到暂存区<!--(add和.之间有一个空格)-->：

     ```
     git add .
     ```

     例如：

     ```
     git add gitTest.txt
     ```

  2. 提交到本地仓库

     ```
     git commit -m <message>
     ```

     message为提交的备注信息，一般为这次提交干了什么

     例如：

     ```
     git commit -m 添加gitTest文件
     ```

- add和commit组合命令<!--（git add .和git commit -m <mesage>的合并）-->

  ```
  git commit -am <message>
  ```

### 版本回退

- 查看提交日志

  ```
  git log
  ```

  例如：

  ```
  $ git log
  commit 2e8b022a6e2ab2c8f246620f49fc13fb591e810a (HEAD -> master)
  Author: yyc007 <34782655@qq.com>
  Date:   Thu Jan 17 10:41:54 2019 +0800
  
      添加了三行
  
  commit 16ffdfa48ccc31bdb11d66ad9a552bc56d90d793
  Author: yyc007 <34782655@qq.com>
  Date:   Thu Jan 17 10:22:39 2019 +0800
  
      添加gitTest文件
  ```

- 版本回退到指定版本<!--（版本号就是git log信息中commit 后面的一大串内容）-->

  ```
  git reset --hard 版本号
  ```

  例如：

  ```
  $ git reset --hard 16ffdfa48ccc31bdb11d66ad9a552bc56d90d793
  HEAD is now at 16ffdfa 添加gitTest文件
  ```

  这时候通过git log 只有一条记录（添加gitTest文件）

- 版本回退到前面几个版本

  ```
  git reset --hard HEAD~版本数/HEAD^
  ```

  例如：(回退到上一个版本)

  ```
  git reset --hard HEAD~1
  ```

  或者

  ```
  git reset --hard HEAD^
  ```

  又例如：（回退到上上一个版本）

  ```
  git reset --hard HEAD~2
  ```

  或者

  ```
  git reset --hard HEAD^^
  ```

- 查看操作命令历史记录

  ```
  git reflog
  ```

  例如：

  ```
  $ git reflog
  bc70ed2 (HEAD -> master) HEAD@{0}: reset: moving to HEAD~1
  7fd2c6a HEAD@{1}: commit: 添加第二行内容
  bc70ed2 (HEAD -> master) HEAD@{2}: commit: 添加第一行内容
  16ffdfa HEAD@{3}: reset: moving to 16ffdfa48ccc31bdb11d66ad9a552bc56d90d793
  2e8b022 HEAD@{4}: commit: 添加了三行
  16ffdfa HEAD@{5}: commit (initial): 添加gitTest文件
  ```

### 撤销修改

- git status命令

  通过这个命令可以查看git中文件状态，比如一个文件已经提交到本地仓库，再对本地文件修改等操作，这时执行git status命令，文件名显示为红色，如下：

  ![1547695749454](images\1547695749454.png)

  表示文件还没有add到暂存区。这时执行add提交到暂存区后，文件名显示为绿色，如下：

  ![1547695948063](images\1547695948063.png)

  表示文件还没有commit到工作区。这时执行commit提交到工作区后，该文件的提示消失，如下：

  ![1547696048022](images\1547696048022.png)

  此时文件已经提交到本地仓库。

- 丢弃暂存区的修改

  当我们修改文件，通过git add <file>命令后，文件存在本地暂存区中。这时希望撤销本次对暂存区的提交，撤销后回到未add的状态。可通过下面的命令：

  ```
  git reset HEAD 文件
  ```

- 丢弃工作区的修改

  通过commit命令之后，文件已经更新到本地仓库中，也就是已经更新到工作区中。这时希望撤销本次对工作区的提交，撤销后回到未commit的状态。可通过下面的命令：

  ```
  git checkout -- 文件
  ```

------

## 远程仓库

> 通过gitee或github创建远程仓库并于本地仓库建立连接，将代码和文件托管到远程仓库中。

### 与远程仓库建立连接

- 在gitHub或码云上创建一个新的仓库，将远程仓库的git地址复制下来。然后通过命令建立连接，如下：

  ```
   git remote add origin url
  ```

  例如：

  ```
   git remote add origin https://gitee.com/yyc007/test-demo.git
  ```

### 将代码提交到远程仓库

- 提交到远程仓库的命令：

  ```
  git push -u origin master
  ```

  第一次提交会弹出输入用户名和密码。如果提示错误：

  ![1547703364588](images\1547703364588.png)

  就需要先执行一次：

  ```
  git pull --rebase origin master
  ```

  这是因为远程仓库上不是空的（比如：码云上新建仓库默认有一个ReadMe.md文件），需要先pull远程仓库到本地保持同步，如下效果如下图：

![1547703118476](images\1547703118476.png)

​	然后再push到远程仓库。  

![1547703593611](images\1547703593611.png)

### 远程仓库克隆

- 将远程仓库直接克隆到本地

  ```
  git clone url
  ```

### 分支管理

- 分支查看

  ```
  git branch
  ```

- 创建分支

  ```
  git branch <name> 
  ```

  例如（下同）：

  ```
  git branch dev
  ```

- 切换分支

  ```
  git checkout <name>
  ```

- 创建+切换分支组合命令

  ```
  git checkout -b <name>
  ```

- 删除分支

  ```
  git branch -d <name>
  ```

- 合并分支

  ```
  git merge <name>
  ```

### 多人协作

- 查看远程仓库信息

  ```
  git remote -v
  ```

- 从远程抓取分支

  ```
  git pull
  ```

- 推送分支

  将建立好的分支推送到远程仓库中

  ```
  git push origin <branch-name>
  ```

  例如：

  ```
   git push origin dev
  ```

  效果图：

  ![1547705187446](images\1547705187446.png)

  ![1547705238814](images\1547705238814.png)


