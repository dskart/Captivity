
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
// #include <WiFi.h>
#include <ESP8266WiFi.h>

//router settings
char  ssid[]     = "it-hurts-when-ip";
const char* password = "SendNudesOn259S";

//creates ros handle
ros::NodeHandle nh;
//set the name of the topic to subscribe
const char* topic = "chatter1";

// std_msgs::String msg;
captivity::Num msg;
ros::Publisher chatter2("chatter2", &msg);

//this should be the IP and Port of your ros server on your computer/device
// 11411 is the default port for every ros server
const uint16_t serverPort = 11411;
IPAddress server(10,9,9,137);

//this function runs when something is publish ed on the subscribed topic
//it prints the string saved in incoming_msg (server published a string)
void messageCb( const captivity::Num& incoming_msg)
{
  int msg_heard = incoming_msg.num;
  Serial.println(msg_heard);
  msg.num = msg_heard;
  chatter2.publish(&msg);
}

//subscribes to ros topic, reference to function that handles what happens when something gets published
ros::Subscriber<captivity::Num> sub(topic, &messageCb );

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
        Serial.print(".");
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
   nh.subscribe(sub);
   nh.advertise(chatter2);
}

void loop()
{

  //processes ros handle Callbacks ("read" what is in the topic)
  nh.spinOnce();

}
