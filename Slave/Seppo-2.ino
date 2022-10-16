#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
/*
  const char* ssid = "SEPPO";
  const char* pass = "Tuotesuunnittelu";


  WiFiServer server(8080);

  // Device Local IP
  IPAddress IP(192, 168, 1, 184);
  // Device GatewaY
  IPAddress gateway(192, 168, 1, 1);
  // Subnet mask
  IPAddress subnet(255, 255, 0, 0);
*/
#define FWD   D1
#define BWD   D2
#define UP    D3
#define DOWN  D4

#define input1  D0
#define input2  D5
#define input3  D6
#define input4  D7

#define master true

int Up = 0;
int Down = 0;
int Fwd = 0;
int Bwd = 0;
int inputInts[8];

void setup() {

  /*
    WiFi.disconnect();

    WiFi.mode(WIFI_AP_STA);

    if (!WiFi.softAPConfig(IP, gateway, subnet)) {
      Serial.println("STA Failed to configure");
    }

    WiFi.softAP(ssid);

    WiFi.softAP(ssid);

    Serial.print("CONNECTED! IP Address: ");
    Serial.println(WiFi.softAPIP());

    server.begin();
  */

  pinMode(FWD, OUTPUT);
  pinMode(BWD, OUTPUT);
  pinMode(UP, OUTPUT);
  pinMode(DOWN, OUTPUT);

  pinMode(input1, INPUT);
  pinMode(input2, INPUT);
  pinMode(input3, INPUT);
  pinMode(input4, INPUT);

  Serial.begin(9600);

}

void loop() {
  /*
    WiFiClient client = server.available();

    while (client.connected()) {
      if (client.available()) {
        String input = client.readStringUntil('\n');
        input.trim();
        Serial.println(input);

        int valueIndex = 0;
        int intIndex = 0;
        for (int i = 0; i < input.length(); i++) {
          if (input.charAt(i) == ';') {
            String tempString =  input.substring(valueIndex, i);
            inputInts[intIndex] = tempString.toInt();
            intIndex++;
            valueIndex = i + 1;
            Serial.println(tempString);
          }
        }
        Fwd = inputInts[0];
        Bwd = inputInts[1];
        Up = inputInts[2];
        Down = inputInts[3];

        if (Fwd == 1) {
          digitalWrite(FWD, HIGH);
          digitalWrite(BWD, LOW);
          digitalWrite(UP, LOW);
          digitalWrite(DOWN, LOW);
          Serial.println("1;0;0;0;");
        }

        else if (Bwd == 1) {
          digitalWrite(FWD, LOW);
          digitalWrite(BWD, HIGH);
          digitalWrite(UP, LOW);
          digitalWrite(DOWN, LOW);
          Serial.println("0;1;0;0;");
        }

        else if (Up == 1) {
          digitalWrite(FWD, LOW);
          digitalWrite(BWD, LOW);
          digitalWrite(UP, HIGH);
          digitalWrite(DOWN, LOW);
          Serial.println("0;0;1;0;");
        }

        else if (Down == 1) {
          digitalWrite(FWD, LOW);
          digitalWrite(BWD, LOW);
          digitalWrite(UP, LOW);
          digitalWrite(DOWN, HIGH);
          Serial.println("0;0;0;1;");
        }

        else {
          digitalWrite(FWD, 0);
          digitalWrite(BWD, 0);
          digitalWrite(UP, 0);
          digitalWrite(DOWN, 0);
          Serial.println("0;0;0;0;");
        }



        Serial.println((String)Fwd + ";" + Bwd + ";" + Up + ";" + Down + ";");

        Fwd = 0;
        Bwd = 0;
        Up = 0;
        Down = 0;


      }

    }
  */


  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    //Serial.println(input);

    int valueIndex = 0;
    int intIndex = 0;
    for (int i = 0; i < input.length(); i++) {
      if (input.charAt(i) == ';') {
        String tempString =  input.substring(valueIndex, i);
        inputInts[intIndex] = tempString.toInt();
        intIndex++;
        valueIndex = i + 1;
        //Serial.println(tempString);
      }
    }
    Fwd = inputInts[0];
    Bwd = inputInts[1];
    Up = inputInts[2];
    Down = inputInts[3];

    if (Fwd == 1) {
      digitalWrite(FWD, HIGH);
      digitalWrite(BWD, LOW);
      digitalWrite(UP, LOW);
      digitalWrite(DOWN, LOW);
      //Serial.println("1;0;0;0;");
    }

    else if (Bwd == 1) {
      digitalWrite(FWD, LOW);
      digitalWrite(BWD, HIGH);
      digitalWrite(UP, LOW);
      digitalWrite(DOWN, LOW);
      //Serial.println("0;1;0;0;");
    }

    else if (Up == 1) {
      digitalWrite(FWD, LOW);
      digitalWrite(BWD, LOW);
      digitalWrite(UP, HIGH);
      digitalWrite(DOWN, LOW);
      //Serial.println("0;0;1;0;");
    }

    else if (Down == 1) {
      digitalWrite(FWD, LOW);
      digitalWrite(BWD, LOW);
      digitalWrite(UP, LOW);
      digitalWrite(DOWN, HIGH
      );
      //digitalWrite(DOWN, HIGH);
      //Serial.println("0;0;0;1;");
    }

    else {
      digitalWrite(FWD, LOW);
      digitalWrite(BWD, LOW);
      digitalWrite(UP, LOW);
      digitalWrite(DOWN, LOW);
    }

    Fwd = 0;
    Bwd = 0;
    Up = 0;
    Down = 0;
  }



  if (digitalRead(input1) == HIGH && Serial.available() == false) {
    //Serial.println("UP");
    digitalWrite(FWD, LOW);
    digitalWrite(BWD, LOW);
    digitalWrite(UP, HIGH);
    digitalWrite(DOWN, LOW);
  }

  else if (digitalRead(input2) == HIGH) {
    //Serial.println("DOWN");
    digitalWrite(FWD, LOW);
    digitalWrite(BWD, LOW);
    digitalWrite(UP, LOW);
    digitalWrite(DOWN, HIGH);
  }

  else if (digitalRead(input3) == HIGH) {
    //Serial.println("FORWARD");
    digitalWrite(FWD, HIGH);
    digitalWrite(BWD, LOW);
    digitalWrite(UP, LOW);
    digitalWrite(DOWN, LOW);
  }

  else if (digitalRead(input4) == HIGH) {
    //Serial.println("BACK");
    digitalWrite(FWD, LOW);
    digitalWrite(BWD, HIGH);
    digitalWrite(UP,  LOW);
    digitalWrite(DOWN, LOW);
  }
  /*
    else if (digitalRead(input1) == LOW && digitalRead(input2) == LOW && digitalRead(input3) == LOW && digitalRead(input4) == LOW && Serial.available() == false) {
      digitalWrite(FWD, LOW);
      digitalWrite(BWD, LOW);
      digitalWrite(UP, LOW);
      digitalWrite(DOWN, LOW);
    } */


}
