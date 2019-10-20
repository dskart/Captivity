
 /*
 * This code makes your esp32 a client that connnects to a ros server on a local network over wifi
 * it then subscribes and outputs anything published by the server on the chatter topic
 * 
 */


#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/UInt32.h>
#include "std_msgs/Float32.h"
#include <std_msgs/Empty.h>
#include <captivity/Num.h>
// FOR ESP32
// #include <WiFi.h>
// FOR ESP8266 
#include <ESP8266WiFi.h>

//router settings
char  ssid[]     = "it-hurts-when-ip";
const char* password = "SendNudesOn259S";

//creates ros handle
ros::NodeHandle nh;

captivity::Num num_msg;
ros::Publisher chatter1("chatter1", &num_msg);

//this should be the IP and Port of your ros server on your computer/device
// 11411 is the default port for every ros server
const uint16_t serverPort = 11411;
// IPAddress server(10, 9, 9, 137);
IPAddress server(192, 168, 0, 137);
// 192.168.0.137

char debug[] = "debug statements";
char info_msg[] = "infos";
char warn[] = "warnings";
char error[] = "errors";
char fatal[] = "fatalities";

void setup()
{
    Serial.begin(115200);

    delay(10);

    // We start by connecting to a WiFi network
    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
    }

    Serial.println("");
    Serial.println("WiFi connected.");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    
    // let esp breathe
    delay(1000);

   //connect to ros server
   nh.getHardware()->setConnection(server, serverPort);
   nh.initNode();
   nh.advertise(chatter1);
}

int ii = 0;

void loop()
{
  ++ii;
  num_msg.num = ii;
  chatter1.publish( &num_msg );

  nh.logdebug(debug);
  nh.loginfo(info_msg);
  // nh.logwarn(warn);
  // nh.logerror(error);
  // nh.logfatal(fatal);
  
  nh.spinOnce();
  delay(500);
}
