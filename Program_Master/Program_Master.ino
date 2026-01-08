#include "HX711.h"
#include <Servo.h>
#include <SoftwareSerial.h>
#include <Wire.h>            // Untuk I2C
#include <LiquidCrystal_I2C.h>  // Library LCD I2C

// PIN KONEKSI LOADCELL
const int LOADCELL_DOUT_PIN = A1;
const int LOADCELL_SCK_PIN = A0;

// PIN SERVO
const int SERVO_PIN_1 = 9;   // Servo Pintu Masuk
const int SERVO_PIN_2 = 10;  // Servo Gerbang Utama
const int SERVO_PIN_3 = 11;  // Gerbang Sortasi 1 (50-120 g)
const int SERVO_PIN_4 = 6;   // Gerbang Sortasi 2 (120-200 g)

// PIN UNTUK KOMUNIKASI DENGAN ESP32
SoftwareSerial espSerial(2, 3); // RX, TX

HX711 scale;
Servo servo1, servo2, servo3, servo4;

// Inisialisasi LCD (Alamat I2C, 20 karakter, 4 baris)
LiquidCrystal_I2C lcd(0x27, 20, 4);

float calibration_factor = 22700.0; 

void setup() {
  Serial.begin(9600);      // Serial untuk debugging di PC
  espSerial.begin(9600);   // Serial untuk komunikasi ke ESP32
  
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_scale(calibration_factor);
  scale.tare();

  servo1.attach(SERVO_PIN_1);
  servo2.attach(SERVO_PIN_2);
  servo3.attach(SERVO_PIN_3);
  servo4.attach(SERVO_PIN_4);

  servo1.write(0); 
  servo2.write(90); 
  servo3.write(0); 
  servo4.write(5); 

  Serial.println("Sistem sortasi siap.");
  
  // Inisialisasi LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Sistem Sortasi");

  delay(2000);
}

void loop() {
  // Langkah 1: Masukkan ikan
  servo1.write(0); 
  delay(4000); 
  servo1.write(100); 
  delay(2000);
  
  // Langkah 2: Proses Penimbangan
  float rawWeight = scale.get_units(10); 
  float W = rawWeight * 51.8411222078;
  String category = "Lainnya"; // Kategori default

  // Langkah 3: Gerakkan servo dan tentukan kategori
  if (W >= 50 && W <= 120) {
    category = "Kecil";
    servo2.write(10); 
    servo3.write(28); 
    delay(7000);      
  } else if (W > 120 && W <= 200) {
    category = "Sedang";
    servo2.write(10); 
    servo4.write(36); 
    delay(12000); 
  } else if (W > 200) {
    category = "Besar";
    servo2.write(10);
    servo3.write(0); 
    servo4.write(5); 
    delay(7000);  
  } else {
    category = "Di Bawah Batas";
    // Tidak ada servo yang bergerak
    delay(2000);
  }

  // Langkah 4: Siapkan dan kirim data ke ESP32
  String dataToSend = String(W, 1) + "," + category;
  Serial.println(dataToSend); // Perintah ini seharusnya membuat LED TX berkedip
  espSerial.println("Mengirim data: " + dataToSend); 
  delay(200);
  
  // Menampilkan data ke LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Berat: ");
  lcd.print(W, 1);   // Menampilkan berat dengan 1 angka desimal
  lcd.setCursor(0, 1);
  lcd.print("Kategori: ");
  lcd.setCursor(0, 2);
  lcd.print(category);

  // Langkah 5: Atur ulang posisi servo
  servo2.write(90);
  servo3.write(0);
  servo4.write(5);
  delay(5000);

  delay(1000);  // Delay sejenak sebelum memperbarui tampilan
}
