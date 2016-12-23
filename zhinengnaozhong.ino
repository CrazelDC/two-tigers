float tonelist[7]={1046.5,1174.7,1318.5,1396.9,1568,1760,1975.5};

long musiclist[32]={1,2,3,1,1,2,3,1,3,4,5,3,4,5,5,6,5,4,3,1,5,6,5,4,3,1,2,5,1,2,5,1};

long highlist[32]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,-1,0};

long rhythmlist[32]={4,4,4,4,4,4,4,4,4,4,2,4,4,2,8,8,8,8,4,4,8,8,8,8,4,4,4,4,2,4,4,2};

void playmusic() {
  for (int i = 1; i <= 32; i = i + (1)) {
    tone(10,tonelist[(int)(musiclist[(int)(i - 1)] - 1)] * pow(2, highlist[(int)(i - 1)]));
     if ( !digitalRead(4)) {
      noTone(10);
     }
    delay((2000 / rhythmlist[(int)(i - 1)]));
    noTone(10);
    delay(10);
  }
}

void setup()
{
  pinMode(10, OUTPUT);
}

void loop()
{
  while (digitalRead(6) && digitalRead(0)) {
    playmusic();
    delay(10000);
  }

}
