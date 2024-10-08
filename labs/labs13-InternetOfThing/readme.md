# Week 12 - Digital To Analog

## Today Topics

1. [MQTT Broker](01.MQTT%20Broker.md)
2. [Connect to ITKMITL WiFi](02.Connect%20To%20ITKMITL%20WiFi.md)
3. [Connect to Personal WiFi](03.Connect%20to%20Personal%20WiFi.md)
4. [Arduino With MQTT.md](04.Arduino%20With%20MQTT.md)

## Today Exercises

**เข็คส่งงาน:** https://bit.ly/PhyCom2024Score

| ข้อ                        | รายละเอียด                                                                                                                                                                                                                                                                                                                                | ตัวอย่าง                                                                                         |
|----------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------|
| **1. Web Server:**         | ให้นำโค้ดนี้ไปรันและเปิด Web Server ผ่านตัว Arduino ให้ได้                                                                                                                                                                                                                                                                                | [Open Web Server With Arduino](02.Connect%20To%20ITKMITL%20WiFi.md#open-web-server-with-arduino) |
| **2. MQTT Potentiometer:** | ต่อตัวต้านทานปรับค่าได้และส่งค่าของตัวต้านทานไปที่ HiveMQ                                                                                                                                                                                                                                                                                 | ![img.png](files/img/ex2.png)                                                                    |
| **3. MQTT LED:**           | ให้ publish ค่า 0-255 แล้วไปสั่งให้หลอด LED หรี่, สว่างค่าที่ส่งมา <br/> <br/> - 0 คือดับ <br/> - 255 คือสว่างสุด <br/> <br/> ในฟังก์ชั่น messageHandler เพิ่มโปรแกรม `void messageHandler(String &topic, String &payload)` จะต้องเปลี่ยน payload จาก String ให้เป็น Interger ก่อน <br/> <br/> `val = XXX.toInt();` `analogWrite(9,val);` | ![img.png](files/img/ex3.png)                                                                    |
| **4. MQTT Pair:**          | ให้นศ จับคู่กัน<br/>- คนส่งส่งค่าจาก Potentiometer <br/> - คนรับนำค่าไปสั่งให้หลอด LED หรี่เหมือนข้อที่ 3                                                                                                                                                                                                                                 | ![img.png](files/img/ex4.png)                                                                    |
| **5. Feedback Form:**      | ให้ประเมินวิขา Physical Computing และ TA <br/> https://forms.office.com/r/PrFUWGzfVu                                                                                                                                                                                                                                                      | ![ex5.png](files/img/ex5.png)                                                                    |

สไลด์ Lecture: [PC67-15_Micro03.pdf](files/PC67-15_Micro03.pdf)

