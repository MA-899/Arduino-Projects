int output_bin = 13;

struct Code {
  char ch;
  String code;
};

Code char_codes[] = {
  {'A', ".-"},
  {'B', "-..."},
  {'C', "-.-."},
  {'D', "-.."},
  {'E', "."},
  {'F', "..-."},
  {'G', "--."},
  {'H', "...."},
  {'I', ".."},
  {'J', ".---"},
  {'K', "-.-"},
  {'L', ".-.."},
  {'M', "--"},
  {'N', "-."},
  {'O', "---"},
  {'P', ".--."},
  {'Q', "--.-"},
  {'R', ".-."},
  {'S', "..."},
  {'T', "-"},
  {'U', "..-"},
  {'V', "...-"},
  {'W', ".--"},
  {'X', "-..-"},
  {'Y', "-.--"},
  {'Z', "--.."},
  {'0', "-----"},
  {'1', ".----"},
  {'2', "..---"},
  {'3', "...--"},
  {'4', "....-"},
  {'5', "....."},
  {'6', "-...."},
  {'7', "--..."},
  {'8', "---.."},
  {'9', "----."}
};

void morse(int length, int* delays, int bin){
  for (int i = 0; i < length; i++) {
    int d = delays[i];
    digitalWrite(bin, HIGH);
    tone(bin, 2000);
    delay(d);
    noTone(bin);
    digitalWrite(bin, LOW);
    delay(d);
  }

  delay(1000);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(output_bin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  String s = Serial.readString();
  int n = s.length();
  s.toUpperCase();

  for(int i = 0; i < n; i++) {
    char ch = s[i];
    String str = "";

    for (int j = 0; j < 36; j++) {
      if (ch == char_codes[j].ch) {
        str = char_codes[j].code;
      }
    }

    int len = str.length();
    
    int ch_code[len]; 

    for (int j = 0; j < len; j++){
      if (str[j] == '.')
        ch_code[j] = 150;
      else if (str[i] == ' ')
        ch_code[j] = 200;
      else
        ch_code[j] = 300;
    }

    morse(len, ch_code, output_bin);
  }

  return;
}
