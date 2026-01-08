// Definisi untuk Blynk - HARAP DIISI SESUAI DASHBOARD BLYNK ANDA
#define BLYNK_TEMPLATE_NAME "s"
#define BLYNK_TEMPLATE_ID "TMPL6M8IKQz64"
#define BLYNK_AUTH_TOKEN "DjXv2VU5L8eTTMOXaVaTzSvoRrGOpJiH"
#define BLYNK_PRINT Serial

// Library yang dibutuhkan
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

// Kredensial Wi-Fi Anda
char ssid[] = "fikriridho";
char pass[] = "administrator";

// Variabel untuk menyimpan data ikan terakhir
float berat = 0.0;
String kategori = "";

// Variabel counter untuk setiap kategori
int jumlahKecil = 0;
int jumlahSedang = 0;
int jumlahBesar = 0;
int TOTAL = 0;

void setup() {
  // Mulai Serial untuk debugging di Serial Monitor PC
  Serial.begin(9600);
  
  // Mulai Serial2 untuk menerima data dari Arduino
  // RX2 terhubung ke GPIO 16
  // TX2 terhubung ke GPIO 17
  Serial2.begin(9600); 
  
  Serial.println("ESP32 siap menerima data dari Arduino...");

  // Menghubungkan ke Blynk
  Serial.println("Menghubungkan ke Blynk...");
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  Serial.println("Terhubung ke Blynk!");
}

void loop() {
  // Menjalankan fungsi Blynk
  Blynk.run();

  // Cek apakah ada data yang masuk dari Arduino melalui Serial2
  if (Serial.available()) {
    // Baca data string sampai menemukan karakter newline ('\n')
    String dataMasuk = Serial.readStringUntil('\n');
    dataMasuk.trim(); // Hapus spasi atau karakter tak terlihat di awal/akhir

    // Proses hanya jika data tidak kosong
    if (dataMasuk.length() > 0) {
      Serial.print("Data mentah diterima: ");
      Serial.println(dataMasuk);

      // Cari posisi karakter koma (',') sebagai pemisah
      int pemisah = dataMasuk.indexOf(',');

      // Jika koma ditemukan (format data benar)
      if (pemisah != -1) {
        // Ambil bagian sebelum koma (berat)
        String beratStr = dataMasuk.substring(0, pemisah);
        // Ambil bagian setelah koma (kategori)
        kategori = dataMasuk.substring(pemisah + 1);

        // Ubah string berat menjadi angka float dan simpan di variabel 'berat'
        berat = beratStr.toFloat();

        // Perbarui counter berdasarkan kategori yang diterima
        if (kategori == "Kecil") {
          jumlahKecil++;
        } else if (kategori == "Sedang") {
          jumlahSedang++;
        } else if (kategori == "Besar") {
          jumlahBesar++;
        }

        TOTAL = jumlahKecil + jumlahSedang + jumlahBesar;



        // --- PERBAIKAN: HAPUS BLOK TIMER MILLIS() ---
        // Data sekarang dikirim ke Blynk SETIAP KALI data baru diterima dari Arduino.
        // Ini adalah perilaku yang paling logis untuk proyek ini.

        // --- MENGIRIM DATA KE BLYNK ---
        Blynk.virtualWrite(V0, berat);
        Blynk.virtualWrite(V1, jumlahKecil);
        Blynk.virtualWrite(V2, jumlahSedang);
        Blynk.virtualWrite(V3, jumlahBesar);
        Blynk.virtualWrite(V4, TOTAL);

        // Tampilkan status terbaru di Serial Monitor
        Serial.println("--- HASIL TERBARU (DIKIRIM KE BLYNK) ---");
        Serial.print("Berat Ikan Terakhir: ");
        Serial.print(berat);
        Serial.println(" g");
        
        Serial.print("Kategori Ikan Terakhir: ");
        Serial.println(kategori);
        Serial.println();
        
        Serial.println("--- TOTAL HITUNGAN ---");
        Serial.print("Jumlah Ikan Kecil: ");
        Serial.println(jumlahKecil);
        
        Serial.print("Jumlah Ikan Sedang: ");
        Serial.println(jumlahSedang);
        
        Serial.print("Jumlah Ikan Besar: ");
        Serial.println(jumlahBesar);

        Serial.print("Jumlah Total Ikan: ");
        Serial.println(TOTAL);
        Serial.println("========================\n");
      }
    }
  }
}
