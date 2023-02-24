// library sini

// DFP lib
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

// DFplayer
static const uint8_t PIN_MP3_TX = 2; // Connects to module's RX
static const uint8_t PIN_MP3_RX = 3; // Connects to module's TX
SoftwareSerial softwareSerial(PIN_MP3_RX, PIN_MP3_TX);

// Create the Player object
DFRobotDFPlayerMini player;

int j1, j2, j3, j4, j5, x, y;

void setup() {
  Serial.begin(9600);
  Serial.println("Semangat Ngoding");
  Serial.println("+---------------+");
  Serial.println("  ");
  softwareSerial.begin(9600);

  // Start communication with DFPlayer Mini
  if (player.begin(softwareSerial)) {
    Serial.println("DFPlayer Mini connected");
  } else {
    Serial.println("Failed to Connect DFPlayer Mini!");
  }

}

void loop() {
  // adlx335
  x = analogRead (A6);
  y = analogRead (A5);
  float suduty = (((x - 365.0) / 65 * 9.8) * 10); //rumus x
  float sudutx = (((y - 375.0) / 68.5 * 9.8) * 10); //rumus y
  String kondisi;

  Serial.print(sudutx);
  Serial.print("  |  ");
  Serial.println(suduty);

  Serial.print(x);
  Serial.print("  |  ");
  Serial.println(y);


  Serial.println(" ");
  if (sudutx >= 50) {
    kondisi = "kanan";
  }
  else if (sudutx <= -40) {
    kondisi = "kiri";
  }
  else if (sudutx >= -39 && sudutx <= 49) {
    kondisi = "lurus";
  }
  if (suduty >= -50 && suduty <= -30) {
    kondisi = "lurusAtas";
  }
  Serial.println(kondisi);
  // adlx335

  //inisiasi jari
  j1 = analogRead (A0);
  j2 = analogRead (A1);
  j3 = analogRead (A2);
  j4 = analogRead (A3);
  j5 = analogRead (A4);

  //kalibrasi
  Serial.print(" ( ");
  Serial.print(j1);
  Serial.print(" )");
  Serial.print("  |  ");
  Serial.print(" ( ");
  Serial.print(j2);
  Serial.print(" )");
  Serial.print("  |  ");
  Serial.print(" ( ");
  Serial.print(j3);
  Serial.print(" )");
  Serial.print("  |  ");
  Serial.print(" ( ");
  Serial.print(j4);
  Serial.print(" )");
  Serial.print("  |  ");
  Serial.print(j5);
  Serial.print(" )");
  Serial.println("  |  ");
  //jari


  // kalibrasi adxl335
  //    Serial.print(" ( ");
  //    Serial.print(x);
  //    Serial.print(" )");
  //    Serial.print("  |  ");
  //
  //    Serial.print(" ( ");
  //    Serial.print(y);
  //    Serial.print(" )");
  //    Serial.println("  |  ");


  //kata-kata
  // AKHIR ABJAD
  if (j1 >= 760 && j1 <= 790 && j2 >= 520 && j2 <= 550 && j3 >= 450 && j3 <= 480 && j4 >= 470 && j4 <= 490 && j5 >= 450 && j5 <= 480 && (kondisi == "kiri" || kondisi == "lurusAtas")) {
    player.volume(50);
    player.play(2);
    Serial.println("Suara  diputar");
    Serial.print("A");
    delay(3000);
  }
  else if (j1 >= 800 && j1 <= 850 && j2 >= 530 && j2 <= 590 && j3 >= 490 && j3 <= 530 && j4 >= 530 && j4 <= 570 && j5 >= 450 && j5 <= 485 && (kondisi == "kanan" || kondisi == "lurusAtas")) {
    player.volume(50);
    player.play(3);
    Serial.println("Suara  diputar");
    Serial.print("B");
    delay(3000);
  }
  else if (j1 >= 810 && j1 <= 850 && j2 >= 585 && j2 <= 610 && j3 >= 450 && j3 <= 470 && j4 >= 470 && j4 <= 490 && j5 >= 450 && j5 <= 470 && kondisi == "lurus") {
    player.volume(50);
    player.play(4);
    Serial.println("Suara  diputar");
    Serial.print("C");
    delay(3000);
  }
  else if (j1 >= 810 && j1 <= 850 && j2 >= 585 && j2 <= 610 && j3 >= 450 && j3 <= 470 && j4 >= 470 && j4 <= 490 && j5 >= 450 && j5 <= 470 && kondisi == "kanan") {
    player.volume(50);
    player.play(5);
    Serial.println("Suara  diputar");
    Serial.print("D");
    delay(3000);
  }  else if (j1 >= 800 && j1 <= 850 && j2 >= 530 && j2 <= 590 && j3 >= 490 && j3 <= 520 && j4 >= 530 && j4 <= 560 && j5 >= 450 && j5 <= 485 && (kondisi == "kanan" || kondisi == "lurusAtas")) {
    player.volume(50);
    player.play(6);
    Serial.println("Suara  diputar");
    Serial.print("E");
    delay(3000);
  }
  else if (j1 >= 825 && j1 <= 850 && j2 >= 535 && j2 <= 560 && j3 >= 480 && j3 <= 540 && j4 >= 460 && j4 <= 490 && j5 >= 450 && j5 <= 470 && kondisi == "kanan") {
    player.volume(50);
    player.play(7);
    Serial.println("Suara  diputar");
    Serial.print("F");
    delay(3000);
  }
  else if (j1 >= 810 && j1 <= 865 && j2 >= 680 && j2 <= 720 && j3 >= 445 && j3 <= 470 && j4 >= 470 && j4 <= 490 && j5 >= 450 && j5 <= 470 && kondisi == "kanan") {
    player.volume(50);
    player.play(8);
    Serial.println("Suara  diputar");
    Serial.print("G");
    delay(3000);
  }
  else if (j1 >= 520 && j1 <= 550 && j2 >= 540 && j2 <= 580 && j3 >= 450 && j3 <= 470 && j4 >= 470 && j4 <= 490 && j5 >= 450 && j5 <= 470 && kondisi == "lurus") {
    player.volume(50);
    player.play(9);
    Serial.println("Suara  diputar");
    Serial.print("H");
    delay(3000);
  }
  else if (j1 >= 840 && j1 <= 890 && j2 >= 670 && j2 <= 700 && j3 >= 450 && j3 <= 470 && j4 >= 460 && j4 <= 490 && j5 >= 520 && j5 <= 550 && kondisi == "lurus") {
    player.volume(50);
    player.play(10);
    Serial.println("Suara  diputar");
    Serial.print("I");
    delay(3000);
  }
  else if (j1 >= 840 && j1 <= 890 && j2 >= 670 && j2 <= 700 && j3 >= 450 && j3 <= 470 && j4 >= 460 && j4 <= 470 && j5 >= 500 && j5 <= 550 && kondisi == "kanan") {
    player.volume(50);
    player.play(11);
    Serial.println("Suara  diputar");
    Serial.print("J");
    delay(3000);
  }
  else if (j1 >= 810 && j1 <= 850 && j2 >= 585 && j2 <= 610 && j3 >= 450 && j3 <= 470 && j4 >= 470 && j4 <= 490 && j5 >= 450 && j5 <= 470 && kondisi == "lurus") {
    player.volume(50);
    player.play(12);
    Serial.println("Suara  diputar");
    Serial.print("K");
    delay(3000);
  }
  else if (j1 >= 810 && j1 <= 850 && j2 >= 585 && j2 <= 610 && j3 >= 450 && j3 <= 470 && j4 >= 470 && j4 <= 490 && j5 >= 450 && j5 <= 470 && kondisi == "lurus") {
    player.volume(50);
    player.play(13);
    Serial.println("Suara  diputar");
    Serial.print("L");
    delay(3000);
  }
  else if (j1 >= 810 && j1 <= 850 && j2 >= 535 && j2 <= 610 && j3 >= 520 && j3 <= 550 && j4 >= 460 && j4 <= 500 && j5 >= 470 && j5 <= 570 && kondisi == "lurus") {
    player.volume(50);
    player.play(14);
    Serial.println("Suara  diputar");
    Serial.print("M");
    delay(3000);
  }
  else if (j1 >= 810 && j1 <= 850 && j2 >= 585 && j2 <= 610 && j3 >= 450 && j3 <= 470 && j4 >= 470 && j4 <= 490 && j5 >= 450 && j5 <= 470 && kondisi == "lurus") {
    player.volume(50);
    player.play(15);
    Serial.println("Suara  diputar");
    Serial.print("N");
    delay(3000);
  }
  else if (j1 >= 810 && j1 <= 850 && j2 >= 585 && j2 <= 610 && j3 >= 450 && j3 <= 470 && j4 >= 470 && j4 <= 490 && j5 >= 450 && j5 <= 470 && kondisi == "lurus") {
    player.volume(50);
    player.play(16);
    Serial.println("Suara  diputar");
    Serial.print("O");
    delay(3000);
  }
  else if (j1 >= 810 && j1 <= 850 && j2 >= 585 && j2 <= 610 && j3 >= 450 && j3 <= 470 && j4 >= 470 && j4 <= 490 && j5 >= 450 && j5 <= 500 && kondisi == "lurus") {
    player.volume(50);
    player.play(17);
    Serial.println("Suara  diputar");
    Serial.print("P");
    delay(3000);
  }
  else if (j1 >= 810 && j1 <= 850 && j2 >= 585 && j2 <= 610 && j3 >= 450 && j3 <= 470 && j4 >= 470 && j4 <= 490 && j5 >= 450 && j5 <= 470 && kondisi == "lurus") {
    player.volume(50);
    player.play(18);
    Serial.println("Suara  diputar");
    Serial.print("Q");
    delay(3000);
  }
  else if (j1 >= 810 && j1 <= 850 && j2 >= 585 && j2 <= 610 && j3 >= 450 && j3 <= 470 && j4 >= 470 && j4 <= 490 && j5 >= 450 && j5 <= 470 && kondisi == "lurus") {
    player.volume(50);
    player.play(19);
    Serial.println("Suara  diputar");
    Serial.print("R");
    delay(3000);
  }
  else if (j1 >= 810 && j1 <= 850 && j2 >= 585 && j2 <= 610 && j3 >= 450 && j3 <= 470 && j4 >= 470 && j4 <= 490 && j5 >= 450 && j5 <= 470 && kondisi == "lurus") {
    player.volume(50);
    player.play(20);
    Serial.println("Suara  diputar");
    Serial.print("S");
    delay(3000);
  }
  else if (j1 >= 810 && j1 <= 850 && j2 >= 555 && j2 <= 610 && j3 >= 450 && j3 <= 470 && j4 >= 470 && j4 <= 490 && j5 >= 450 && j5 <= 470 && kondisi == "kiri") {
    player.volume(50);
    player.play(21);
    Serial.println("Suara  diputar");
    Serial.print("T");
    delay(3000);
  }
  else if (j1 >= 810 && j1 <= 850 && j2 >= 585 && j2 <= 610 && j3 >= 450 && j3 <= 470 && j4 >= 470 && j4 <= 490 && j5 >= 450 && j5 <= 470 && kondisi == "lurus") {
    player.volume(50);
    player.play(22);
    Serial.println("Suara  diputar");
    Serial.print("U");
    delay(3000);
  }
  else if (j1 >= 810 && j1 <= 850 && j2 >= 585 && j2 <= 610 && j3 >= 450 && j3 <= 470 && j4 >= 470 && j4 <= 490 && j5 >= 450 && j5 <= 470 && kondisi == "lurus") {
    player.volume(50);
    player.play(23);
    Serial.println("Suara  diputar");
    Serial.print("V");
    delay(3000);
  }
  else if (j1 >= 810 && j1 <= 850 && j2 >= 585 && j2 <= 610 && j3 >= 450 && j3 <= 470 && j4 >= 470 && j4 <= 490 && j5 >= 450 && j5 <= 470 && kondisi == "lurus") {
    player.volume(50);
    player.play(24);
    Serial.println("Suara  diputar");
    Serial.print("W");
    delay(3000);
  }
  else if (j1 >= 810 && j1 <= 850 && j2 >= 585 && j2 <= 610 && j3 >= 450 && j3 <= 470 && j4 >= 470 && j4 <= 490 && j5 >= 450 && j5 <= 470 && kondisi == "lurus") {
    player.volume(50);
    player.play(25);
    Serial.println("Suara  diputar");
    Serial.print("X");
    delay(3000);
  }
  else if (j1 >= 810 && j1 <= 850 && j2 >= 585 && j2 <= 610 && j3 >= 450 && j3 <= 470 && j4 >= 470 && j4 <= 490 && j5 >= 450 && j5 <= 470 && kondisi == "lurus") {
    player.volume(50);
    player.play(26);
    Serial.println("Suara  diputar");
    Serial.print("Y");
    delay(3000);
  }
  else if (j1 >= 750 && j1 <= 800 && j2 >= 560 && j2 <= 620 && j3 >= 470 && j3 <= 530 && j4 >= 500 && j4 <= 580 && j5 >= 500 && j5 <= 550 && kondisi == "lurus") {
    player.volume(50);
    player.play(27);
    Serial.println("Suara  diputar");
    Serial.print("Z");
    delay(3000);
  }

  // AKHIR ABJAD

  //ANGKA
  else if (j1 >= 820 && j1 <= 850 && j2 >= 55 && j2 <= 580 && j3 >= 445 && j3 <= 480 && j4 >= 450 && j4 <= 490 && j5 >= 440 && j5 <= 480 && kondisi == "lurus") {
    player.volume(50);
    player.play(28);
    Serial.println("Suara  diputar");
    Serial.print("SATU");
    delay(3000);
  }
  else if (j1 >= 825 && j1 <= 850 && j2 >= 535 && j2 <= 560 && j3 >= 480 && j3 <= 540 && j4 >= 460 && j4 <= 490 && j5 >= 450 && j5 <= 470 && kondisi == "lurus") {
    player.volume(50);
    player.play(29);
    Serial.println("Suara  diputar");
    Serial.print("DUA");
    delay(3000);
  }
  else if (j1 >= 800 && j1 <= 840 && j2 >= 525 && j2 <= 570 && j3 >= 510 && j3 <= 550 && j4 >= 520 && j4 <= 580 && j5 >= 460 && j5 <= 480 && kondisi == "lurus") {
    player.volume(50);
    player.play(30);
    Serial.println("Suara  diputar");
    Serial.print("TIGA");
    delay(3000);
  }
  else if (j1 >= 845 && j1 <= 880 && j2 >= 525 && j2 <= 560 && j3 >= 515 && j3 <= 550 && j4 >= 550 && j4 <= 590 && j5 >= 540 && j5 <= 580 && kondisi == "lurus") {
    player.volume(50);
    player.play(31);
    Serial.println("Suara  diputar");
    Serial.print("EMPAT");
    delay(3000);
  }
  else if (j1 >= 770 && j1 <= 820 && j2 >= 500 && j2 <= 540 && j3 >= 515 && j3 <= 550 && j4 >= 540 && j4 <= 600 && j5 >= 565 && j5 <= 590 && kondisi == "lurus") {
    player.volume(50);
    player.play(32);
    Serial.println("Suara  diputar");
    Serial.print("LIMA");
    delay(3000);
  }
  else if (j1 >= 770 && j1 <= 800 && j2 >= 660 && j2 <= 690 && j3 >= 430 && j3 <= 470 && j4 >= 450 && j4 <= 490 && j5 >= 440 && j5 <= 480 && kondisi == "lurus") {
    player.volume(50);
    player.play(33);
    Serial.println("Suara  diputar");
    Serial.print("ENAM");
    delay(3000);
  }
  else if (j1 >= 780 && j1 <= 810 && j2 >= 510 && j2 <= 560 && j3 >= 450 && j3 <= 500 && j4 >= 460 && j4 <= 490 && j5 >= 450 && j5 <= 480 && kondisi == "lurus") {
    player.volume(50);
    player.play(34);
    Serial.println("Suara  diputar");
    Serial.print("TUJUH");
    delay(3000);
  }
  else if (j1 >= 760 && j1 <= 805 && j2 >= 510 && j2 <= 610 && j3 >= 500 && j3 <= 540 && j4 >= 470 && j4 <= 500 && j5 >= 450 && j5 <= 480 && kondisi == "lurus") {
    player.volume(50);
    player.play(35);
    Serial.println("Suara  diputar");
    Serial.print("DELAPAN");
    delay(3000);
  }
  else if (j1 >= 780 && j1 <= 820 && j2 >= 510 && j2 <= 550 && j3 >= 510 && j3 <= 550 && j4 >= 550 && j4 <= 590 && j5 >= 470 && j5 <= 520 && kondisi == "lurus") {
    player.volume(50);
    player.play(36);
    Serial.println("Suara  diputar");
    Serial.print("SEMBILAN");
    delay(3000);
  }
  else if (j1 >= 770 && j1 <= 820 && j2 >= 500 && j2 <= 540 && j3 >= 515 && j3 <= 550 && j4 >= 540 && j4 <= 600 && j5 >= 565 && j5 <= 590 && kondisi == "kanan") {
    player.volume(50);
    player.play(37);
    Serial.println("Suara  diputar");
    Serial.print("SEPULUH");
    delay(3000);
  }

  // AKHIR ANGKA

  //KATA

  else if (j1 >= 800 && j1 <= 850 && j2 >= 585 && j2 <= 610 && j3 >= 450 && j3 <= 470 && j4 >= 470 && j4 <= 490 && j5 >= 450 && j5 <= 470 && kondisi == "lurus") {
    player.volume(50);
    player.play(38);
    Serial.println("Suara  diputar");
    Serial.print("Hallo");
    delay(3000);
  }
  else if (j1 >= 810 && j1 <= 850 && j2 >= 555 && j2 <= 610 && j3 >= 450 && j3 <= 470 && j4 >= 470 && j4 <= 490 && j5 >= 450 && j5 <= 470 && kondisi == "kanan") {
    player.volume(50);
    player.play(39);
    Serial.println("Suara  diputar");
    Serial.print("kamu");
    delay(3000);
  }
  else if (j1 >= 810 && j1 <= 850 && j2 >= 585 && j2 <= 610 && j3 >= 450 && j3 <= 470 && j4 >= 470 && j4 <= 490 && j5 >= 450 && j5 <= 470 && kondisi == "lurus") {
    player.volume(50);
    player.play(40);
    Serial.println("Suara  diputar");
    Serial.print("saya");
    delay(3000);
  }
  else if (j1 >= 810 && j1 <= 850 && j2 >= 585 && j2 <= 610 && j3 >= 450 && j3 <= 470 && j4 >= 470 && j4 <= 490 && j5 >= 450 && j5 <= 470 && kondisi == "lurus") {
    player.volume(50);
    player.play(41);
    Serial.println("Suara  diputar");
    Serial.print("siapa");
    delay(3000);
  }
  else if (j1 >= 810 && j1 <= 850 && j2 >= 585 && j2 <= 610 && j3 >= 450 && j3 <= 470 && j4 >= 470 && j4 <= 490 && j5 >= 450 && j5 <= 470 && kondisi == "lurus") {
    player.volume(50);
    player.play(42);
    Serial.println("Suara  diputar");
    Serial.print("nama");
    delay(3000);
  }
  else if (j1 >= 810 && j1 <= 850 && j2 >= 585 && j2 <= 610 && j3 >= 450 && j3 <= 470 && j4 >= 470 && j4 <= 490 && j5 >= 450 && j5 <= 470 && kondisi == "lurus") {
    player.volume(50);
    player.play(43);
    Serial.println("Suara  diputar");
    Serial.print("apa kabar");
    delay(3000);
  }
  else if (j1 >= 820 && j1 <= 850 && j2 >= 55 && j2 <= 580 && j3 >= 445 && j3 <= 480 && j4 >= 450 && j4 <= 490 && j5 >= 440 && j5 <= 480 && kondisi == "lurus") {
    player.volume(50);
    player.play(44);
    Serial.println("Suara  diputar");
    Serial.print("tuli");
    delay(3000);
  }
  else if (j1 >= 840 && j1 <= 870 && j2 >= 530 && j2 <= 570 && j3 >= 440 && j3 <= 475 && j4 >= 530 && j4 <= 570 && j5 >= 550 && j5 <= 585 && ( kondisi == "lurus" || kondisi== "kiri")) {
    player.volume(50);
    player.play(45);
    Serial.println("Suara  diputar");
    Serial.print("maaf");
    delay(3000);
  }
  else if (j1 >= 810 && j1 <= 850 && j2 >= 585 && j2 <= 610 && j3 >= 450 && j3 <= 470 && j4 >= 470 && j4 <= 490 && j5 >= 450 && j5 <= 470 && kondisi == "lurus") {
    player.volume(50);
    player.play(46);
    Serial.println("Suara  diputar");
    Serial.print("terima kasih");
    delay(3000);
  }
  else if (j1 >= 810 && j1 <= 850 && j2 >= 585 && j2 <= 610 && j3 >= 450 && j3 <= 470 && j4 >= 470 && j4 <= 490 && j5 >= 450 && j5 <= 470 && kondisi == "lurus") {
    player.volume(50);
    player.play(47);
    Serial.println("Suara  diputar");
    Serial.print("umur");
    delay(3000);
  }
  else if (j1 >= 810 && j1 <= 850 && j2 >= 585 && j2 <= 610 && j3 >= 450 && j3 <= 470 && j4 >= 470 && j4 <= 490 && j5 >= 450 && j5 <= 470 && kondisi == "lurus") {
    player.volume(50);
    player.play(48);
    Serial.println("Suara  diputar");
    Serial.print("lagi");
    delay(3000);
  }
  else if (j1 >= 810 && j1 <= 850 && j2 >= 585 && j2 <= 610 && j3 >= 450 && j3 <= 470 && j4 >= 470 && j4 <= 490 && j5 >= 450 && j5 <= 470 && kondisi == "lurus") {
    player.volume(50);
    player.play(49);
    Serial.println("Suara  diputar");
    Serial.print("sulit");
    delay(3000);
  }
    else if (j1 >= 750 && j1 <= 790 && j2 >= 640 && j2 <= 680 && j3 >= 440 && j3 <= 480 && j4 >= 480 && j4 <= 520 && j5 >= 530 && j5 <= 570 && kondisi == "lurus") {
    player.volume(50);
    player.play(50);
    Serial.println("Suara  diputar");
    Serial.print("sama");
    delay(3000);
  }
  else if (j1 >= 810 && j1 <= 850 && j2 >= 585 && j2 <= 610 && j3 >= 450 && j3 <= 470 && j4 >= 470 && j4 <= 490 && j5 >= 450 && j5 <= 470 && kondisi == "lurus") {
    player.volume(50);
    player.play(1);
    Serial.println("Suara  diputar");
    Serial.print("terakhir");
    delay(3000);
  }
  //AKHIR KATA
  //kata-kata


  delay(1000);
}
