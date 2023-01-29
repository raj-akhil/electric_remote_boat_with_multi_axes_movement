/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on NodeMCU.

  Note: This requires ESP8266 support package:
    https://github.com/esp8266/Arduino

  Please be sure to select the right NodeMCU module
  in the Tools -> Board menu!

  For advanced settings please follow ESP examples :
   - ESP8266_Standalone_Manual_IP.ino
   - ESP8266_Standalone_SmartConfig.ino
   - ESP8266_Standalone_SSL.ino

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

/* Fill-in your Template ID (only if using Blynk.Cloud) */
//#define BLYNK_TEMPLATE_ID   "YourTemplateID"


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
void GO_LEFT()
{
  digitalWrite(16,HIGH);
  digitalWrite(5,LOW);
  Serial.println("going left");
  
}
void GO_RIGHT()
{
  digitalWrite(5,HIGH);
  digitalWrite(16,LOW);
   Serial.println("going right");
}
void GO_FORWARD()
{
  digitalWrite(16,HIGH);
  digitalWrite(5,HIGH);
  Serial.println("going forward");
  
}


// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "PkfJdRBurioXk7zzUYrdgAYjAKFJOHSN";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Force0.5";
char pass[] = "appu@0488";
int s=155;
void setup()
{
  // Debug console
  Serial.begin(115200);
  pinMode(16,OUTPUT);//D0
  pinMode(5,OUTPUT);//D1
  pinMode(4,OUTPUT);//D2
  pinMode(12,OUTPUT);//D6
  pinMode(2,OUTPUT);//D4
  pinMode(13,OUTPUT);//D7
  digitalWrite(13,HIGH);
  digitalWrite(2,HIGH);
  Blynk.begin(auth, ssid, pass);

  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
}

void loop()
{
  Blynk.run();
  analogWrite(4,s);
  analogWrite(12,s);
  //Serial.println(s);

}
BLYNK_WRITE(V0)
{
  s=param.asInt();
}
BLYNK_WRITE(V3)
{   

  // The param can contain multiple values, in such case:
  int x = param[0].asInt();
  int y = param[1].asInt();

  if(y>1000)
  {
    GO_FORWARD();
  }
  else if(x<50)
  {
    GO_LEFT();
  }
  else if(x>1000)
  {
    GO_RIGHT();
  }
  else
  {
  digitalWrite(16,LOW);
  digitalWrite(5,LOW);
  }
  
}
BLYNK_WRITE(V1)
{
  int k=param.asInt();
  if(k==1)
  {
    digitalWrite(13,LOW);
    digitalWrite(2,LOW);
  }
  else
  {
  digitalWrite(13,HIGH);
  digitalWrite(2,HIGH);
  }
}
