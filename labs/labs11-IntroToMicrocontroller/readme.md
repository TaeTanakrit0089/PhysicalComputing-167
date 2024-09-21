# Week 11 - Introduction to Microcontroller

## Today Topics

1. [Intro to Arduino-R4-WiFi](01.Arduino-R4-WiFi)
2. [LED Matrix](02.LED_Matrix)
3. [RGB LED](03.RGB%20LED.md)
4. [7 Segment](04.7%20Segment.md)

## Today Exercises

เข็คส่งงาน: https://bit.ly/PhyCom2024Score

1. **LED Matrix**: ให้สร้างเป็นตัวอักษรแรกของชื่อเล่นของตัวเองเป็นภาษาอังกฤษออกทาง LED Matrix
   โดยแต่ละตัวอักษรต้องอยู่คนละเฟรม เช่น
    - **TAE:** ให้แสดงเป็น `T`, `A` และ `E`
      ![ex01.png](files/img/ex01.png)
2. **Blinking LED**: ให้เขียนโปรแกรมและใช้งานร่วมกับหลอดไฟ LED เพื่อให้หลอดไฟนั้นกระพิบเป็นจังหวะเรื่อยๆ
    - สามารถกำหนดความถี่ในการกระพิบเองได้
    - ให้ต่อ Resistor เข้ากับ LED ด้วยเพื่อป้องกันหลอดขาด
3. **RGB**: จงเขียนโปรแกรมแสดงสี 7 สี โดยเว้นช่วงสีละ 1 วินาที
   ![rgb.jpg](files/img/rgb.jpg)
4. **7Segment**: จงเขียนโปรแกรมแสดงเลขทีละ 2 หลักท้ายของรหัสนักศึกษา
    - เช่นรหัส 66070012 ก็แสดง 64 07 00 12 ช่วงละ 1 วินาที
      ![ex02.jpg](files/img/ex02.jpg)
    - Hint: ใช้วิธี Multiplexing

## How to install Arduino

Go to https://www.arduino.cc/en/software

![install01.jpg](files/img/install01.jpg)
![install02.jpg](files/img/install02.jpg)

เมื่อ Install เสร็จแล้วให้เปิดโปรแกรม Arduino ขึ้นมาและไปโหลด Board `Arduino UNO R4`

![install03.jpg](files/img/install03.jpg)