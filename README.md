# fireDetector on WOKWI
![image](https://github.com/user-attachments/assets/c7bb50e4-d8c4-4e5e-8edf-5f92901dc573)
<h3> Embedded System Fire Detector</h3> without waterpump & flamesensor


![image](https://github.com/user-attachments/assets/2d0a81a0-534c-4eff-872d-155c4b2e985f)
<h3> IOT Fire Detector</h3> without waterpump & flamesensor<br>
<h3>Tambahkan datastream di blink dengan</h3><br>
🟢 1. Datastream untuk Suhu (Temperature) <br>
Name: Temperature<br>
Type: Virtual Pin<br>
Virtual Pin: V0<br>
Data type: Double<br>
Units: °C<br>
Min/Max: Misalnya 0 - 100<br>
Widget / Display: Gauge, Value Display, atau Chart<br>
<br>
🟡 2. Datastream untuk Gas (MQ2 Sensor)<br>
Name: Gas Sensor<br>
Type: Virtual Pin<br>
Virtual Pin: V1<br>
Data type: Integer<br>
Units: Misalnya: ppm (jika dikalibrasi) atau Analog<br>
Min/Max: 0 - 4095 (karena ADC ESP32 12-bit)<br>
Widget / Display: Gauge, Value Display, atau Chart<br>
<br>
🔴 3. Datastream untuk Flame (Sensor Api)<br>
Name: Flame<br>
Type: Virtual Pin<br>
Virtual Pin: V2<br>
Data type: Integer (gunakan 0 atau 1)<br>
Min/Max: 0 - 1<br>
Widget / Display: LED, Value Display, atau Notification trigger
