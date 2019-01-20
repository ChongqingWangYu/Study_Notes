# Servlet笔记

## Servlet技术

> Java Servlet技术简称Servlet技术，是Java开发Web应用的底层技术。由Sun公式于1996年发布，用来代替CGI——当时生成Web动态内容的主流技术。

## Servlet技术与CGI技术的比较

> Servlet是一个特殊的Java程序，一个基于Java的Web应用通常包含一个或多个Servlet类。Servlet不能够自行创建并执行，必须运行在Servlet容器中。Servlet容器将用户的请求传递给Servlet程序，并将Servlet的响应回传给用户。通常一个Servlet会关联一个或多个JSP页面。CGI技术的主要问题是每个Web请求都需要新启动一个进程来处理，创建进程会消耗不少CPU周期，导致难以编写可扩展的CGI程序。而Servlet有着比CGI程序更好的性能，因为Servlet在创建后（处理第一个请求时）就一直保持在内容中。

### CGI的缺点

- 需要为每个请求加载和运行一个CGI程序，这将带来很大的CPU开销
- 需要重复编写处理网络协议的代码以及编码，耗时费力。

### Servlet的优点

- 只需要启动一个操作系统进程以及加载一个JVM，大大降低了系统的开销
- 如果多个请求需要做同样处理的时候，这时候只需要加载一个类，这也大大降低了开销
- 所有动态加载的类可以实现对网络协议以及请求解码的共享，大大降低了工作量。
- Servlet能直接和Web服务器交互，而普通的CGI程序不能。Servlet还能在各个程序之间共享数据，使数据库连接池之类的功能很容易实现。

## Servlet运行原理

### Servlet的处理步骤

![img](images\969110-20170212132656901-1174433025.jpg)

### Servlet的生命周期

> Servlet生命周期定义了一个Servlet如何被加载、初始化，以及它怎样接收请求、响应请求，提供服务等。

Servlet接口

在这里我们自己随便建的一个Servlet,他默认继承自HttpServlet类，可以发现最终实现了接口Servlet。见下图：

![1547967677803](images\1547967677803.png)

其中Servlet接口中定义了如下五个方法，其中**init,service,destory是生命周期方法**：

```java
void init(ServletConfig var1) throws ServletException;

ServletConfig getServletConfig();

void service(ServletRequest var1, ServletResponse var2) throws ServletException, IOException;

String getServletInfo();

void destroy();
```

#### 生命周期方法

- init()方法，**只执行一次**：只有当该Servlet第一次被请求时，Servlet容器会调用一次这个方法。无论有多少客户机访问Servlet，都不会再重复执行这个方法。我们可以利用这个方法执行相应的初始化工作。

- service()方法，**客户端每次请求Servlet都会执行**：它是Servlet的核心，每当请求Servlet时，Servlet容器就会调用这个方法，而且每次请求都会传递给这个方法一个“请求”（ServletRequest）对象和一个“响应”（ServletResponse）对象作为参数。第一次请求Servlet时，Servlet容器调用init()方法和service()方法。后续的请求将只调用Service方法。

  通常service()方法会根据需要调用与请求对应的**doGet或doPost**等方法（是HttpServlet这个类处理的）。

- destroy()方法，**只执行一次**：当服务器关闭或项目被卸载时服务器会将Servlet实例销毁，此时会调用Servlet的destroy()方法。此时init()方法中的所有初始化工作将被销毁。

Servlet中有时会用到一些需要初始化与销毁的资源，因此可以把初始化资源的代码放入init方法中，销毁资源的代码放入destroy方法中，这样就不需要每次处理客户端的请求都要初始化与销毁资源。

#### 生命周期方法中的几个参数

- ServletRequest：对于每一个HTTP请求，Servlet容器都会创建一个ServletRequest实例，并将它传给Servlet的Service方法。ServletRequest封装了关于这个请求的信息。

- ServletResponse:：javax.servlet.ServletResponse接口表示一个Servlet响应。在**调用Servlet的Service方法前**，Servlet容器会首先创建一个ServletResponse，并将它作为第二个参数传给Service方法。ServletResponse隐藏了向浏览器发送响应的复杂过程。

  在ServletResponse中定义的方法之一是getWriter方法，它返回了一个可以向客户端发送文本的java.io.PrintWriter。默认情况下，PrintWriter对象使用**ISO-8859-1**编码。

- ServletConfig：Servlet的初始化方法(init方法)会传入一个ServletConfig。它里面封装的是初始参数（是key，value键值对），初始参数的设置可以通过web.xml和@WebServlet设置。该接口中包含了如下方法：

```
    String getServletName();

    ServletContext getServletContext();

    String getInitParameter(String var1);

    Enumeration<String> getInitParameterNames();
```

通过在ServletConfig中调用**getServletContext**方法，可以获取ServletContext，它表示一个Servlet应用程序。每个Web应用程序只有一个上下文。如果将一个应用程序同时部署到多个容器的分布式环境中时，每台java虚拟机上的Web应用都会有一个ServletContext对象。有了ServletContext，就可以共享从应用程序中可以访问到的信息，并且可以动态注册Web对象。

可以通过**java.util.Enumeration<java.lang.String> getInitParameterNames()**获取所有的初始参数名称；

可以通过**java.lang.String getInitParameter(java.lang.String name)**获取到初始参数的值。

#### GenericServlet和HttpServlet类

- GenericServlet类

由于Servlet类是一个接口，如果通过实现Servlet接口来写Servlet的话，那我们就必须实现它的所有方法（5个），即便其中有一些根本就没有包含任何代码。所以我们那样做是没有意义的。还好有GenericServlet类的出现，它是一个抽象类，实现了Servlet和ServletConfig接口，并完成以下任务：

> - 将init方法中的ServletConfig赋给一个类级变量，以便可以通过调用getServletConfig获取。
> - 为Servlet接口中的所有方法提供默认的实现。
> - 提供方法，包含ServletConfig中的方法。

- HttpServlet类

HttpServlet类覆盖了GenericServlet类。使用HttpServlet时，还要借助分别代表Servlet请求和Servlet响应的HttpServletRequest和HttpServletResponse对象，HttpServletRequest和HttpServletResponse分别继承自ServletRequest和ServletResponse，并新增了一些方法（比如：Cookie相关，Session相关方法）。

在HttpServlet类中，原始的Service(覆写自GenericServlet)方法将Servlet容器request和response对象分别转换成HttpServletRequest和HttpServletResponse，并调用新的Service方法。

在新的Service方法中会检验用来发送请求的Http方法（通过调用request.getMethod），并调用相对应的方法（doGet、doPost、doHead、doPut、doTrace、doOptions和doDelete）,这七种方法中，每一种方法都表示一个Http方法，doGet和doPost是最常用的。

因此，我们继承自HttpServlet的Servlet就不用覆盖Service方法了，只需要覆盖我们需要的对应http方法即可。

