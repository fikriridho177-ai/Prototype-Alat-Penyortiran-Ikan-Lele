## PROTOTYPE ALAT PENYORTIRAN IKAN LELE BERBASIS IoT MELALUI APLIKASI ANDROID

### Tujuan Proyek: 

Membangun prototipe alat penyortiran ikan lele otomatis berbasis IoT yang dapat memilah ikan berdasarkan berat, serta memonitoring data secara real-time melalui aplikasi Android.



### Komponen Sistem:
Mikrokontroler: Arduino Uno R3 sebagai unit pemrosesan data sensor dan aktuator, serta ESP32 sebagai pusat komunikasi IoT.


### Sensor & Aktuator: 
Sensor loadcell HX711 untuk mengukur berat ikan, dan motor servo SG-90 untuk menggerakkan gerbang sortir.

### Integrasi: 
Data berat ditampilkan melalui aplikasi Blynk dan disimpan ke dalam database MongoDB menggunakan RESTful API.

### Kategori Penyortiran: 
Sistem membagi ikan lele ke dalam tiga kategori berat:
Kecil: < 120 gram.
Sedang: 120–200 gram.
Besar: > 200 gram.

### Hasil Pengujian:
Sensor loadcell HX711 menunjukkan kinerja yang baik dengan nilai rata-rata galat sebesar 2,90%.
Sistem berhasil melakukan penyortiran ikan lele sesuai dengan kategori berat yang ditentukan dan mengirimkan data ke aplikasi serta database secara real-time.


### Kesimpulan: 
Prototipe yang dibangun berhasil memenuhi tujuan penelitian dengan menyediakan solusi digital yang membantu pembudidaya dalam proses penyortiran ikan lele yang lebih efisien dan terotomatisasi.

### 📸 Dokumentasi & Sistem Kerja (Showcase)

#### 1. Desain Mekanik & Prototipe Fisik
<img width="714" height="367" alt="image" src="https://github.com/user-attachments/assets/12ffa3fe-8479-4e18-b703-55133f944644" />

Dimensi keseluruhan dari wadah pada Gambar memiliki detail sebagai berikut :

1) Panjang : 90cm
2) Tinggi : 36cm
3) Lebar : 15cm


#### 2. Rangkaian Elektronik (Wiring)
*(Di sini masukkan foto kotak panel tempat Arduino, ESP32, dan kabel-kabel terpasang)*
![Rangkaian Elektronik](link-foto-wiring-di-sini.jpg)

#### 3. Arsitektur Sistem (Block Diagram)
*(Di sini masukkan gambar Block Diagram yang ada di Bab 3)*
![Block Diagram Sistem](link-foto-diagram-di-sini.jpg)

#### 4. Dashboard Pemantauan (Aplikasi & Database)
*(Di sini masukkan gabungan Screenshot aplikasi Blynk dan Screenshot database MongoDB)*
![Dashboard Blynk & MongoDB](link-foto-software-di-sini.jpg)

---

## ⚙️ Cara Instalasi & Penggunaan
1. Konfigurasi `SSID` dan `PASSWORD` Wi-Fi pada file ESP32.
2. Masukkan `AUTH TOKEN` Blynk ke dalam kode.
3. Pastikan server lokal MongoDB berjalan pada port `27017`.
4. Upload kode `slave.ino` ke Arduino Uno dan `master.ino` ke ESP32.




# 🐟 Prototipe Alat Penyortiran Ikan Lele Berbasis IoT (Android App)

Prototipe alat penyortiran ikan lele otomatis berbasis IoT yang dapat memilah ikan berdasarkan berat secara presisi, serta memonitor data secara *real-time* melalui aplikasi Android.

---

## 📌 Komponen & Arsitektur Sistem

* **Mikrokontroler:** 
  * **Arduino Uno R3:** Unit pemrosesan data sensor & aktuator.
  * **ESP32:** Pusat komunikasi data IoT.
* **Sensor & Aktuator:**
  * **Loadcell HX711:** Mengukur berat ikan.
  * **Motor Servo SG-90:** Menggerakkan gerbang sortir.
* **Integrasi & Database:**
  * **Blynk App:** Tampilan pemantauan *real-time* pada Android.
  * **MongoDB:** Penyimpanan data melalui RESTful API.

---

## ⚖️ Kategori Penyortiran

| Kategori | Ukuran Berat |
| :--- | :--- |
| **Kecil** | `< 120 gram` |
| **Sedang** | `120 – 200 gram` |
| **Besar** | `> 200 gram` |

---

## 📊 Hasil Pengujian & Kesimpulan

* **Akurasi Sensor:** Sensor loadcell HX711 menunjukkan kinerja yang baik dengan nilai rata-rata *error/galat* hanya sebesar **2.90%**.
* **Kesimpulan:** Sistem berhasil melakukan penyortiran ikan lele secara otomatis sesuai kategori berat dan mengirimkan data telemetry ke aplikasi Blynk serta database MongoDB secara *real-time*.

---

## 📸 Dokumentasi & Showcase

### 1. Desain Mekanik & Prototipe Fisik
* **Panjang:** 90 cm
* **Tinggi:** 36 cm
* **Lebar:** 15 cm

![Desain Mekanik]( link_gambar_mekanik_anda.jpg )

### 2. Rangkaian Elektronik (Wiring)
![Wiring Diagram]( link_gambar_wiring_anda.jpg )

### 3. Arsitektur Sistem (Block Diagram)
![Block Diagram]( link_gambar_block_diagram.jpg )

### 4. Dashboard Pemantauan (Aplikasi & Database)
![Dashboard UI]( link_gambar_dashboard.jpg )

---

## ⚙️ Cara Instalasi & Penggunaan

1. Buka kode ESP32, lalu sesuaikan konfigurasi `SSID` dan `PASSWORD` Wi-Fi Anda.
2. Masukkan `AUTH TOKEN` Blynk ke dalam kode ESP32.
3. Pastikan server lokal **MongoDB** sudah berjalan pada port `27017`.
4. Upload kode `slave.ino` ke **Arduino Uno**.
5. Upload kode `master.ino` ke **ESP32**.
