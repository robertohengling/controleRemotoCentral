/*
A simple web server using an Arduino Wiznet Ethernet shield. 
For Arduino IDE V1.0 only. Previous IDE versions require mods to this code.

Original code created 18 Dec 2009
by David A. Mellis
modified 4 Sep 2010
by Tom Igoe
modified 18 Jan 2012
by Tim Dicus 
*/

#include <Ethernet.h>
#include <IRremote.h>

IRsend irsend;

// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip( 192,168,15,177 );

// Initialize the Ethernet server library
// with the IP address and port you want to use 
// (port 80 is default for HTTP):
EthernetServer server(80);
void sendIR(unsigned int *irSignalToSend, int tamanho, int quantityOfLoops) {
  unsigned int khz = 38;
  for(int j=0; j < tamanho; j++){
    Serial.println(irSignalToSend[j]);
  }
  for(int i=0; i < quantityOfLoops; i++){
    irsend.sendRaw(irSignalToSend, tamanho, khz); //Note the approach used to automatically calculate the size of the array.
    delay(100);    
  }
}

void convertingCharToInt(char *text, unsigned int * vector, int tamanhoTexto ){
  boolean inicio = false;
  boolean fim = false;
  int quantityOfElements = 0;
  char textOfOneElement[10];
  int j=0;
  for(int i = 0; i < tamanhoTexto; i++){
    if(text[i]== '<'){
      inicio = true;
      fim = false;
    } else if (text[i]== '>'){
      inicio = false;
      fim = true;
    } else if (text[i] == ' ' && !inicio){
      textOfOneElement[j+1] = '\0'; 
      vector[quantityOfElements] = atoi(textOfOneElement);
      quantityOfElements++;
      for(int k=0; k < 10; k++){
        textOfOneElement[k] = ' ';
      }
      j= 0;
    } else {
      inicio = false;
      fim = false;
      textOfOneElement[j] = text[i];
      j++;
    }
  }
}
void setup()
{
 Serial.begin(9600);

 // start the SD interface here if you want.
 // Add the SD.h library above
 // SD.begin(4);

 // start the Ethernet connection and the server:
 Ethernet.begin(mac, ip);
 delay(2000);
 server.begin();

 Serial.println("setup finished");
}

void loop()
{
 // listen for incoming clients
 EthernetClient client = server.available();
 if (client) {
   Serial.println("Client");
   // an http request ends with a blank line
   boolean currentLineIsBlank = true;
   char data[290];
   while (client.connected()) {
     while(client.available()) {
       char c = client.read();
       // if you've gotten to the end of the line (received a newline
       // character) and the line is blank, the http request has ended,
       // so you can send a reply
       if (c == '\n' && currentLineIsBlank) {

         // Here is where the POST data is.  
         int i=0;
         while(client.available())
         {  
            data[i] = client.read();
            Serial.write(data[i]);
            i++;
         }
         Serial.println();
         unsigned int inteiros[68];
         convertingCharToInt(data,inteiros, 290);
         sendIR(inteiros+1, 67, inteiros[0]);
         Serial.println("Sending response");
         // send a standard http response header
         client.println("HTTP/1.0 200 OK");  
         client.println("Access-Control-Allow-Origin: *");   
         client.println("Access-Control-Allow-Methods: POST");
         client.println("Content-Type: text/html");
         client.println();
         client.println("<HTML><BODY>TEST OK!</BODY></HTML>");
         client.stop();
       }
       else if (c == '\n') {
         // you're starting a new line
         currentLineIsBlank = true;
       } 
       else if (c != '\r') {
         // you've gotten a character on the current line
         currentLineIsBlank = false;
       }
     }
   }
   Serial.println("Disconnected");
 }
}
