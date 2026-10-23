#include <SoftwareSerial.h>
SoftwareSerial bluetooth(5,6); //rx tx

// declaração das variáveis

int FLEX_PIN1 = A0; 
int flexADC1 = 0; 
int sensorMin1 = 749; 
int sensorMax1 = 925;

int FLEX_PIN2 = A1; 
int flexADC2 = 0; 
int sensorMin2 = 767; 
int sensorMax2 = 928;

int FLEX_PIN3 = A2; 
int flexADC3 = 0; 
int sensorMin3 = 787; 
int sensorMax3 = 908;

int FLEX_PIN4 = A3; 
int flexADC4 = 0; 
int sensorMin4 = 802; 
int sensorMax4 = 921;

int FLEX_PIN5 = A4; 
int flexADC5 = 0; 
int sensorMin5 = 754; 
int sensorMax5 = 905;

int xpin = A5;
int xadc = 0;
int xmin = 1023;
int xmax = 0;

int ypin = A6;
int yadc = 0;
int ymin = 1023;
int ymax = 0;


void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
  while (!Serial) 
  {
    ; // aguarda a ligação da porta série. necessário apenas para a porta USB nativa
  }

  /*
  // calibração dos sensores para adaptabilidade a diferentes curvas
  Serial.println("A calibrar");

  while(millis()<15000){
    float flexADC1 = analogRead(FLEX_PIN1);
    float flexADC2 = analogRead(FLEX_PIN2);
    float flexADC3 = analogRead(FLEX_PIN3);
    float flexADC4 = analogRead(FLEX_PIN4);
    float flexADC5 = analogRead(FLEX_PIN5);

    if(flexADC1<sensorMin1){
      sensorMin1=flexADC1;
    }
    if(flexADC1>sensorMax1){
      sensorMax1=flexADC1;
    }

    if(flexADC2<sensorMin2){
      sensorMin2=flexADC2;
    }
    if(flexADC2>sensorMax2){
      sensorMax2=flexADC2;
    }

    if(flexADC3<sensorMin3){
      sensorMin3=flexADC3;
    }
    if(flexADC3>sensorMax3){
      sensorMax3=flexADC3;
    }

    if(flexADC4<sensorMin4){
      sensorMin4=flexADC4;
    }
    if(flexADC4>sensorMax4){
      sensorMax4=flexADC4;
    }

    if(flexADC5<sensorMin5){
      sensorMin5=flexADC5;
    }
    if(flexADC5>sensorMax5){
      sensorMax5=flexADC5;
    }
  }

  Serial.println(sensorMin1);
  Serial.println(sensorMax1);
  Serial.println(sensorMin2);
  Serial.println(sensorMax2);
  Serial.println(sensorMin3);
  Serial.println(sensorMax3);
  Serial.println(sensorMin4);
  Serial.println(sensorMax4);
  Serial.println(sensorMin5);
  Serial.println(sensorMax5);

  Serial.println("Calibração concluida");

  */

}

