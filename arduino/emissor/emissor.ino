#include <Ethernet.h>
#include <IRremote.h>

IRsend irsend;

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip( 192,168,15,177 );

EthernetServer server(80);

void sendIR(unsigned int *irSignalToSend, int tamanho, int quantityOfLoops) {
  unsigned int khz = 38;
  
  for(int i=0; i < quantityOfLoops; i++){
    irsend.sendRaw(irSignalToSend, tamanho, khz);
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

 Ethernet.begin(mac, ip);
 delay(2000);
 server.begin();

 Serial.println("setup finished");
}

void loop()
{

 EthernetClient client = server.available();
 if (client) {
   Serial.println("Client");
   
   boolean currentLineIsBlank = true;
   char data[290];
   while (client.connected()) {
     while(client.available()) {
       char c = client.read();
	
       if (c == '\n' && currentLineIsBlank) {

         int i=0;
         while(client.available())
         {  
            data[i] = client.read();
            i++;
         }
		 
         unsigned int inteiros[68];
         convertingCharToInt(data,inteiros, 290);
         sendIR(inteiros+1, 67, inteiros[0]);
		 
         client.println("HTTP/1.0 200 OK");  
         client.println("Access-Control-Allow-Origin: *");   
         client.println("Access-Control-Allow-Methods: POST");
         client.println("Content-Type: text/html");
         client.println();
         client.println("<HTML><BODY>OK!</BODY></HTML>");
         client.stop();
       }
       else if (c == '\n') {
         currentLineIsBlank = true;
       } 
       else if (c != '\r') {
         currentLineIsBlank = false;
       }
     }
   }
 }
}
