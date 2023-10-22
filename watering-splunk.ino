#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>

// Need to connec to the wifi somehow, set it up here
WiFiClient wifiClient;
String esid  = "<your-wifi-id>";
String epass = "<your-wifi-password>";

// splunk settings and http collector token
String collectorToken = "<your-collector-token>";
String splunkIndexer = "127.0.0.1";
String eventData="";

//you need a different client per board
String clientName ="nodemcu";

int IN1 = 5;
int Pin1 = A0;
float value1 = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("splunk hec");
  initWiFi();
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  pinMode(IN1, OUTPUT);
  pinMode(Pin1, INPUT);
  digitalWrite(IN1, HIGH);
  delay(500);
}

void loop() {
  Serial.print("MOISTURE LEVEL:");
  value1 = analogRead(Pin1);
  Serial.println(value1); 
  if(value1>500) {
    digitalWrite(IN1, LOW);
  } else {
    digitalWrite(IN1, HIGH);
  }
  Serial.println(value1);
  eventData="\"clientname\": \""+clientName + "\",\"humidity\": \""+String(value1)+"\"";
  Serial.println(eventData);
  //send off the data
  splunkpost(collectorToken, eventData, clientName, splunkIndexer); 
  delay(2000);
}

void initWiFi(){
  Serial.println();
  Serial.println("Wifi Startup");
  esid.trim();
  if ( esid.length() > 1 ) {
      // test esid 
      WiFi.disconnect();
      delay(100);
      WiFi.mode(WIFI_STA);
      Serial.print("Connecting to WiFi ");
      Serial.println(esid);
      WiFi.begin(esid.c_str(), epass.c_str());
      if ( testWifi() == 20 ) { 
          return;
      }
  }
}

int testWifi(void) {
  int c = 0;
  Serial.println("Wifi test...");  
  while ( c < 30 ) {
    if (WiFi.status() == WL_CONNECTED) { return(20); } 
    delay(500);
    Serial.print(".");    
    c++;
  }
  Serial.println("WiFi Connect timed out");
  return(10);
} 

void splunkpost(String collectorToken, String PostData, String Host, String splunkIndexer)
{
  // recieved the token, post data clienthost and the splunk indexer  
  String payload = "{ \"host\" : \"" + Host +"\", \"sourcetype\" : \"http_test\", \"index\" : \"auto-irrigation\", \"event\": {" + PostData + "}}";
  
  //Build the request
  HTTPClient http;
  String splunkurl="http://"+ splunkIndexer +":8088/services/collector";
  String tokenValue="Splunk " + collectorToken;
  
  // fire at will!! 
  http.begin(wifiClient, splunkurl);
  http.addHeader("Content-Type", "application/json");
  Serial.println(tokenValue);
  http.addHeader("Authorization", tokenValue);
  Serial.println(payload);
  String contentlength = String(payload.length());
  http.addHeader("Content-Length", contentlength );
  int httpCode = http.POST(payload);
  http.writeToStream(&Serial);
  Serial.print("HTTP response code: ");
  Serial.println(httpCode);
  String response = http.getString();
  Serial.println(response);
  http.end();
 
}