# Lab 12 - Introduction to Microcontroller

## Today Topics

1. [Intro to Arduino-R4-WiFi](01.Arduino-R4-WiFi.md)
2. [RGB LED](02.RGB%20LED.md)
3. [7 Segment](03.7%20Segment.md)

## Today Exercises

**เข็คส่งงาน:** https://bit.ly/PhyCom2025Score

| ข้อ                        | รายละเอียด                                                                                                                                                                                                                                                                                                                                                                                                                              | ตัวอย่าง                                                                                            |
|----------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------|
| **1. ไฟกระพิบ:**           | ให้สร้างไฟกระพิบโดนให้กำหนดความถี่ในการกระพิบเอง                                                                                                                                                                                                                                                                                                                                                                                        |                                                                                                     |
| **2. RGB:**                | จงเขียนโปรแกรมแสดงสี 7 สี โดยเว้นช่วงสีละ 1 วินาที <br/> <br/>- **RGB ที่แจกคือประเภท Common Anode** <br/> <br/>**Hint:** [วิธีการต่อ](02.RGB%20LED.md#วิธีการต่อ-rgb-common-anode)                                                                                                                                                                                                                                                     | ![ex02-rgb-example.png](files/img/ex02-rgb-example.png)                                             |
| **3. 7Segment (1 digit):** | จงเขียนโปรแกรมแสดงเลข 0-9 โดยเว้นช่วงละ 1 วินาที  <br/> <br/> - **Hint:** [วิธีการต่อ](03.7%20Segment.md#labs-03-วิธีการต่อ-7-segment-common-cathode-แบบ-1-ตัว) <br/> - [Tinkercad](https://www.tinkercad.com/things/eMgolJBjfB4-arduino-7-segment-display-common-cathode?sharecode=obS0eusqqYM8q-2Yjtl2wpl8u_L5XufAHJziz3IJyjc)                                                                                                        | ![ex02.jpg](files/img/ex04-Arduino7segmentdisplay.png)                                              | 
| **4. 7Segment (2 digit):** | จงเขียนโปรแกรมแสดงเลขทีละ 2 หลักท้ายของรหัสนักศึกษา <br> - เช่นรหัส 66070012 ก็แสดง 64 07 00 12 ช่วงละ 1 วินาที <br> - Hint: ใช้วิธี Multiplexing  <br/> <br/> - **Hint:** [วิธีการต่อ](03.7%20Segment.md#labs-04-วิธีการต่อ-7-segment-common-cathode-แบบ-2-ตัว)<br/>- [Tinkercad](https://www.tinkercad.com/things/0UFIFnMgv3X-arduino-7-segment-display-2-digit-common-cathode?sharecode=r6QYv58_iq_AP0dGzT7TQb2cb2Nh-sM8MlHVzgRnydk) | ![ex04.jpg](files/img/Arduino%207%20segment%20display%20%282%20digit%29%20-%20Common%20Cathode.png) | 

สไลด์ Lecture: [PC67-12_Micro01.pdf](files/PC67-12_Micro01.pdf)

## How to install Arduino

Go to https://www.arduino.cc/en/software

![install01.jpg](files/img/install01.jpg)
![install02.jpg](files/img/install02.jpg)

เมื่อ Install เสร็จแล้วให้เปิดโปรแกรม Arduino ขึ้นมาและไปโหลด Board `Arduino UNO R4`

![install03.jpg](files/img/install03.jpg)