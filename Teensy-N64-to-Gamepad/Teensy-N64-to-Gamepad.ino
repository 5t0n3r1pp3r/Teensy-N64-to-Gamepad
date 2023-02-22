/*

   Teensy N64 Serial Converter
   by 5t0n3r1pp3r

   TX pin from 16Mhz Board connects to RX1 on Teensy or Pin0
   Set to Joystick mode for USB Type


*/


bool Debug = true;//Send Serial Output for debug or testing in proccessing
//Button Variables
char a, b, z, Strt, up, down, left, right, lrstrt, na, l, r, cup, cdown, cleft, cright;
// X/Y Variable Storage
int num1 = 0, num2 = 0;

void setup() {
  Serial.begin(115200); // Initialize serial communication with USB
  Serial1.begin(115200); // Initialize serial communication with Control Reader
}

void loop() {
  if (Serial1.available() > 0) { // Check if there is incoming data
    String input = Serial1.readStringUntil('\n'); // Read the incoming string
    input.trim(); // Remove any leading or trailing whitespace
    if (input.length() > 0) { // Check if the string is not empty

      //Set the data in the buttons variables
      a = input.charAt(0);
      b = input.charAt(1);
      z = input.charAt(2);
      Strt = input.charAt(3);
      up = input.charAt(4);
      down = input.charAt(5);
      left = input.charAt(6);
      right = input.charAt(7);
      lrstrt = input.charAt(8);
      na = input.charAt(9);
      l = input.charAt(10);
      r = input.charAt(11);
      cup = input.charAt(12);
      cdown = input.charAt(13);
      cleft = input.charAt(14);
      cright = input.charAt(15);

      //Retrieve the xy coordinates from the end using spaces as delimiters
      int space1 = input.indexOf(' ');
      int space2 = input.indexOf(' ', space1 + 1);
      if (space1 != -1 && space2 != -1) {
        String num1Str = input.substring(space1 + 1, space2);
        String num2Str = input.substring(space2 + 1);
        num1 = num1Str.toInt();
        num2 = num2Str.toInt();
      }
      // Print the parsed integers to the serial console for Debug and formatted to run in control proccessing sketch
      if (Debug) {
        Serial.print(a);
        Serial.print(b);
        Serial.print(z);
        Serial.print(Strt);
        Serial.print(up);
        Serial.print(down);
        Serial.print(left);
        Serial.print(right);
        Serial.print(lrstrt);
        Serial.print(na);
        Serial.print(l);
        Serial.print(r);
        Serial.print(cup);
        Serial.print(cdown);
        Serial.print(cleft);
        Serial.print(cright);
        Serial.print(' ');
        Serial.print(num1);
        Serial.print(' ');
        Serial.print(num2);
        Serial.print(" \n");
      }
      //Send Controller Signals
      Joystick.X(map(num1, -80, 80, 0, 1023));//left right
      Joystick.Y(map(num2, 79, -82, 0, 1023));//down up
      if (a == '0') {
        Joystick.button(1, false);
      }
      if (a == '4') {
        Joystick.button(1, true);
      }
      if (b == '0') {
        Joystick.button(2, false);
      }
      if (b == '4') {
        Joystick.button(2, true);
      }
      if (z == '0') {
        Joystick.button(3, false);
      }
      if (z == '4') {
        Joystick.button(3, true);
      }
      if (up == '0') {
        Joystick.button(5, false);
      }
      if (up == '4') {
        Joystick.button(5, true);
      }
      if (down == '0') {
        Joystick.button(6, false);
      }
      if (down == '4') {
        Joystick.button(6, true);
      }
      if (left == '0') {
        Joystick.button(7, false);
      }
      if (left == '4') {
        Joystick.button(7, true);
      }
      if (right == '0') {
        Joystick.button(8, false);
      }
      if (right == '4') {
        Joystick.button(8, true);
      }
      if (l == '0') {
        Joystick.button(9, false);
      }
      if (l == '4') {
        Joystick.button(9, true);
      }
      if (r == '0') {
        Joystick.button(10, false);
      }
      if (r == '4') {
        Joystick.button(10, true);
      }
      if (cup == '0') {
        Joystick.button(11, false);
      }
      if (cup == '4') {
        Joystick.button(11, true);
      }
      if (cdown == '0') {
        Joystick.button(12, false);
      }
      if (cdown == '4') {
        Joystick.button(12, true);
      }
      if (cleft == '0') {
        Joystick.button(13, false);
      }
      if (cleft == '4') {
        Joystick.button(13, true);
      }
      if (cright == '0') {
        Joystick.button(14, false);
      }
      if (cright == '4') {
        Joystick.button(14, true);
      }
      if (Strt == '4' || lrstrt == '4') {
        Joystick.button(4, true);
      }
      else {
        Joystick.button(4, false);
      }
      Joystick.hat(-1); //center hat -1 "angle" is 0,45,90,135,180,225,270,315
    }
  }
}

//Format
//0000000000000000 0 0 /n
//a;
//b;
//z;
//Strt;
//up;
//down;
//left;
//right;
//lrstrt;
//na;
//l;
//r;
//cup;
//cdown;
//cleft;
//cright;
