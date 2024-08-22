// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
    Name:       dataTransfer.ino
    Created:	2023/07/03 16:05:57
    Author:     LAPTOP-LMSAH8O8\amtl
*/

// Define User Types below here or use a .h file
//


// Define Function Prototypes that use User Types below here or use a .h file
//


// Define Functions below here or use other .ino or cpp files
//

// The setup() function runs once each time the micro-controller starts
#include <Arduino.h>
#include <SoftwareSerial.h>

SoftwareSerial dataSerial(22, 21); // RX TX, sends MSP data to 
byte character = 0;
const unsigned int MAX_MESSAGE_LENGTH = 12;
void setup()
{
    Serial.begin(115200);
    dataSerial.begin(115200);

}

// Add the main program code into the continuous loop() function
void loop()
{
    //Serial.println("hello");
    dataSerial.write("request\n");
    //Serial.write("hellooooo\n");
    while (dataSerial.available()) {

        //Create a place to hold the incoming message
        static char message[MAX_MESSAGE_LENGTH];
        static unsigned int message_pos = 0;

        //Read the next available byte in the serial receive buffer
        char inByte = dataSerial.read();

        //Message coming in (check not terminating character) and guard for over message size
        if (inByte != '!' && (message_pos < MAX_MESSAGE_LENGTH - 1))
        {
            //Add the incoming byte to our message
            message[message_pos] = inByte;
            message_pos++;
        }
        //Full message received...
        else
        {
            //Add null character to string
            message[message_pos] = '\0';

            //Print the message (or do other things)
            Serial.println(message);

            //Reset for the next message
            message_pos = 0;
        }
        // = dataSerial.read();
       //Serial.println((char)character);
    }
    delay(500);
}