void loop(){
  // leitura dos valor dos sensores
  float flexADC1 = analogRead(FLEX_PIN1);
  float flexADC2 = analogRead(FLEX_PIN2);
  float flexADC3 = analogRead(FLEX_PIN3);
  float flexADC4 = analogRead(FLEX_PIN4);
  float flexADC5 = analogRead(FLEX_PIN5);

  flexADC1 = constrain(flexADC1,sensorMin1, sensorMax1);
  flexADC2 = constrain(flexADC2,sensorMin2, sensorMax2);
  flexADC3 = constrain(flexADC3,sensorMin3, sensorMax3);
  flexADC4 = constrain(flexADC4,sensorMin4, sensorMax4);
  flexADC5 = constrain(flexADC5,sensorMin5, sensorMax5);

  float angle1 = map(flexADC1, sensorMin1, sensorMax1, 0, 90);
  float angle2 = map(flexADC2, sensorMin2, sensorMax2, 0, 90);
  float angle3 = map(flexADC3, sensorMin3, sensorMax3, 0, 90);
  float angle4 = map(flexADC4, sensorMin4, sensorMax4, 0, 90);
  float angle5 = map(flexADC5, sensorMin5, sensorMax5, 0, 90); 

  xadc = analogRead(xpin);
  yadc = analogRead(ypin);

  // valores dos sensores em tempo real
  Serial.print("a1= ");
  Serial.println(angle1);
  Serial.print("a2= ");
  Serial.println(angle2);
  Serial.print("a3= ");
  Serial.println(angle3);
  Serial.print("a4= ");
  Serial.println(angle4);
  Serial.print("a5= ");
  Serial.println(angle5);
  Serial.print("xadc= ");
  Serial.println(xadc);
  Serial.print("yadc= ");
  Serial.println(yadc);
  Serial.println(" ");
  
  // condições para cada símbolo
  if(((angle1>=20)&&(angle1<=40))&&((angle2>=60)&&(angle2<=75))&&((angle3>=0)&&(angle3<=20))&&((angle4>=30)&&(angle4<=50))&&((angle5>=60)&&(angle5<=80))){
    bluetooth.print("A");
    Serial.println("A");
  }
  if(((angle1>=0)&&(angle1<=20))&&((angle2>=60)&&(angle2<=80))&&((angle3>=60)&&(angle3<=80))&&((angle4>=60)&&(angle4<=80))&&((angle5>=60)&&(angle5<=80))&&((yadc>=400)&&(yadc<=499))){
    bluetooth.print("B");
    Serial.println("B");
  }
  if(((angle1>=30)&&(angle1<=50))&&((angle2>=50)&&(angle2<=70))&&((angle3>=40)&&(angle3<=60))&&((angle4>=30)&&(angle4<=50))&&((angle5>=40)&&(angle5<=60))){
    bluetooth.print("C");
    Serial.println("C");
  }
  if(((angle1>=20)&&(angle1<=40))&&((angle2>=20)&&(angle2<=40))&&((angle3>=0)&&(angle3<=20))&&((angle4>=0)&&(angle4<=20))&&((angle5>=10)&&(angle5<=30))&&((xadc>=350)&&(xadc<=400))){
    bluetooth.print("D");
    Serial.println("D");
  }
  if(((angle1>=20)&&(angle1<=40))&&((angle2>=40)&&(angle2<=60))&&((angle3>=50)&&(angle3<=70))&&((angle4>=50)&&(angle4<=70))&&((angle5>=60)&&(angle5<=80))){
    bluetooth.print("E");
    Serial.println("E");
  }
  if(((angle1>=10)&&(angle1<=20))&&((angle2>=40)&&(angle2<=60))&&((angle3>=0)&&(angle3<=10))&&((angle4>=0)&&(angle4<=10))&&((angle5>=0)&&(angle5<=20))){
    bluetooth.print("F");
    Serial.println("F");
  }
  if(((angle1>=30)&&(angle1<=50))&&((angle2>=70)&&(angle2<=85))&&((angle3>=70)&&(angle3<=85))&&((angle4>=70)&&(angle4<=85))&&((angle5>=70)&&(angle5<=85))){
    bluetooth.print("G");
    Serial.println("G");
  }
  if(((angle1>=20)&&(angle1<=40))&&((angle2>=50)&&(angle2<=60))&&((angle3>=0)&&(angle3<=10))&&((angle4>=0)&&(angle4<=10))&&((angle5>=0)&&(angle5<=10))){
    bluetooth.print("H");
    Serial.println("H");
  }
  if(((angle1>=40)&&(angle1<=50))&&((angle2>=70)&&(angle2<=80))&&((angle3>=60)&&(angle3<=70))&&((angle4>=50)&&(angle4<=60))&&((angle5>=10)&&(angle5<=20))){
    bluetooth.print("I");
    Serial.println("I");
  }
  if(((angle1>=20)&&(angle1<=30))&&((angle2>=0)&&(angle2<=20))&&((angle3>=0)&&(angle3<=10))&&((angle4>=0)&&(angle4<=10))&&((angle5>=0)&&(angle5<=10))){
    bluetooth.print("J");
    Serial.println("J");
  }
  if(((angle1>=0)&&(angle1<=20))&&((angle2>=0)&&(angle2<=20))&&((angle3>=0)&&(angle3<=10))&&((angle4>=50)&&(angle4<=70))&&((angle5>=60)&&(angle5<=80))){
    bluetooth.print("K");
    Serial.println("K");
  }
  if(((angle1>=0)&&(angle1<=20))&&((angle2>=10)&&(angle2<=30))&&((angle3>=40)&&(angle3<=60))&&((angle4>=40)&&(angle4<=60))&&((angle5>=70)&&(angle5<=90))&&((xadc>=400)&&(xadc<=499))){
    bluetooth.print("L");
    Serial.println("L");
  }
  if(((angle1>=30)&&(angle1<=50))&&((angle2>=10)&&(angle2<=30))&&((angle3>=0)&&(angle3<=20))&&((angle4>=0)&&(angle4<=20))&&((angle5>=60)&&(angle5<=80))){
    bluetooth.print("M");
    Serial.println("M");
  }
  if(((angle1>=40)&&(angle1<=60))&&((angle2>=0)&&(angle2<=20))&&((angle3>=0)&&(angle3<=10))&&((angle4>=60)&&(angle4<=80))&&((angle5>=60)&&(angle5<=80))){
    bluetooth.print("N");
    Serial.println("N");
  }
  if(((angle1>=50)&&(angle1<=70))&&((angle2>=50)&&(angle2<=70))&&((angle3>=50)&&(angle3<=70))&&((angle4>=50)&&(angle4<=70))&&((angle5>=50)&&(angle5<=70))){
    bluetooth.print("O");
    Serial.println("O");
  }
  if(((angle1>=50)&&(angle1<=70))&&((angle2>=60)&&(angle2<=80))&&((angle3>=0)&&(angle3<=20))&&((angle4>=0)&&(angle4<=20))&&((angle5>=20)&&(angle5<=40))){
    bluetooth.print("P");
    Serial.println("P");
  }
  if(((angle1>=0)&&(angle1<=20))&&((angle2>=60)&&(angle2<=80))&&((angle3>=60)&&(angle3<=80))&&((angle4>=60)&&(angle4<=80))&&((angle5>=70)&&(angle5<=90))&&((yadc>=300)&&(yadc<=399))){
    bluetooth.print("Q");
    Serial.println("Q");
  }
  if(((angle1>=0)&&(angle1<=20))&&((angle2>=10)&&(angle2<=30))&&((angle3>=40)&&(angle3<=65))&&((angle4>=40)&&(angle4<=60))&&((angle5>=60)&&(angle5<=90))&&((xadc>=300)&&(xadc<=399))){
    bluetooth.print("T");
    Serial.println("T");
  }
  if(((angle1>=20)&&(angle1<=40))&&((angle2>=20)&&(angle2<=40))&&((angle3>=0)&&(angle3<=20))&&((angle4>=30)&&(angle4<=50))&&((angle5>=60)&&(angle5<=80))){
    bluetooth.print("U");
    Serial.println("U");
  }

  delay(500);
}