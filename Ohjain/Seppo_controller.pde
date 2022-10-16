import processing.net.*; 

Client Seppo; 
int dataIn; 
String data = "0;0;0;0;";

void setup() { 
  size(200, 200); 
  Seppo = new Client(this, "192.168.1.184", 8080);
} 

void draw() {
  
}


void keyPressed() {
  if (key == 'a' || key == 'A') { //FWD
    data = "1;0;0;0;\n";
  } else if (key == 'd' || key == 'D') { //BWD
    data = "0;1;0;0;\n";
  } else if (key == 'W' || key == 'w') { //UP
  
    data = "0;0;1;0;\n";
  } else if (key == 's' || key == 'S') { //DOWN
    data = "0;0;0;1;\n";
    
  } else {
    data = "0;0;0;0;";
  }
  Seppo.write(data+"\n");
  println(data);
}

void keyReleased(){
  data = "0;0;0;0;";
  Seppo.write(data+"\n");
}
