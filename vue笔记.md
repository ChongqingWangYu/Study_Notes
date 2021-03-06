# Vue笔记

## 基础工具介绍

### node

> 官网地址：http://nodejs.cn/

### nrm

> 作用：提供了一些最常用的NPM包镜像地址，能够让我们快速的切换安装包时候的服务器地址；

> 什么是镜像：原来包刚一开始是只存在于国外的NPM服务器，但是由于网络原因，经常访问不到，这时候，我们可以在国内，创建一个和官网完全一样的NPM服务器，只不过，数据都是从人家那里拿过来的，除此之外，使用方式完全一样；

> 安装和使用

1. 运行`npm i nrm -g`全局安装`nrm`包；
2. 使用`nrm ls`查看当前所有可用的镜像源地址以及当前所使用的镜像源地址；
3. 使用`nrm use npm`或`nrm use taobao`切换不同的镜像源地址；

*注意：nrm只是单纯的是供了几个常用的下戴包的URL地址，并能多让我们在这几个她址之间，很方便的进行切旋，但是，我们每次装包的时候，使用的装包工具，是npm*

### webpack

> 作用：webpack 是前端的一个项目构建工具，它是基于 Node.js 开发出来的一个前端工具；借助于webpack这个前端自动化构建工具，可以完美实现资源的合并、打包、压缩、混淆等诸多功能，最常见的功能有：
>
> 1. webpack 能够处理 JS 文件的互相依赖关系；
>
> 2. webpack 能够处理JS的兼容问题，把 高级的、浏览器不识别的语法，转为 低级的，浏览器能正常识别的语法

> 安装（两种方式）

1. 运行`npm i webpack -g`全局安装webpack，这样就能在全局使用webpack的命令
2. 在项目根目录中运行`npm i webpack --save-dev`安装到项目依赖中

