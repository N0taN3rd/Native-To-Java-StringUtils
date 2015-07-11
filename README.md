Quick implementation of String methods in C++ that were originally written in Java and  a few other methods. 
The goal was to begin teaching myself the JNI interface.

This code was written in windows 64bit and compiled using g++ 5.1.0 and using jdk1.8.0_45
To compile use:
<br>Java: javac StringUtils.java
<br>C++: g++ -IpathTo\Java\jdk1.8.0_45\include -IpathTo\jdk1.8.0_45\include\win32 StringUtils.cpp -shared -o StringUtils.dll-std=c++11
	
To run:
	java StringUtils
