#define Buton8 9
#define Buton7 8
#define Buton6 7
#define Buton5 6
#define Buton4 5
#define Buton3 4
#define Buton2 3
#define Buton1 2

#define Led1 0


#include <SPI.h>        // Include SPI library (needed for the SD card)
#include <SD.h>         // Include SD library

String myText;
int myMoney[20];
int counter=0;

  
  int paraMiktari[5][2];  // = {{100,10},{50,10},{20,10},{10,10},{5,10}};
  int para;
  int paraAdedi;
  int yuklenenPara = 0;
  int hizmetler[4][2];  // = {{30,15},{50,10},{100,5},{8,50}};
  int harcama = 0;
  int butonState = 0;
  int butonState2 = 0;
  int paraUstu = 0;
  int kopukleme=0,yikama=0,kurulama=0,cilalama=0;
  int randNumber = 1;

  File myFile;
  
void setup()
{
  Serial.begin(9600);
    while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
 
  Serial.print("Initializing SD card...");
 
  if (!SD.begin()) {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");
 
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  SD.remove("test.txt");
  myFile = SD.open("test.txt", FILE_WRITE);
 
  // if the file opened okay, write to it:
  if (myFile) {
    Serial.print("Writing to test.txt...");
    myFile.println("20,20,10,30,5");
    myFile.println("1,kopukleme,30,15");
    myFile.println("2,yikama,50,10");
    myFile.println("3,kurulama,100,5");
    myFile.println("4,cilalama,20,50");
    // close the file:
    myFile.close();
    Serial.println("done.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
 
  // re-open the file for reading:
  myFile = SD.open("test.txt");
  if (myFile) {
    Serial.println("test.txt:");
 
    // read from the file until there's nothing else in it:
    while (myFile.available()) {
       myMoney[counter] = myFile.parseInt();
       counter++;
   }
    // close the file:

     
      paraMiktari[0][1] = myMoney[4];
      paraMiktari[0][0] = 100;
      paraMiktari[1][1] = myMoney[3];
      paraMiktari[1][0] = 50;
      paraMiktari[2][1] = myMoney[2];
      paraMiktari[2][0] = 20;
      paraMiktari[3][1] = myMoney[1];
      paraMiktari[3][0] = 10;
      paraMiktari[4][1] = myMoney[0];
      paraMiktari[4][0] = 5;
       
      hizmetler[0][0] = myMoney[6];
      hizmetler[0][1] = myMoney[7];
      
      hizmetler[1][0] = myMoney[9];
      hizmetler[1][1] = myMoney[10];
      
      hizmetler[2][0] = myMoney[12];
      hizmetler[2][1] = myMoney[13];
      
      hizmetler[3][0] = myMoney[15];
      hizmetler[3][1] = myMoney[16];
      


    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
  pinMode(Buton1, INPUT_PULLUP);
  pinMode(Buton2, INPUT_PULLUP);
  pinMode(Buton3, INPUT_PULLUP);
  pinMode(Buton4, INPUT_PULLUP);
  pinMode(Buton5, INPUT_PULLUP);
  pinMode(Buton6, INPUT_PULLUP);
  pinMode(Buton7, INPUT_PULLUP);
  pinMode(Buton8, INPUT_PULLUP);
  
  pinMode(Led1, OUTPUT);
  Serial.println("Kasadaki Banknot Miktari:   ");
  Serial.print("  ");
  Serial.print(paraMiktari[4][1]);
  Serial.print("  ");
  Serial.print(paraMiktari[3][1]);
  Serial.print("  ");
  Serial.print(paraMiktari[2][1]);
  Serial.print("  ");
  Serial.print(paraMiktari[1][1]);
  Serial.print("  ");
  Serial.print(paraMiktari[0][1]);
  Serial.println("  ");
  Serial.println("---------------------- ");
  Serial.println("Hizmet Miktarlari    ");
  Serial.print("kopukleme hizmet miktari : ");
  Serial.println(hizmetler[0][0]);
  Serial.print("yikama hizmet miktari : ");
  Serial.println(hizmetler[1][0]);
  Serial.print("kurulama hizmet miktari : ");
  Serial.println(hizmetler[2][0]);
  Serial.print("cilalama hizmet miktari : ");
  Serial.println(hizmetler[3][0]);
  Serial.println("---------------------- ");
  
}

void loop()
{
  
  int sensorVal1 = digitalRead(Buton1);
  int sensorVal2 = digitalRead(Buton2);
  int sensorVal3 = digitalRead(Buton3);
  int sensorVal4 = digitalRead(Buton4);
  int sensorVal5 = digitalRead(Buton5);
  int sensorVal6 = digitalRead(Buton6);
  int sensorVal7 = digitalRead(Buton7);
  int sensorVal8 = digitalRead(Buton8);

  if(butonState2<=butonState){
      if (sensorVal1 == LOW){
      paraMiktari[4][1]++;
      yuklenenPara += paraMiktari[4][0]; 
      delay(500);
  }else if (sensorVal2 == LOW){
      paraMiktari[3][1]++;
      yuklenenPara += paraMiktari[3][0]; 
      delay(500);
  }else if (sensorVal3 == LOW){
      paraMiktari[2][1]++;
      yuklenenPara += paraMiktari[2][0]; 
      delay(500);
  }else if (sensorVal4 == LOW){
      paraMiktari[1][1]++;
      yuklenenPara += paraMiktari[1][0]; 
      delay(500);
  }else if (sensorVal5 == LOW){
      paraMiktari[0][1]++;
      yuklenenPara += paraMiktari[0][0]; 
      delay(500);
  }
  }
  if(sensorVal8==LOW){
    Serial.println("Program Resetleniyor");
    setup();
    delay(500);
  }

  if (sensorVal6 == LOW){
      Serial.println(" ");
      Serial.print("Kasaya yuklenen para:  ");
      Serial.println(yuklenenPara); 
      butonState2++;
      
      delay(500);
  }
  if(butonState2>butonState){
    if (sensorVal1 == LOW){
        if(yuklenenPara <= harcama || (yuklenenPara-harcama) < hizmetler[0][1]){
          Serial.println("yeterli bakiyeniz kalmamıstir");
          delay(500);
        }else if(hizmetler[0][0] == 0) {
          Serial.println("Almak istediginiz hizmet suan da mevcut degildir.");
          delay(500);
        } else {
          hizmetler[0][0]--;
          harcama += hizmetler[0][1];
          kopukleme++;
          delay(500);
        } 
    }else if (sensorVal2 == LOW){
        if(yuklenenPara <= harcama || (yuklenenPara-harcama) < hizmetler[1][1]){
          Serial.println("yeterli bakiyeniz kalmamıstir");
          delay(500);
        }else if(hizmetler[1][0] == 0) {
          Serial.println("Almak istediginiz hizmet suan da mevcut degildir.");
          delay(500);
        }else {
          hizmetler[1][0]--;
          harcama += hizmetler[1][1];
          yikama++;
          delay(500);
        } 
    }else if (sensorVal3 == LOW){
        if(yuklenenPara <= harcama || (yuklenenPara-harcama) < hizmetler[2][1]){
          Serial.println("yeterli bakiyeniz kalmamistir");
          delay(500);
        }else if(hizmetler[2][0] == 0) {
          Serial.println("Almak istediginiz hizmet suan da mevcut degildir.");
          delay(500);
        } else {
          hizmetler[2][0]--;
          harcama += hizmetler[2][1];
          kurulama++;
          delay(500);
        } 
    }else if (sensorVal4 == LOW){
        if(yuklenenPara <= harcama || (yuklenenPara-harcama) < hizmetler[3][1]){
          Serial.println("yeterli bakiyeniz kalmamistir");
          delay(500);
        }else if(hizmetler[3][0] == 0) {
          Serial.println("Almak istediginiz hizmet suan da mevcut degildir.");
          delay(500);
        } else {
          hizmetler[3][0]--;
          harcama += hizmetler[3][1];
          cilalama++;
          delay(500);
        } 
    }
  }
  paraUstu = yuklenenPara - harcama;
  if (sensorVal7 == LOW){
    butonState2--;
    if (randNumber == 2) {
      digitalWrite(Led1,HIGH);
      Serial.println("Para sikismasi olmustur");
      Serial.println("Alinan hizmetler geri veriliyor...");
      for(int i=0; i<kopukleme; i++){
        hizmetler[0][0]++;
      }
      for(int i=0; i<yikama; i++){
        hizmetler[1][0]++;
      }
      for(int i=0; i<kurulama; i++){
        hizmetler[2][0]++;
      }
      for(int i=0; i<cilalama; i++){
        hizmetler[3][0]++;
      }
      Serial.println("Para geri iade ediliyor...");
      int j = 0;
      while(j<5){
        para = paraMiktari[j][0];
        paraAdedi = paraMiktari[j][1]; 
        if(yuklenenPara/para != 0){
          paraMiktari[j][1] -= yuklenenPara/para;
          yuklenenPara = yuklenenPara%para;
        }
        j++;
      }        
    Serial.println("Kasadaki Banknot Miktari:   ");
    Serial.print("  ");
    Serial.print(paraMiktari[4][1]);
    Serial.print("  ");
    Serial.print(paraMiktari[3][1]);
    Serial.print("  ");
    Serial.print(paraMiktari[2][1]);
    Serial.print("  ");
    Serial.print(paraMiktari[1][1]);
    Serial.print("  ");
    Serial.print(paraMiktari[0][1]);
    Serial.println("  ");
    
    Serial.println("Kalan Hizmet Miktari:   ");
    Serial.print("kopukleme hizmet miktari : ");
    Serial.println(hizmetler[0][0]);
    Serial.print("yikama hizmet miktari : ");
    Serial.println(hizmetler[1][0]);
    Serial.print("kurulama hizmet miktari : ");
    Serial.println(hizmetler[2][0]);
    Serial.print("cilalama hizmet miktari : ");
    Serial.println(hizmetler[3][0]);
    Serial.println("---------------------- ");    
    yuklenenPara = 0;  
  }else {
    Serial.println(" ");
    Serial.print("Alinan hizmet tutari:  ");
    Serial.println(harcama);
    Serial.print("Odenecek para ustu miktari:  ");
    Serial.println(paraUstu);
    int i =0;
    while(i<5){
      para = paraMiktari[i][0];
      paraAdedi = paraMiktari[i][1];  
      if(paraUstu/para != 0){
        if(paraAdedi>=paraUstu/para){
          paraMiktari[i][1] -= paraUstu/para;
          Serial.print(paraUstu/para);
          Serial.print(" adet ");
          Serial.println(para);
          paraUstu = paraUstu % para;
        } else {
          paraUstu = paraUstu - paraMiktari[i][1];
        }
      }
      i++;
    }
    if(paraUstu > 0){
      for(int i=0; i<kopukleme; i++){
        hizmetler[0][0]++;
      }
      for(int i=0; i<yikama; i++){
        hizmetler[1][0]++;
      }
      for(int i=0; i<kurulama; i++){
        hizmetler[2][0]++;
      }
      for(int i=0; i<cilalama; i++){
        hizmetler[3][0]++;
      }
      int geriKalan = paraUstu+harcama;
      Serial.println("");
      Serial.println("KASADA YETERLI PARA KALMAMISTIR");
      Serial.print("Yuklediginiz ");
      Serial.print(yuklenenPara);
      Serial.println(" tl iade edilmistir.");
      int j = 0;
      while(j<5){
        para = paraMiktari[j][0];
        paraAdedi = paraMiktari[j][1]; 
        if(geriKalan/para != 0){
          paraMiktari[j][1] -= geriKalan/para;
          geriKalan = geriKalan%para;
        }
        if (geriKalan == 0) {
          break;
        }
        j++;
      }
    }
    Serial.println("Kasadaki Banknot Miktari:   ");
    Serial.print("  ");
    Serial.print(paraMiktari[4][1]);
    Serial.print("  ");
    Serial.print(paraMiktari[3][1]);
    Serial.print("  ");
    Serial.print(paraMiktari[2][1]);
    Serial.print("  ");
    Serial.print(paraMiktari[1][1]);
    Serial.print("  ");
    Serial.print(paraMiktari[0][1]);
    Serial.println("  ");
    
    Serial.println("Kalan Hizmet Miktari:   ");
    Serial.print("kopukleme hizmet miktari : ");
    Serial.println(hizmetler[0][0]);
    Serial.print("yikama hizmet miktari : ");
    Serial.println(hizmetler[1][0]);
    Serial.print("kurulama hizmet miktari : ");
    Serial.println(hizmetler[2][0]);
    Serial.print("cilalama hizmet miktari : ");
    Serial.println(hizmetler[3][0]);
    Serial.println("---------------------- ");
    yuklenenPara = 0;  
  }

    delay(500);
   }
   
 }
  
  
