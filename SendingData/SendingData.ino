/*
  Make sure your Firebase project's ".read" and ".write" rules are set to "true".
  Avoiding this will result in an error.
  For more details- https://github.com/Rupakpoddar/ESP8266Firebase/blob/master/README.md
*/

#include <ESP8266Firebase.h>
#include <ESP8266WiFi.h>

#define _SSID "redmi"        // Your WiFi SSID
#define _PASSWORD "redmi1021"    // Your WiFi Password  // Your Firebase Project ID. Can be found in project settings.
#define PROJECT_ID "wastesegregator-ea8d2-default-rtdb"
/*
  // FAST METHOD
  // REQUIRES PERIODIC UPDATE OF FINGERPRINT (EVERY 1 YEAR)
  // OUTDATED FINGERPRINT WILL STOP THE SERVICE
  // LATEST FINGERPRINT CAN BE FOUND AT- https://www.grc.com/fingerprints.htm?domain=test.firebaseio.com
  // REPLACE COLONS(:) WITH A SPACE(" ") AS SHOWN BELOW
  // 03:9E:4F:E6:83:FC:40:EF:FC:B2:C5:EF:36:0E:7C:3C:42:20:1B:8F ==> 03 9E 4F E6 83 FC 40 EF FC B2 C5 EF 36 0E 7C 3C 42 20 1B 8F
  #define FINGERPRINT "03 9E 4F E6 83 FC 40 EF FC B2 C5 EF 36 0E 7C 3C 42 20 1B 8F"
  Firebase firebase(PROJECT_ID, FINGERPRINT);
  // UNCOMMENT THIS BLOCK AND COMMENT THE LINE BELOW
*/
char index_html[] PROGMEM ={"Our Entire Website GOES here as a string"};
const int cpin = 5;
Firebase firebase(PROJECT_ID);   
int distance_1()
{  
  const int trigPin = 9;
  const int echoPin = 10;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  int duration = pulseIn(echoPin, HIGH);
  int distance = (duration / 2) * 0.0343;
 return distance;
  }

void handleHtml(){
  
    server.send_P(200,"text/html",index_html);
  
  }

void handleNotFound() {
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
}
long distance_2()
{  
  const int trigPin = 7;
  const int echoPin = 6;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  int duration = pulseIn(echoPin, HIGH);
  long distance = (duration / 2) * 0.0343;
 return distance;
  }
int distance_3()
{
    const int trigPin = 13;
  const int echoPin =11;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  int duration = pulseIn(echoPin, HIGH);
  long distance = (duration / 2) * 0.0343;
 return distance;
  
  
  }
void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(1000);

  Serial.println();
  Serial.println();
  Serial.print("Connecting to: ");
  Serial.println(_SSID);
  WiFi.begin(_SSID, _PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print("-");
  }

  Serial.println("");
  Serial.println("WiFi Connected");

  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
  digitalWrite(LED_BUILTIN, HIGH);
server.on("/", handleHtml);
  firebase.setString("Waste/dry", "It's Working");
  firebase.setInt("waste/wet", 123);
  firebase.setFloat("Waste/Metal", 45.32);
  firebase.setString("ip-addresss", WiFi.localIP().toString());


}

void loop() {
 
  int on  = digitalRead(cpin);
  if(on)
  {
    while(on)
    {
      delay(500);
        int on  = digitalRead(D7);
      }
      
    }
      firebase.setString("Waste/dry", distance_1());
  firebase.setInt("waste/wet", distance_2());
  firebase.setFloat("Waste/Metal", distance_3());

}
