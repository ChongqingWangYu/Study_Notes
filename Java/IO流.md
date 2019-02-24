# IO流

## 文本IO

Java中有很多I/O类，区分为输出类和输入类。最简单的输入输出类就是使用Scanner类读取文本数据、使用PrintWriter类写文本数据。

下面是一个输出类的例子（写文件）：

```java
PrintWriter output = new PrintWriter("temp.txt");
output.print("text io");
output.close();
```

下面是一个输入类的例子（读文件）：

```java
Scanner input = new Scanner(new File("temp.txt"));
System.out.print(input.nextLine());
```

输入对象从文件中读取数据流，输出对象将数据流写入文件。输入对象也称为输入流（input stream），输出对象称为输出流（output stream）。

## 文本IO和二进制IO比较

二进制I/O从文件中读取一个字节，将其直接复制到内存中，反之亦然。文本I/O需要编码和解码。在编写字符时，JVM将Unicode转换为特定于文件的编码，并在读取字符时将特定于文件的编码转换为Unicode。所以，二进制I/O效率比二进制I/O高。