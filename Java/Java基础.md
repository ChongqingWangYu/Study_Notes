# Java基础

## 什么是OO,OOA,OOD,OOP？

> 参考：[https://www.jianshu.com/p/41b3d7e1c624](https://www.jianshu.com/p/41b3d7e1c624)

- OO :**Object - Oriented** ,面向对象,基于对象概念,以对象为中心,以类和继承为构造机制,来认识,理解,刻画客观世界和设计,构建相应的软件系统的一门方法;本意-- 模拟人类的思维方式,使开发,维护,修改更加容易。
- OOA:**Object - Oriented Analysis**, 面向对象分析,强调的是在系统调查资料的基础上,针对OO方法所需要的素材进行的归类分析和整理,而不是对管理业务现状和方法的分析---其实就是进一步对OO进行细化,初步得出OO的方法(或者简单的理解:在得出的文档中对接口粗略定义)。
- OOD:**Object - Oriented Design**,面向对象设计,OO方法中一个中间过渡环节,其主要作用是对OOA分析的结果进一步的规范和整理,以便能够被OOP直接接受---整理和定义OO的属性和方法。
- OOP:**Object - Oriented Programming**,把组件的实现和接口分开,并且让组件具有多态性---(抽象,封装,继承,多态)面向接口编程。

## 抽象和封装、继承、多态

> 封装、继承、多态称为Java面向对象的三大特性。

### 抽象和封装

- 类的抽象：将类的实现和类的使用分开。

- 类的封装：实现的细节被封装并且对用户隐藏。

类的创建者描述类的功能，让使用者明白如何才能使用类。从类外可以访问的方法和数据域的集合以及预期这些成员如何行为的描述。类的使用者不需要知道类是如何实现的。

### 继承

继承是使用已存在的类的定义作为基础建立新类的技术，新类的定义可以增加新的数据或新的功能，也可以用父类的功能，但不能选择性地继承父类。通过使用继承我们能够非常方便地复用以前的代码。

1. 子类拥有父类非 private 的属性（数据域）和方法。
2. 子类可以拥有自己属性和方法，即子类可以对父类进行扩展。
3. 子类可以用自己的方式实现父类的方法（重写）。
4. 子类不可以重写父类的构造方法。

### 多态 

> 多态意味着父类的变量可以指向子类对象。
>

#### 实现方式

在Java中有两种形式可以实现多态：继承（多个子类对同一方法的重写）和接口（实现接口并覆盖接口中同一方法）。

#### 动态绑定

一个方法可以在继承链的几个类中被实现。JVM决定在运行时调用哪个方法。

## 自动装箱与拆箱

### 装箱

> 将基本类型值转换为包装类对象的过程称为装箱（boxing）；

### 拆箱

> 装箱的相反转换过程，将包装类对象转换为基本数据类型的过程称为装箱（unboxing）；

Java允许基本类型和包装类类型之间进行**自动转换**。

## BigInteger和BigDecimal类

> BigInteger和BigDecimal类可以用于表示任意大小和精度的整数或者十进制数。他们位于`java.math`包中。

使用`new BigInteger();`和`new BigDecimal();`创建BigInteger和BigDecimal的实例。

使用`add`,`substract`,`multipe`,`divide`,`remainder`方法完成算术运算（加、减、乘、除、取余），例如下面是一个取余的例子：

```java
BigInteger num1 = new BigInteger("123123");
BigInteger num2 = new BigInteger("10");
BigInteger result = num1.remainder(num2);//123123 % 10
System.out.println(result);
```

## String 、StringBuffer和StringBuilder

### 可变性

String 类中使用 final 关键字字符数组保存字符串，`private　final　char　value[]`，所以 String 对象是**不可变**的。如下，源码中String类的定义：

```java
public final class String
	implements java.io.Serializable, Comparable<String>, CharSequence {
		/** The value is used for character storage. */
    	private final char value[];
    	...
    	...
    
}
```

StringBuilder 与 StringBuffer 都继承自 AbstractStringBuilder 类，在 AbstractStringBuilder 中也是使用字符数组保存字符串`char[]value` 但是没有用 final 关键字修饰，所以这两种对象都是**可变**的。

### 线程安全性

**String** 中的对象是不可变的，也就可以理解为常量，**线程安全**。AbstractStringBuilder 是 StringBuilder 与 StringBuffer 的公共父类，定义了一些字符串的基本操作，如 expandCapacity、append、insert、indexOf 等公共方法。**StringBuffer** 对方法加了同步锁或者对调用的方法加了同步锁（在源码中可以看到每个方法都加了`synchronized`关键字），所以是**线程安全**的。**StringBuilder** 并没有对方法进行加同步锁，所以是**非线程安全**的。 　　

### 性能

每次对 String 类型进行改变的时候，都会生成一个新的 String 对象，然后将指针指向新的 String 对象。

StringBuffer 每次都会对 StringBuffer 对象本身进行操作，而不是生成新的对象并改变对象引用。

相同情况下使用 StringBuilder 相比使用 StringBuffer 仅能获得 10%~15% 左右的性能提升，但却要冒多线程不安全的风险。

如果是多任务并发访问，使用StringBuffer；如果是单任务访问，使用StringBuilder会更有效。

## 方法重写和重载

### 方法重写

是指子类从父类中继承方法。使用场景一般是子类需要修改父类中定义的方法的实现。

- 仅当实例方法是可访问的，才能被覆盖。如果子类中定义的方法在父类中是私有的，那么这两个方法完全没有关系。
- 重写的方法必须使用相同的签名和相同的返回值类型在子类中定义。
- 静态方法也**能被继承但不能被覆盖**。

### 方法重载

重载方法使得你可以使用相同的名字来定义不同的方法，只要它们的签名是不同的。也就是说，一个类中有多个方法，具有相同的名字，但有不同的参数列表。Java编译器根据方法签名决定使用哪个方法。

### 重写和重载的区别

- 方法重写放生在通过继承而相关的不同类中；方法重载可以发生在同一个类中，也可以发生在由于继承而相关的不同类中。
- 方法重写具有相同的签名和返回值类型；方法重载具有相同的名字，但是不同的参数列表。

## 对象转换

> 对象的引用可以类型转换为对另一种对象的引用，这称为对象转换。

- 将对象`new Student()`赋值给一个`Object`类型的参数：

```java
Object o = new Student();
```

由于Student的实例也是Object的实例，所以语句`Object o = new Student();`合法。称为**隐式转换（implicit casting）**。像这样，将一个子类的实例转换成一个父类的变量，称为**向上转换（upcasting）**。

- 将`Object`类型的对象赋值给一个`Student`类型的参数：

```java
Student s = (Student)o;
```

为了告诉编译器o是一个Student对象，就要使用**显示转换（explicit casting）**。像这样，把一个父类的实例转换为它的子类变量，称为**向下转换（downcasting）**。

## equals方法与"=="运算符

**equals()** : 它的作用也是判断两个对象是否相等。但它一般有两种使用情况：

- 类没有覆盖 equals() 方法。则通过 equals() 比较该类的两个对象时，等价于通过“==”比较这两个对象。
- 类覆盖了 equals() 方法。一般，我们都覆盖 equals() 方法来两个对象的内容相等；若它们的内容相等，则返回 true (即，认为这两个对象相等)。

*注：*equals方法是被定义在Object类中的，但在Java API的许多类中被重写，比如我们常用的`java.lang.String`和`java.util.Date`，用于比较两个对象的内容是否相等。

**警告：**在之类中，应该使用`equals(Object obj)`签名来重写equals方法，而不是形如`equals(SomeClassName obj)`来重写。

**==** : 比较两个基本数据类型的值是否相等，或者判断两个对象是否具有相同的引用。

## 可见性修饰符

> 修饰符private、protected和public都称为可见性修饰符(visibility modifier)或可访问性修饰符(accessibility modifier)。用来指定是否可以从类外部访问数据域和方法。

### 类中成员的修饰符

| 类中成员的修饰符 | 在同一类可访问 | 在同一包内可访问 | 在子类内可访问 | 在不同包可访问 |
| :--------------: | :------------: | :--------------: | :------------: | :------------: |
|      public      |       √        |        √         |       √        |       √        |
|    protected     |       √        |        √         |       √        |       —        |
|    (default)     |       √        |        √         |       —        |       —        |
|     private      |       √        |        —         |       —        |       —        |

private：完全隐藏类的成员，不能从类外直接访问；

(default)：允许同一个包内的任何类直接访问类的成员，但是其它包中的类不可以访问；

protected：允许任何包中的子类或同一包中的类访问类的成员；

public：允许任意类访问类的成员。

### 类修饰符

修饰符private和protected只能用于类中的成员。public修饰符和(default)修饰符（也就是没有修饰符）既可以用于类的成员，也可以用于类。也就是说**一个类要么没有修饰符要么就是用public修饰**，但是**一个没有修饰符的类不能被其它包中的类访问**。

**注意**：子类可以重写它的父类中被protected修饰的方法，并把它的可见性改为public。但是**子类不能削弱父类中定义的方法的可访问性**，例如，如果一个方法在父类中定义为public，在子类中也必须定义为public。