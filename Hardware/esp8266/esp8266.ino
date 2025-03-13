
/* https://arduino.esp8266.com/stable/package_esp8266com_index.json
 * ESP8266 as Web Server using WiFi Access Point (AP) mode
 * Connect to AP "Robot Wifi", password = "87654321"
 */
 
#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

const char* ssid = "Robot Wifi";
const char* password = "11111111";

#define ENA   4     // Enable/speed motors Right    GPIO4(D2)
#define IN_1  0     // L298N in1 motors Right       GPIO0(D3)
#define IN_2  2     // L298N in2 motors Right       GPIO2(D4)
#define IN_3  12    // L298N in3 motors Left        GPIO12(D6)
#define IN_4  13    // L298N in4 motors Left        GPIO13(D7)
#define ENB   15    // Enable/speed motors Left     GPIO15(D8)


String command;           
int speedCar = 150; /
int speed_low = 60;

ESP8266WebServer server(80);

void setup() {
 
  Serial.begin(115200);

 pinMode(ENA, OUTPUT); 
 pinMode(IN_1, OUTPUT);
 pinMode(IN_2, OUTPUT);
 pinMode(IN_3, OUTPUT);
 pinMode(IN_4, OUTPUT);
 pinMode(ENB, OUTPUT); 

 pinMode(Light, OUTPUT); 
 
  
// Connecting WiFi

  WiFi.mode(WIFI_AP);        
  WiFi.softAP(ssid, password); 

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
 
     server.on ( "/", HTTP_handleRoot );
     server.onNotFound ( HTTP_handleRoot );
     server.begin();    
}

void loop() {
    server.handleClient();
    
      command = server.arg("State");
           if (command == "F") goForword();
      else if (command == "B") goBack();
      else if (command == "L") goLeft();
      else if (command == "R") goRight();
      else if (command == "S") stopRobot();
}

void HTTP_handleRoot(void) {

if( server.hasArg("State") ){
       Serial.println(server.arg("State"));
  }
  server.send ( 200, "text/html", "" );
  delay(1);
}

void goForword(){ 

      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      analogWrite(ENA, speedCar);

      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
      analogWrite(ENB, speedCar);
  }

void goBack(){ 

      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);
      analogWrite(ENA, speedCar);

      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
      analogWrite(ENB, speedCar);
  }

void goRight(){ 

          Serial.println("Moving Right");
          digitalWrite(IN_1, LOW);
          digitalWrite(IN_2, HIGH);
          analogWrite(ENA, 100);
          digitalWrite(IN_3, LOW);
          digitalWrite(IN_4, HIGH);
          analogWrite(ENB, 100);
  }

void goLeft(){
          Serial.println("Moving Left");
          digitalWrite(IN_1, HIGH);
          digitalWrite(IN_2, LOW);
          analogWrite(ENA, 100);
          digitalWrite(IN_3, HIGH);
          digitalWrite(IN_4, LOW);
          analogWrite(ENB, 100);
  }

void stopRobot(){  

      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, LOW);
      analogWrite(ENA, speedCar);

      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, LOW);
      analogWrite(ENB, speedCar);
 }